#include "PlayPokerMediator.h"
#include "LobbyMediator.h"
#include "LobbyView.h"
#include "SGTools.h"
#include "TCPSocketService.h"
#include "DataManager.h"
#include "ViewManager.h"
#include "SGTools.h"
#include "AccountView.h"
#include "AccountMediator.h"
#include "ConnectGameServiceCommand.h"
#include "ViewManager.h"



static string strLvNum[15] = { "0", "0", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

PlayPokerMediator::~PlayPokerMediator()
{
	if (mpViewMatchRanking)
	{
		mpViewMatchRanking->removeAllChildrenWithCleanup(true);
	}
	playPokerView->imgHuaPai->removeFromParentAndCleanup(true);

	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void PlayPokerMediator::OnRegister()
{
	playPokerView = (PlayPokerView*)getView();
	isShowMatchEndLoading = false;
	mpViewMatchRanking = NULL;
	matchEndLoadingNode = NULL;
	matchEndLoadingNode2 = NULL;
	if (DATA->bGameCate == DataManager::E_GameCateMatch)
	{
		mpViewMatchRanking = ViewMatchRanking::create();         //���а�
		VIEW->mainScene->addChild(mpViewMatchRanking, 1000, 1000);
		mpViewMatchRanking->setVisible(false);
	}

	//���ֱ�ӷ�׼����Ϣ
	sendReadyMsg();
	//
	//���ذ�ť
	fanHuiBtn = dynamic_cast<Button*>(getView()->rootNode->getChildByName("fanhui_btn"));

	//���찴ť
	chatBtn = dynamic_cast<Button*>(getView()->rootNode->getChildByName("liaotian_Btn"));

	//���ơ���������ʾ�ڵ�
	actionNode = getView()->rootNode->getChildByName("ProjectNode_1");
	chuPaiBtn = dynamic_cast<Button*>(actionNode->getChildByName("chupai_Btn"));
	tiShiBtn = dynamic_cast<Button*>(actionNode->getChildByName("tishi_Btn"));
	buChuBtn = dynamic_cast<Button*>(actionNode->getChildByName("buchu_Btn"));

	//������������ť
	jingongBtn = dynamic_cast<Button*>(getView()->rootNode->getChildByName("jingongBtn"));
	huangongBtn = dynamic_cast<Button*>(getView()->rootNode->getChildByName("huangongBtn"));
	jingongBtn->setVisible(false);
	huangongBtn->setVisible(false);
	if (*(int *)getNoteData() == 0)
	{
		(dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("bscback_1")))->setVisible(true);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_1")))->setVisible(true);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_2")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_2")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_3")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_3")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_4")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_4")))->setVisible(false);
	}
	else if (*(int *)getNoteData() == 1)
	{
		(dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("bscback_1")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_1")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_2")))->setVisible(true);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_2")))->setVisible(true);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_3")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_3")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_4")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_4")))->setVisible(false);
	}
	else if (*(int *)getNoteData() == 2)
	{
		(dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("bscback_1")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_1")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_2")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_2")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_3")))->setVisible(true);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_3")))->setVisible(true);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_4")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_4")))->setVisible(false);
	}
	else if (*(int *)getNoteData() == 3)
	{
		(dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("bscback_1")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_1")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_2")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_2")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_3")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_3")))->setVisible(false);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscback_4")))->setVisible(true);
		(dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("bscdesk_4")))->setVisible(true);
	}

	actionNode->setVisible(false);
	lookTableBtn = dynamic_cast<Button*>(getView()->rootNode->getChildByName("lookTableBtn"));
	lookTableBtn->addTouchEventListener(lookTableBtn, toucheventselector(PlayPokerMediator::clicklookTableBtn));
	//���ƽڵ�
	auto liPaiNode = getView()->rootNode->getChildByName("ProjectNode_3");
	tongHuaShunBtn = dynamic_cast<Button*>(liPaiNode->getChildByName("tonghuashun_Btn"));
	liChengYiPaiBtn = dynamic_cast<Button*>(liPaiNode->getChildByName("lichengyipai_Btn"));
	chongLiBtn = dynamic_cast<Button*>(liPaiNode->getChildByName("chongxinglipai_Btn"));
	//������ť�ڵ�
	auto topBtnNode = getView()->rootNode->getChildByName("ProjectNode_5");
	markBtn = dynamic_cast<Button*>(topBtnNode->getChildByName("jipaiqi_Btn"));
	autoBtn = dynamic_cast<Button*>(topBtnNode->getChildByName("tuoguan_Btn"));
	clearBtn = dynamic_cast<Button*>(topBtnNode->getChildByName("clear_btn"));

	UIGet_ImageView("Image_jpTip", topBtnNode, imgJPTip)
		UIGet_Text("Text_jpTip", imgJPTip, txtJPTips)


	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	jipaiqiNum = 0;
	for (DWORD i = 0; i < pokerGameModel->packageItem.size(); i++)
	{
		if (8 == pokerGameModel->packageItem.at(i).wKindID)   //jipaiqi
		{
			jipaiqiNum = pokerGameModel->packageItem.at(i).wPropCount;
		}
	}
	txtJPTips->setString(Tools::parseInt2String(jipaiqiNum));


	//�Ʒֽڵ�
	paiFenNode = getView()->rootNode->getChildByName("ProjectNode_4");
	myJiShu1 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("myJiShu1"));
	myJiShu2 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("myJiShu2"));
	otherJiShu1 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("otherJiShu1"));
	otherJiShu2 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("otherJiShu2"));

	UIGet_Text("Text_myLv", getView()->rootNode->getChildByName("ProjectNode_4"), myLv);
	UIGet_Text("Text_otherLv", getView()->rootNode->getChildByName("ProjectNode_4"), otherLv);
		myLv->setString(strLvNum[2]);
	otherLv->setString(strLvNum[2]);

	//����
	buchu1 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu1"));
	buchu2 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu2"));
	buchu3 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu3"));
	buchu4 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu4"));
	buchu1->setVisible(false);
	buchu2->setVisible(false);
	buchu3->setVisible(false);
	buchu4->setVisible(false);

	Node* anjianNode;

	UIGet_Node("ProjectNode_1", getView()->rootNode, anjianNode)
		UIGet_Button("buchu_Btn", anjianNode, buChuBtn)
		UIClick(buChuBtn, PlayPokerMediator::clickBuChuBtnHander)

	//	logV("buchu_btn local zorder %d, globelZorder %d", buChuBtn->getLocalZOrder(), buChuBtn->getGlobalZOrder());
	buChuBtn->setGlobalZOrder(10);



	//׼��
	zhunbei1 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei1"));
	zhunbei2 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei2"));
	zhunbei3 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei3"));
	zhunbei4 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei4"));
	
	zhunbei1->setVisible(true);
	zhunbei2->setVisible(false);
	zhunbei3->setVisible(false);
	zhunbei4->setVisible(false);

	//�й�
	meAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("meAutoImage"));
	leftAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("leftAutoImage"));
	topAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("topAutoImage"));
	rightAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("rightAutoImage"));
	meAutoImage->setVisible(false);
	leftAutoImage->setVisible(false);
	topAutoImage->setVisible(false);
	rightAutoImage->setVisible(false);

