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
	int j = *(int*)data;   //按钮传递
	
	int i = 0;
	unsigned short port;   
	if (j == 3)  //match 
	{
		if (DATA->bMatchItem == 0)
		{
			port = atoi(UTF8::getInstance()->getString("net", "MatchPort").c_str());
		} 
		else if (DATA->bMatchItem == 1)
		{
			port = atoi(UTF8::getInstance()->getString("net", "MatchPort").c_str());
		}
	} 
	else
	{
		if (DATA->bGameCate == DataManager::E_GameRandZhupai)
		{
			port = atoi(UTF8::getInstance()->getString("net", "RandZhupaiPort").c_str());
		}
		else if (DATA->bGameCate == DataManager::E_GameFriend || DATA->bGameCate == DataManager::E_GameFriendPassive)
		{
			port = atoi(UTF8::getInstance()->getString("net", "FriendPort").c_str());
		}
		else if (DATA->bGameCate == DataManager::E_GameTeam || DATA->bGameCate == DataManager::E_GameTeamPassive)
		{
			port = atoi(UTF8::getInstance()->getString("net", "TeamPort").c_str());
		}
		else
		{
			i = roomListModel->realSn[j];
			port = ((RoomListModel*)getModel(RoomListModel::NAME))->roomList[i].wwServerPort;
		}
	}


	string ip = ((RoomListModel*)getModel(RoomListModel::NAME))->roomList[i].wszServerAddr;

	TCPSocketService*  tcp_game = (TCPSocketService*)getService(TCPSocketService::GAME);
	bool iErrorCode = tcp_game->Connect(ip.data(), port);
	tcp_game->eventList.clear();
	tcp_game->lastRcvTime = time(NULL);
	tcp_game->m_wRecvSize = 0;

	if (iErrorCode)
	{
		logF("cocos2d-x socket game connect success m_hSocket %d ", tcp_game->m_hSocket);
		logV("cocos2d-x socket game connect success m_hSocket %d ", tcp_game->m_hSocket);


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
	Node*  img = static_cast<Node*>(psender);
	img->getParent()->removeFromParentAndCleanup(true);
	
	logF("time out 30s and close mysocket");
	logV("time out 30s and close mysocket");

	((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();

	//停掉网络主动监测与心跳
	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
	}

	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
	}

	//跳转至大厅界面
	blueSkyDispatchEvent(EventType::BACK_TO_HALL);
	creatView(new LobbyView(), new LobbyMediator());

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