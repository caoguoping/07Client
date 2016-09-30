#include "AccountMediator.h"
#include "LobbyView.h"
#include "LobbyMediator.h"
#include "SGTools.h"
#include "TCPSocketService.h"
#include "DataManager.h"
#include "ConnectGameServiceCommand.h"


static DWORD   adwRewards[4] = { 10000, 6000, 2000, 1000 };

AccountMediator::AccountMediator(CMD_S_GameEnd data)
{
	if (DATA->bGameCate == DataManager::E_GameCateNormal)
	{
		//�Ȼ�ȡ��Ҷ�Ӧ�ķ���������ID
		int myChairID, player1ChairID, player2ChairID, player3ChairID = -1;
		PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));

		myChairID = playerInDeskModel->getServiceChairID(0);
		player1ChairID = playerInDeskModel->getServiceChairID(1);
		player2ChairID = playerInDeskModel->getServiceChairID(2);
		player3ChairID = playerInDeskModel->getServiceChairID(3);

		//�Ȼ�ȡ���������Ϣ
		//�ҵ���Ϣ
		myFaceID = playerInDeskModel->DeskPlayerInfo[myChairID].wFaceID;
		myNickName = playerInDeskModel->DeskPlayerInfo[myChairID].szNickName;
		//���1����Ϣ
		playerNick1Name = playerInDeskModel->DeskPlayerInfo[player1ChairID].szNickName;
		player1FaceID = playerInDeskModel->DeskPlayerInfo[player1ChairID].wFaceID;
		//���2����Ϣ
		playerNick2Name = playerInDeskModel->DeskPlayerInfo[player2ChairID].szNickName;
		player2FaceID = playerInDeskModel->DeskPlayerInfo[player2ChairID].wFaceID;
		//���3����Ϣ
		playerNick3Name = playerInDeskModel->DeskPlayerInfo[player3ChairID].szNickName;
		player3FaceID = playerInDeskModel->DeskPlayerInfo[player3ChairID].wFaceID;

		//��ȡ������ҵ�����(0~3)

		if (data.m_iGameResult[0] == 0 && data.m_iGameResult[1] == 0 && data.m_iGameResult[2] == 0 && data.m_iGameResult[3] == 0)
		{
			if (data.lGameScore[player2ChairID] < 0)
			{
				myGrade = 0;
				player2Grade = 0;
			}
			else
			{
				myGrade = 1;
				player2Grade = 1;
			}
		}
		else
		{
			myGrade = data.Rank[myChairID];
			player1Grade = data.Rank[player1ChairID];
			player2Grade = data.Rank[player2ChairID];
			player3Grade = data.Rank[player3ChairID];
		}



		//��ʾ�Լ���ʤ�����
		if (myGrade == 1 || player2Grade == 1)
		{
			isSuccess = true;
			((GameDataModel*)getModel(GameDataModel::NAME))->player[0].isSuccess = true;
		}
		else
		{
			isSuccess = false;
			((GameDataModel*)getModel(GameDataModel::NAME))->player[0].isSuccess = false;
		}

		//��ȡ������ҽ�ұ仯
		char myGold[256];
		sprintf(myGold, "%d", data.lGameScore[myChairID]);
		string m = myGold;
		myGoldChange = m;
		char player1Gold[256];
		sprintf(player1Gold, "%d", data.lGameScore[player1ChairID]);
		string a = player1Gold;
		player1GoldChange = a;
		char player2Gold[256];
		sprintf(player2Gold, "%d", data.lGameScore[player2ChairID]);
		string b = player2Gold;
		player2GoldChange = b;
		char player3Gold[256];
		sprintf(player3Gold, "%d", data.lGameScore[player3ChairID]);
		string c = player3Gold;
		player3GoldChange = c;

		//����ұ仯ͬ���������Ϣ
		;
		DATA->myBaseData.lUserScore += data.lGameScore[myChairID];
		//blueSkyDispatchEvent(EventType::INSURESUCCESS);
	}

}


