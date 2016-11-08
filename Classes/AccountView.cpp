#include "AccountView.h"
#include "DataManager.h"
#include "SGTools.h"
#include "SendDataService.h"
#include "TCPSocketService.h"
#include "ConnectGameServiceCommand.h"
#include "LobbyView.h"
#include "LobbyMediator.h"

AccountView::AccountView()
{

}

AccountView::~AccountView()
{
	delete rootNode;
	rootNode = NULL;
}

void AccountView::initView()
{

	if (DATA->bGameCate != DataManager::E_GameCateMatch)
	{
		rootNode = CSLoader::createNode("jieShuan.csb");
		addChild(rootNode);

		UIGet_Button("fanHuiBtn", rootNode, btnBack)
			UIClick(btnBack, AccountView::clickBtnBack)

		UIGet_Button("continueBtn", rootNode, btnContinue)
		UIClick(btnContinue, AccountView::clickBtnContinune)
		if (DATA->bGameCate == DataManager::E_GameBlood)
		{
			if (DATA->GameEndData.bIsBlood)  //Ѫս���
			{
				btnContinue->setVisible(false);
				btnBack->setPositionX(0);
			}
			else
			{
				btnBack->setVisible(false);
				btnContinue->setPositionX(0);
			}
		}
	}

	else if (DATA->bGameCate == DataManager::E_GameCateMatch)  //����
	{
		rootNode = CSLoader::createNode("jieShuan_match.csb");
		addChild(rootNode);

		UIGet_Button("fanHuiBtn", rootNode, btnBack)
			UIClick(btnBack, AccountView::clickBtnBack)

		UIGet_Button("nextMatchBtn", rootNode, btnNextMatch)
			UIClick(btnNextMatch, AccountView::clickBtnNextMatch)
			UIGet_Layout("Panel_win", rootNode, winLayout)
			UIGet_Layout("Panel_fail", rootNode, loseLayout)
			UIGet_Text("Text_matchNum", rootNode, txtPeoples)
			UIGet_Text("Text_matchRank", rootNode, txtRanks)
			UIGet_Text("Text_matchRankBest", rootNode, txtBestRanks)
			UIGet_Text("Text_reward", winLayout, txtRewards)
	}

}

void AccountView::clickBtnBack(Ref* pSender)
{
	//�����뿪������Ϣ
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	int myChair = playerInDeskModel->getServiceChairID(0);
	int myTable = playerInDeskModel->DeskPlayerInfo[myChair].wTableID;
	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable, myChair, true);

	//�ر���Ϸ������SOCKET
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
	blueSkyDispatchEvent(10501);

}

void AccountView::clickBtnContinune(Ref* pSender)
{
	((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr = {};
	((SendDataService *)getService(SendDataService::NAME))->sendReady();
	blueSkyDispatchEvent(EventType::SHOW_PLAYER_ON_DESK);
	//��ת�����ƽ���
	blueSkyDispatchEvent(10501);

}

void AccountView::clickBtnNextMatch(Ref* pSender)
{
	//�����뿪������Ϣ
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	int myChair = playerInDeskModel->getServiceChairID(0);
	int myTable = playerInDeskModel->DeskPlayerInfo[myChair].wTableID;
	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable, myChair, true);

	//�ر���Ϸ������SOCKET
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
	blueSkyDispatchEvent(10501);

}

void AccountView::playAccountAction(bool isSuccess)
{
	failActionNode = rootNode->getChildByName("failActionNode");
	failActionNode->setVisible(false);
	winParticle = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("winParticle"));
	winParticle->setVisible(false);
	glodParticle = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("glodParticle"));
	glodParticle->setVisible(false);
	if (!isSuccess)
	{
		failActionNode->setVisible(true);
		failAction = CSLoader::createTimeline("failAction.csb");
		rootNode->runAction(failAction);
		failAction->gotoFrameAndPlay(0, false);
	}
	else
	{
		winParticle->setVisible(true);
		glodParticle->setVisible(true);
	}
}


void AccountView::showSuccessAction(float dt)
{
	glodParticle->setVisible(true);
}
