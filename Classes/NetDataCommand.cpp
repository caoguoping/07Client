#include "NetDataCommand.h"
#include "SocketInitCommand.h"
#include "TCPSocketService.h"
#include "UTF8.h"
#include "SGTools.h"
#include "DataManager.h"
#include "ConnectGameServiceCommand.h"
#include "ViewPopup.h"
#include "ViewManager.h"
#include "FriendView.h"
/**
�¼�ִ֪ͨ�к���
*/






#define  ShowMessage 0

NetDataCommand::NetDataCommand()
{
	txtLogin = Text::create();
	txtLogin->setFontSize(20);
	txtLogin->setPosition(Vec2(300, 200));
	txtLogin->setColor(Color3B(0, 0, 255));
	getcontainer()->addChild(txtLogin, 999999);

	txtGame = Text::create();
	txtGame->setFontSize(20);
	txtGame->setPosition(Vec2(300, 350));
	txtGame->setColor(Color3B(0, 255, 0));
	getcontainer()->addChild(txtGame, 999999);

	txtFail = Text::create();
	txtFail->setFontSize(20);
	txtFail->setPosition(Vec2(300, 500));
	txtFail->setColor(Color3B(255, 0, 0));
	getcontainer()->addChild(txtFail, 999999);
}


void NetDataCommand::execute(void* data)
{
	NetData netData = *(NetData*)data;
	if (netData.type == 2)
	{
		executeGame(netData);
	}
	else if (netData.type == 1)
	{
		executeLogin(netData);
	}
}
//��Ϸ��������������
void NetDataCommand::executeGame(NetData netData)
{
#if(ShowMessage == 1)
	char temp[512];
	sprintf(temp, "GameServer main: %d,  sub: %d    \n", netData.command.wMainCmdID, netData.command.wSubCmdID);
	txtGame->setString(temp);

#endif

	logV("cocos2d-x GameServer main : %d, sub : %d   size %d \n", netData.command.wMainCmdID, netData.command.wSubCmdID, netData.wDataSize);
	logF("cocos2d-x GameServer main : %d, sub : %d   size %d \n", netData.command.wMainCmdID, netData.command.wSubCmdID, netData.wDataSize);


	int wKindID = ((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->wKindID;
	if (netData.command.wMainCmdID == 1)
	{
		std::string errMessage;
		switch (netData.command.wSubCmdID)
		{
		case 101:

			netData.readDWORD();
			errMessage =  netData.readString(netData.wDataSize);
			((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();

			//ͣ�������������������
			if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
			{
				getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
			}

			if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
			{
				getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
			}


			break;

			case 102:	//��Ϸ��������¼�ɹ�
				blueSkyDispatchEvent(EventType::GAMESERVER_LOGIN_SUCSS);

				break;

			case 103:  //���ܽ�ͬһ������
				((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();

				//ͣ�������������������
				if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
				{
					getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
				}

				if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
				{
					getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
				}
				break;

		}
	}
	else if (netData.command.wMainCmdID == 3)
	{
		switch (netData.command.wSubCmdID)
		{
		case 100:
			//��ȡ���뷿��������Ϣ

			getInDeskPlayerInfo(netData);
			break;
		case 102:	
			getDeskInfo(netData);
			break;
		case 103:
			getGameFail(netData);
			break;

		case 104:    //���������û���Ϣ
			getMatchUserScore(netData);
			break;

		case 105:    //��������ʣ������

			logV("cocos2d-x 3, 105 leftDesks");
			getMatchLeftDesk(netData);
			break;

		case 106:     //��������������Ϣ

			logV("cocos2d-x 3, 106 gameRank info");
			getMatchRank(netData);
			break;

		case 301://ʹ�õ���
			useItem(netData);
			break;
		case 307:
			useJiPaiQi(netData);
			break;
		}
	}
	else if (netData.command.wMainCmdID == 4)
	{
		switch (netData.command.wSubCmdID)
		{
		case 101://4�˺��ѳ��������˳�����
			getTableInfo(netData);
			break;

		case 102:
			blueSkyDispatchEvent(EventType::FRIEND_FIELD_QUIT);
			break;
		}
	}
	else if (netData.command.wMainCmdID == 200)
	{
		if (wKindID == 2)
		{
			switch (netData.command.wSubCmdID)
			{
			case 105://��Ϸ����
				gameOver(netData);
				break;
			case 101:
				getSendPokerInfo(netData);  //����
				break;
			case 102://�û�����
				getPlayerOutPoker(netData);
				break;
			case 103://��������
				notOutPoker(netData);
				break;
			case 104://��Ϸ����
				getPayTribute(netData);
				break;

			case 112://���ͼ���������
				getJipaiqiData(netData);
				break;

			case 110:    //ϵͳ��Ϣs
				//getSMessage(netData);
				break;

			case 113://�㲥�Ҽ���
				getBroadCastDaoju(netData);
				break;


			}
		}

	}
	else if (netData.command.wMainCmdID == 5)
	{
		switch (netData.command.wSubCmdID)
		{
		case 104://����
			getMisInfo(netData);
			break;
		}
	}
	else if (netData.command.wMainCmdID == 7)
	{
		switch (netData.command.wSubCmdID)
		{
		case 401: //��������

			logV("cocos2d-x join people");
			getMatchNumInfo(netData);
			break;


		case 406:  //����������״̬ һ���ֽ�

			logV("cocos2d-x 406 gameState");
			getMatchStates(netData);
			break;



		case 409 ://  ��������

			logV("cocos2d-x lunchang");
			getMatchChangLun(netData);
			break;

		case 410:  //��̭��Ϣ
			logV("cocos2d-x taotai");
			getMatchPass(netData);
			break;

		case 411:   //��ʷ������� һ��WORD
			logV("cocos2d-x bestRank");
			getBestRank(netData);
				break;

		}
	}
	else if (netData.command.wMainCmdID == 100)
	{
		switch (netData.command.wSubCmdID)
		{
		case 11: //����
			getChat(netData);
			break;

		case 200:  //systemMessage1
			//getSystemMessage(netData);
			break;
		}
	}

	else if (netData.command.wMainCmdID == 1000)
	{
		switch (netData.command.wSubCmdID)
		{
		case 1:  //systemMessage2
			//getSystemMessage(netData);
			break;
		}
	}
	
}


//��¼��������������
void NetDataCommand::executeLogin(NetData netData)
{
	
#if(ShowMessage == 1)
	char temp[512];
	sprintf(temp, "LoginServer main: %d,  sub: %d    \n", netData.command.wMainCmdID, netData.command.wSubCmdID);
	txtLogin->setString(temp);
#endif

	logV("LoginServer main: %d,  sub: %d   size %d \n", netData.command.wMainCmdID, netData.command.wSubCmdID, netData.wDataSize);
	logF("LoginServer main: %d,  sub: %d   size %d \n", netData.command.wMainCmdID, netData.command.wSubCmdID, netData.wDataSize);

	if (netData.command.wMainCmdID == MDM_GP_LOGON)
	{
		int i;
		switch (netData.command.wSubCmdID)
		{
			case SUB_GP_LOGON_SUCCESS:	//��¼�ɹ�
				loginComplete(netData);
				//blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "test", "test1", -1, -1));
				break;
			case SUB_GP_LOGON_FAILURE:	//��¼ʧ��
				//Tools::getInstance()->showSysMsg(UTF8::getInstance()->getString("err", "err5"));
				i = netData.readWORD();
				switch (i)
				{
				case 1:
					blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "err", "err1", -1, -1));
					((TCPSocketService*)getService(TCPSocketService::LOGIN))->closeMySocket();
					break;
				case 3:
					blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "err", "err1", -1, -1));
					((TCPSocketService*)getService(TCPSocketService::LOGIN))->closeMySocket();
					break;
				case 7:
					blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "err", "err2", -1, -1));
					((TCPSocketService*)getService(TCPSocketService::LOGIN))->closeMySocket();
					blueSkyDispatchEvent(EventType::GAME_START);
					blueSkyDispatchEvent(EventType::ERROR_MSG, &i);
					break;
				}
				
				break;
			case SUB_GP_LOGON_FINISH:	//��¼���
				break;
			case SUB_GP_VALIDATE_MBCARD:	//��¼ʧ��
				blueSkyDispatchEvent(EventType::ERROR_MSG, new unsigned short(netData.readWORD()));
				break;
			case SUB_GP_UPDATE_NOTIFY:	//������ʾ
				break;
			case 104:					//�齱��Ϣ   
				getGamblingInfo(netData);
				break;

			case SUB_GP_CREATE_ROLE: //�״ε�½��������ɫ
				firstLogin(netData);
				break;

			default:
				break;



		}
	}
	else if (netData.command.wMainCmdID == 2)
	{
		switch (netData.command.wSubCmdID)
		{
		case 104://��ȡ�����б�
			getRoomList(netData);
			unsigned char cbBuffer[SOCKET_TCP_PACKET];
			log("##cocos2d-x getRoomList");

			((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(3, 1000, cbBuffer, 0);
			break;
		}
	}
	else if (netData.command.wMainCmdID == 3)
	{
		switch (netData.command.wSubCmdID)
		{
		case 405://gold
			insureSuccess(netData);
			break;
		
		case 502://�����̳���Ʒ
			getBuyItemsInfo(netData);
			break;
			
			//��ʯ�䶯
		case 1001:
			getZuanShiInfo(netData);
			break;

			//���а���Ϣ
		case 1007:
			getRankInfo(netData);
			break;
			//������ȡ����
		case 1008:
			getCupAwardInfo(netData);
			break;

		case 703://������   ����Ϸ������Ǩ�ƹ���
			getMisReward(netData);
			break;

		}
	}
	else if (netData.command.wMainCmdID == 6)
	{
		switch (netData.command.wSubCmdID)
		{
		case 3:
			getFriendsInfo(netData);
			break;
		case  5:    //�Լ����ģ��ظ��Լ���
			getFriedsAddInfoMe(netData);
			break;
		case 6:   //�Է����ģ��ظ��Լ���
			getFriedsAddInfoHim(netData);
			break;
		case 9:
			getFriendsShuRen(netData);
			break;

		case 11:
			getFriendSearch(netData);
			break;

		case 13:
			getFriendPush(netData);
			break;

		case 16:
			getFriendFieldInvite(netData);
			break;
		default:
			break;
		}
	}

	else if (netData.command.wMainCmdID == 600)
	{
		switch (netData.command.wSubCmdID)
		{
		//���յ�½���Ѿ���¼�������� ��%7��
		case 601:

			log("##cocos2d-x seven day");
			getSignInformation(netData);
			break;
		}
	}
	else if (netData.command.wMainCmdID == 201)
	{
		switch (netData.command.wSubCmdID)
		{
			//�̳���Ϣ
			case 1:
				getMallInfo(netData);
				break;
		}
	}
	else if (netData.command.wMainCmdID == 700)
	{
		switch (netData.command.wSubCmdID)
		{
			//������Ϣ
		case 701:
			getLoginMisInfo(netData);
			break;
		}
	}
	else if (netData.command.wMainCmdID == 500)
	{
		switch (netData.command.wSubCmdID)
		{
			//������Ϣ
		case 501:
			getItemsInfo(netData);
			break;
		}
	}
}



void NetDataCommand::firstLogin(NetData netData)
{
	registLogin *rLogin = new registLogin();
	rLogin->type = 2;      //ע��
	rLogin->cbGender = random(1, 2);
	rLogin->szAccounts = "12345678";
	rLogin->szLogonPass = "23456789";
	rLogin->wFaceID = (int)(CCRANDOM_0_1() * 4 + 1);//1~4
	blueSkyDispatchEvent(EventType::REGIST_CHARACTER, rLogin);
}


/*��¼�ɹ� �����Ϣ*/
void NetDataCommand::loginComplete(NetData netData)
{
	;
	//DATA->myBaseData = (MyBaseData*)netData.pDataBuffer;
	DATA->myBaseData.wFaceID = netData.readWORD();						 	//ͷ���ʶ
	DATA->myBaseData.dwUserID = netData.readDWORD();							//�û� I D
	DATA->myBaseData.dwGameID = netData.readDWORD();							//��Ϸ I D
	DATA->myBaseData.dwGroupID = netData.readDWORD();							//���ű�ʶ
	DATA->myBaseData.dwCustomID = netData.readDWORD();							//�Զ���ʶ
	DATA->myBaseData.dwUserMedal = netData.readDWORD();							//�û�����
	DATA->myBaseData.dwExperience = netData.readDWORD();						//������ֵ
	DATA->myBaseData.dwLoveLiness = netData.readDWORD();						//�û�����

	//�û��ɼ�
	DATA->myBaseData.lUserScore = netData.readUInt64();								//�û����
	DATA->myBaseData.lUserInsure = netData.readUInt64();								//�û�����

	//�û���Ϣ
	DATA->myBaseData.cbGender = netData.readByte();							//�û��Ա�
	DATA->myBaseData.cbMoorMachine = netData.readByte();						//��������
	DATA->myBaseData.szAccounts = netData.readString(64);								//��¼�ʺ�
	std::string tempstring = DATA->myBaseData.szNickName = netData.readString(64);								//�û��ǳ�
	DATA->myBaseData.szGroupName = netData.readString(64);							//��������

	//������Ϣ
	DATA->myBaseData.cbShowServerStatus = netData.readByte();                 //��ʾ������״̬

	//
	DATA->myBaseData.isFirstLogin = netData.readDWORD();						  //�Ƿ��ǽ����һ�ε�¼

	//
	DATA->myBaseData.rmb = netData.readDWORD();									  //��ʯ	

	blueSkyDispatchEvent(EventType::LOGIN_COMPLETE);
}

void NetDataCommand::getJipaiqiData(NetData netData)
{
	for (int i = 0; i < 18; i ++)
	{
		DATA->jipai[i] = netData.readByte();
	}
	blueSkyDispatchEvent(EventType::PUSH_JIPAIQI);
}

void NetDataCommand::getSMessage(NetData netData)
{
	WORD   wchairId = netData.readWORD();
	string sMsg = netData.readString(256);
	//Tools::getInstance()->showSysMsgTouming(sMsg);
}

void NetDataCommand::getSystemMessage(NetData netData)  //1000, 1,     //
{
	WORD   wType = netData.readWORD();
	WORD    wLenth = netData.readWORD();
	if (wLenth > 512)
	{
		return;
	}
	std::string sMsg = netData.readString(wLenth * 2);
	//Tools::getInstance()->showSysMsgTouming(sMsg);
}

//3, 103, game fail
void NetDataCommand::getGameFail(NetData netData)
{
	//unsigned int errorCode = netData.readInt32();

	((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();

	//ͣ�������������������
	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
	}

	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
	}

	//string errMsg = netData.readString(256);
//	logF("getGameFailed 3, 103, id %d", errorCode);

}

//3, 104 �û�����
void NetDataCommand::getMatchUserScore(NetData netData)
{
	CMD_GR_UserScore *data = new CMD_GR_UserScore();
	data->dwUserID = netData.readDWORD();
	data->UserScore.lScore = netData.readUInt64();
	data->UserScore.lGrade = netData.readUInt64();
	data->UserScore.lInsure = netData.readUInt64();
	data->UserScore.dwWinCount = netData.readDWORD();
	data->UserScore.dwLostCount = netData.readDWORD();
	data->UserScore.dwDrawCount = netData.readDWORD();
	data->UserScore.dwFleeCount = netData.readDWORD();
	data->UserScore.dwUserMedal = netData.readDWORD();
	data->UserScore.dwExperience = netData.readDWORD();
	data->UserScore.lLoveLiness = netData.readInt32();
	data->wMatchScore = netData.readWORD();
	blueSkyDispatchEvent(10508, data);   //�����û�����


}

//3   105  ʣ��������Ŀ
void NetDataCommand::getMatchLeftDesk(NetData netData)
{
	WORD* data = new(WORD);
	*data = netData.readWORD();
	blueSkyDispatchEvent(10504, data);
}


//3  106  ���а�
void NetDataCommand::getMatchRank(NetData netData)
{
	CMD_GR_MATCH_RANKING*  data = new CMD_GR_MATCH_RANKING();
	for (int i = 0; i < 20; i++)
	{
		data->rankingInfo[i].dwUserID = netData.readDWORD();


		data->rankingInfo[i].szSendNickName = netData.readString(64);
		data->rankingInfo[i].wMatchScore = netData.readWORD();
		data->rankingInfo[i].wRankingID = netData.readWORD();

		if (data->rankingInfo[i].dwUserID == DATA->myBaseData.dwUserID)
		{
			DATA->wMatchScore = data->rankingInfo[i].wMatchScore;
			
		}
	}

	blueSkyDispatchEvent(10505, data);

}

//7, 409 �����ֳ���
void NetDataCommand::getMatchChangLun(NetData netData)
{
	DATA->wMatchNowLuanci = netData.readWORD();
	DATA->wMatchNowChangci = netData.readWORD();
	DATA->wMatchAllLunci = netData.readWORD();
	DATA->wMatchAllChangci = netData.readWORD();
	DATA->wMatchPlayer = netData.readWORD();   //��ǰ������
	DATA->wMatchNextPlayerCount = netData.readWORD();   //��һ�ֵ�����
}

//7. 410  �������Ƿ���̭
void NetDataCommand::getMatchPass(NetData netData)
{
	netData.readDWORD();
	DATA->bIsJinji = netData.readByte();
	DATA->wCdRank = netData.readWORD();
	if (DATA->bIsJinji == 0)  //��̭
	{
		blueSkyDispatchEvent(10507);
	}
	
}
	
void NetDataCommand::getBestRank(NetData netData)
{
	DATA->wBestRank =  netData.readWORD();
}


/*�����б�*/
void NetDataCommand::getRoomList(NetData netData)
{
	unsigned char num = netData.readByte();
	if (num == 0)
		return;
	int oneListSize = netData.wDataSize / num;
	RoomListModel * roomListModel = ((RoomListModel*)getModel(RoomListModel::NAME));
	roomListModel->num = num;
	for (int i = 0; i < num; i++)
	{
		//int kindID = 
		netData.readWORD();
		int kindID = 2;   //only guandan
		if (kindID == 2)
		{
			RoomList guandanRoom;
			guandanRoom.wKindID = kindID;
			guandanRoom.wwNodeID = netData.readWORD();
			guandanRoom.wwSortID = netData.readWORD();
			guandanRoom.wwServerID = netData.readWORD();
			guandanRoom.wwServerPort = netData.readWORD();
			guandanRoom.wdwOnLineCount = netData.readDWORD();
			guandanRoom.wdwFullCount = netData.readDWORD();
			guandanRoom.wszServerAddr = netData.readString(64);
			guandanRoom.wszServerName = netData.readString(64);
			guandanRoom.dizhu = netData.readInt32();
			guandanRoom.wRoomType = netData.readWORD();

			if (guandanRoom.dizhu == 150)
			{
				roomListModel->realSn[0] = i;
			} 
			else if (guandanRoom.dizhu == 600)
			{
				roomListModel->realSn[1] = i;
			}
			else if (guandanRoom.dizhu == 3000)
			{
				roomListModel->realSn[2] = i;
			}

			roomListModel->roomList.push_back(guandanRoom);
			blueSkyDispatchEvent(EventType::ROOM_LIST_GET);
		}
		else if (kindID == 1)
		{

			//netData.positionMove(oneListSize - 82);
		}
		else if (kindID == 3)
		{
			RoomList fruitRoom;
			fruitRoom.wKindID = kindID;
			fruitRoom.wwNodeID = netData.readWORD();
			fruitRoom.wwSortID = netData.readWORD();
			fruitRoom.wwServerID = netData.readWORD();
			fruitRoom.wwServerPort = netData.readWORD();
			fruitRoom.wdwOnLineCount = netData.readDWORD();
			fruitRoom.wdwFullCount = netData.readDWORD();
			fruitRoom.wszServerAddr = netData.readString(64);
			fruitRoom.wszServerName = netData.readString(64);

			roomListModel->fruitroomList.push_back(fruitRoom);
			//netData.positionMove(oneListSize - 82);
			blueSkyDispatchEvent(EventType::ROOM_LIST_GET);
		}
	}
}

//�����̳���Ʒ
void NetDataCommand::getBuyItemsInfo(NetData netData)
{
	int buyNum = 0;
	//��ȡ��Ϣ
	DWORD dwPropID = netData.readDWORD();
	unsigned short wPropCount = netData.readWORD();
	unsigned short wKindID = netData.readWORD();

	//���뱳��
	bool hasSameItem = false;
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	for (DWORD i = 0; i < pokerGameModel->packageItem.size(); i++)
	{
		if (dwPropID == pokerGameModel->packageItem.at(i).dwPropID)
		{
			buyNum = wPropCount - pokerGameModel->packageItem.at(i).wPropCount;
			pokerGameModel->packageItem.at(i).wPropCount = wPropCount;
			hasSameItem = true;
		}
	}
	if (!hasSameItem)
	{
		int size = pokerGameModel->packageItem.size();
		pokerGameModel->packageItem.resize(size + 1);
		pokerGameModel->packageItem.at(size).dwPropID = dwPropID;
		pokerGameModel->packageItem.at(size).wPropCount = wPropCount;
		pokerGameModel->packageItem.at(size).wKindID = wKindID;
	}

	//��ʾ��õ���
	if (wKindID >= 6)
	{
		MessageVO* data = new  MessageVO();
		data->type = 3;
		char t[12];
		sprintf(t, "%d", wKindID);

		char num[12];
		sprintf(num, " * %d", buyNum);
		std::string propName = UTF8::getInstance()->getString("prop", t);
		data->name = propName + num;
		data->name = propName;
		blueSkyDispatchEvent(11901, data);
	}


}

//���ӽ��
void NetDataCommand::insureSuccess(NetData netData)
{
	
	netData.readDWORD();
	int gold = netData.readUInt64();
	int goldAdd = gold - DATA->myBaseData.lUserScore;
	log("cocos2d-x add gold %d", goldAdd);
	DATA->myBaseData.lUserScore = gold;										//�û����
	DATA->myBaseData.lUserInsure = netData.readUInt64();						//�û�����
	blueSkyDispatchEvent(EventType::INSURESUCCESS);

	//��ʾ���������Ϣ
	if (goldAdd > 0)
	{
		MessageVO* data = new  MessageVO();
		data->type = 2;

		char t[256];
		sprintf(t, "%d", goldAdd);
		string name = t;
		data->name = name;

		blueSkyDispatchEvent(11901, data);
	}
}

/*
	��ʯ�䶯
*/
void NetDataCommand::getZuanShiInfo(NetData netData)
{
	DWORD zuanShiNum = netData.readDWORD();
	int zuanShiAdd = zuanShiNum - DATA->myBaseData.rmb;
	DATA->myBaseData.rmb = zuanShiNum;
	blueSkyDispatchEvent(EventType::INSURESUCCESS);

	//��ʾ��ʯ�䶯��Ϣ
	if (zuanShiAdd > 0)
	{
		MessageVO* data = new  MessageVO();
		data->type = 1;

		char t[256];
		sprintf(t, "%d", zuanShiAdd);         
		string name = t;
		data->name = name;
		blueSkyDispatchEvent(11901, data);
	}
}


//�齱��Ϣ
void NetDataCommand::getGamblingInfo(NetData netData)
{
	CMD_GP_User_Gambling *gamblingReward = new CMD_GP_User_Gambling();
	gamblingReward->dwUserID = netData.readDWORD();
	gamblingReward->Gambling = netData.readWORD();  //����ID
	gamblingReward->GamblingCnt = netData.readWORD();
	gamblingReward->diamondNum = netData.readWORD();

	DATA->chouJiangTime = gamblingReward->GamblingCnt;
	DATA->diamondNum = gamblingReward->diamondNum;  //����ʯ

	blueSkyDispatchEvent(EventType::GET_GAMBLING_REWARD, gamblingReward);

}


//paihang
void NetDataCommand::getRankInfo(NetData netData)
{
	CMD_GP_CupInfo *result = new CMD_GP_CupInfo();
	result->openTime = netData.readDWORD();

	result->dwUserID = netData.readDWORD();
	result->cLevel = netData.readWORD();
	result->cExp = netData.readWORD();
	result->awards = netData.readWORD();
	result->rankingInfo.dwNum = netData.readWORD();

	for (int i = 0; i < result->rankingInfo.dwNum; i ++)
	{
		result->rankingInfo.dwRankingInfos[i].dwUserID = netData.readDWORD();
		result->rankingInfo.dwRankingInfos[i].szNickName = netData.readString(64);
		result->rankingInfo.dwRankingInfos[i].cLevel = netData.readWORD();
		result->rankingInfo.dwRankingInfos[i].cExp = netData.readWORD();
		result->rankingInfo.dwRankingInfos[i].faceId = netData.readWORD();
	}
	blueSkyDispatchEvent(15020, result);   //�ɳ�����
}

void NetDataCommand::getCupAwardInfo(NetData netData)
{
	CMD_GP_CupAwards* awardInfo = new CMD_GP_CupAwards();
	awardInfo->dwUserID = netData.readDWORD();
	awardInfo->flag = netData.readWORD();
	awardInfo->dwIndex = netData.readWORD();
	awardInfo->dwAwards = netData.readWORD();

	blueSkyDispatchEvent(15021, awardInfo);
}

void NetDataCommand::getMatchNumInfo(NetData netData)
{

	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	pokerGameModel->num_info.dwWaitting = netData.readDWORD();
	pokerGameModel->num_info.dwTotal = netData.readDWORD();
	pokerGameModel->num_info.dwMatchTotal = netData.readDWORD();
	blueSkyDispatchEvent(EventType::MATCH_NUM);
}

void NetDataCommand::getMatchStates(NetData netData)
{
	logV("cocos2d-x getMatchStates now!  ");
	BYTE* bStates = new BYTE;
	*bStates = netData.readByte();
	blueSkyDispatchEvent(EventType::MATCH_STATES, bStates);
}



//��������
void NetDataCommand::getMatchJiesuanInfo(NetData netData)
{

}






/*
���״̬
*/


void NetDataCommand::getDeskInfo(NetData netData)
{
	OnDesk *result = new OnDesk();
	result->dwUserID = netData.readDWORD();
	result->wTableID = netData.readWORD();
	result->wChairID = netData.readWORD();
	result->cbUserStatus = netData.readByte();

	//������׼��
	if (result->cbUserStatus == US_SIT || result->cbUserStatus == US_READY ||
		result->cbUserStatus == US_FREE || result->cbUserStatus == US_OFFLINE
		)
	{
		blueSkyDispatchEvent(EventType::ON_DESK, result);
	}

	//����
	if (result->cbUserStatus == 1)
	{
		logP
	}
}

//��ȡ���뷿��������Ϣ
void NetDataCommand::getInDeskPlayerInfo(NetData netData)
{
	OnDeskPlayerInfo *result = new OnDeskPlayerInfo();
	result->dwGameID = netData.readDWORD();
	result->dwUserID = netData.readDWORD();
	result->dwGroupID = netData.readDWORD();
	result->wFaceID = netData.readWORD();
	result->dwCustomID = netData.readDWORD();
	result->cbGender = netData.readByte();
	result->cbMemberOrder = netData.readByte();
	result->cbMasterOrder = netData.readByte();
	result->wTableID = netData.readWORD();
	result->wChairID = netData.readWORD();
	result->cbUserStatus = netData.readByte();
	result->lScore = netData.readUInt64();
	result->lGrade = netData.readUInt64();
	result->lInsure = netData.readUInt64();

	result->dwWinCount = netData.readDWORD();
	result->dwLostCount = netData.readDWORD();
	result->dwDrawCount = netData.readDWORD();
	result->dwFleeCount = netData.readDWORD();
	result->dwUserMedal = netData.readDWORD();
	result->dwExperience = netData.readDWORD();
	result->lLoveLiness = netData.readDWORD();
	result->nick1 = netData.readWORD();
	result->nick2 = netData.readWORD();
	result->szNickName = netData.readString(result->nick1);
	blueSkyDispatchEvent(EventType::OTHER_PLAYER_ON_DESK, result);
}

//��ȡ��������
void NetDataCommand::getSendPokerInfo(NetData netData)
{
	CMD_S_GameStart *result = new CMD_S_GameStart();
	result->wBankerUser = netData.readWORD();
	result->wCurrentUser = netData.readWORD();
	for (int i = 0; i < 27; i++)
	{
		result->cbCardData[i] = netData.readByte();
	}
	result->bOurSeries = netData.readByte();
	result->bOtherSeries = netData.readByte();
	result->bCurrentSeries = netData.readByte();
	for (int i = 0; i < 4; i++)
	{
		result->m_iGameResult[i] = netData.readInt32();
	}
	result->RoomType = netData.readDWORD();
	result->wServerType = netData.readWORD();
	result->bLiangPai = netData.readInt8();
	result->bLiangCard = netData.readWORD();

	DATA->sendPokerData = result;
	//
	blueSkyDispatchEvent(EventType::SEND_POKER, result);
}
//�û�����
void NetDataCommand::getPlayerOutPoker(NetData netData)
{
	PokerGameModel *pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	pokerGameModel->playerOutCard.bCardCount = netData.readByte();//�˿���Ŀ
	netData.readByte();
	pokerGameModel->playerOutCard.wCurrentUser = netData.readWORD();//��ǰ���
	pokerGameModel->playerOutCard.wOutCardUser = netData.readWORD();//�������
	for (int i = 0; i < 27; i++)
	{
		pokerGameModel->playerOutCard.bCardData[i] = 0;//ȫ������
	}
	for (int i = 0; i < pokerGameModel->playerOutCard.bCardCount; i++)
	{
		pokerGameModel->playerOutCard.bCardData[i] = netData.readByte();//�˿��б�
	}
	blueSkyDispatchEvent(EventType::REV_PLAYER_OUT_POKER);
}
//����
void NetDataCommand::notOutPoker(NetData netData)
{
	CMD_S_PassCard *passCard = new CMD_S_PassCard();
	passCard->bNewTurn = netData.readByte();
	netData.readByte();
	passCard->wPassUser = netData.readWORD();
	passCard->wCurrentUser = netData.readWORD();
	blueSkyDispatchEvent(EventType::NOT_OUT_POKER, passCard);
}
//����
void NetDataCommand::getPayTribute(NetData netData)
{
	CMD_S_PayTribute *payTribute = new CMD_S_PayTribute();
	for (int i = 0; i < 4; i++)
	{
		payTribute->bPayType[i] = netData.readByte();
	}
	payTribute->bPayStatus = netData.readDWORD();
	payTribute->wFromUser = netData.readWORD();
	payTribute->wToUser = netData.readWORD();
	payTribute->wCurrentUser = netData.readWORD();
	payTribute->bCard = netData.readByte();
	blueSkyDispatchEvent(EventType::PAY_TRIBUTE, payTribute);
}
//��Ϸ����
void NetDataCommand::gameOver(NetData netData)
{
	CMD_S_GameEnd *gameEnd = new CMD_S_GameEnd();
	gameEnd->lGameTax = netData.readInt32();
	for (int i = 0; i < 4; i++)
	{
		gameEnd->lGameScore[i] = netData.readInt32();
	}
	for (int i = 0; i < 4; i++)
	{
		gameEnd->bCardCount[i] = netData.readByte();
	}
	for (int i = 0; i < 108; i++)
	{
		gameEnd->bCardData[i] = netData.readByte();
	}
	gameEnd->bOurSeries = netData.readByte();
	gameEnd->bOtherSeries = netData.readByte();
	gameEnd->bCurrentSeries = netData.readByte();
	netData.readByte();
	for (int i = 0; i < 4; i++)
	{
		gameEnd->m_iGameResult[i] = netData.readInt32();
	}
	for (int i = 0; i < 4; i++)
	{
		gameEnd->Rank[i] = netData.readInt32();
	}
	gameEnd->bIsBlood = netData.readByte(); //new add

	logV("bisBlood %d", gameEnd->bIsBlood);
	blueSkyDispatchEvent(EventType::GAME_OVER, gameEnd);
}

//����
void NetDataCommand::getChat(NetData netData)
{
	CMD_GR_S_UserExpression *chat = new CMD_GR_S_UserExpression();

	chat->wItemIndex = netData.readWORD();
	chat->dwSendUserID = netData.readInt32();
	chat->dwTargetUserID = netData.readInt32();
	blueSkyDispatchEvent(EventType::CHAT, chat);
}

//ǩ����ѯ
void NetDataCommand::getSignInformation(NetData netData)
{
	DBO_GP_Seven_Logon *sevenLogin = new DBO_GP_Seven_Logon();

	sevenLogin->dwUserID = netData.readInt32();
	sevenLogin->LogonCnt = netData.readWORD();
	blueSkyDispatchEvent(EventType::SEVEN_LOGIN_INFO, sevenLogin);
}

//������Ϣ
void NetDataCommand::getLoginMisInfo(NetData netData)
{
	//
	unsigned char num = netData.readByte();
	if (num == 0)
		return;
	netData.readString(3);
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	pokerGameModel->dailyMisInfo.resize(num);
	for (int i = 0; i < num; i++)
	{
		pokerGameModel->dailyMisInfo.at(i).wKindId = netData.readWORD();
		netData.readString(2);
		pokerGameModel->dailyMisInfo.at(i).dwUserID = netData.readDWORD();

		pokerGameModel->dailyMisInfo.at(i).wMissionId = netData.readWORD();
		netData.readString(2);
		pokerGameModel->dailyMisInfo.at(i).dwValue = netData.readDWORD();
		pokerGameModel->dailyMisInfo.at(i).Complete = netData.readWORD();
		pokerGameModel->dailyMisInfo.at(i).Receive = netData.readWORD();
	}
}

//������Ϣ
void NetDataCommand::getMisInfo(NetData netData)
{
	//
	unsigned char num = netData.readByte();
	if (num == 0)
		return;
	netData.readString(3);
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	pokerGameModel->dailyMisInfo.resize(num);
	for (int i = 0; i < num; i++)
	{
		pokerGameModel->dailyMisInfo.at(i).wKindId = netData.readWORD();
		netData.readString(2);
		pokerGameModel->dailyMisInfo.at(i).dwUserID = netData.readDWORD();

		pokerGameModel->dailyMisInfo.at(i).wMissionId = netData.readWORD();
		netData.readString(2);
		pokerGameModel->dailyMisInfo.at(i).dwValue = netData.readDWORD();

		//netData.readString(1);
		//netData.readString(15);
		pokerGameModel->dailyMisInfo.at(i).Complete = netData.readWORD();
		pokerGameModel->dailyMisInfo.at(i).Receive = netData.readWORD();
	}
}

//�̳���Ϣ
void NetDataCommand::getMallInfo(NetData netData)
{

}

//������
void NetDataCommand::getMisReward(NetData netData)
{
	CMD_GR_GetMissionRewardRec *misReward = new CMD_GR_GetMissionRewardRec();

	misReward->flag = netData.readWORD();
	misReward->wMissionId = netData.readWORD();
	misReward->Score = netData.readWORD();
	misReward->KindID = netData.readWORD();
	misReward->PropCnt = netData.readWORD();

	if (misReward->flag == 1)
	{
	//��ȡ�ɹ�

		DATA->myBaseData.lUserScore = DATA->myBaseData.lUserScore + misReward->Score;

		// ˢ������
		PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
		for (vector<DBR_GR_UserLogonMissionRes>::iterator iter = (pokerGameModel->dailyMisInfo).begin(); \
			iter != (pokerGameModel->dailyMisInfo).end(); iter++)
		{
			if (iter->wMissionId == misReward->wMissionId)
			{
				iter->Receive = 1;
				blueSkyDispatchEvent(11010);
				break;
			}
		}

		//��ʾ���������Ϣ
		if (misReward->Score > 0)
		{
			MessageVO* data = new  MessageVO();
			data->type = 2;

			char t[256];
			sprintf(t, "%d", misReward->Score);
			string name = t;
			data->name = name;

			blueSkyDispatchEvent(11901, data);
			//blueSkyDispatchEvent(EventType::TASK_REWORD);
		}


	}
	else if (misReward->flag == 2)
	{
	//��ȡʧ��
		// ����ʾ

	}
}



//��������
void NetDataCommand::getItemsInfo(NetData netData)
{
	unsigned char num = netData.readByte();
	if (num == 0)
		return;

	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	pokerGameModel->packageItem.resize(num);
	for (int i = 0; i < num; i++)
	{
		pokerGameModel->packageItem.at(i).dwPropID = netData.readDWORD();
		pokerGameModel->packageItem.at(i).wPropCount = netData.readWORD();
		pokerGameModel->packageItem.at(i).wKindID = netData.readWORD();  //��ƷID��6������������
	}
// 	pokerGameModel->packageItem.resize(5);
// 	pokerGameModel->packageItem.at(0).wPropCount = 2;
// 	pokerGameModel->packageItem.at(0).wKindID = 6;
// 	pokerGameModel->packageItem.at(1).wPropCount = 3;
// 	pokerGameModel->packageItem.at(1).wKindID = 7;
// 	pokerGameModel->packageItem.at(2).wPropCount = 5;
// 	pokerGameModel->packageItem.at(2).wKindID = 8;
// 	pokerGameModel->packageItem.at(3).wPropCount = 54;
// 	pokerGameModel->packageItem.at(3).wKindID = 11;
// 	pokerGameModel->packageItem.at(4).wPropCount = 5;
// 	pokerGameModel->packageItem.at(4).wKindID = 6;
}



//���߱��
void NetDataCommand::useItem(NetData netData)
{
	CMD_GR_S_PropertySuccess *useItem = new CMD_GR_S_PropertySuccess();
	useItem->cbRequestArea = netData.readByte();
	useItem->wItemCount = netData.readWORD();
	useItem->wPropertyIndex = netData.readWORD();  //��ƷID  6������������
	useItem->dwSourceUserID = netData.readDWORD();
	useItem->dwTargetUserID = netData.readDWORD();

	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	DWORD num =  pokerGameModel->packageItem.size();
	for (DWORD i = 0; i < num; i++)
	{
		if (pokerGameModel->packageItem.at(i).wKindID == useItem->wPropertyIndex)
		{
			pokerGameModel->packageItem.at(i).wPropCount -= useItem->wItemCount;
			if (pokerGameModel->packageItem.at(i).wPropCount <= 0)
			{
				pokerGameModel->packageItem.erase(pokerGameModel->packageItem.begin() + i);
			}
		}
	}

}

//ʹ�ü�����
void NetDataCommand::useJiPaiQi(NetData netData)
{
	DBR_GR_PropertyConsume *pUseJiPaiQi = new DBR_GR_PropertyConsume();
	pUseJiPaiQi->wPropertyIndex = netData.readWORD();
	pUseJiPaiQi->wKindID = netData.readWORD();
	pUseJiPaiQi->dwUserID = netData.readDWORD();
	pUseJiPaiQi->lScore = netData.readUInt64();
	pUseJiPaiQi->resultID = netData.readWORD();

	blueSkyDispatchEvent(EventType::USE_JI_PAI_QI, pUseJiPaiQi);
}


//6	3 ���غ�����Ϣ
void NetDataCommand::getFriendsInfo(NetData netData)
{
	netData.readDWORD();
	WORD wSize = netData.readWORD();
	if (wSize > 500)
	{
		logV("friends Size is too big, maybe error!");
		return;
	}
	DATA->vFriends.resize(wSize);
	for (int i = 0; i < wSize; i ++)
	{
		DATA->vFriends.at(i).dwUserID = netData.readDWORD();
		DATA->vFriends.at(i).szNickName = netData.readString(64);
		DATA->vFriends.at(i).dwRmb = netData.readDWORD();
		DATA->vFriends.at(i).FaceID = netData.readWORD();
		DATA->vFriends.at(i).wServerID = netData.readWORD();
		DATA->vFriends.at(i).wKindID = netData.readWORD();
		DATA->vFriends.at(i).dwLoveLiness = netData.readDWORD();
		DATA->vFriends.at(i).WinRate = netData.readWORD();
		DATA->vFriends.at(i).bStates = netData.readByte();


	}
	blueSkyDispatchEvent(EventType::FRIEND_LIST);
}

//6	5 me���غ��������Ϣ
void NetDataCommand::getFriedsAddInfoMe(NetData netData)
{
	CMD_GP_C_ADD_Friend* pFriendOpt = new CMD_GP_C_ADD_Friend();

	pFriendOpt->dwUserID = netData.readDWORD();
	pFriendOpt->dwTargretUserID = netData.readDWORD();
	pFriendOpt->wStatue = netData.readWORD();
	pFriendOpt->szNickName = netData.readString(64);
	pFriendOpt->dwRmb = netData.readDWORD();
	pFriendOpt->FaceID = netData.readWORD();
	pFriendOpt->wServerID = netData.readWORD();
	pFriendOpt->wKindID = netData.readWORD();
	pFriendOpt->dwLoveLiness = netData.readDWORD();
	pFriendOpt->WinRate = netData.readWORD();
	pFriendOpt->wRcStates = netData.readWORD();


	switch (pFriendOpt->wRcStates)
	{
	case FriendView::ecAgreeSuccess: //ͬ����ӶԷ�Ϊ����
		tagFriendParameter* addedFriends = new tagFriendParameter();
		addedFriends->dwUserID = pFriendOpt->dwTargretUserID;
		addedFriends->szNickName = pFriendOpt->szNickName;
		addedFriends->FaceID = pFriendOpt->FaceID;
		addedFriends->dwRmb = pFriendOpt->dwRmb;
		addedFriends->wServerID = pFriendOpt->wServerID;
		addedFriends->wKindID = pFriendOpt->wKindID;
		addedFriends->dwLoveLiness = pFriendOpt->dwLoveLiness;
		addedFriends->WinRate = pFriendOpt->WinRate;

		DATA->vFriends.push_back(*addedFriends);
		break;

	}

}

//�� 6 6 him ���غ��������Ϣ
void NetDataCommand::getFriedsAddInfoHim(NetData netData)
{
	CMD_GP_C_ADD_Friend* pFriendOpt = new CMD_GP_C_ADD_Friend();
	pFriendOpt->dwUserID = netData.readDWORD();
	pFriendOpt->dwTargretUserID = netData.readDWORD();
	pFriendOpt->wStatue = netData.readWORD();
	pFriendOpt->szNickName = netData.readString(64);
	pFriendOpt->dwRmb = netData.readDWORD();
	pFriendOpt->FaceID = netData.readWORD();
	pFriendOpt->wServerID = netData.readWORD();
	pFriendOpt->wKindID = netData.readWORD();
	pFriendOpt->dwLoveLiness = netData.readDWORD();
	pFriendOpt->WinRate = netData.readWORD();
	pFriendOpt->wRcStates = netData.readWORD();
	


	std::string strName;
	std::string strAgree;
	tagInviteInfo*  pInvite;
	logV("handleHim States%d ", pFriendOpt->wRcStates);
	
	switch (pFriendOpt->wRcStates)
	{
	case FriendView::ecInviteSuccess:   //�Է�Ҫ����
		pInvite = new tagInviteInfo();
		pInvite->dwUserID = pFriendOpt->dwTargretUserID;
		pInvite->wFaceID = pFriendOpt->FaceID;
		pInvite->szNickName = pFriendOpt->szNickName;
		DATA->vFriendPush.push_back(*pInvite);

		blueSkyDispatchEvent(EventType::FRIEND_OPT_HIM, pFriendOpt);
		break;

	case FriendView::ecAgreeSuccess:   //�Է�ͬ����Ӻ���
	{
		strName = pFriendOpt->szNickName;
		strAgree = UTF8::getInstance()->getString("friend", "agreeAdd");
		strName = strName + strAgree;
		Tools::getInstance()->showSysMsgTouming(strName);
		tagFriendParameter* addedFriends = new tagFriendParameter();
		addedFriends->dwUserID = pFriendOpt->dwTargretUserID;  //�Է�
		addedFriends->szNickName = pFriendOpt->szNickName;
		addedFriends->dwRmb = pFriendOpt->dwRmb;
		addedFriends->FaceID = pFriendOpt->FaceID;
		addedFriends->wServerID = pFriendOpt->wServerID;
		addedFriends->wKindID = pFriendOpt->wKindID;
		addedFriends->dwLoveLiness = pFriendOpt->dwLoveLiness;
		addedFriends->WinRate = pFriendOpt->WinRate;
		DATA->vFriends.push_back(*addedFriends);
		break;
	}

	case FriendView::ecAgreeFail:

		break;
	case FriendView::ecAgreeAlready:

		break;
	case FriendView::ecRefuseSuccess:

		break;
	case FriendView::ecRefuseFail:

		break;
	case FriendView::ecRefuseNot:

		break;
	case FriendView::ecDeleteSuccess:

		break;

	case FriendView::ecDeleteFail:

		break;

	case FriendView::ecDeleteNot:

		break;

	}

}

//6	9	���������б�
void NetDataCommand::getFriendsShuRen(NetData netData)
{
	WORD wSize = netData.readWORD();
	logV("FriendsShuRen Size is %d", wSize);
	if (wSize > 50)
	{
		
		return;
	}
	DATA->vFriendsShuRen.resize(wSize);
	for (int i = 0; i < wSize; i++)
	{
		DATA->vFriendsShuRen.at(i).dwUserID = netData.readDWORD();
		DATA->vFriendsShuRen.at(i).szNickName = netData.readString(64);
		DATA->vFriendsShuRen.at(i).wFaceID = netData.readWORD();

		logV("dwUserId %d", DATA->vFriendsShuRen.at(i).dwUserID);
		logV("Name %s", DATA->vFriendsShuRen.at(i).szNickName.c_str());
		logV("FaceId %d", DATA->vFriendsShuRen.at(i).wFaceID);
	}
	blueSkyDispatchEvent(EventType::FRIEND_SHUREN);
}

//6	11	���ز��ҽ��
void NetDataCommand::getFriendSearch(NetData netData)
{
	CMD_GP_S_SEARCH_USER* pSearch = new CMD_GP_S_SEARCH_USER();
	pSearch->dwUserID = netData.readDWORD();
	pSearch->szNickName = netData.readString(64);
	pSearch->wFaceID = netData.readWORD();

	blueSkyDispatchEvent(EventType::FRIEND_SEARCH, pSearch);
}

//6. 13�� ��������
void NetDataCommand::getFriendPush(NetData netData)
{
	netData.readDWORD();
	WORD wSize = netData.readWORD();
	logV("\n\nFriendPush Size %d",wSize);
	if (wSize > 20)
	{
		
		return;
	}
	DATA->vFriendPush.resize(wSize);
	for (int i = 0; i < wSize; i++)
	{
		DATA->vFriendPush.at(i).dwUserID = netData.readDWORD();
		DATA->vFriendPush.at(i).szNickName = netData.readString(64);
		DATA->vFriendPush.at(i).wFaceID = netData.readWORD();
		logV("dwUserId %d", DATA->vFriendPush.at(i).dwUserID);
		logV("Name %s", DATA->vFriendPush.at(i).szNickName.c_str());
		logV("FaceId %d", DATA->vFriendPush.at(i).wFaceID);
	}
	//blueSkyDispatchEvent(EventType::FRIEND_SHUREN);
}

void NetDataCommand::getFriendFieldInvite(NetData netData)
{
	CMD_SUB_C_INVITE_ENTER_GAME*  friendInvite = new CMD_SUB_C_INVITE_ENTER_GAME();
	friendInvite->dwUserID = netData.readDWORD();
	friendInvite->dwTargetID = netData.readDWORD();
	friendInvite->wGameID = netData.readWORD();
	friendInvite->wTableID = netData.readWORD();
	friendInvite->wChairID = netData.readWORD();
	friendInvite->wIsFriend = netData.readWORD();
	friendInvite->strName = netData.readString(64);
	ViewPopup*  popup = ViewPopup::create(ViewPopup::popupFriendInvite, friendInvite);
	VIEW->mainScene->addChild(popup, 1001);
}

void NetDataCommand::getBroadCastDaoju(NetData netData)
{

}

void NetDataCommand::getTableInfo(NetData netData)
{
	CMD_GR_TableStatus tables;
	tables.wTableID = netData.readWORD();
	tables.cbTableLock = netData.readByte();
	tables.cbPlayStatus = netData.readByte();
	if (tables.cbPlayStatus == 0)
	{
	//	
	}



}