AccountMediator::AccountMediator()
{

}
AccountMediator::~AccountMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/


void AccountMediator::OnRegister()
{
	accountView = (AccountView*)getView();
	accountView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);

	if (DATA->bGameCate == DataManager::E_GameCateNormal)
	{
		//�ҵ���Ϸ������Ϣ
		successImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage1"));
		successImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage2"));
		failImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage1"));
		failImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage2"));
		myName = dynamic_cast<Text*>(getView()->rootNode->getChildByName("myName"));
		myGold = dynamic_cast<Text*>(getView()->rootNode->getChildByName("myGold"));
		myHead = getView()->rootNode->getChildByName("myHead");
		grade = getView()->rootNode->getChildByName("grade");
		myName->setString(myNickName);
		myGold->setString(myGoldChange);
		showHead(myHead, myFaceID);
		showGrade(myGrade);


		successImage1->setVisible(isSuccess);
		successImage2->setVisible(isSuccess);
		failImage1->setVisible(!isSuccess);
		failImage2->setVisible(!isSuccess);

		//
		playAccountMusic(isSuccess);
		accountView->playAccountAction(isSuccess);

		//���1�Ľ�����Ϣ
		player1Name = dynamic_cast<Text*>(getView()->rootNode->getChildByName("player1Name"));
		player1Gold = dynamic_cast<Text*>(getView()->rootNode->getChildByName("player1Gold"));
		player1Head = getView()->rootNode->getChildByName("player1Head");
		player1Name->setString(playerNick1Name);
		player1Gold->setString(player1GoldChange);
		showHead(player1Head, player1FaceID);

		//���2�Ľ�����Ϣ
		player2Name = dynamic_cast<Text*>(getView()->rootNode->getChildByName("player2Name"));
		player2Gold = dynamic_cast<Text*>(getView()->rootNode->getChildByName("player2Gold"));
		player2Head = getView()->rootNode->getChildByName("player2Head");
		player2Name->setString(playerNick2Name);
		player2Gold->setString(player2GoldChange);
		showHead(player2Head, player2FaceID);

		//���3�Ľ�����Ϣ
		player3Name = dynamic_cast<Text*>(getView()->rootNode->getChildByName("player3Name"));
		player3Gold = dynamic_cast<Text*>(getView()->rootNode->getChildByName("player3Gold"));
		player3Head = getView()->rootNode->getChildByName("player3Head");
		player3Name->setString(playerNick3Name);
		player3Gold->setString(player3GoldChange);
		showHead(player3Head, player3FaceID);

	}
	else if (DATA->bGameCate == DataManager::E_GameCateMatch)  //��������
	{
		//����������Ϣ
		bool isSuccess;
		DWORD dwReword = 0;
		if (DATA->wCdRank > 0 && DATA->wCdRank < 5)  //1��4��
		{
			dwReword = adwRewards[(DATA->wCdRank) - 1];
			isSuccess = true;

		}
		else 
		{
			isSuccess = false;
		}
		successImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage1"));
		successImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage2"));
		failImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage1"));
		failImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage2"));
		successImage1->setVisible(isSuccess);
		successImage2->setVisible(isSuccess);
		failImage1->setVisible(!isSuccess);
		failImage2->setVisible(!isSuccess);
		accountView->winLayout->setVisible(isSuccess);
		accountView->loseLayout->setVisible(!isSuccess);

		accountView->txtRanks->setString(Tools::parseInt2String(DATA->wCdRank));
		accountView->txtBestRanks->setString(Tools::parseInt2String(DATA->wBestRank));

		accountView->txtRewards->setString(Tools::parseInt2String(dwReword));

		playAccountMusic(isSuccess);
		accountView->playAccountAction(isSuccess);
		DATA->wMatchScore = 10;   //��һ������

		//����ұ仯ͬ���������Ϣ
		;
		DATA->myBaseData.lUserScore += dwReword;
	}
}

