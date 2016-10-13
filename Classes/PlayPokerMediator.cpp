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
开始执行函数
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
		mpViewMatchRanking = ViewMatchRanking::create();         //排行榜
		VIEW->mainScene->addChild(mpViewMatchRanking, 1000, 1000);
		mpViewMatchRanking->setVisible(false);
	}

	//这边直接发准备消息
	sendReadyMsg();
	//
	//返回按钮
	fanHuiBtn = dynamic_cast<Button*>(getView()->rootNode->getChildByName("fanhui_btn"));

	//聊天按钮
	chatBtn = dynamic_cast<Button*>(getView()->rootNode->getChildByName("liaotian_Btn"));

	//出牌、不出、提示节点
	actionNode = getView()->rootNode->getChildByName("ProjectNode_1");
	chuPaiBtn = dynamic_cast<Button*>(actionNode->getChildByName("chupai_Btn"));
	tiShiBtn = dynamic_cast<Button*>(actionNode->getChildByName("tishi_Btn"));
	buChuBtn = dynamic_cast<Button*>(actionNode->getChildByName("buchu_Btn"));

	//进贡、还贡按钮
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
	//理牌节点
	auto liPaiNode = getView()->rootNode->getChildByName("ProjectNode_3");
	tongHuaShunBtn = dynamic_cast<Button*>(liPaiNode->getChildByName("tonghuashun_Btn"));
	liChengYiPaiBtn = dynamic_cast<Button*>(liPaiNode->getChildByName("lichengyipai_Btn"));
	chongLiBtn = dynamic_cast<Button*>(liPaiNode->getChildByName("chongxinglipai_Btn"));
	//顶部按钮节点
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


	//牌分节点
	paiFenNode = getView()->rootNode->getChildByName("ProjectNode_4");
	myJiShu1 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("myJiShu1"));
	myJiShu2 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("myJiShu2"));
	otherJiShu1 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("otherJiShu1"));
	otherJiShu2 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("otherJiShu2"));

	UIGet_Text("Text_myLv", getView()->rootNode->getChildByName("ProjectNode_4"), myLv);
	UIGet_Text("Text_otherLv", getView()->rootNode->getChildByName("ProjectNode_4"), otherLv);
		myLv->setString(strLvNum[2]);
	otherLv->setString(strLvNum[2]);

	//不出
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



	//准备
	zhunbei1 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei1"));
	zhunbei2 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei2"));
	zhunbei3 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei3"));
	zhunbei4 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei4"));
	
	zhunbei1->setVisible(true);
	zhunbei2->setVisible(false);
	zhunbei3->setVisible(false);
	zhunbei4->setVisible(false);

	//托管
	meAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("meAutoImage"));
	leftAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("leftAutoImage"));
	topAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("topAutoImage"));
	rightAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("rightAutoImage"));
	meAutoImage->setVisible(false);
	leftAutoImage->setVisible(false);
	topAutoImage->setVisible(false);
	rightAutoImage->setVisible(false);

//	Text_1 = dynamic_cast<Text*>(getView()->rootNode->getChildByName("Text_1"));



	//比赛场积分排名
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
	bool notClickPoker;   //没有击中其中的一张牌
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
				//先取消之前手牌的选中状态
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
结束回收执行函数
*/
void PlayPokerMediator::onRemove()
{
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(lookTableBtn);
}

