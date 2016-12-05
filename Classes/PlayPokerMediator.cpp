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
#include "MusicService.h"
#include "MallMediator.h"
#include "MallView.h"
#include "ViewManager.h"
static string strLvNum[15] = { "0", "0", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

PlayPokerMediator::PlayPokerMediator()
{
	touchBeginPos = Vec2(0, 0);
	nowBeiLv = 1;  //���ֱ���
	huiGongID = -1;   //�ع�����ķ���������ID
	hasPlayJinGongAction = false;
	hasPlayHuanGongAction = false;
	hasGetJinGong = false;
	hasGetHuanGong = false;
	isFirstOutPoker = true;  //�Ƿ��ǵ�һ�η���
	isMeFirstOutPoker = false;
	mJoinInPlayer = 0;  //�������ӵ������Ŀ
	mPlayCount = 0;    //�����˼��δ��ƣ����������һ�Σ�
	isAutoState = false;
	clickTiShiTimes = 0; //��¼������ʾ������Ĵ���
	clickTongHuaShunTimes = 0; //��¼����ͬ��˳��ť������Ĵ���
	isChatOpened = false; 	//��������Ƿ񱻴�
	isJipaiQiShow = false;
	isJiapaiQiRequested = false;
	UIFrameInit(matchEndLoading)
	UIFrameInit(matchEndLoading2)
	UIFrameInit(bloodStart)
}


PlayPokerMediator::~PlayPokerMediator()
{
	if (mpViewMatchRanking)
	{
		mpViewMatchRanking->removeAllChildrenWithCleanup(true);
	}
	if (playPokerView->imgHuaPai)
	{
		playPokerView->imgHuaPai->removeFromParentAndCleanup(true);
		playPokerView->imgHuaPai = NULL;
	}
	

	delete getView();
	setView(NULL);
}

void PlayPokerMediator::showFriendButtons(bool isShow)
{
	if (isShow)
	{
		paiFenNode->setVisible(true);
		tongHuaShunBtn->setVisible(true);
		liChengYiPaiBtn->setVisible(true);
		chongLiBtn->setVisible(true);
		if (DATA->bGameCate != DataManager::E_GameCateMatch)
		{
			markBtn->setVisible(true);
			imgJPTip->setVisible(true);
		}
		autoBtn->setVisible(true);
		taskBtn->setVisible(true);
		lookTableBtn->setVisible(true);
		chatBtn->setVisible(true);

	}
	else
	{
		paiFenNode     ->setVisible(false);
		tongHuaShunBtn ->setVisible(false);
		liChengYiPaiBtn->setVisible(false);
		chongLiBtn     ->setVisible(false);
		markBtn        ->setVisible(false);
		autoBtn        ->setVisible(false);
		taskBtn        ->setVisible(false);
		lookTableBtn   ->setVisible(false);
		chatBtn->setVisible(false);
		imgJPTip->setVisible(false);
		zhunbei1->setVisible(false);
	}
}

void PlayPokerMediator::readyPlay()
{
	//���ƴ���
	playPokerView->imgHuaPai = ImageView::create("touchLayer.png");
	VIEW->myPokerLayer->addChild(playPokerView->imgHuaPai, 1000);
	playPokerView->imgHuaPai->setAnchorPoint(Vec2(0, 0));
	playPokerView->imgHuaPai->setPosition(Vec2(0, 50));
	playPokerView->imgHuaPai->setTouchEnabled(true);
	playPokerView->imgHuaPai->setVisible(true);
	playPokerView->imgHuaPai->addTouchEventListener(CC_CALLBACK_2(PlayPokerMediator::onTouchesHuapai, this));
	showFriendButtons(true);
}



void PlayPokerMediator::OnRegister()
{
	VIEW->nowViewTag = ViewManager::eViewGame;
	playPokerView = (PlayPokerView*)getView();
	mpViewMatchRanking = NULL;
	playPokerView->imgHuaPai = NULL;

	if (DATA->bGameCate == DataManager::E_GameCateMatch)
	{
		mpViewMatchRanking = ViewMatchRanking::create();         //���а�
		VIEW->mainScene->addChild(mpViewMatchRanking, 1000, 1000);
		mpViewMatchRanking->setVisible(false);
	}

	UIGet_Button("fanhui_btn", playPokerView->rootNode, fanHuiBtn)

		UIGet_Button("liaotian_Btn", playPokerView->rootNode, chatBtn)
		UIGet_Button("jingongBtn", playPokerView->rootNode, jingongBtn)
		UIGet_Button("huangongBtn", playPokerView->rootNode, huangongBtn)
		UIClick(chatBtn, PlayPokerMediator::clickChatBtnHander)
		UIClick(jingongBtn, PlayPokerMediator::clickJinGongBtnHander)
		UIClick(huangongBtn, PlayPokerMediator::clickHuanGongBtnHander)
		

		UIGet_Button("lookTableBtn", playPokerView->rootNode, lookTableBtn)
	lookTableBtn->addTouchEventListener(lookTableBtn, toucheventselector(PlayPokerMediator::clicklookTableBtn));
	
	Node*  liPaiNode;
	UIGet_Node("ProjectNode_lipai", playPokerView->rootNode, liPaiNode)
		UIGet_Button("tonghuashun_Btn", liPaiNode, tongHuaShunBtn)
		UIGet_Button("lichengyipai_Btn", liPaiNode, liChengYiPaiBtn)
		UIGet_Button("chongxinglipai_Btn", liPaiNode, chongLiBtn)
		UIClick(tongHuaShunBtn, PlayPokerMediator::clickTongHuaShunBtnHander)
		UIClick(liChengYiPaiBtn, PlayPokerMediator::clickLiChengYiPaiBtnHander)
		UIClick(chongLiBtn, PlayPokerMediator::clickChongLiBtnHander)

		auto topBtnNode = playPokerView->rootNode->getChildByName("ProjectNode_topBtn");
	UIGet_Button("jipaiqi_Btn", topBtnNode, markBtn)
		UIGet_Button("tuoguan_Btn", topBtnNode, autoBtn)
		UIGet_Button("task_btn", topBtnNode, taskBtn)
		UIClick(markBtn, PlayPokerMediator::clickMarkBtnHander)
		UIClick(autoBtn, PlayPokerMediator::clickAutoBtnHander)
		UIClick(taskBtn, PlayPokerMediator::clickTaskBtnHander)

		UIGet_Node("ProjectNode_action", playPokerView->rootNode, actionNode)
		UIGet_Button("buchu_Btn", actionNode, buChuBtn)
		UIGet_Button("tishi_Btn", actionNode, tiShiBtn)
		UIGet_Button("chupai_Btn", actionNode, chuPaiBtn)
		UIClick(buChuBtn, PlayPokerMediator::clickBuChuBtnHander)
		UIClick(tiShiBtn, PlayPokerMediator::clickTiShiBtnHander)
		UIClick(chuPaiBtn, PlayPokerMediator::clickChuPaiBtnHander)
		buChuBtn->setGlobalZOrder(10);
	tiShiBtn->setGlobalZOrder(10);
	chuPaiBtn->setGlobalZOrder(10);
	jingongBtn->setGlobalZOrder(10);
	huangongBtn->setGlobalZOrder(10);
	

	jingongBtn->setVisible(false);
	huangongBtn->setVisible(false);
	actionNode->setVisible(false);

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
	paiFenNode = getView()->rootNode->getChildByName("ProjectNode_score");
	myJiShu1 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("myJiShu1"));
	otherJiShu1 = dynamic_cast<ImageView*>(paiFenNode->getChildByName("otherJiShu1"));

	UIGet_Text("Text_myLv", paiFenNode, myLv);
	UIGet_Text("Text_otherLv", paiFenNode, otherLv);
	myLv->setString("-");
    otherLv->setString("-");

	buchu1 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu1"));
	buchu2 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu2"));
	buchu3 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu3"));
	buchu4 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("buchu4"));
	buchu1->setVisible(false);
	buchu2->setVisible(false);
	buchu3->setVisible(false);
	buchu4->setVisible(false);

	zhunbei1 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei1"));
	zhunbei2 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei2"));
	zhunbei3 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei3"));
	zhunbei4 = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("zhunbei4"));
	
	zhunbei1->setVisible(true);
	zhunbei2->setVisible(false);
	zhunbei3->setVisible(false);
	zhunbei4->setVisible(false);