//	Text_1 = dynamic_cast<Text*>(getView()->rootNode->getChildByName("Text_1"));



	//��������������
	UIGet_ImageView("Image_rank", getView()->rootNode, imgMatchScore)
		UIGet_Text("txtScore", imgMatchScore, txtScore)
		UIGet_Text("txtRank", imgMatchScore, txtNowRank)
		UIGet_Text("txtAllLeft", imgMatchScore, txtAllLeftPeople)

	if (DataManager::E_GameCateMatch == DATA->bGameCate)
	{
		markBtn->setVisible(false);
		imgJPTip->setVisible(false);
		imgMatchScore->setVisible(true);
		updateMatchScore();


	}
	else if (DataManager::E_GameCateNormal == DATA->bGameCate)
	{
		markBtn->setVisible(true);
		imgJPTip->setVisible(true);
		imgMatchScore->setVisible(false);
	}

	playPokerView->viewInit();

	playPokerView->imgHuaPai->addTouchEventListener(CC_CALLBACK_2(PlayPokerMediator::onTouchesHuapai, this));
}

void PlayPokerMediator::updateMatchScore()
{
	txtAllLeftPeople->setString(Tools::parseInt2String(DATA->wMatchPlayer));
	txtScore->setString(Tools::parseInt2String(DATA->wMatchScore));
	txtNowRank->setString(Tools::parseInt2String(DATA->wCdRank));
}

void PlayPokerMediator::onTouchesHuapai(Ref*  pSender, Widget::TouchEventType type)
{
	ImageView*  imgHP = static_cast<ImageView*>(pSender);
	Vec2 touchPos;
	PokerVO*  poker;
	bool notClickPoker;   //û�л������е�һ����
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
	{
		touchBeginPos = imgHP->getTouchBeganPosition();
		
	}
		break;
	case Widget::TouchEventType::ENDED:
	{
		notClickPoker = true;
		touchPos = imgHP->getTouchEndPosition();
		if (abs(touchPos.x - touchBeginPos.x) < 30 && abs(touchPos.y - touchBeginPos.y) < 30)
		{
			for (int i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
			{
				poker = gameDataModel->player[0].pokerArr.at(i);
				if (poker->rect.containsPoint(touchPos))
				{
					pokeridData *data = new pokeridData();

					data->pokerID = poker->pokerID;
					data->pokerID2 = poker->pokerID2;
					blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
					notClickPoker = false;
				}
			}
			if (notClickPoker == true)
			{
				//��ȡ��֮ǰ���Ƶ�ѡ��״̬
				int ids[30];
				int id2s[30];
				int selectSize = gameDataModel->player[0].selectedPokerArr.size();
				for (int i = 0; i < selectSize; i++)
				{
					ids[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
					id2s[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
				}
				for (int i = 0; i < selectSize; i++)
				{
					pokeridData *data = new pokeridData();
					data->pokerID = ids[i];
					data->pokerID2 = id2s[i];
					blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
				}
			}
		}
	}
		break;
	case Widget::TouchEventType::MOVED:
	{
		 touchPos = imgHP->getTouchMovePosition();

		 if (abs(touchPos.x - touchBeginPos.x) < 10 && abs(touchPos.y - touchBeginPos.y) < 10)
		 {
			 return;
		 }
		for (int i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
		{
			poker = gameDataModel->player[0].pokerArr.at(i);
			if (poker->rect.containsPoint(touchPos))
			{
				pokeridData *data = new pokeridData();

				data->pokerID = poker->pokerID;
				data->pokerID2 = poker->pokerID2;
				blueSkyDispatchEvent(EventType::SELECT_POKER_MOVE, data);
			}
		}
	}
		break;
	default:
		break;
	}
}


/*
��������ִ�к���
*/
void PlayPokerMediator::onRemove()
{
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(lookTableBtn);
}

/*
	����׼����Ϣ
*/
void PlayPokerMediator::sendReadyMsg()
{
	((SendDataService *)getService(SendDataService::NAME))->sendReady();
}


void PlayPokerMediator::showPlayerOnDeskHandle(void* data)
{
	logV("mJoinPlayer %d", mJoinInPlayer);
	if (mJoinInPlayer == 0)
	{
		//ͷ�Σ����Σ���
		playPokerView->touyouNode->setVisible(false);
		for (int i = 0; i < 3; i++)
		{
			if (playPokerView->imgTouyou[i] != NULL)
			{
				playPokerView->imgTouyou[i]->removeFromParentAndCleanup(true);
				playPokerView->imgTouyou[i] = NULL;
			}
		}
	}

	//��ʾ����
	nowBeiLv = 1;
	playPokerView->showBeiLv(nowBeiLv);

	playPokerView->showJiPaiQiBtn(false);
	fanHuiBtn->setVisible(true);
	playPokerView->hideAllFace();
	playPokerView->hideAllName();
	playPokerView->hideAllPokerNum();
	showPlayerOnDesk();
	//ȥ������ʾ
	playPokerView->hideClock();
	//�������֮ǰ�Ĳ�����ʾ
	for (int j = 0; j < 4; j++)
	{
		showBuchu(j, false, true);
	}
	//ȥ�����ư�ť��ʾ
	isOrNotMyTurn(false);

	paiFenNode->setPosition(Vec2(180, 502));

	if (mJoinInPlayer == 3)
	{
		playPokerView->showPiPei(false);
	}
	else
	{
		playPokerView->showPiPei(true);
	}

	mJoinInPlayer++;
}

void PlayPokerMediator::OnDeskHandle(void* data)
{
	OnDesk onDeskResult;
	onDeskResult = *(OnDesk*)data;
	if (onDeskResult.dwUserID != DATA->myBaseData.dwUserID &&
		(onDeskResult.cbUserStatus == US_OFFLINE || onDeskResult.cbUserStatus == US_FREE))
	{
		for (int i = 0; i < 4; i++)
		{
			if (DATAPlayerIndesk->DeskPlayerInfo[i].dwUserID == onDeskResult.dwUserID)
			{
				DATAPlayerIndesk->DeskPlayerInfo[i].isClear = true;
				showPlayerOnDesk();
				break;
			}
		}

	}
}

void PlayPokerMediator::sendPokerkHandle(void* data)
{
	CMD_S_GameStart Data;
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	mJoinInPlayer = 0;  
	playPokerView->sucessesPlayer = 0;
	playPokerView->imgHuaPai->setVisible(true);

	if (DATA->bGameCate == DataManager::E_GameCateMatch)
	{
		logV("  cocos2d-x match send poker now!  ");
		hideMatchRanking();
		hideEndLoading();
		updateMatchScore();
		playPokerView->showLunChang();
		playPokerView->hideAllFace();
		playPokerView->hideAllName();
		playPokerView->hideAllPokerNum();
		for (int i = 0; i < 4; i++)
		{
			playPokerView->showDaiJiFace(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].wFaceID);
			playPokerView->showCharacterName(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].szNickName);
		}
	}
	else
	{
		logV("cocos2d-x send poker now!  ");
		LogFile("\n\n***************  normal  send poker now!  ********\n\n");
	}

	playPokerView->showJiPaiQiBtn(true);
	hasBuyJiPaiQi = false;
	playPokerView->showPiPei(false);
	//������Ч
	blueSkyDispatchEvent(20047);
	//���ƺ�ȡ�����ذ�ť��ʾ
	fanHuiBtn->setVisible(false);
	//������ҵ�������
	gameDataModel->player[0].pokerNum = 27;
	gameDataModel->player[1].pokerNum = 27;
	gameDataModel->player[2].pokerNum = 27;
	gameDataModel->player[3].pokerNum = 27;
	gameDataModel->player[0].isNeedToDelete = false;
	gameDataModel->player[1].isNeedToDelete = false;
	gameDataModel->player[2].isNeedToDelete = false;
	gameDataModel->player[3].isNeedToDelete = false;
	gameDataModel->player[0].quanNum = 0;
	gameDataModel->player[1].quanNum = 0;
	gameDataModel->player[2].quanNum = 0;
	gameDataModel->player[3].quanNum = 0;
	Data = *(CMD_S_GameStart*)(data);
	//ȥ��׼����ʾ
	for (int i = 0; i < 4; i++)
	{
		showZhunBei(i, false);
	}

	//��ʾ���ּ���
	paiFenNode->setPosition(Vec2(81, 502));
	if (Data.bOtherSeries > 14 || Data.bOurSeries > 14)
	{
		return;
	}
	if (playerInDeskModel->getServiceChairID(0) % 2 == 0)
	{
		myLv->setString(strLvNum[Data.bOurSeries]);
		otherLv->setString(strLvNum[Data.bOtherSeries]);
	}
	else
	{
		myLv->setString(strLvNum[Data.bOtherSeries]);
		otherLv->setString(strLvNum[Data.bOurSeries]);
	}

	//��ʾ���ִ�
	if (Data.bCurrentSeries == 2)
	{
		showNowJiShu(true);
	}
	else if (gameDataModel->player[0].isSuccess)
	{
		showNowJiShu(true);
	}
	else
	{
		showNowJiShu(false);
	}

	//�ж��Ƿ����Լ��ȳ���
	if (Data.bCurrentSeries == 2)
		isFirstOutPoker = true;
	else
		isFirstOutPoker = false;
	if (!isFirstOutPoker)
	{
		wCurrentUser = Data.wCurrentUser;
		isOrNotMyTurn(false);
	}
	else if (playerInDeskModel->getServiceChairID(0) == Data.wCurrentUser)
	{
		isOrNotMyTurn(true);
		setBuChuBtnState(false);
		playPokerView->startClock(0);
	}
	else
	{
		isOrNotMyTurn(false);
		playPokerView->startClock(playerInDeskModel->chair[Data.wCurrentUser]);
	}
}


void PlayPokerMediator::reveivePlayerOutPokerHandle(void* data)
{
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	PokerGameModel *pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));

	int desk;
	int nextDesk;
	int face;
	int outPokerNum;
	int pokerNum;
	int outPokerType;
	vector<PokerVO*> outPokerArr;
	
	//ʣ��10����ʱ��ʼ����
	desk = playerInDeskModel->chair[pokerGameModel->playerOutCard.wOutCardUser];
	pokerNum = gameDataModel->player[desk].pokerNum - pokerGameModel->playerOutCard.bCardCount;
	if (pokerNum < 11)
	{
		playPokerView->showPokerNum(desk, pokerNum);
	}
	gameDataModel->player[desk].pokerNum = pokerNum;

	if (pokerNum != 0)
	{
		playPokerView->showChuPaiFace(desk, playerInDeskModel->DeskPlayerInfo[pokerGameModel->playerOutCard.wOutCardUser].wFaceID);
	}
	else
	{
		playPokerView->showSuccessFace(desk, playerInDeskModel->DeskPlayerInfo[pokerGameModel->playerOutCard.wOutCardUser].wFaceID);
		gameDataModel->player[desk].quanNum = 0;
	}

	for (DWORD i = 0; i < gameDataModel->player[desk].outPokerArr.size(); i++)
	{
		outPokerArr.push_back(gameDataModel->player[desk].outPokerArr[i]);
	}
	//��ʾ������Ч
	outPokerType = OutPokerLogicRule::outPokerType(outPokerArr).type;
	outPokerNum = OutPokerLogicRule::outPokerType(outPokerArr).len;
	if (outPokerType == 9)
	{
		blueSkyDispatchEvent(EventType::TONG_HUA_SHUN);
		//��ʾ����
		nowBeiLv *= 2;
		playPokerView->showBeiLv(nowBeiLv);
	}
	if (outPokerType == 10)
	{
		blueSkyDispatchEvent(EventType::HUO_JIAN);
		//��ʾ����
		nowBeiLv *= 2;
		playPokerView->showBeiLv(nowBeiLv);
	}
	if (outPokerType == 7)
	{
		blueSkyDispatchEvent(EventType::FEI_JI);
	}
	if (outPokerType == 8)
	{
		blueSkyDispatchEvent(EventType::BOOM);
		//��ʾ����
		if (outPokerNum > 4)
		{
			nowBeiLv *= 2;
			playPokerView->showBeiLv(nowBeiLv);
		}
	}

	face = playerInDeskModel->DeskPlayerInfo[pokerGameModel->playerOutCard.wOutCardUser].wFaceID;
	playChuPaiMusic(outPokerType, face);

	nextDesk = playerInDeskModel->chair[pokerGameModel->playerOutCard.wCurrentUser];
	showBuchu(nextDesk, false, false);
	if (nextDesk == 0)
	{
		isOrNotMyTurn(true);
		setBuChuBtnState(true);
	}
	else
	{
		isOrNotMyTurn(false);
	}
	playPokerView->startClock(nextDesk);
}