/*
	发送准备消息
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
		//头游，二游，三
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

	//显示倍率
	nowBeiLv = 1;
	playPokerView->showBeiLv(nowBeiLv);

	playPokerView->showJiPaiQiBtn(false);
	fanHuiBtn->setVisible(true);
	playPokerView->hideAllFace();
	playPokerView->hideAllName();
	playPokerView->hideAllPokerNum();
	showPlayerOnDesk();
	//去除钟显示
	playPokerView->hideClock();
	//清除所有之前的不出显示
	for (int j = 0; j < 4; j++)
	{
		showBuchu(j, false, true);
	}
	//去除出牌按钮显示
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
	//发牌音效
	blueSkyDispatchEvent(20047);
	//发牌后取消返回按钮显示
	fanHuiBtn->setVisible(false);
	//设置玩家的手牌数
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
	//去除准备显示
	for (int i = 0; i < 4; i++)
	{
		showZhunBei(i, false);
	}

	//显示本轮级数
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

	//显示本轮打几
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

	//判断是否是自己先出牌
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
	
	//剩余10张牌时开始报牌
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
	//显示出牌特效
	outPokerType = OutPokerLogicRule::outPokerType(outPokerArr).type;
	outPokerNum = OutPokerLogicRule::outPokerType(outPokerArr).len;
	if (outPokerType == 9)
	{
		blueSkyDispatchEvent(EventType::TONG_HUA_SHUN);
		//显示倍率
		nowBeiLv *= 2;
		playPokerView->showBeiLv(nowBeiLv);
	}
	if (outPokerType == 10)
	{
		blueSkyDispatchEvent(EventType::HUO_JIAN);
		//显示倍率
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
		//显示倍率
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
	//先判断是哪个不出
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
		//清除所有之前的出牌的显示和数据
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

	//贡牌时将托管按钮置灰
	autoBtn->setTouchEnabled(false);
	autoBtn->setColor(Color3B(128, 128, 128));

	//自己是否要进贡
	mySeviceDeskChairID = playerInDeskModel->getServiceChairID(0);
	if (payTributeData.bPayType[mySeviceDeskChairID] == 2 && payTributeData.bPayStatus == 1)
	{
		setJinGongBtnState(true);
	}
	else if (payTributeData.bPayType[mySeviceDeskChairID] != 2 && payTributeData.bPayStatus == 1)
	{
		setJinGongBtnState(false);
	}

	//自己收到进贡
	if (payTributeData.bPayStatus == 2 && payTributeData.wToUser == mySeviceDeskChairID)
	{
		if (!hasGetJinGong)
		{
			huiGongID = payTributeData.wFromUser;
			getJingGong(payTributeData.bCard);
			hasGetJinGong = true;
		}
	}
	//自己是否要回贡
	if (payTributeData.bPayType[mySeviceDeskChairID] == 1 && payTributeData.bPayStatus == 2)
	{
		setHuanGongBtnState(true);
	}
	else if (payTributeData.bPayType[mySeviceDeskChairID] != 1 && payTributeData.bPayStatus == 2)
	{
		setHuanGongBtnState(false);
	}

	//自己收到回贡
	if (payTributeData.bPayStatus == 3 && payTributeData.wToUser == mySeviceDeskChairID)
	{
		if (!hasGetHuanGong)
		{
			getJingGong(payTributeData.bCard);
			hasGetHuanGong = true;
		}
	}

	//抗贡情况
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

	//贡牌流程结束
	if (payTributeData.bPayStatus == 0 && payTributeData.wCurrentUser != 65535)
	{
		//判断是否是自己先出牌(payTributeData.wCurrentUser先出)
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
	case EventType::SHOW_PLAYER_ON_DESK:  //桌子进来一位玩家
		showPlayerOnDeskHandle(data);
		break;

		//玩家状态改变
	case EventType::ON_DESK:
		OnDeskHandle(data);
		break;

	case EventType::SEND_POKER:    //发牌
		sendPokerkHandle(data);
		break;

		//玩家出牌，判断是否轮到自己出牌,清除该玩家的不出显示
	case EventType::REV_PLAYER_OUT_POKER:
		reveivePlayerOutPokerHandle(data);
		break;

		//玩家不出牌，界面上显示不出,删除该玩家出牌数据和显示，判断下一个轮到谁出牌，如果到新的一轮，则删除所有出牌不出显示和数据
	case EventType::NOT_OUT_POKER:
		notOutPokerHandle(data);
		break;

	//处理进贡和回贡
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
		//网络消息，使用记牌器的结果，先不处理，全部显示
// 		useJiPaiQi = *(DBR_GR_PropertyConsume*)(data);
// 		switch (useJiPaiQi.resultID)
// 		{
// 		//1 没钱  2钱不够 3成功
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

	case 10504:   //桌子数

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

	case 10505:   //排名更新
		if (mpViewMatchRanking)
		{
			mpViewMatchRanking->updateMatchRanking(data);
		}
		
		break;

	case 10506:   //比赛第一场结束等待
		showMatchEndLoading();
		break;

	case 10507:   //比赛淘汰, 在排名的后面
		hideMatchRanking();
		DATA->bLastMatch = 0;
		creatView(new AccountView(), new AccountMediator());


	case 10508:  //刷新用户分数
		if (data)
		{
			DATA->wMatchScore = ((CMD_GR_UserScore*)data)->wMatchScore;
		}
		break;

	case 10509:    //显示排行榜
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
		//点击记牌器按钮
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
//比赛状态
#define MS_NULL						0x00								//没有状态 ,比赛结束
#define MS_SIGNUP					0x01								//报名状态
// #define MS_MATCHING					0x02								//比赛状态
// #define MS_OUT						0x03								//淘汰状态
#define MS_QUIT						0x04							    //退赛
*/
void PlayPokerMediator::onMatchEnd(BYTE bState)
{
	switch (bState)
	{
	case 0:
		hideMatchRanking();
		hideEndLoading();
		DATA->bMatchOver = GAME_STATE_END;   //比赛结束
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
	//发送离开桌子消息
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	int myChair = playerInDeskModel->getServiceChairID(0);
	int myTable = playerInDeskModel->DeskPlayerInfo[myChair].wTableID;
	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable,myChair,true);

	//关闭游戏服务器SOCKET
	LogFile("playPoker click back ");
		TCPSocketService*  tcp_game = ((TCPSocketService*)getService(TCPSocketService::GAME));
	tcp_game->closeMySocket();

	//停掉网络主动监测与心跳
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
	//先判断能不能出牌
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
	//先考虑是否是跟牌的情况
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
	//不需要跟牌就判断是否符合牌型
	else
	{
		if (OutPokerLogicRule::outPokerType(gameDataModel->player[0].selectedPokerArr).type != 0)
			canOutPoker = true;
	}

	//canOutPoker = true;
	//能出牌就向服务器发消息出牌，并更新玩家手牌和本轮出牌数据，然后重新分析手牌类型
	if (canOutPoker)
	{
		unsigned char CardData[27];
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			CardData[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		}
		((SendDataService *)getService(SendDataService::NAME))->sendOutPoker(gameDataModel->player[0].selectedPokerArr.size(), CardData);
		//在手牌中移除出掉的牌
		gameDataModel->removeMyPokerArr(gameDataModel->player[0].selectedPokerArr);
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::REMOVE_POKER, data);
		}


		gameDataModel->player[0].selectedPokerArr = {};

		//重新分析玩家的手牌类型
		//vector<PokerVO*> pokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr;
		gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);

		//重新调整手牌的位置
		for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::CHANGE_POKER_POSITION, data);
		}

		//重置本轮提示点击次数
		clickTiShiTimes = 0;

		//重置本轮同花顺按钮点击次数
		clickTongHuaShunTimes = 0;
	}

}