//auto
	meAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("meAutoImage"));
	leftAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("leftAutoImage"));
	topAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("topAutoImage"));
	rightAutoImage = dynamic_cast<ImageView*>(getView()->rootNode->getChildByName("rightAutoImage"));
	meAutoImage->setVisible(false);
	leftAutoImage->setVisible(false);
	topAutoImage->setVisible(false);
	rightAutoImage->setVisible(false);

	//match rank
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
	else
	{
		markBtn->setVisible(true);
		imgJPTip->setVisible(true);
		imgMatchScore->setVisible(false);
	}
	markBtn->setTouchEnabled(false);  //����ʱ�ſ��Ե�

	playPokerView->viewInit();

	if (DataManager::E_GameTeam == DATA->bGameCate || DATA->bGameCate == DataManager::E_GameFriend)
	{
		playPokerView->showFriendInvites();
		showFriendButtons(false);
	}
	else
	{
		readyPlay();
	}
	sendReadyMsg();

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
	bool notClickPoker;   
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
		if (abs(touchPos.x - touchBeginPos.x) < 10 && abs(touchPos.y - touchBeginPos.y) < 10)
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
				//cancel selected pokers
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

void PlayPokerMediator::onRemove()
{
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(lookTableBtn);
}

void PlayPokerMediator::sendReadyMsg()
{
	((SendDataService *)getService(SendDataService::NAME))->sendReady();
}

void PlayPokerMediator::handleFriendPlay()
{

}