void PlayPokerMediator::notOutPokerHandle(void* data)
{
	bool isNewTurn;
	int desk;
	int nextDesk;
	int face;

	CMD_S_PassCard passData;
	passData = *(CMD_S_PassCard*)data;
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	//���ж����ĸ�����
	desk = playerInDeskModel->chair[passData.wPassUser];
	nextDesk = playerInDeskModel->chair[passData.wCurrentUser];
	isNewTurn = passData.bNewTurn;
	showBuchu(desk, true, true);
	if (nextDesk == 0)
	{
		isOrNotMyTurn(true);
		if (isNewTurn)
		{
			setBuChuBtnState(false);
		}
		else
		{
			setBuChuBtnState(true);
		}
	}
	else
	{
		isOrNotMyTurn(false);
	}
		
	playPokerView->startClock(nextDesk);
	if (isNewTurn)
	{
		//�������֮ǰ�ĳ��Ƶ���ʾ������
		for (int j = 0; j < 4; j++)
		{
			showBuchu(j, false, true);
		}
	}
	face = playerInDeskModel->DeskPlayerInfo[passData.wPassUser].wFaceID;
	playChuPaiMusic(0, face);
}


void PlayPokerMediator::payTributeHandle(void* data)
{
	int mySeviceDeskChairID;
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	CMD_S_PayTribute payTributeData;
	payTributeData = *(CMD_S_PayTribute*)(data);

	//����ʱ���йܰ�ť�û�
	autoBtn->setTouchEnabled(false);
	autoBtn->setColor(Color3B(128, 128, 128));

	//�Լ��Ƿ�Ҫ����
	mySeviceDeskChairID = playerInDeskModel->getServiceChairID(0);
	if (payTributeData.bPayType[mySeviceDeskChairID] == 2 && payTributeData.bPayStatus == 1)
	{
		setJinGongBtnState(true);
	}
	else if (payTributeData.bPayType[mySeviceDeskChairID] != 2 && payTributeData.bPayStatus == 1)
	{
		setJinGongBtnState(false);
	}

	//�Լ��յ�����
	if (payTributeData.bPayStatus == 2 && payTributeData.wToUser == mySeviceDeskChairID)
	{
		if (!hasGetJinGong)
		{
			huiGongID = payTributeData.wFromUser;
			getJingGong(payTributeData.bCard);
			hasGetJinGong = true;
		}
	}
	//�Լ��Ƿ�Ҫ�ع�
	if (payTributeData.bPayType[mySeviceDeskChairID] == 1 && payTributeData.bPayStatus == 2)
	{
		setHuanGongBtnState(true);
	}
	else if (payTributeData.bPayType[mySeviceDeskChairID] != 1 && payTributeData.bPayStatus == 2)
	{
		setHuanGongBtnState(false);
	}

	//�Լ��յ��ع�
	if (payTributeData.bPayStatus == 3 && payTributeData.wToUser == mySeviceDeskChairID)
	{
		if (!hasGetHuanGong)
		{
			getJingGong(payTributeData.bCard);
			hasGetHuanGong = true;
		}
	}

	//�������
	if (payTributeData.bPayStatus == 4)
	{
		blueSkyDispatchEvent(EventType::KANG_GONG);
		if (wCurrentUser == playerInDeskModel->getServiceChairID(0))
		{
			isOrNotMyTurn(true);
			setBuChuBtnState(false);
		}
		else
		{
			isOrNotMyTurn(false);
		}
		playPokerView->startClock(playerInDeskModel->chair[wCurrentUser]);
		hasPlayJinGongAction = false;
		hasPlayHuanGongAction = false;
		hasGetJinGong = false;
		hasGetHuanGong = false;
		autoBtn->setTouchEnabled(true);
		autoBtn->setColor(Color3B(255, 255, 255));
	}

	//�������̽���
	if (payTributeData.bPayStatus == 0 && payTributeData.wCurrentUser != 65535)
	{
		//�ж��Ƿ����Լ��ȳ���(payTributeData.wCurrentUser�ȳ�)
		if (playerInDeskModel->getServiceChairID(0) == payTributeData.wCurrentUser)
		{
			isOrNotMyTurn(true);
			setBuChuBtnState(false);
		}
		else
		{
			isOrNotMyTurn(false);
		}
		playPokerView->startClock(playerInDeskModel->chair[payTributeData.wCurrentUser]);
		hasPlayJinGongAction = false;
		hasPlayHuanGongAction = false;
		hasGetJinGong = false;
		hasGetHuanGong = false;
		autoBtn->setTouchEnabled(true);
		autoBtn->setColor(Color3B(255, 255, 255));
	}
}