void PlayPokerMediator::clickJinGongBtnHander()
{

	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	//取出玩家的选的要进贡的牌
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//只能进贡一张最大的牌,不能进贡癞子
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

			//在手牌中移除出掉的牌
			gameDataModel->removeMyPokerArr(gameDataModel->player[0].selectedPokerArr);
			for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
			{
				pokeridData *data = new pokeridData();
				data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
				data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
				blueSkyDispatchEvent(EventType::REMOVE_POKER, data);
			}

			gameDataModel->player[0].selectedPokerArr = {};

			//重新分析玩家的手牌类型

			gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);

			//重新调整手牌的位置
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
	//取出玩家的选的要还贡的牌
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//还贡只能还10以下的
	if (gameDataModel->player[0].selectedPokerArr.size() == 1 && gameDataModel->player[0].selectedPokerArr.at(0)->pokerNum< J)
	{
		int pokerID = gameDataModel->player[0].selectedPokerArr.at(0)->pokerID;
		((SendDataService *)getService(SendDataService::NAME))->sendPayTribute(2, playerInDeskModel->getServiceChairID(0), huiGongID, pokerID);

		//在手牌中移除出掉的牌
		gameDataModel->removeMyPokerArr(gameDataModel->player[0].selectedPokerArr);
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::REMOVE_POKER, data);
		}
	
		gameDataModel->player[0].selectedPokerArr = {};

		//重新分析玩家的手牌类型
		//vector<PokerVO*> pokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr;
		gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);

		//重新调整手牌的位置
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