void PlayPokerMediator::showPlayerOnDeskHandle()
{
	nowBeiLv = 1;
	playPokerView->showBeiLv(nowBeiLv);
	fanHuiBtn->setVisible(true);
	playPokerView->hideAllFace();
	playPokerView->hideAllName();
	playPokerView->hideAllPokerNum();
	showPlayerOnDesk();
	playPokerView->hideClock();
	for (int j = 0; j < 4; j++)
	{
		showBuchu(j, false, true);
	}
	//ȥ�����ư�ť��ʾ
	isOrNotMyTurn(false);
	//paiFenNode->setPosition(Vec2(180, 502));
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

void PlayPokerMediator::showPlayerOnDeskHandle(void* data)
{
	OnDeskPlayerInfo deskInfo = *(OnDeskPlayerInfo*)data;
	logV("mJoinPlayer %d", mJoinInPlayer);
	if (mJoinInPlayer == 0)
	{
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		if (DATA->bGameCate == DataManager::E_GameFriend ||
			DATA->bGameCate == DataManager::E_GameTeam
			
			)
		{
			DATA->wFriendFieldTableId = deskInfo.wTableID;
			DATA->wFriendFieldChairId = deskInfo.wChairID;
		}
	}
	else
	{
		if (DATA->bGameCate == DataManager::E_GameFriend ||
			DATA->bGameCate == DataManager::E_GameTeam )
		{
			int clientChairId = DATAPlayerIndesk->chair[deskInfo.wChairID % 4];
			playPokerView->hideFriendInvite(clientChairId);
		}
	}

	nowBeiLv = 1;
	playPokerView->showBeiLv(nowBeiLv);


	fanHuiBtn->setVisible(true);
	playPokerView->hideAllFace();
	playPokerView->hideAllName();
	playPokerView->hideAllPokerNum();
	showPlayerOnDesk();

	playPokerView->hideClock();

	//hide all buchu
	for (int j = 0; j < 4; j++)
	{
		showBuchu(j, false, true);
	}
	//ȥ�����ư�ť��ʾ
	isOrNotMyTurn(false);

	//paiFenNode->setPosition(Vec2(180, 502));

	if (mJoinInPlayer == 3)
	{
		playPokerView->showPiPei(false);
		if (DataManager::E_GameFriendPassive == DATA->bGameCate ||
			DataManager::E_GameFriend == DATA->bGameCate ||
			DATA->bGameCate == DataManager::E_GameTeam ||
			DATA->bGameCate == DataManager::E_GameTeamPassive

			)
		{
			playPokerView->imgInviteBg->setVisible(false);
			showFriendButtons(true);
			readyPlay();
		}
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

				if (DATA->bGameCate == DataManager::E_GameTeamPassive)
				{
					if (DATAPlayerIndesk->getServiceChairID(2) == i)  //�Լ�����
					{
						clickfanHuiBtnHander();
						return;
					}
				}
				showPlayerOnDesk();
				break;
			}
		}

	}
}

void PlayPokerMediator::sendPokerkHandle()
{
	markBtn->setTouchEnabled(true);
	//ȥ��׼����ʾ
	for (int i = 0; i < 4; i++)
	{
		showZhunBei(i, false);
	}

	playPokerView->showPiPei(false);

	//���ƺ�ȡ�����ذ�ť��ʾ
	//just here
	if (DATA->bGameCate == DataManager::E_GameCateMatch  
	//	|| DATA->bGameCate == DataManager::E_GameCateNormal
		 )
	{
		fanHuiBtn->setVisible(false);
	}
	//fanHuiBtn->setVisible(false);

	if (DATA->bGameCate == DataManager::E_GameCateMatch ||
		DATA->bGameCate == DataManager::E_GameRandZhupai
		)
	{

		imgZhupaiDi = ImageView::create("now-card_bg.png");
		imgZhupaiDi->setPosition(Vec2(WScreen * 0.5, HScreen * 0.5));
		VIEW->uiLayer->addChild(imgZhupaiDi);

		UIFrameCreate(zhupai, "zhupai.csb", VIEW->uiLayer, false);
		zhupaiNode->setPosition(WScreen * 0.5, HScreen * 0.5);

		FiniteTimeAction*  seq = Sequence::create(
			DelayTime::create(1.2f),
			CallFunc::create(CC_CALLBACK_0(PlayPokerMediator::delayShowZhupai, this)),
			DelayTime::create(1.3f),
			CallFunc::create(CC_CALLBACK_0(PlayPokerMediator::delaySendPokerHandle, this)),
			NULL);
		VIEW->uiLayer->runAction(seq);

		if (DATA->bGameCate == DataManager::E_GameCateMatch)
		{
			logV("  cocos2d-x match send poker now!  ");
			hideMatchRanking();
			hideEndLoading();
			updateMatchScore();
			playPokerView->showLunChang();
		}
	}
	else if (DATA->bGameCate == DataManager::E_GameBlood)
	{
		UIFrameCreate(bloodStart, "bloodStart.csb", VIEW->uiLayer, false);
		FiniteTimeAction*  seq = Sequence::create(
			DelayTime::create(2.0f),
			CallFunc::create(CC_CALLBACK_0(PlayPokerMediator::delaySendPokerHandle, this)),
			NULL);
		VIEW->uiLayer->runAction(seq);

		bloodStartNode->setPosition(WScreen * 0.5, HScreen * 0.5);


		Text*  txtName[4];
		Text   *txtBlueWhite, *txtBlueYellow, *txtRedWhite,  *txtRedYellow;
		ImageView  *imgBlue, *imgRed; //blue is me,  red is other
		UIGet_ImageView("Image_blue", bloodStartNode, imgBlue)
			UIGet_ImageView("Image_red", bloodStartNode, imgRed)
			UIGet_Text("Text_name0", imgBlue, txtName[0])
			UIGet_Text("Text_name1", imgBlue, txtName[2])
			UIGet_Text("Text_name2", imgRed, txtName[1])
			UIGet_Text("Text_name3", imgRed, txtName[3])
			UIGet_Text("Text_LvWhite", imgBlue, txtBlueWhite)
			UIGet_Text("Text_LvYellow", imgBlue, txtBlueYellow)
			UIGet_Text("Text_LvWhite", imgRed, txtRedWhite)
			UIGet_Text("Text_LvYellow", imgRed, txtRedYellow)

		for (int i = 0; i < 4; i++)
		{
			int svrId = DATAPlayerIndesk->getServiceChairID(i);
			txtName[i]->setString(DATAPlayerIndesk->DeskPlayerInfo[svrId].szNickName);
		}
		CMD_S_GameStart*   sendPokerInfo = (CMD_S_GameStart*)(DATA->sendPokerData);

		if (DATAPlayerIndesk->getServiceChairID(0) == 0
			|| DATAPlayerIndesk->getServiceChairID(2) == 2
			)  //�ҷ���
		{
			txtBlueYellow->setString(strLvNum[sendPokerInfo->bOurSeries]);
			txtBlueWhite->setVisible(false);
			txtRedYellow->setVisible(false);
			txtRedWhite->setString(strLvNum[sendPokerInfo->bOtherSeries]);
		}
		else
		{
			txtBlueYellow->setVisible(false); 
			txtBlueWhite->setString(strLvNum[sendPokerInfo->bOtherSeries]);
			txtRedYellow->setString(strLvNum[sendPokerInfo->bOurSeries]);
			txtRedWhite->setVisible(false);
		}
	}
	else  //
	{
		delaySendPokerHandle();
	}



}