void PlayPokerMediator::onEvent(int i, void* data)
{

	DWORD wLeftDesks;
	
	switch (i)
	{
	case EventType::SHOW_PLAYER_ON_DESK:  //���ӽ���һλ���
		showPlayerOnDeskHandle(data);
		break;

		//���״̬�ı�
	case EventType::ON_DESK:
		OnDeskHandle(data);
		break;

	case EventType::SEND_POKER:    //����
		sendPokerkHandle(data);
		break;

		//��ҳ��ƣ��ж��Ƿ��ֵ��Լ�����,�������ҵĲ�����ʾ
	case EventType::REV_PLAYER_OUT_POKER:
		reveivePlayerOutPokerHandle(data);
		break;

		//��Ҳ����ƣ���������ʾ����,ɾ������ҳ������ݺ���ʾ���ж���һ���ֵ�˭���ƣ�������µ�һ�֣���ɾ�����г��Ʋ�����ʾ������
	case EventType::NOT_OUT_POKER:
		notOutPokerHandle(data);
		break;

	//��������ͻع�
	case EventType::PAY_TRIBUTE:
		payTributeHandle(data);
		break;

	case EventType::GAME_OVER:
		clickCancelAutoBtnHander();
		playPokerView->hideClock();
		playPokerView->stopClock();
		playPokerView->imgHuaPai->setVisible(false);
		break;

	case EventType::BACK_TO_HALL:
		DATAPlayerIndesk->clean();
		removeView(this);
		break;

	case EventType::USE_JI_PAI_QI:
		//������Ϣ��ʹ�ü������Ľ�����Ȳ�����ȫ����ʾ
// 		useJiPaiQi = *(DBR_GR_PropertyConsume*)(data);
// 		switch (useJiPaiQi.resultID)
// 		{
// 		//1 ûǮ  2Ǯ���� 3�ɹ�
// // 		case 1:
// // 			break;
// // 		case 2:
// // 			break;
// 		case 3:
// 			hasBuyJiPaiQi = true;
// 			blueSkyDispatchEvent(12201);
// 			break;
// 		}
 		break;


	case EventType::MATCH_STATES:
		onMatchEnd(*((BYTE*)data));
		break;

	case 10504:   //������

		logV("cocos2d-x send DeskInfo!  ");
		wLeftDesks = (*(WORD*)data);
		if (mpViewMatchRanking && txtLeftDesks)
		{
			//mpViewMatchRanking->txtLeftDesk->setString(Tools::parseInt2String(wLeftDesks));
		}
		if (matchEndLoadingNode && txtLeftDesks)
		{
			//txtLeftDesks->setString(Tools::parseInt2String(wLeftDesks));
		}

		break;

	case 10505:   //��������
		if (mpViewMatchRanking)
		{
			mpViewMatchRanking->updateMatchRanking(data);
		}
		
		break;

	case 10506:   //������һ�������ȴ�
		showMatchEndLoading();
		break;

	case 10507:   //������̭, �������ĺ���
		hideMatchRanking();
		DATA->bLastMatch = 0;
		creatView(new AccountView(), new AccountMediator());


	case 10508:  //ˢ���û�����
		if (data)
		{
			DATA->wMatchScore = ((CMD_GR_UserScore*)data)->wMatchScore;
		}
		break;

	case 10509:    //��ʾ���а�
		showMatchRanking();
		break;

	case 10601:
		clickfanHuiBtnHander();
		break;
	case 10602:
		clickChatBtnHander();
		break;
	case 10603:
		clickChuPaiBtnHander();
		break;
	case 10604:
		clickTiShiBtnHander();
		break;
// 	case 10605:
// 		clickBuChuBtnHander();
		break;
	case 10606:
		clickJinGongBtnHander();
		break;
	case 10607:
		clickHuanGongBtnHander();
		break;
	case 10609:
		clickTongHuaShunBtnHander();
		break;
	case 10610:
		clickLiChengYiPaiBtnHander();
		break;
	case 10611:
		clickChongLiBtnHander();
		break;
	case 10612:
		//�����������ť
		clickMarkBtnHander();
		break;
	case 10613:
		clickAutoBtnHander();
		break;
	case 10614:
		clickClearBtnHander();
		break;
	case 11101:
		clickCancelAutoBtnHander();
		break;
	case 10615:
		creatView(new ShopView(1), new ShopMediator());
		break;
	case 10618:
		//creatView(new PlayerInfoView(),new PlayerInfoMediator(0));
		break;
	case 10619:
		creatView(new PlayerInfoView(), new PlayerInfoMediator(1));
		break;
	case 10620:
		creatView(new PlayerInfoView(), new PlayerInfoMediator(2));
		break;
	case 10621:
		creatView(new PlayerInfoView(), new PlayerInfoMediator(3));
		break;
	case 10622:
		isChatOpened = false;
		break;
	case 10623:
		setChuPaiBtnState(true);
		break;
	case 10624:
		setChuPaiBtnState(false);
		break;
	case 10043:
		meTimeUp();
		break;
	case 10044:
		jinGongTimeUp();
		break;
	case 10045:
		huanGongTimeUp();
		break;
	}
}

void PlayPokerMediator::showMatchEndLoading()
{

	if (isShowMatchEndLoading == false)
	{
		matchEndLoadingNode = CSLoader::createNode("matchEndLoading.csb");
		matchEndLoadingNode->setPosition(WScreen* 0.5, HScreen * 0.5);
		getcontainer()->addChild(matchEndLoadingNode);

		matchEndLoading = CSLoader::createTimeline("matchEndLoading.csb");
		getcontainer()->runAction(matchEndLoading);
		matchEndLoading->gotoFrameAndPlay(0, true);
		UIGet_Text("Text_leftDesk", matchEndLoadingNode, txtLeftDesks)
	}
	if (isShowMatchEndLoading == false)
	{
		matchEndLoadingNode2 = CSLoader::createNode("matchEndLoading2.csb");
		matchEndLoadingNode2->setPosition(WScreen* 0.5, HScreen * 0.5);
		getcontainer()->addChild(matchEndLoadingNode2);
		matchEndLoading2 = CSLoader::createTimeline("matchEndLoading2.csb");
		getcontainer()->runAction(matchEndLoading2);
		matchEndLoading2->gotoFrameAndPlay(0, true);
	}

 	isShowMatchEndLoading = true;

}

