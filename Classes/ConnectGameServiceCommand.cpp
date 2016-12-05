#include "ConnectGameServiceCommand.h"
#include "SGTools.h"
#include "TCPSocketService.h"
#include "UTF8.h"
#include "LobbyMediator.h"
#include "LobbyView.h"
#include "DataManager.h"

/**
事件通知执行函数
*/
void ConnectGameServiceCommand::execute(void* data)
{

	RoomListModel* roomListModel = ((RoomListModel*)getModel(RoomListModel::NAME));
	
	unsigned short port;  

	switch (DATA->bGameCate)
	{
	case DataManager::E_GameCateNormal:
		if (DATA->bGameCateSub == 0)
		{
			port = atoi(UTF8::getInstance()->getString("net", "PrimaryPort").c_str());
		}
		else if (DATA->bGameCateSub == 1)
		{
			port = atoi(UTF8::getInstance()->getString("net", "MediumPort").c_str());
		}
		else if (DATA->bGameCateSub == 2)
		{
			port = atoi(UTF8::getInstance()->getString("net", "MasterPort").c_str());
		}
		break;

	case DataManager::E_GameCateMatch:
		port = atoi(UTF8::getInstance()->getString("net", "MatchPort").c_str());
		break;

	case DataManager::E_GameFriend:
	case DataManager::E_GameFriendPassive:
		port = atoi(UTF8::getInstance()->getString("net", "FriendPort").c_str());
			break;

	case DataManager::E_GameTeam:
	case DataManager::E_GameTeamPassive:
		port = atoi(UTF8::getInstance()->getString("net", "TeamPort").c_str());
		break;

	case DataManager::E_GameRandZhupai:
		port = atoi(UTF8::getInstance()->getString("net", "RandZhupaiPort").c_str());
		break;

	case DataManager::E_GameBlood:
		if (DATA->bGameCateSub == 0)
		{
			port = atoi(UTF8::getInstance()->getString("net", "BloodPort0").c_str());
		}
		else if (DATA->bGameCateSub == 1)
		{
			port = atoi(UTF8::getInstance()->getString("net", "BloodPort1").c_str());
		}
		else if (DATA->bGameCateSub == 2)
		{
			port = atoi(UTF8::getInstance()->getString("net", "BloodPort2").c_str());
		}
		break;

	default:

		break;

	}


	
	string ip = ((RoomListModel*)getModel(RoomListModel::NAME))->roomList[0].wszServerAddr;
	logV("port %d, ip %s", port, ip.c_str());
	logF("port %d, ip %s", port, ip.c_str());

	TCPSocketService*  tcp_game = (TCPSocketService*)getService(TCPSocketService::GAME);
	bool iErrorCode = tcp_game->Connect(ip.data(), port);
	tcp_game->eventList.clear();
	tcp_game->lastRcvTime = time(NULL);
	tcp_game->m_wRecvSize = 0;

	if (iErrorCode)
	{
		logF("cocos2d-x socket game connect success m_hSocket %d ", tcp_game->m_hSocket);
		logV("\ncocos2d-x socket game connect success m_hSocket %d \n", tcp_game->m_hSocket);


		getcontainer()->schedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks), 30.0f);

		tcp_game->type = 2;

		getcontainer()->schedule(schedule_selector(ConnectGameServiceCommand::heartPacket), 5.0f);
		std::thread recvDate(&ConnectGameServiceCommand::recvDate, this);
		recvDate.detach();

		DWORD dwUserID = DATA->myBaseData.dwUserID;
		const char* szLogonPass = DATA->md5Passwd.data();
		/*unsigned short wKindID = ((RoomListModel*)getModel(RoomListModel::NAME))->roomList[i].wKindID;*/
		unsigned short wKindID = 2;   //only guandan 
		if (DATA->bGameCate == DataManager::E_GameFriendPassive || DATA->bGameCate == DataManager::E_GameTeamPassive)
		{
			((SendDataService *)getService(SendDataService::NAME))->sendGameServerLogin(dwUserID, szLogonPass, wKindID, DATA->wFriendPassiveTableId, DATA->wFriendPassiveChairId);
		}
		else
		{
			((SendDataService *)getService(SendDataService::NAME))->sendGameServerLogin(dwUserID, szLogonPass, wKindID);
		}
		
	}

	else
	{
		
	}
}

void ConnectGameServiceCommand::callNotConnect(Ref* psender)
{
	blueSkyDispatchEvent(10601);
 	Node*  img = static_cast<Node*>(psender);
 	img->getParent()->removeFromParentAndCleanup(true);
// 	
// 	logF("time out 30s and close mysocket");
// 	logV("time out 30s and close mysocket");
// 
// 	((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();
// 
// 	//停掉网络主动监测与心跳
// 	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
// 	{
// 		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
// 	}
// 
// 	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
// 	{
// 		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
// 	}
// 
// 	//跳转至大厅界面
// 	blueSkyDispatchEvent(EventType::BACK_TO_HALL);
// 	creatView(new LobbyView(), new LobbyMediator());

}

void ConnectGameServiceCommand::checkNetWorks(float dt)
{
	time_t nowTime = time(NULL);
	time_t lastTime = ((TCPSocketService*)getService(TCPSocketService::GAME))->lastRcvTime;
	if (nowTime - lastTime > 30.0)  //断线
	{ 
		Tools::getInstance()->showSysMsg(UTF8::getInstance()->getString("err", "err8"), CC_CALLBACK_1(ConnectGameServiceCommand::callNotConnect, this));

	}



}

void ConnectGameServiceCommand::heartPacket(float dt)
{
	((TCPSocketService*)getService(TCPSocketService::GAME))->SendData(MDM_KN_COMMAND, SUB_KN_DETECT_SOCKET, NULL, 0);
}
void ConnectGameServiceCommand::recvDate()
{

	((TCPSocketService*)getService(TCPSocketService::GAME))->OnRecvPacket();
}