//这边必须是要跟牌，才能点击提示按钮，可以在每次轮到玩家出牌时判断一下按钮的显示
void PlayPokerMediator::clickTiShiBtnHander()
{

	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//先取消之前手牌的选中状态
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


	//所有的能跟牌的组合
	vector<vector<PokerVO*>> allPokerArr;
	
	//先考虑是否是跟牌的情况
	if (gameDataModel->player[1].outPokerArr.size() != 0)
	{
		for (DWORD i = 0; i < gameDataModel->player[1].outPokerArr.size(); i++)
		{
			outPokerArr.push_back(gameDataModel->player[1].outPokerArr[i]);
		}
		allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
		//allPokerArr = OutPokerLogicRule::FollowPoker(outPokerArr, gameDataModel->player[0].pokerTypeArr, {});
		//找不到对应的牌型就用炸弹压
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//用炸弹压
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, {});
			}
			//同花顺用6张以上的炸弹压
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
		//找不到对应的牌型就用炸弹压
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//用炸弹压
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, {});
			}
			//同花顺用6张以上的炸弹压
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
		//找不到对应的牌型就用炸弹压
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//用炸弹压
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, {});
			}
			//同花顺用6张以上的炸弹压
			else if (pokerType.type == 9)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				//allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, {});
			}
		}
	}
	//不是跟牌的情况
	else
	{
		allPokerArr = {};
		//随便出一种牌型
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

	//如果跟不上牌
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

	//这边实现每次点击提示时换一种能跟牌的牌组
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

	//先取消手牌的选中状态
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//先取消之前手牌的选中状态
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

	//不出时清空本轮出牌数据
	gameDataModel->player[0].selectedPokerArr = {};

	//向服务器发消息
	((SendDataService *)getService(SendDataService::NAME))->sendNotOutPoker();

	//重置本轮提示点击次数
	clickTiShiTimes = 0;

	//重置本轮同花顺按钮点击次数
	clickTongHuaShunTimes = 0;

}

void PlayPokerMediator::clickTongHuaShunBtnHander()
{

	//先取消之前手牌的选中状态
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}

	//在手牌的牌型中取出同花顺
	//然后发事件给pokerMediator, data:牌的ID
	vector<PokerVO*> LaiZiArr = PokerLogic::getMyLaiZiArr(((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr);
	//vector<PokerTypeVO> myPokerTypeArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerTypeArr;
	vector<vector<PokerVO*>> allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerTypeArr, LaiZiArr);

	//如果没有同花顺
	if (allPokerArr.size() == 0)
	{
		//log("没有同花顺 =。=");
		return;
	}

	//这边实现每次点击时换一种同花顺的牌组
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
	//先移除所有的手牌显示
	for (DWORD i = 0; i <gameDataModel->player[0].pokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
		data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::REMOVE_POKER_VIEW, data);
	}

	//取出玩家选的要理成一排的牌，改变其isChangePosition属性
	int nowPos = gameDataModel->gameData.cPositionPokerDuiNum;
	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
	{
		gameDataModel->player[0].selectedPokerArr.at(i)->isChangePosition = nowPos + 1;
	}
	gameDataModel->gameData.cPositionPokerDuiNum = nowPos + 1;



	//发消息到command，处理牌的排序显示
	blueSkyDispatchEvent(EventType::RE_SORT_POKER);
}