void PlayPokerMediator::hideEndLoading()
{
	if (isShowMatchEndLoading == true)
	{
		matchEndLoading->pause();
		matchEndLoadingNode->removeFromParentAndCleanup(true);
		matchEndLoadingNode = NULL;
		
		matchEndLoading2->pause();
		matchEndLoadingNode2->removeFromParentAndCleanup(true);
		isShowMatchEndLoading = false;
		matchEndLoadingNode2 = NULL;
	}
}

void PlayPokerMediator::showMatchRanking()
{
	if (mpViewMatchRanking)
	{
		mpViewMatchRanking->setVisible(true);
	}
}

void PlayPokerMediator::hideMatchRanking()
{
	if (mpViewMatchRanking)
	{
		mpViewMatchRanking->setVisible(false);
	}

}

/*
//����״̬
#define MS_NULL						0x00								//û��״̬ ,��������
#define MS_SIGNUP					0x01								//����״̬
// #define MS_MATCHING					0x02								//����״̬
// #define MS_OUT						0x03								//��̭״̬
#define MS_QUIT						0x04							    //����
*/
void PlayPokerMediator::onMatchEnd(BYTE bState)
{
	switch (bState)
	{
	case 0:
		hideMatchRanking();
		hideEndLoading();
		DATA->bMatchOver = GAME_STATE_END;   //��������
		{
			DATA->bLastMatch = 1;
			DATA->bMatchOver = 0;
			creatView(new AccountView(), new AccountMediator(DATA->GameEndData));
		}
		break;
	case 1:
		break;
	case 4:
		break;
	}
}

Layer* PlayPokerMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->mainLayer;
}


void PlayPokerMediator::clickAddWealthBtnHander()
{
	///log("1111");
}


void PlayPokerMediator::clickfanHuiBtnHander()
{
	//�����뿪������Ϣ
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	int myChair = playerInDeskModel->getServiceChairID(0);
	int myTable = playerInDeskModel->DeskPlayerInfo[myChair].wTableID;
	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable,myChair,true);

	//�ر���Ϸ������SOCKET
	LogFile("playPoker click back ");
		TCPSocketService*  tcp_game = ((TCPSocketService*)getService(TCPSocketService::GAME));
	tcp_game->closeMySocket();

	//ͣ�������������������
	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
	}

	if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
	{
		getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
	}

	creatView(new LobbyView(), new LobbyMediator());

	blueSkyDispatchEvent(EventType::BACK_TO_HALL);
	
	playPokerView->imgHuaPai->removeFromParentAndCleanup(true);

}

void PlayPokerMediator::clickChatBtnHander()
{
	if (!isChatOpened)
	{
		creatView(new ChatView(), new ChatMediator());
		isChatOpened = true;
	}
	else
	{
		blueSkyDispatchEvent(11310);
		isChatOpened = false;
	}
}


void PlayPokerMediator::clickChuPaiBtnHander()
{
	//���ж��ܲ��ܳ���
	bool canOutPoker = false;

	GameDataModel *gameDataModel = (GameDataModel*)getModel(GameDataModel::NAME);
	vector<PokerVO*> outPokerArr;
	vector<PokerVO*> selectedPokerArr;
	vector<PokerVO*> pokerArr;
	//
	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
	{
		selectedPokerArr.push_back(gameDataModel->player[0].selectedPokerArr[i]);
	}
	for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
	{
		pokerArr.push_back(gameDataModel->player[0].pokerArr[i]);
	}
	//�ȿ����Ƿ��Ǹ��Ƶ����
	if (gameDataModel->player[1].outPokerArr.size() != 0)
	{
		for (DWORD i = 0; i < gameDataModel->player[1].outPokerArr.size(); i++)
		{
			outPokerArr.push_back(gameDataModel->player[1].outPokerArr[i]);
		}
		if (OutPokerLogicRule::canFollowPoker(outPokerArr, selectedPokerArr))
		{
			canOutPoker = true;
		}
	}
	else if (gameDataModel->player[2].outPokerArr.size() != 0)
	{
		for (DWORD i = 0; i < gameDataModel->player[2].outPokerArr.size(); i++)
		{
			outPokerArr.push_back(gameDataModel->player[2].outPokerArr[i]);
		}
		if (OutPokerLogicRule::canFollowPoker(outPokerArr, selectedPokerArr))
			canOutPoker = true;
	}
	else if (gameDataModel->player[3].outPokerArr.size() != 0)
	{
		for (DWORD i = 0; i < gameDataModel->player[3].outPokerArr.size(); i++)
		{
			outPokerArr.push_back(gameDataModel->player[3].outPokerArr[i]);
		}
		if (OutPokerLogicRule::canFollowPoker(outPokerArr, selectedPokerArr))
			canOutPoker = true;
	}
	//����Ҫ���ƾ��ж��Ƿ��������
	else
	{
		if (OutPokerLogicRule::outPokerType(gameDataModel->player[0].selectedPokerArr).type != 0)
			canOutPoker = true;
	}

	//canOutPoker = true;
	//�ܳ��ƾ������������Ϣ���ƣ�������������ƺͱ��ֳ������ݣ�Ȼ�����·�����������
	if (canOutPoker)
	{
		unsigned char CardData[27];
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			CardData[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		}
		((SendDataService *)getService(SendDataService::NAME))->sendOutPoker(gameDataModel->player[0].selectedPokerArr.size(), CardData);
		//���������Ƴ���������
		gameDataModel->removeMyPokerArr(gameDataModel->player[0].selectedPokerArr);
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::REMOVE_POKER, data);
		}


		gameDataModel->player[0].selectedPokerArr = {};

		//���·�����ҵ���������
		//vector<PokerVO*> pokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr;
		gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);

		//���µ������Ƶ�λ��
		for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::CHANGE_POKER_POSITION, data);
		}

		//���ñ�����ʾ�������
		clickTiShiTimes = 0;

		//���ñ���ͬ��˳��ť�������
		clickTongHuaShunTimes = 0;
	}

}


void PlayPokerMediator::clickJinGongBtnHander()
{

	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	//ȡ����ҵ�ѡ��Ҫ��������
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//ֻ�ܽ���һ��������,���ܽ������
	int size = gameDataModel->player[0].pokerArr.size();
	if (gameDataModel->player[0].selectedPokerArr.size() == 1)
	{
		if (gameDataModel->player[0].selectedPokerArr.at(0)->pokerHuaSe == HongXing 
			&& gameDataModel->player[0].selectedPokerArr.at(0)->pokerNum == ZhuPai)
		{
			return;
		}

		bool canJinGong = true;
		for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
		{
			if (gameDataModel->player[0].pokerArr.at(i)->pokerNum >gameDataModel->player[0].selectedPokerArr.at(0)->pokerNum
				&& (gameDataModel->player[0].pokerArr.at(i)->pokerHuaSe != HongXing || gameDataModel->player[0].pokerArr.at(i)->pokerNum != ZhuPai))
			{
				canJinGong = false;
			}
		}
		if (canJinGong)
		{
			int pokerID = gameDataModel->player[0].selectedPokerArr.at(0)->pokerID;
			((SendDataService *)getService(SendDataService::NAME))->sendPayTribute(1, playerInDeskModel->getServiceChairID(0), 0, pokerID);

			//���������Ƴ���������
			gameDataModel->removeMyPokerArr(gameDataModel->player[0].selectedPokerArr);
			for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
			{
				pokeridData *data = new pokeridData();
				data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
				data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
				blueSkyDispatchEvent(EventType::REMOVE_POKER, data);
			}

			gameDataModel->player[0].selectedPokerArr = {};

			//���·�����ҵ���������

			gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);

			//���µ������Ƶ�λ��
			for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.size(); i++)
			{
				pokeridData *data = new pokeridData();
				data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
				data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
				blueSkyDispatchEvent(EventType::CHANGE_POKER_POSITION, data);
			}
			jingongBtn->setVisible(false);

			//
			PlayPokerView* playPokerView = (PlayPokerView*)getView();
			playPokerView->stopClock();
			playPokerView->hideClock(0);
		}
	}
}