/**
��������ִ�к���
*/
void AccountMediator::onRemove()
{

}

/*
�¼���Ӧ����
*//*
�¼���Ӧ����
*/
void AccountMediator::onEvent(int i, void* data)
{

	switch (i)
	{
	case 10501:
		clickFanHuiBtnHander();
		break;
	case 10502:
		clickContinueBtnHander();
		break;
	case 10503:
		clickNextMatch();   //������һ��
		break;
	case GAME_OVER:

		break;



	}
}



//�ŵ����ֲ�
Layer* AccountMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->maskLayer;
}

//������ذ�ť
void AccountMediator::clickFanHuiBtnHander()
{

	//�����뿪������Ϣ
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	int myChair = playerInDeskModel->getServiceChairID(0);
	int myTable = playerInDeskModel->DeskPlayerInfo[myChair].wTableID;
	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable, myChair, true);

	//�ر���Ϸ������SOCKET
	LogFile("Account click back closeSocket");
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

	//��ת����������
	blueSkyDispatchEvent(EventType::BACK_TO_HALL);
	creatView(new LobbyView(), new LobbyMediator());

	removeView(this);
}

//���������ť
void AccountMediator::clickContinueBtnHander()
{
	((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr = {};
	((SendDataService *)getService(SendDataService::NAME))->sendReady();
	blueSkyDispatchEvent(EventType::SHOW_PLAYER_ON_DESK);

	//��ת�����ƽ���
	removeView(this);
}

//
void AccountMediator::clickNextMatch()
{
	//�����뿪������Ϣ
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	int myChair = playerInDeskModel->getServiceChairID(0);
	int myTable = playerInDeskModel->DeskPlayerInfo[myChair].wTableID;
	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable, myChair, true);

	//�ر���Ϸ������SOCKET
	LogFile("Account nextMatch closeSocket ");
		((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();  //test
	//ͣ�������������������
	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
	}

	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
	}


	DATA->bGameCate = DataManager::E_GameCateMatch;
	creatView(new MatchView(), new MatchMediator());

	removeView(this);
}

//��ʾ���ͷ��
void AccountMediator::showHead(Node* head, int faceID)
{
	ImageView* image1 = dynamic_cast<ImageView*>(head->getChildByName("character_1"));
	ImageView* image2 = dynamic_cast<ImageView*>(head->getChildByName("character_2"));
	ImageView* image3 = dynamic_cast<ImageView*>(head->getChildByName("character_3"));
	ImageView* image4 = dynamic_cast<ImageView*>(head->getChildByName("character_4"));
	switch (faceID)
	{
	case 1:
		image1->setVisible(true);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 2:
		image1->setVisible(false);
		image2->setVisible(true);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 3:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(true);
		image4->setVisible(false);
		break;
	case 4:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(true);
		break;
	}
}

//��ʾ�������
void AccountMediator::showGrade(int rank)
{
	ImageView* image1 = dynamic_cast<ImageView*>(grade->getChildByName("first"));
	ImageView* image2 = dynamic_cast<ImageView*>(grade->getChildByName("second"));
	ImageView* image3 = dynamic_cast<ImageView*>(grade->getChildByName("third"));
	ImageView* image4 = dynamic_cast<ImageView*>(grade->getChildByName("fourth"));
	switch (myGrade)
	{
	case 0:
	case 4:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(true);
		break;
	case 1:
		image1->setVisible(true);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 2:
		image1->setVisible(false);
		image2->setVisible(true);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 3:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(true);
		image4->setVisible(false);
		break;
	}
}

//���Ž�����Ч
void AccountMediator::playAccountMusic(bool isSuccess)
{
	if (isSuccess)
		blueSkyDispatchEvent(20048);
	else
		blueSkyDispatchEvent(20049);
}

