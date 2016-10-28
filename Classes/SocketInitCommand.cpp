#include "SocketInitCommand.h"
#include "PlatFormControl.h"
#include "UTF8.h"
#include "MTNotificationQueue.h"
#include "TCPSocketService.h"
#include "SGTools.h"

/**
ÊÂ¼þÍ¨ÖªÖ´ÐÐº¯Êý
*/
#define CLoseSocketTime 300
void SocketInitCommand::execute(void* data)
{
	registLogin rLogin = *(registLogin*)(data);
	bool iErrorCode = false;
	TCPSocketService*  tcp_login = (TCPSocketService*)getService(TCPSocketService::LOGIN);
	iErrorCode = tcp_login->
		Connect(UTF8::getInstance()->getString("net", "loginServerIp").c_str() ,
		        atoi(UTF8::getInstance()->getString("net", "loginServerPort").c_str()));


	tcp_login->lastRcvTime = time(NULL);
	tcp_login->m_wRecvSize = 0;

 	if (iErrorCode)
	{
		logF("login Socket %d ", tcp_login->m_hSocket);
		logV("login Socket %d ", tcp_login->m_hSocket);
		tcp_login->type = 1;

		getcontainer()->schedule(schedule_selector(SocketInitCommand::heartPacket2), 5.0f);  //cgp
		std::thread recvDate(&SocketInitCommand::recvDate, this);
		recvDate.detach();
		
		getcontainer()->schedule(schedule_selector(SocketInitCommand::socketEventDispatch), 1.0 / 30.0f); //cgp
		
		if (rLogin.type == 1)
		{
			//µÇÂ¼²âÊÔ
			MD5 md5;
			md5.update(rLogin.szLogonPass);
			((SendDataService *)getService(SendDataService::NAME))->sendLogin(rLogin.szAccounts, md5.toString().data(), md5.toString().data());
			DATA->md5Passwd = md5.toString();
		}
		else
		{

			//×¢²á²âÊÔ
			MD5 md5;
			md5.update(rLogin.szLogonPass);
			((SendDataService *)getService(SendDataService::NAME))->sendRegister(md5.toString().data(), rLogin.wFaceID, rLogin.cbGender, rLogin.szAccounts, rLogin.szNickName);
			DATA->md5Passwd = md5.toString();

		}

	}

	else
	{
		Tools::getInstance()->showSysMsg(UTF8::getInstance()->getString("err", "err6"), CC_CALLBACK_1(SocketInitCommand::callNotConnect, this));
	}
}

void SocketInitCommand::callNotConnect(Ref* psender)
{
	Node*  img = static_cast<Node*>(psender);
	img->getParent()->removeFromParentAndCleanup(true);
	log("not connect to login server ##############################");
}

void SocketInitCommand::checkNetWorks2(float dt)
{
	time_t nowTime = time(NULL);
	time_t lastTime = ((TCPSocketService*)getService(TCPSocketService::LOGIN))->lastRcvTime;
	if (nowTime - lastTime > CLoseSocketTime)
	{
		Tools::getInstance()->showSysMsg(UTF8::getInstance()->getString("err", "err7"), CC_CALLBACK_1(SocketInitCommand::callNotConnect, this));
	}
}


void SocketInitCommand::heartPacket2(float dt)
{
	((TCPSocketService*)getService(TCPSocketService::LOGIN))->SendData(MDM_KN_COMMAND, SUB_KN_DETECT_SOCKET, NULL, 0);
}


void SocketInitCommand::recvDate()
{
	((TCPSocketService*)getService(TCPSocketService::LOGIN))->OnRecvPacket();
}

void SocketInitCommand::socketEventDispatch(float dt)
{
	LifeCircleMutexLock(&shareNotificationQueueLock);
	TCPSocketService *socketServiceLogin = ((TCPSocketService*)getService(TCPSocketService::LOGIN));
	TCPSocketService *socketServiceGame = ((TCPSocketService*)getService(TCPSocketService::GAME));

	if (socketServiceLogin->eventList.size() > 0)
	{

		list<NetData*>::iterator it;
		for (it = socketServiceLogin->eventList.begin(); it != socketServiceLogin->eventList.end();)
		{
			blueSkyDispatchEvent(EventType::SOCKET_REC_DATA, *it);
			it = socketServiceLogin->eventList.erase(it);
		}
	}



	if (socketServiceGame->eventList.size() > 0)
	{
		list<NetData*>::iterator it;
		for (it = socketServiceGame->eventList.begin(); it != socketServiceGame->eventList.end();)
		{
			blueSkyDispatchEvent(EventType::SOCKET_REC_DATA, *it);
			it = socketServiceGame->eventList.erase(it);
		}
	}




}