void PlayPokerMediator::clickHuanGongBtnHander()
{

	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	//ȡ����ҵ�ѡ��Ҫ��������
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//����ֻ�ܻ�10���µ�
	if (gameDataModel->player[0].selectedPokerArr.size() == 1 && gameDataModel->player[0].selectedPokerArr.at(0)->pokerNum< J)
	{
		int pokerID = gameDataModel->player[0].selectedPokerArr.at(0)->pokerID;
		((SendDataService *)getService(SendDataService::NAME))->sendPayTribute(2, playerInDeskModel->getServiceChairID(0), huiGongID, pokerID);

		//���������Ƴ���������
		gameDataModel->removeMyPokerArr(gameDataModel->player[0].selectedPokerArr);
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::REMOVE_POKER, data);
		}
	
		gameDataModel->player[0].selectedPokerArr = {};

		//���·�����ҵ���������
		//vector<PokerVO*> pokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr;
		gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);

		//���µ������Ƶ�λ��
		for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::CHANGE_POKER_POSITION, data);
		}
		huangongBtn->setVisible(false);
		//
		PlayPokerView* playPokerView = (PlayPokerView*)getView();
		playPokerView->stopClock();
		playPokerView->hideClock(0);
	}
}


//��߱�����Ҫ���ƣ����ܵ����ʾ��ť��������ÿ���ֵ���ҳ���ʱ�ж�һ�°�ť����ʾ
void PlayPokerMediator::clickTiShiBtnHander()
{

	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//��ȡ��֮ǰ���Ƶ�ѡ��״̬
	int ids[30];
	int id2s[30];
	int selectSize = gameDataModel->player[0].selectedPokerArr.size();
	for (int i = 0; i < selectSize; i++)
	{
		ids[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		id2s[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
	}
	for (int i = 0; i < selectSize; i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ids[i];
		data->pokerID2 = id2s[i];
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}

	vector<PokerVO*> outPokerArr;
	//
	vector<PokerVO*> LaiZiArr = PokerLogic::getMyLaiZiArr(gameDataModel->player[0].pokerArr);


	//���е��ܸ��Ƶ����
	vector<vector<PokerVO*>> allPokerArr;
	
	//�ȿ����Ƿ��Ǹ��Ƶ����
	if (gameDataModel->player[1].outPokerArr.size() != 0)
	{
		for (DWORD i = 0; i < gameDataModel->player[1].outPokerArr.size(); i++)
		{
			outPokerArr.push_back(gameDataModel->player[1].outPokerArr[i]);
		}
		allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
		//allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, {});
		//�Ҳ�����Ӧ�����;���ը��ѹ
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//��ը��ѹ
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, {});
			}
			//ͬ��˳��6�����ϵ�ը��ѹ
			else if (pokerType.type == 9)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, {});
			}
		}
	}
	else if (gameDataModel->player[2].outPokerArr.size() != 0)
	{
		for (DWORD i = 0; i < gameDataModel->player[2].outPokerArr.size(); i++)
		{
			outPokerArr.push_back(gameDataModel->player[2].outPokerArr[i]);
		}
		allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
		//allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, {});
		//�Ҳ�����Ӧ�����;���ը��ѹ
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//��ը��ѹ
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, {});
			}
			//ͬ��˳��6�����ϵ�ը��ѹ
			else if (pokerType.type == 9)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, {});
			}
		}
	}
	else if (gameDataModel->player[3].outPokerArr.size() != 0)
	{
		for (DWORD i = 0; i < gameDataModel->player[3].outPokerArr.size(); i++)
		{
			outPokerArr.push_back(gameDataModel->player[3].outPokerArr[i]);
		}
		allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
		//allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, {});
		//�Ҳ�����Ӧ�����;���ը��ѹ
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//��ը��ѹ
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, {});
			}
			//ͬ��˳��6�����ϵ�ը��ѹ
			else if (pokerType.type == 9)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, {});
			}
		}
	}
	//���Ǹ��Ƶ����
	else
	{
		allPokerArr = {};
		//����һ������
		for (DWORD i = 0; i < gameDataModel->player[0].pokerTypeArr.size(); i++)
		{
			allPokerArr.push_back(gameDataModel->player[0].pokerTypeArr.at(i).pokerArr);
		}

		if (LaiZiArr.size() == 1)
		{
			allPokerArr.push_back({ LaiZiArr.at(0) });
		}
		else if (LaiZiArr.size() == 2)
		{
			allPokerArr.push_back({ LaiZiArr.at(0) , LaiZiArr.at(1) });
		}
	}

	//�����������
	if (allPokerArr.size() == 0)
	{
		//clickBuChuBtnHander(NULL);

		GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
		int ids[30];
		int id2s[30];

		gameDataModel->player[0].selectedPokerArr = {};
		((SendDataService *)getService(SendDataService::NAME))->sendNotOutPoker();
		clickTiShiTimes = 0;
		clickTongHuaShunTimes = 0;
		return;
	}

	//���ʵ��ÿ�ε����ʾʱ��һ���ܸ��Ƶ�����
	int num = clickTiShiTimes % allPokerArr.size();
	vector<PokerVO*> pokerArr = allPokerArr.at(num);
	for (DWORD i = 0; i < pokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = pokerArr.at(i)->pokerID;
		data->pokerID2 = pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	//
	clickTiShiTimes++;
}