void PlayPokerMediator::callRemoveZhupaiDi() 
{
	imgZhupaiDi->removeFromParentAndCleanup(true);
}

void PlayPokerMediator::callRemoveZhupaiNode()
{
	zhupaiNode->removeFromParentAndCleanup(true);
}

void PlayPokerMediator::delayShowZhupai()
{
	DWORD dwJishu = ((CMD_S_GameStart*)DATA->sendPokerData)->bCurrentSeries;
	if (dwJishu == 14)
	{
		dwJishu = 1;
	}
	char imgName[64];
	sprintf(imgName, "%d.png", dwJishu);
	imgZhupai = ImageView::create(imgName);
	FiniteTimeAction*  seq = Sequence::create(
		DelayTime::create(1.0f),
		MoveTo::create(0.1f, Vec2(-350, 200)),
		FadeOut::create(0.1f),
		NULL);
	imgZhupai->runAction(seq);
	zhupaiNode->addChild(imgZhupai);




}

void PlayPokerMediator::delaySendPokerHandle()
{
	CMD_S_GameStart Data;
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	mJoinInPlayer = 0;  
	playPokerView->sucessesPlayer = 0;
	playPokerView->imgHuaPai->setVisible(true);


	if (DATA->bGameCate == DataManager::E_GameCateMatch)
	{
		logV("  cocos2d-x match send poker now! \n\n ");
		logF("  cocos2d-x match send poker now! \n\n");
		playPokerView->showLunChang();
		playPokerView->hideAllFace();
		playPokerView->hideAllName();
		playPokerView->hideAllPokerNum();
		for (int i = 0; i < 4; i++)
		{
			playPokerView->showDaiJiFace(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].wFaceID);
			playPokerView->showCharacterName(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].szNickName);
		}

		//remove zhupaiPoker