void PlayPokerMediator::clickChongLiBtnHander()
{
	//先取消手牌的选中状态
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr = {};

	//先移除所有的手牌显示
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->pokerID;
		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::REMOVE_POKER_VIEW, data);
	}

	//改变玩家所有牌的isChangePosition属性
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.size(); i++)
	{
		((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->isChangePosition = -1;
	}
	((GameDataModel*)getModel(GameDataModel::NAME))->gameData.cPositionPokerDuiNum = 0;

	//发消息到command，处理牌的排序显示
	blueSkyDispatchEvent(EventType::RE_SORT_POKER);
}

//记牌器 //点击记牌器按钮
void PlayPokerMediator::clickMarkBtnHander()
{

	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));

	if (jipaiqiNum > 0)
	{
		;
		unsigned long dwUserID = DATA->myBaseData.dwUserID;
		RoomListModel* roomListModel = ((RoomListModel*)getModel(RoomListModel::NAME));
		unsigned short wKindID = roomListModel->roomList.at(((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->ccNun).wwServerID;

		//使用的是第nowIndex个物品
		((SendDataService*)getService(SendDataService::NAME))->sendUseJiPaiQi(8, wKindID, dwUserID, 0, 0);

 		hasBuyJiPaiQi = true;
 		blueSkyDispatchEvent(12201); 
		jipaiqiNum--;
		((PlayPokerView*)getView())->_jipaiqi_Btn->setTouchEnabled(false);
		txtJPTips->setString(Tools::parseInt2String(jipaiqiNum));
		
	}
	else   //没有就购买
	{
		//creatView(new MallView(), new MallMediator());
		((PlayPokerView*)getView())->_jipaiqi_Btn->setTouchEnabled(false);
	}
}

//托管
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

//点击任务按钮
void PlayPokerMediator::clickClearBtnHander()
{
	creatView(new DailyMissionView(), new DailyMissionMediator());
}

//取消托管
void PlayPokerMediator::clickCancelAutoBtnHander()
{

	isAutoState = false;
	showAutoImage(0, false);
}

//点击桌面按钮
bool PlayPokerMediator::clicklookTableBtn(Touch *touch, Widget::TouchEventType type)
{

	if (type == Widget::TouchEventType::BEGAN)
	{
		//设置手牌的透明效果
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

//是否显示出牌按钮
void PlayPokerMediator::isOrNotMyTurn(bool value)
{
	actionNode->setVisible(value);

	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

	//
	if (gameDataModel->player[0].selectedPokerArr.size() > 0)
		setChuPaiBtnState(false);
	else
		setChuPaiBtnState(true);

	//这边处理是否已经有玩家与本局无关的情况
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
				//清空该玩家本轮出牌数据和显示
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
		//和提示功能相同
		clickTiShiBtnHander();

		//这边要通过抛事件来自动出牌
		blueSkyDispatchEvent(10603);
	}
}

//是否显示显示不出文字，删除该玩家出牌数据和显示
void PlayPokerMediator::showBuchu(int deskID, bool show, bool isClearData)
{
	if (isClearData)
	{
		//清空该玩家本轮出牌数据和显示
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

	//显示不出文字
	switch (deskID)
	{
		//本玩家
		case 0:
			buchu1->setVisible(show);
			break;
		//右边的玩家
		case 3:
			buchu2->setVisible(show);
			break;
		//对面的玩家
		case 2:
			buchu3->setVisible(show);
			break;
		//左边的玩家
		case 1:
			buchu4->setVisible(show);
			break;
	}
}

//显示上座的玩家
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

//显示准备
void PlayPokerMediator::showZhunBei(int deskID,bool show)
{
	switch (deskID)
	{
		//本玩家
	case 0:
		zhunbei1->setVisible(show);
		break;
		//右边的玩家
	case 3:
		zhunbei2->setVisible(show);
		break;
		//对面的玩家
	case 2:
		zhunbei3->setVisible(show);
		break;
		//左边的玩家
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
		//默认一张进贡牌
		//先取消之前手牌的选中状态
		GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
		}
		//贡最大的。且不能贡癞子
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

//获取别人给自己进贡的牌
void PlayPokerMediator::getJingGong(int pokerID)
{
	int* data = new int(pokerID);
	blueSkyDispatchEvent(EventType::GET_JING_GONG, data);
}


//自己的出牌时间已到
void PlayPokerMediator::meTimeUp()
{
	if (buChuBtn->isVisible())
	{
		//直接不出
		clickBuChuBtnHander(NULL);
		logV("cocos2d-x meTimeUp not out poker");
	}
	else
	{
		//和提示功能相同
		clickTiShiBtnHander();

		//这边要通过抛事件来自动出牌
		blueSkyDispatchEvent(10603);
		logV("cocos2d-x meTimeUp  out poker as tishi");

	}
}

//进贡时间到
void PlayPokerMediator::jinGongTimeUp()
{
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

	//先取消之前手牌的选中状态
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	//贡最大的。且不能贡癞子
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

//还贡时间到
void PlayPokerMediator::huanGongTimeUp()
{
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

	//先取消之前手牌的选中状态
	//vector<PokerVO*> selectedPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr;
	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
	}
	//还最小的
	int size = gameDataModel->player[0].pokerArr.size();
	pokeridData *data = new pokeridData();
	data->pokerID = gameDataModel->player[0].pokerArr.at(size - 1)->pokerID;
	data->pokerID2 = gameDataModel->player[0].pokerArr.at(size - 1)->pokerID2;
	blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);

	blueSkyDispatchEvent(10607);
}

//显示托管图标
void PlayPokerMediator::showAutoImage(int deskID, bool show)
{
	switch (deskID)
	{
		//本玩家
	case 0:
		meAutoImage->setVisible(show);
		break;
		//右边的玩家
	case 3:
		rightAutoImage->setVisible(show);
		break;
		//对面的玩家
	case 2:
		topAutoImage->setVisible(show);
		break;
		//左边的玩家
	case 1:
		leftAutoImage->setVisible(show);
		break;
	}
}

//播放出牌音效
void PlayPokerMediator::playChuPaiMusic(int pokerType, int faceID)
{
	switch (faceID)
	{
		//女
		case 1:
		case 4:
		{
			//1.单张 2.对子 3.3张  4.3带2 5.顺子 6.连队 7.飞机  8.炸弹 9.同花顺 10.火箭
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
		//男
		case 2:
		case 3:
		{
			//1.单张 2.对子 3.3张  4.3带2 5.顺子 6.连队 7.飞机  8.炸弹 9.同花顺 10.火箭
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

//显示本轮谁打
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