void PlayPokerMediator::clickBuChuBtnHander(Ref* psender)
{

	//��ȡ�����Ƶ�ѡ��״̬
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//��ȡ��֮ǰ���Ƶ�ѡ��״̬
	int ids[30];
	int id2s[30];
	int selectSize = gameDataModel->player[0].selectedPokerArr.size();
	for (int i = 0; i < selectSize; i++)
	{
		ids[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		id2s[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
	}
	for (int i = 0; i < selectSize; i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ids[i];
		data->pokerID2 = id2s[i];
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}

	//����ʱ��ձ��ֳ�������
	gameDataModel->player[0].selectedPokerArr = {};

	//�����������Ϣ
	((SendDataService *)getService(SendDataService::NAME))->sendNotOutPoker();

	//���ñ�����ʾ�������
	clickTiShiTimes = 0;

	//���ñ���ͬ��˳��ť�������
	clickTongHuaShunTimes = 0;

}

void PlayPokerMediator::clickTongHuaShunBtnHander()
{

	//��ȡ��֮ǰ���Ƶ�ѡ��״̬
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}

	//�����Ƶ�������ȡ��ͬ��˳
	//Ȼ���¼���pokerMediator, data:�Ƶ�ID
	vector<PokerVO*> LaiZiArr = PokerLogic::getMyLaiZiArr(((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr);
	//vector<PokerTypeVO> myPokerTypeArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerTypeArr;
	vector<vector<PokerVO*>> allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerTypeArr, LaiZiArr);

	//���û��ͬ��˳
	if (allPokerArr.size() == 0)
	{
		//log("û��ͬ��˳ =��=");
		return;
	}

	//���ʵ��ÿ�ε��ʱ��һ��ͬ��˳������
	int num = clickTongHuaShunTimes % allPokerArr.size();
	vector<PokerVO*> pokerArr = allPokerArr.at(num);
	for (DWORD i = 0; i < pokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = pokerArr.at(i)->pokerID;
		data->pokerID2 = pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	clickTongHuaShunTimes++;
}

void PlayPokerMediator::clickLiChengYiPaiBtnHander()
{

	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//���Ƴ����е�������ʾ
	for (DWORD i = 0; i <gameDataModel->player[0].pokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
		data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::REMOVE_POKER_VIEW, data);
	}

	//ȡ�����ѡ��Ҫ���һ�ŵ��ƣ��ı���isChangePosition����
	int nowPos = gameDataModel->gameData.cPositionPokerDuiNum;
	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
	{
		gameDataModel->player[0].selectedPokerArr.at(i)->isChangePosition = nowPos + 1;
	}
	gameDataModel->gameData.cPositionPokerDuiNum = nowPos + 1;



	//����Ϣ��command�������Ƶ�������ʾ
	blueSkyDispatchEvent(EventType::RE_SORT_POKER);
}

void PlayPokerMediator::clickChongLiBtnHander()
{
	//��ȡ�����Ƶ�ѡ��״̬
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr = {};

	//���Ƴ����е�������ʾ
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->pokerID;
		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::REMOVE_POKER_VIEW, data);
	}

	//�ı���������Ƶ�isChangePosition����
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.size(); i++)
	{
		((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->isChangePosition = -1;
	}
	((GameDataModel*)getModel(GameDataModel::NAME))->gameData.cPositionPokerDuiNum = 0;

	//����Ϣ��command�������Ƶ�������ʾ
	blueSkyDispatchEvent(EventType::RE_SORT_POKER);
}

//������ //�����������ť
void PlayPokerMediator::clickMarkBtnHander()
{

	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));

	if (jipaiqiNum > 0)
	{
		;
		unsigned long dwUserID = DATA->myBaseData.dwUserID;
		RoomListModel* roomListModel = ((RoomListModel*)getModel(RoomListModel::NAME));
		unsigned short wKindID = roomListModel->roomList.at(((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->ccNun).wwServerID;

		//ʹ�õ��ǵ�nowIndex����Ʒ
		((SendDataService*)getService(SendDataService::NAME))->sendUseJiPaiQi(8, wKindID, dwUserID, 0, 0);

 		hasBuyJiPaiQi = true;
 		blueSkyDispatchEvent(12201); 
		jipaiqiNum--;
		((PlayPokerView*)getView())->_jipaiqi_Btn->setTouchEnabled(false);
		txtJPTips->setString(Tools::parseInt2String(jipaiqiNum));
		
	}
	else   //û�о͹���
	{
		//creatView(new MallView(), new MallMediator());
		((PlayPokerView*)getView())->_jipaiqi_Btn->setTouchEnabled(false);
	}
}

//�й�
void PlayPokerMediator::clickAutoBtnHander()
{

	isAutoState = true; 
	showAutoImage(0,true);

	if (actionNode->isVisible())
	{
		isOrNotMyTurn(true);
	}

	//
	creatView(new CancelAutoView(),new CancelAutoMediator());
}

//�������ť
void PlayPokerMediator::clickClearBtnHander()
{
	creatView(new DailyMissionView(), new DailyMissionMediator());
}

//ȡ���й�
void PlayPokerMediator::clickCancelAutoBtnHander()
{

	isAutoState = false;
	showAutoImage(0, false);
}

//������水ť
bool PlayPokerMediator::clicklookTableBtn(Touch *touch, Widget::TouchEventType type)
{

	if (type == Widget::TouchEventType::BEGAN)
	{
		//�������Ƶ�͸��Ч��
		int *i = new int(50);
		blueSkyDispatchEvent(EventType::SET_POKER_OPACITY,i);

	//	showMatchEndLoading();

	}
	if (type == Widget::TouchEventType::ENDED)
	{
		int *i = new int(255);
		blueSkyDispatchEvent(EventType::SET_POKER_OPACITY,i);
	//	hideEndLoading();

	}
	return true;
}
void PlayPokerMediator::clicklookTableBtnHander()
{

}

void PlayPokerMediator::setChuPaiBtnState(bool isZhiHui)
{
	if (isZhiHui)
	{
		chuPaiBtn->setColor(Color3B(128, 128, 128));
		chuPaiBtn->setTouchEnabled(false);
		jingongBtn->setColor(Color3B(128, 128, 128));
		jingongBtn->setTouchEnabled(false);
		huangongBtn->setColor(Color3B(128, 128, 128));
		huangongBtn->setTouchEnabled(false);
	}
	else
	{
		chuPaiBtn->setColor(Color3B(255, 255, 255));
		chuPaiBtn->setTouchEnabled(true);
		jingongBtn->setColor(Color3B(255, 255, 255));
		jingongBtn->setTouchEnabled(true);
		huangongBtn->setColor(Color3B(255, 255, 255));
		huangongBtn->setTouchEnabled(true);
	}
}

//�Ƿ���ʾ���ư�ť
void PlayPokerMediator::isOrNotMyTurn(bool value)
{
	actionNode->setVisible(value);

	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

	//
	if (gameDataModel->player[0].selectedPokerArr.size() > 0)
		setChuPaiBtnState(false);
	else
		setChuPaiBtnState(true);

	//��ߴ����Ƿ��Ѿ�������뱾���޹ص����
	if (value)
	{
		//
		for (int i = 0; i < 4; i++)
		{
			if (gameDataModel->player[i].pokerNum == 0)
			{
				gameDataModel->player[i].quanNum++;
			}
			if (gameDataModel->player[i].quanNum == 2)
			{
				gameDataModel->player[i].isNeedToDelete = true;
			}
		}

		
		for (int i = 0; i < 4; i++)
		{
			if (gameDataModel->player[i].isNeedToDelete)
			{
				//��ո���ұ��ֳ������ݺ���ʾ
				for (DWORD j = 0; j < gameDataModel->player[i].outPokerArr.size(); j++)
				{
					pokeridData *data = new pokeridData();
					data->pokerID = gameDataModel->player[i].outPokerArr.at(j)->pokerID;
					data->deskID = i;
					blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data);
				}

				gameDataModel->player[i].outPokerArr = {};
			}
		}
	}

	if (value && isAutoState)
	{
		//����ʾ������ͬ
		clickTiShiBtnHander();

		//���Ҫͨ�����¼����Զ�����
		blueSkyDispatchEvent(10603);
	}
}

//�Ƿ���ʾ��ʾ�������֣�ɾ������ҳ������ݺ���ʾ
void PlayPokerMediator::showBuchu(int deskID, bool show, bool isClearData)
{
	if (isClearData)
	{
		//��ո���ұ��ֳ������ݺ���ʾ
		GameDataModel *gameDataModel = (GameDataModel*)getModel(GameDataModel::NAME);
		//vector<PokerVO*> outPokerArr = (GameDataModel*)getModel(GameDataModel::NAME)->player[deskID].outPokerArr;
		for (DWORD i = 0; i < gameDataModel->player[deskID].outPokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[deskID].outPokerArr.at(i)->pokerID;
			data->deskID = deskID;
			blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data);
		}

		gameDataModel->player[deskID].outPokerArr = {};
	}

	//��ʾ��������
	switch (deskID)
	{
		//�����
		case 0:
			buchu1->setVisible(show);
			break;
		//�ұߵ����
		case 3:
			buchu2->setVisible(show);
			break;
		//��������
		case 2:
			buchu3->setVisible(show);
			break;
		//��ߵ����
		case 1:
			buchu4->setVisible(show);
			break;
	}
}