// 		UIFrameCreate(zhupai, "zhupai.csb", playPokerView->rootNode, false);
// 		zhupaiNode->setPosition(WScreen * 0.5, HScreen * 0.5);

	}
	else
	{
		creatView(new JiPaiView(), new JiPaiMediator());
		logV("cocos2d-x send poker now! \n\n ");
		logF("cocos2d-x send poker now! \n\n ");
	}

	//������Ч
	PLayEffect(SEND_CARD)

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
	Data = *(CMD_S_GameStart*)(DATA->sendPokerData);


	//��ʾ���ּ���
	//paiFenNode->setPosition(Vec2(81, 502));
	if (Data.bOtherSeries > 14 || Data.bOurSeries > 14)
	{
		return;
	}


	if (DATA->bGameCate == DataManager::E_GameCateMatch)
	{
		UIFrameRemove(zhupai, VIEW->uiLayer)
		imgZhupaiDi->removeFromParentAndCleanup(true);
		myLv->setString(strLvNum[Data.bCurrentSeries]);
		otherLv->setString(strLvNum[Data.bCurrentSeries]);
		showNowJiShu(true);
		if (playerInDeskModel->getServiceChairID(0) == Data.wCurrentUser)
		{
			isOrNotMyTurn(true);
			setBuChuBtnState(false);
			playPokerView->startClock(0);
		}

	}
	else if (DATA->bGameCate == DataManager::E_GameRandZhupai)
	{
		UIFrameRemove(zhupai, VIEW->uiLayer)
			imgZhupaiDi->removeFromParentAndCleanup(true);
		myLv->setString(strLvNum[Data.bCurrentSeries]);
		otherLv->setString(strLvNum[Data.bCurrentSeries]);
		if (playerInDeskModel->getServiceChairID(0) == Data.wCurrentUser ||
			playerInDeskModel->getServiceChairID(2) == Data.wCurrentUser
			)
		{
			showNowJiShu(true);
		}
		else
		{
			showNowJiShu(false);
		}

		if (playerInDeskModel->getServiceChairID(0) == Data.wCurrentUser)
		{
			isOrNotMyTurn(true);
			setBuChuBtnState(false);
			playPokerView->startClock(0);
			
		}

	}
	else
	{
		if (DATA->bGameCate == DataManager::E_GameBlood)
		{
			UIFrameRemove(bloodStart, VIEW->uiLayer)
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

		//��ʾ����˭��
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
		{
			isFirstOutPoker = true;
		}
		else
		{
			isFirstOutPoker = false;
		}

		if (!isFirstOutPoker)
		{
			wCurrentUser = Data.wCurrentUser;
			isOrNotMyTurn(false);
		}
		//first out poker
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

	logF("\nreceive playersize 0:%d, 1:%d, 2:%d, 3:%d",
		gameDataModel->player[0].pokerArr.size(),
		gameDataModel->player[1].pokerArr.size(),
		gameDataModel->player[2].pokerArr.size(),
		gameDataModel->player[3].pokerArr.size()
		);
	logV("\nreceive playersize 0:%d, 1:%d, 2:%d, 3:%d",
		gameDataModel->player[0].pokerArr.size(),
		gameDataModel->player[1].pokerArr.size(),
		gameDataModel->player[2].pokerArr.size(),
		gameDataModel->player[3].pokerArr.size()
		);
	logV("### desk %d  ###", desk);
	logF("### desk %d  ###", desk);
	if (pokerNum < 11 && pokerNum >= 0)
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
		int pokerId = gameDataModel->player[desk].outPokerArr[i]->pokerID;
		logV("(%d %d) ", PokerLogic::getPokerNum(pokerId) + 2, 
			PokerLogic::getPokerHuaSe(pokerId)
			);
		logF("(%d %d) ", PokerLogic::getPokerNum(pokerId) + 2,
			PokerLogic::getPokerHuaSe(pokerId)
			);
	}
	//��ʾ������Ч
	outPokerType = OutPokerLogicRule::outPokerType(outPokerArr).type;
	outPokerNum = OutPokerLogicRule::outPokerType(outPokerArr).len;
	if (outPokerType == 9)
	{
		blueSkyDispatchEvent(EventType::TONG_HUA_SHUN);
		//��ʾ����
		nowBeiLv = nowBeiLv + 2;
		nowBeiLv = nowBeiLv / 2 * 2;
		playPokerView->showBeiLv(nowBeiLv);
	}
	if (outPokerType == 10)
	{
		blueSkyDispatchEvent(EventType::HUO_JIAN);
		//��ʾ����
		nowBeiLv = nowBeiLv + 2 ;
		nowBeiLv = nowBeiLv / 2 * 2;
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
			nowBeiLv = nowBeiLv + 2;
			nowBeiLv = nowBeiLv / 2 * 2;
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
	CMD_C_USE_PROPERTY*  broadcasts = NULL;
	
	switch (i)
	{
	case EventType::FRIEND_PLAY:
		handleFriendPlay();
		break;

	case EventType::SHOW_PLAYER_ON_DESK_DATA:  //���ӽ���һλ���
		showPlayerOnDeskHandle(data);
		break;

	case EventType::SHOW_PLAYER_ON_DESK:  //���ӽ���һλ���
		showPlayerOnDeskHandle();
		break;

		//���״̬�ı�
	case EventType::ON_DESK:
		
		OnDeskHandle(data);
		break;

	case EventType::SEND_POKER:    //����
		sendPokerkHandle();
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
            playPokerView->gameOverHandle();
		
		break;

	case EventType::BACK_TO_HALL:
		DATAPlayerIndesk->clean();
		VIEW->myPokerLayer->removeAllChildrenWithCleanup(true);
		removeView(this);
		break;

	case FRIEND_FIELD_QUIT:
		clickfanHuiBtnHander();
		break;

	case EventType::USE_JI_PAI_QI:
		blueSkyDispatchEvent(12201);
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

	case 10603:
		clickChuPaiBtnHander(NULL);
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
	UIFrameCreate(matchEndLoading, "matchEndLoading.csb", VIEW->mainScene, true)
		UIFrameCreate(matchEndLoading2, "matchEndLoading2.csb", VIEW->mainScene, true)
		matchEndLoadingNode->setPosition(WScreen* 0.5, HScreen * 0.5);
		matchEndLoading2Node->setPosition(WScreen* 0.5, HScreen * 0.5);
		UIGet_Text("Text_leftDesk", matchEndLoadingNode, txtLeftDesks)
}

void PlayPokerMediator::hideEndLoading()
{
	UIFrameRemove(matchEndLoading, VIEW->mainScene)
		UIFrameRemove(matchEndLoading2, VIEW->mainScene)
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
	return VIEW->mainLayer;
}




void PlayPokerMediator::clickfanHuiBtnHander()
{
	PLayEffect(EFFECT_BTN)
	//�����뿪������Ϣ
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	int myChair = playerInDeskModel->getServiceChairID(0);
	int myTable = playerInDeskModel->DeskPlayerInfo[myChair].wTableID;
	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable,myChair,true);

	//�ر���Ϸ������SOCKET
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

	//�������
	DATAGameData->player[0].pokerArr = {};
	DATAGameData->player[0].outPokerArr = {};
	DATAGameData->player[1].outPokerArr = {};
	DATAGameData->player[2].outPokerArr = {};
	DATAGameData->player[3].outPokerArr = {};
	for (int i = 0; i < 4; i++)
	{
		DATAGameData->player[i].allOutPokerArrID = {};
	}
	DATAGameData->player[0].selectedPokerArr = {};


	creatView(new LobbyView(), new LobbyMediator());

	blueSkyDispatchEvent(EventType::BACK_TO_HALL);
	
	if (playPokerView->imgHuaPai)
	{
		playPokerView->imgHuaPai->removeFromParentAndCleanup(true);
		playPokerView->imgHuaPai = NULL;
	}


}

void PlayPokerMediator::clickChatBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
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



void PlayPokerMediator::clickJinGongBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
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
			PlayPokerView* playPokerView = (PlayPokerView*)getView();
			playPokerView->stopClock();
			playPokerView->hideClock(0);
		}
	}
}

void PlayPokerMediator::clickHuanGongBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	//ȡ����ҵ�ѡ��Ҫ��������
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
		PlayPokerView* playPokerView = (PlayPokerView*)getView();
		playPokerView->stopClock();
		playPokerView->hideClock(0);
	}
}


//��߱�����Ҫ���ƣ����ܵ����ʾ��ť��������ÿ���ֵ���ҳ���ʱ�ж�һ�°�ť����ʾ
void PlayPokerMediator::clickTiShiBtnHander(Ref*  pSender)
{
	PLayEffect(EFFECT_BTN)
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
		//�Ҳ�����Ӧ�����;���ը��ѹ
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//��ը��ѹ
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				if (allPokerArr.size() == 0) //no boom
				{
					allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				}
			}
			else if (pokerType.type == 8 && pokerType.len <= 5) //5�ż����µ�ը��
			{
				allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
			}
			//ͬ��˳��6�����ϵ�ը��ѹ
			else if (pokerType.type == 9)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
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
		//�Ҳ�����Ӧ�����;���ը��ѹ
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//��ը��ѹ
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				if (allPokerArr.size() == 0) //no boom
				{
					allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				}
			}
			else if (pokerType.type == 8 && pokerType.len <= 5) //5�ż����µ�ը��
			{
				allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
			}
			//ͬ��˳��6�����ϵ�ը��ѹ
			else if (pokerType.type == 9)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
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
		//�Ҳ�����Ӧ�����;���ը��ѹ
		if (allPokerArr.size() == 0)
		{
			PokerTypeVO pokerType = OutPokerLogicRule::outPokerType(outPokerArr);
			//��ը��ѹ
			if (pokerType.type < 8)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 4, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				if (allPokerArr.size() == 0) //no boom
				{
					allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
				}
			}
			else if (pokerType.type == 8 && pokerType.len <= 5) //5�ż����µ�ը��
			{
				allPokerArr = OutPokerLogicRule::TiQuTongHuaShun(-1, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
			}
			//ͬ��˳��6�����ϵ�ը��ѹ
			else if (pokerType.type == 9)
			{
				allPokerArr = OutPokerLogicRule::TiQuBoom(-1, 6, gameDataModel->player[0].pokerTypeArr, LaiZiArr);
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
		GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
		int ids[30];
		int id2s[30];

		gameDataModel->player[0].selectedPokerArr = {};
		((SendDataService *)getService(SendDataService::NAME))->sendNotOutPoker();
		clickTiShiTimes = 0;
		clickTongHuaShunTimes = 0;
		actionNode->setVisible(false);  
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
	clickTiShiTimes++;
}

void PlayPokerMediator::clickChuPaiBtnHander(Ref*  pSender)
{
	PLayEffect(EFFECT_BTN)
	//���ж��ܲ��ܳ���
	bool canOutPoker = false;
	GameDataModel *gameDataModel = (GameDataModel*)getModel(GameDataModel::NAME);
	vector<PokerVO*> outPokerArr;
	vector<PokerVO*> selectedPokerArr;
	vector<PokerVO*> pokerArr;
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
		actionNode->setVisible(false);
		unsigned char CardData[27];

		logF("my outpoker");
		logV("my outpoker");
		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
		{
			CardData[i] = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
			logV("(%d %d) ", PokerLogic::getPokerNum(CardData[i]) + 2,
				PokerLogic::getPokerHuaSe(CardData[i])
				);
			logF("(%d %d) ", PokerLogic::getPokerNum(CardData[i]) + 2,
				PokerLogic::getPokerHuaSe(CardData[i])
				);
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
		gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);

		//���µ������Ƶ�λ��
	//	logF("------         left poker   size %d      -------", gameDataModel->player[0].pokerArr.size());
	//	logV("------         left poker   size %d      -------", gameDataModel->player[0].pokerArr.size());
		for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::CHANGE_POKER_POSITION, data);
// 			logV("(%d %d) ", PokerLogic::getPokerNum(data->pokerID) + 2,
// 				PokerLogic::getPokerHuaSe(data->pokerID)
// 				);
// 			logF("(%d %d) ", PokerLogic::getPokerNum(data->pokerID) + 2,
// 				PokerLogic::getPokerHuaSe(data->pokerID)
// 				);
		}

		//���ñ�����ʾ�������
		clickTiShiTimes = 0;

		//���ñ���ͬ��˳��ť�������
		clickTongHuaShunTimes = 0;
	}
	//�����ϳ��ƣ��������й�״̬��ֱ�Ӳ���
// 	else  
// 	{
// 		if (isAutoState == true)
// 		{
// 			clickBuChuBtnHander(NULL);
// 		}
// 	}

}

void PlayPokerMediator::clickBuChuBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
	actionNode->setVisible(false);
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

void PlayPokerMediator::clickTongHuaShunBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
	//��ȡ��֮ǰ���Ƶ�ѡ��״̬
// 	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.size(); i++)
// 	{
// 		pokeridData *data = new pokeridData();
// 		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID;
// 		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].selectedPokerArr.at(i)->pokerID2;
// 		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
// 	}

	//cancel selected pokers
	int ids[30];
	int id2s[30];
	int selectSize = DATAGameData->player[0].selectedPokerArr.size();
	for (int i = 0; i < selectSize; i++)
	{
		ids[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID;
		id2s[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID2;
	}
	for (int i = 0; i < selectSize; i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ids[i];
		data->pokerID2 = id2s[i];
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
		Tools::getInstance()->showSysMsgTouming
			(UTF8::getInstance()->getString("game", "noTonghuaShun"), 0, -100, Color3B(0xFF, 0x8A, 0x00));
		return;
	}

	logV("tonghuashun num  %d, clickTimes %d", allPokerArr.size(), clickTongHuaShunTimes);
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

void PlayPokerMediator::clickLiChengYiPaiBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
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

void PlayPokerMediator::clickChongLiBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
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
void PlayPokerMediator::clickMarkBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));

	if (jipaiqiNum > 0)
	{
		if (!isJiapaiQiRequested)
		{
			logV("if (!isJiapaiQiRequested)");
			isJiapaiQiRequested = true;
			isJipaiQiShow = true;
			DWORD dwUserID = DATA->myBaseData.dwUserID;
			WORD wKindID = 2;
			//ʹ�õ��ǵ�nowIndex����Ʒ
			((SendDataService*)getService(SendDataService::NAME))->sendUseJiPaiQi(8, wKindID, dwUserID, 0, 0);
			jipaiqiNum--;
			txtJPTips->setString(Tools::parseInt2String(jipaiqiNum));
			blueSkyDispatchEvent(12201);
		}
		else
		{
			isJipaiQiShow = !isJipaiQiShow;
			if (isJipaiQiShow)
			{
				logV("if (isJipaiQiShow 12201)");
				blueSkyDispatchEvent(12201);
			}
			else
			{
				logV("else (isJipaiQiShow 12202)");
				blueSkyDispatchEvent(12202);
			}
		}
	}
	else   //û�о͹���
	{
		creatView(new MallView(), new MallMediator());
	}
}

//�й�
void PlayPokerMediator::clickAutoBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
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
void PlayPokerMediator::clickTaskBtnHander(Ref* psender)
{
	PLayEffect(EFFECT_BTN)
	creatView(new DailyMissionView(), new DailyMissionMediator());
}

//ȡ���й�
void PlayPokerMediator::clickCancelAutoBtnHander()
{
	PLayEffect(EFFECT_BTN)
	isAutoState = false;
	showAutoImage(0, false);
}