//��ʾ���������
void PlayPokerMediator::showPlayerOnDesk()
{
	PlayPokerView* playPokerView = (PlayPokerView*)getView();

//	if (DATA->bGameCate != DataManager::E_GameCateMatch)
	{
		playPokerView->hideAllFace();
		playPokerView->hideAllName();
		playPokerView->hideAllPokerNum();
	}

	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));

	for (int i = 0; i < 4; i++)
	{
		if (!playerInDeskModel->DeskPlayerInfo[i].isClear)
		{
			//logV("playerInDeskModel->chair[i]", playerInDeskModel->chair[i]);
			playPokerView->showDaiJiFace(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].wFaceID);
			playPokerView->showCharacterName(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].szNickName);
			if (playerInDeskModel->DeskPlayerInfo[i].cbUserStatus == US_READY ||
				playerInDeskModel->getServiceChairID(0) == i)
			{
				showZhunBei(playerInDeskModel->chair[i], true);

			}
				
			else
			{
				//showZhunBei(playerInDeskModel->chair[i], false);
				showZhunBei(playerInDeskModel->chair[i], true);
			}

		}
		else
			showZhunBei(playerInDeskModel->chair[i], false);
	}
}

//
void PlayPokerMediator::setBuChuBtnState(bool state)
{
	buChuBtn->setVisible(state);
}

//��ʾ׼��
void PlayPokerMediator::showZhunBei(int deskID,bool show)
{
	switch (deskID)
	{
		//�����
	case 0:
		zhunbei1->setVisible(show);
		break;
		//�ұߵ����
	case 3:
		zhunbei2->setVisible(show);
		break;
		//��������
	case 2:
		zhunbei3->setVisible(show);
		break;
		//��ߵ����
	case 1:
		zhunbei4->setVisible(show);
		break;
	}
}

//
void PlayPokerMediator::setJinGongBtnState(bool show)
{
	jingongBtn->setVisible(show);

	//
	if (show)
	{
		//Ĭ��һ�Ž�����
		//��ȡ��֮ǰ���Ƶ�ѡ��״̬
		GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
		}
		//�����ġ��Ҳ��ܹ����
		pokeridData *data = new pokeridData();
		for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
		{
			if (gameDataModel->player[0].pokerArr.at(i)->pokerHuaSe != HongXing
				|| gameDataModel->player[0].pokerArr.at(i)->pokerNum != ZhuPai)
			{
				data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
				data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
				blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
				break;
			}
		}

		PlayPokerView* playPokerView = (PlayPokerView*)getView();
		playPokerView->startClock(0, 2);
	}
}

//
void PlayPokerMediator::setHuanGongBtnState(bool show)
{
	huangongBtn->setVisible(show);
	if (show)
	{
		GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

		//
		if (gameDataModel->player[0].selectedPokerArr.size() == 0)
		{
			huangongBtn->setColor(Color3B(128, 128, 128));
			huangongBtn->setTouchEnabled(false);
		}


		PlayPokerView* playPokerView = (PlayPokerView*)getView();
		playPokerView->startClock(0, 3);
	}
}

//��ȡ���˸��Լ���������
void PlayPokerMediator::getJingGong(int pokerID)
{
	int* data = new int(pokerID);
	blueSkyDispatchEvent(EventType::GET_JING_GONG, data);
}


//�Լ��ĳ���ʱ���ѵ�
void PlayPokerMediator::meTimeUp()
{
	if (buChuBtn->isVisible())
	{
		//ֱ�Ӳ���
		clickBuChuBtnHander(NULL);
		logV("cocos2d-x meTimeUp not out poker");
	}
	else
	{
		//����ʾ������ͬ
		clickTiShiBtnHander();

		//���Ҫͨ�����¼����Զ�����
		blueSkyDispatchEvent(10603);
		logV("cocos2d-x meTimeUp  out poker as tishi");

	}
}

//����ʱ�䵽
void PlayPokerMediator::jinGongTimeUp()
{
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

	//��ȡ��֮ǰ���Ƶ�ѡ��״̬
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	//�����ġ��Ҳ��ܹ����
	pokeridData *data = new pokeridData();
	for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
	{
		if (gameDataModel->player[0].pokerArr.at(i)->pokerHuaSe != HongXing 
			|| gameDataModel->player[0].pokerArr.at(i)->pokerNum != ZhuPai)
		{
			data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
			break;
		}
	}

	blueSkyDispatchEvent(10606);
}

//����ʱ�䵽
void PlayPokerMediator::huanGongTimeUp()
{
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

	//��ȡ��֮ǰ���Ƶ�ѡ��״̬
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	//����С��
	int size = gameDataModel->player[0].pokerArr.size();
	pokeridData *data = new pokeridData();
	data->pokerID = gameDataModel->player[0].pokerArr.at(size - 1)->pokerID;
	data->pokerID2 = gameDataModel->player[0].pokerArr.at(size - 1)->pokerID2;
	blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);

	blueSkyDispatchEvent(10607);
}

//��ʾ�й�ͼ��
void PlayPokerMediator::showAutoImage(int deskID, bool show)
{
	switch (deskID)
	{
		//�����
	case 0:
		meAutoImage->setVisible(show);
		break;
		//�ұߵ����
	case 3:
		rightAutoImage->setVisible(show);
		break;
		//��������
	case 2:
		topAutoImage->setVisible(show);
		break;
		//��ߵ����
	case 1:
		leftAutoImage->setVisible(show);
		break;
	}
}

//���ų�����Ч
void PlayPokerMediator::playChuPaiMusic(int pokerType, int faceID)
{
	switch (faceID)
	{
		//Ů
		case 1:
		case 4:
		{
			//1.���� 2.���� 3.3��  4.3��2 5.˳�� 6.���� 7.�ɻ�  8.ը�� 9.ͬ��˳ 10.���
			switch (pokerType)
			{
				case 0:
					blueSkyDispatchEvent(20004);
					break;
				case 1:
					blueSkyDispatchEvent(20012);
					break;
				case 2:
					blueSkyDispatchEvent(20014);
					break;
				case 3:
					blueSkyDispatchEvent(20020);
					break;
				case 4:
					blueSkyDispatchEvent(20018);
					break;
				case 5:
					break;
				case 6:
					blueSkyDispatchEvent(20016);
					break;
				case 7:
					blueSkyDispatchEvent(20022);
				case 8:
					blueSkyDispatchEvent(20006);
					break;
				case 9:
					blueSkyDispatchEvent(20008);
					break;
				case 10:
					blueSkyDispatchEvent(20010);
					break;
			}
		}
		break;
		//��
		case 2:
		case 3:
		{
			//1.���� 2.���� 3.3��  4.3��2 5.˳�� 6.���� 7.�ɻ�  8.ը�� 9.ͬ��˳ 10.���
			switch (pokerType)
			{
			case 0:
				blueSkyDispatchEvent(20003);
				break;
			case 1:
				blueSkyDispatchEvent(20011);
				break;
			case 2:
				blueSkyDispatchEvent(20013);
				break;
			case 3:
				blueSkyDispatchEvent(20019);
				break;
			case 4:
				blueSkyDispatchEvent(20017);
				break;
			case 5:
				break;
			case 6:
				blueSkyDispatchEvent(20015);
				break;
			case 7:
				blueSkyDispatchEvent(20021);
			case 8:
				blueSkyDispatchEvent(20005);
				break;
			case 9:
				blueSkyDispatchEvent(20007);
				break;
			case 10:
				blueSkyDispatchEvent(20009);
				break;
			}
		}
		break;
	}
}

//��ʾ����˭��
void PlayPokerMediator::showNowJiShu(bool isMyJiShu)
{
	if (isMyJiShu)
	{
		myJiShu1->setVisible(true);
		myJiShu2->setVisible(false);
		otherJiShu1->setVisible(false);
		otherJiShu2->setVisible(true);
	}
	else
	{
		myJiShu1->setVisible(false);
		myJiShu2->setVisible(true);
		otherJiShu1->setVisible(true);
		otherJiShu2->setVisible(false);
	}
}