//������水ť
bool PlayPokerMediator::clicklookTableBtn(Touch *touch, Widget::TouchEventType type)
{
	PLayEffect(EFFECT_BTN)
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
		clickTiShiBtnHander(NULL);


		//���Ҫͨ�����¼����Զ�����
		blueSkyDispatchEvent(10603);
		//���Ҫͨ�����¼����Զ�����
		//clickChuPaiBtnHander(NULL);
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


		playPokerView->hideAllFace();
		playPokerView->hideAllName();
		playPokerView->hideAllPokerNum();

	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));

	for (int i = 0; i < 4; i++)
	{
		if (!playerInDeskModel->DeskPlayerInfo[i].isClear)
		{
			playPokerView->showDaiJiFace(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].wFaceID);
			playPokerView->showCharacterName(playerInDeskModel->chair[i], playerInDeskModel->DeskPlayerInfo[i].szNickName);
			if (playerInDeskModel->DeskPlayerInfo[i].cbUserStatus == US_READY ||
				playerInDeskModel->getServiceChairID(0) == i)
			{
				showZhunBei(playerInDeskModel->chair[i], true);

			}
				
			else
			{
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

		int ids[30];
		int id2s[30];
		int selectSize = DATAGameData->player[0].selectedPokerArr.size();
		for (int i = 0; i < selectSize; i++)
		{
			ids[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID;
			id2s[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID2;
		}
		for (int i = 0; i < selectSize; i++)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = ids[i];
			data->pokerID2 = id2s[i];
			blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
		}

 		GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
// 		for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
// 		{
// 			pokeridData *data = new pokeridData();
// 			data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
// 			data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
// 			blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
// 		}
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
		clickTiShiBtnHander(NULL);

		//���Ҫͨ�����¼����Զ�����
		//clickChuPaiBtnHander(NULL);
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
// 	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
// 	{
// 		pokeridData *data = new pokeridData();
// 		data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
// 		data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
// 		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
// 	}

	int ids[30];
	int id2s[30];
	int selectSize = DATAGameData->player[0].selectedPokerArr.size();
	for (int i = 0; i < selectSize; i++)
	{
		ids[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID;
		id2s[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID2;
	}
	for (int i = 0; i < selectSize; i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ids[i];
		data->pokerID2 = id2s[i];
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
// 	for (DWORD i = 0; i < gameDataModel->player[0].selectedPokerArr.size(); i++)
// 	{
// 		pokeridData *data = new pokeridData();
// 		data->pokerID = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
// 		data->pokerID2 = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID2;
// 		blueSkyDispatchEvent(EventType::CHANGE_POKER_STATE, data);
// 	}

	int ids[30];
	int id2s[30];
	int selectSize = DATAGameData->player[0].selectedPokerArr.size();
	for (int i = 0; i < selectSize; i++)
	{
		ids[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID;
		id2s[i] = DATAGameData->player[0].selectedPokerArr.at(i)->pokerID2;
	}
	for (int i = 0; i < selectSize; i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = ids[i];
		data->pokerID2 = id2s[i];
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
		case 2:
		{
			//0 ���� ��1.���� 2.���� 3.3��  4.3��2 5.˳�� 6.���� 7.�ɻ�  8.ը�� 9.ͬ��˳ 10.���
			switch (pokerType)
			{
				case 0:
					PLayEffect(BU_CHU_NV);
					break;
				case 1:
					PLayEffect(DAN_ZHANG_NV);
					break;
				case 2:
					PLayEffect(DUI_ZI_NV);
					break;
				case 3:
					PLayEffect(SAN_ZHANG_NV);
					break;
				case 4:
					PLayEffect(SAN_DAI_ER_NV);
					break;
				case 5:
					PLayEffect(SHUN_NV);
					break;
				case 6:
					PLayEffect(LIAN_DUI_NV);
					break;
				case 7:
					PLayEffect(FEI_JI_NV);
					break;
				case 8:
					PLayEffect(BOOM_NV);
					break;
				case 9:
					PLayEffect(TONG_HUA_SHUN_NV);
					break;
				case 10:
					PLayEffect(HUO_JIAN_NV);
					break;
			}
		}
		break;
		//��
		case 3:
		case 4:
		{
			//1.���� 2.���� 3.3��  4.3��2 5.˳�� 6.���� 7.�ɻ�  8.ը�� 9.ͬ��˳ 10.���
			switch (pokerType)
			{
			case 0:
				PLayEffect(BU_CHU_NAN);
				break;
			case 1:
				PLayEffect(DAN_ZHANG_NAN);
				break;
			case 2:
				PLayEffect(DUI_ZI_NAN);
				break;
			case 3:
				PLayEffect(SAN_ZHANG_NAN);
				break;
			case 4:
				PLayEffect(SAN_DAI_ER_NAN);
				break;
			case 5:
				PLayEffect(SHUN_NAN);
				break;
			case 6:
				PLayEffect(LIAN_DUI_NAN);
				break;
			case 7:
				PLayEffect(FEI_JI_NAN);
				break;
			case 8:
				PLayEffect(BOOM_NAN);
				break;
			case 9:
				PLayEffect(TONG_HUA_SHUN_NAN);
				break;
			case 10:
				PLayEffect(HUO_JIAN_NAN);
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
		otherJiShu1->setVisible(false);
	}
	else
	{
		myJiShu1->setVisible(false);
		otherJiShu1->setVisible(true);
	}
}
