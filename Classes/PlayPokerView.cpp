#include "PlayPokerView.h"
#include "SGTools.h"
#include "DataManager.h"
#include "ViewManager.h"
#include "UILayerService.h"
//test
#include "InviteMediator.h"
#include "InviteView.h"

#define TIME_SendPoker 20

PlayPokerView::PlayPokerView()
{
	time = 1;
	nowIndex = 1;
	sucessesPlayer = 0;   //已出完牌的玩家个数
	desk = -1;
	face = -1;
	touyouNode = NULL;

	rootNode = CSLoader::createNode("PlayScene.csb");
	addChild(rootNode);

	blueSkyDispatchEvent(12600);
	blueSkyDispatchEvent(12700);
	blueSkyDispatchEvent(12800);
	for (int i = 0; i < 3; i++)
	{
		imgTouyou[i] = NULL;
	}

	Node  *node1, *node2, *node3, *node4;
	UIGet_Node("me_character"   ,rootNode, node1)
	UIGet_Node("left_character" ,rootNode, node2)
	UIGet_Node("top_character"  ,rootNode, node3)
	UIGet_Node("right_character",rootNode, node4)

	UIGet_Button("fanhui_btn", rootNode, fanhui_btn)
	UIGet_Button("clickBtn", node1, clickMeBtn)
	UIGet_Button("clickBtn", node2, clickLeftBtn)
	UIGet_Button("clickBtn", node3, clickTopBtn)
	UIGet_Button("clickBtn", node4, clickRightBtn)

	BTN_EVENT(fanhui_btn, 10601)
	BTN_EVENT(clickMeBtn, 10618)
	BTN_EVENT(clickLeftBtn, 10619)
	BTN_EVENT(clickTopBtn, 10620)
	BTN_EVENT(clickRightBtn, 10621)

	//调整层级不被划牌触摸层覆盖
	clickMeBtn->setGlobalZOrder   (GOrderPlayerHead);
	clickLeftBtn->setGlobalZOrder (GOrderPlayerHead);
	clickTopBtn->setGlobalZOrder  (GOrderPlayerHead);
	clickRightBtn->setGlobalZOrder(GOrderPlayerHead);

}
PlayPokerView::~PlayPokerView()
{

}

void PlayPokerView::showFriendInvites()
{
	imgInviteBg->setVisible(true);
	imgInvitebg[0]->setVisible(true);
	imgInvitebg[1]->setVisible(true);
	imgInvitebg[2]->setVisible(true);
	btnInvite[0]->setVisible(true);
	btnInvite[1]->setVisible(true);
	btnInvite[2]->setVisible(true);
	if (DataManager::E_GameTeam == DATA->bGameCate)
	{
		btnInvite[0]->setVisible(false);
		btnInvite[2]->setVisible(false);
		imgInvitebg[0]->setVisible(false);
		imgInvitebg[2]->setVisible(false);
	}
}

void PlayPokerView::hideFriendInvite(DWORD  dwWhich)
{
	if (dwWhich > 3 || dwWhich <= 0)
	{
		return;
	}
	btnInvite[dwWhich - 1]->setVisible(false);
	imgInvitebg[dwWhich - 1]->setVisible(false);
}

//外部的邀请按钮
void PlayPokerView::clickBtnInvite(Ref*   pSender)
{
	PLayEffect(EFFECT_BTN)
	Button*  btn = static_cast<Button*>(pSender);
	int iTag = btn->getTag();

	creatView(new InviteView(iTag), new InviteMediator());

}

void PlayPokerView::viewInit()
{
	char deskName[64];
	char bgName[64];
	for (int i = 0; i < 4; i++)
	{
		sprintf(deskName, "bscdesk_%d", i + 1);
		sprintf(bgName, "bscback_%d", i + 1);
		UIGet_Sprite(deskName, rootNode, spDesk[i])
		UIGet_Sprite(bgName, rootNode, spBg[i])
		spDesk[i]->setVisible(false);
		spBg[i]->setVisible(false);
	}
	switch (DATA->bGameCate)
	{
	case DataManager::E_GameCateNormal:
		if (DATA->bGameCateSub == 0)
		{
			spDesk[0]->setVisible(true);
			spBg[0]->setVisible(true);
		}
		else if (DATA->bGameCateSub == 1)
		{
			spDesk[1]->setVisible(true);
			spBg[1]->setVisible(true);
		}
		else if (DATA->bGameCateSub == 2)
		{
			spDesk[2]->setVisible(true);
			spBg[2]->setVisible(true);
		}
		break;

	case DataManager::E_GameCateMatch:
	case DataManager::E_GameFriend:
	case DataManager::E_GameFriendPassive:
	case DataManager::E_GameTeam:
	case DataManager::E_GameTeamPassive:
	case DataManager::E_GameRandZhupai:
	case DataManager::E_GameBlood:
		spDesk[3]->setVisible(true);
		spBg[3]->setVisible(true);
		break;
	default:

		break;

	}


	//好友场 ,组队
	if (DataManager::E_GameFriend == DATA->bGameCate || DataManager::E_GameTeam == DATA->bGameCate)
	{
		UIGet_ImageView("Image_inviteBlack1", rootNode, imgInvitebg[0])
			UIGet_ImageView("Image_inviteBlack2", rootNode, imgInvitebg[1])
			UIGet_ImageView("Image_inviteBlack3", rootNode, imgInvitebg[2])

			UIGet_ImageView("Image_inviteBg", rootNode, imgInviteBg)
			imgInviteBg->setVisible(true);
		Text  *txtFriend, *txtTeam;
		UIGet_Text("Text_friend", imgInviteBg, txtFriend)
			UIGet_Text("Text_team", imgInviteBg, txtTeam)
			txtFriend->setVisible(true);
			txtTeam->setVisible(false);
			if (DataManager::E_GameTeam == DATA->bGameCate)
			{
				txtFriend->setVisible(false);
				txtTeam->setVisible(true);
			}

			UIGet_Button("Button_invite1", rootNode, btnInvite[0])
			UIGet_Button("Button_invite2", rootNode, btnInvite[1])
			UIGet_Button("Button_invite3", rootNode, btnInvite[2])

		btnInvite[0]->setTag(1);
		btnInvite[1]->setTag(2);
		btnInvite[2]->setTag(3);

			UIClick(btnInvite[0], PlayPokerView::clickBtnInvite)
			UIClick(btnInvite[1], PlayPokerView::clickBtnInvite)
			UIClick(btnInvite[2], PlayPokerView::clickBtnInvite)
	}

	if (DataManager::E_GameFriendPassive == DATA->bGameCate ||
		DataManager::E_GameTeamPassive == DATA->bGameCate)
	{
		UIGet_ImageView("Image_inviteBg", rootNode, imgInviteBg)
			imgInviteBg->setVisible(true);
		Text  *txtFriend, *txtTeam;
		UIGet_Text("Text_friend", imgInviteBg, txtFriend)
			UIGet_Text("Text_team", imgInviteBg, txtTeam)

		if (DataManager::E_GameFriendPassive == DATA->bGameCate)
		{
			txtFriend->setVisible(true);
			txtTeam->setVisible(false);
		} 
		else if (DataManager::E_GameTeamPassive == DATA->bGameCate)
		{
			txtFriend->setVisible(false);
			txtTeam->setVisible(true);
		}
	}


	//时间钟
	myClock = rootNode->getChildByName("myClock");
	leftClock = rootNode->getChildByName("leftClock");
	rightClock = rootNode->getChildByName("rightClock");
	topClock = rootNode->getChildByName("topClock");

	UIGet_TextBMFont("timeText", myClock, myClockText)
		UIGet_TextBMFont("timeText", leftClock, leftClockText)
		UIGet_TextBMFont("timeText", topClock, topClockText)
		UIGet_TextBMFont("timeText", rightClock, rightClockText)

	Sprite*  mySp = Sprite::create("timer_inner.png");
	myTimer = ProgressTimer::create(mySp);

	Sprite*  leftSp = Sprite::create("timer_inner.png");
	leftTimer = ProgressTimer::create(leftSp);

	Sprite*  topSp = Sprite::create("timer_inner.png");
	topTimer = ProgressTimer::create(topSp);

	Sprite*  rightSp = Sprite::create("timer_inner.png");
	rightTimer = ProgressTimer::create(rightSp);


	myClock->addChild(myTimer);
	myTimer->setPosition(Vec2(0, -7));
	myClockText->setLocalZOrder(myTimer->getLocalZOrder() + 1);

	leftClock->addChild(leftTimer);
	leftTimer->setPosition(Vec2(0, -7));
	leftClockText->setLocalZOrder(leftTimer->getLocalZOrder() + 1);

	topClock->addChild(topTimer);
	topTimer->setPosition(Vec2(0, -7));
	topClockText->setLocalZOrder(topTimer->getLocalZOrder() + 1);

	rightClock->addChild(rightTimer);
	rightTimer->setPosition(Vec2(0, -7));
	rightClockText->setLocalZOrder(rightTimer->getLocalZOrder() + 1);

	hideClock();

	//玩家形象
	meCharacterNode = rootNode->getChildByName("me_character");
	leftCharacterNode = rootNode->getChildByName("left_character");
	topCharacterNode = rootNode->getChildByName("top_character");
	rightCharacterNode = rootNode->getChildByName("right_character");
	hideAllFace();

	//玩家名称
	leftName = dynamic_cast<Text*>(rootNode->getChildByName("leftName"));
	rightName = dynamic_cast<Text*>(rootNode->getChildByName("rightName"));
	topName = dynamic_cast<Text*>(rootNode->getChildByName("topName"));
	hideAllName();

	//玩家剩余牌数
	leftPokerNum = rootNode->getChildByName("leftPokerNum");
	topPokerNum = rootNode->getChildByName("topPokerNum");
	rightPokerNum = rootNode->getChildByName("rightPokerNum");
	hideAllPokerNum();

	pipeiAction = dynamic_cast<cocostudio::Armature*>(rootNode->getChildByName("pipeiAction"));
	pipeiAction->setVisible(false);
	showPiPei(true);


	//倍率与轮场
	Node* paiFenNode = rootNode->getChildByName("ProjectNode_score");
	UIGet_ImageView("Image_beilv", paiFenNode, imgBeilv)
		UIGet_ImageView("Image_lunchang", paiFenNode, imgLunChang)
		UIGet_Text("Text_beiLv", imgBeilv, txtBeilv)
		UIGet_Text("Text_lun", imgLunChang, txtLun)
		UIGet_Text("Text_chang", imgLunChang, txtChang)


		if (DATA->bGameCate == DataManager::E_GameCateMatch)
		{
			imgLunChang->setVisible(true);
			imgBeilv->setVisible(false);
			showLunChang();

		}
		else
		{
			imgLunChang->setVisible(false);
			imgBeilv->setVisible(true);
		}
}

void PlayPokerView::showPiPei(bool show)
{
	if (DATA->bGameCate == DataManager::E_GameCateMatch ||
		DATA->bGameCate == DataManager::E_GameFriend ||
		DATA->bGameCate == DataManager::E_GameFriendPassive||
		DATA->bGameCate == DataManager::E_GameTeam ||
		DATA->bGameCate == DataManager::E_GameTeamPassive)
	{
		return;
	}
	pipeiAction->setVisible(show);
}

void PlayPokerView::hideClock(int pos)
{
	switch (pos)
	{
	case -1:
		myClock->setVisible(false);
		leftClock->setVisible(false);
		rightClock->setVisible(false);
		topClock->setVisible(false);
		break;
	case 0:
		myClock->setVisible(false);
		break;
	case 1:
		leftClock->setVisible(false);
		break;
	case 2:
		topClock->setVisible(false);
		break;
	case 3:
		rightClock->setVisible(false);
		break;
	}
	

}

void PlayPokerView::stopClock()
{
	if (this->isScheduled(schedule_selector(PlayPokerView::clockShow)))
	{
		this->unschedule(schedule_selector(PlayPokerView::clockShow));
	}
}

void PlayPokerView::startClock(int deskID,int index)
{
	if (this->isScheduled(schedule_selector(PlayPokerView::clockShow)))
	{
		this->unschedule(schedule_selector(PlayPokerView::clockShow));
		time = 1;
	}

	nowIndex = index;

	this->schedule(schedule_selector(PlayPokerView::clockShow), 1.0f);
	switch (deskID)
	{
	case 0:
		myClock->setVisible(true);
		rightClock->setVisible(false);
		topClock->setVisible(false);
		leftClock->setVisible(false);
		break;
	case 3:
		myClock->setVisible(false);
		rightClock->setVisible(true);
		topClock->setVisible(false);
		leftClock->setVisible(false);
		break;
	case 2:
		myClock->setVisible(false);
		rightClock->setVisible(false);
		topClock->setVisible(true);
		leftClock->setVisible(false);
		break;
	case 1:
		myClock->setVisible(false);
		rightClock->setVisible(false);
		topClock->setVisible(false);
		leftClock->setVisible(true);
		break;
	}
	myClockText->setString("20");
	rightClockText->setString("20");
	topClockText->setString("20");
	leftClockText->setString("20");

	myTimer->setPercentage(100);
	leftTimer->setPercentage(100);
	topTimer->setPercentage(100);
	rightTimer->setPercentage(100);

}
void PlayPokerView::clockShow(float dt)
{
	if (time > TIME_SendPoker)
		return;
	char a[256];
	int i = TIME_SendPoker - time;
	sprintf(a, "%d", i);
	string m = a;
	myClockText->setString(m);
	rightClockText->setString(m);
	topClockText->setString(m);
	leftClockText->setString(m);

	myTimer->setPercentage(i * 100 / TIME_SendPoker);
	rightTimer->setPercentage(i * 100 / TIME_SendPoker);
	topTimer->setPercentage(i * 100 / TIME_SendPoker);
	leftTimer->setPercentage(i * 100 / TIME_SendPoker);

	//倒数10秒时开始播放计时器音效
	if (time > 10)
	{
		//blueSkyDispatchEvent(20053);
		PLayEffect(JI_SHI_QI)
	}
	if (time == TIME_SendPoker && myClock->isVisible())
	{
		if (nowIndex == 1)
		{
			blueSkyDispatchEvent(10043);
		}
		else if (nowIndex == 2)
		{
			//进贡时间到
			blueSkyDispatchEvent(10044);
			myClock->setVisible(false);
		}
		else if (nowIndex == 3)
		{
			//还贡时间到
			blueSkyDispatchEvent(10045);
			myClock->setVisible(false);
		}
	}
		
	time++;
}

//隐藏玩家名称、
void PlayPokerView::hideAllName()
{
	leftName->setVisible(false);
	topName->setVisible(false);
	rightName->setVisible(false);
}

//显示玩家名称
void PlayPokerView::showCharacterName(int pos, string name)
{
	switch (pos)
	{
	case 0:
		break;
	case 1:
		leftName->setString(name);
		leftName->setVisible(true);
		break;
	case 2:
		topName->setString(name);
		topName->setVisible(true);
		break;
	case 3:
		rightName->setString(name);
		rightName->setVisible(true);
		break;
	}
}

//隐藏所有玩家形象
void PlayPokerView::hideAllFace()
{
	meCharacterNode->setVisible(false);
	leftCharacterNode->setVisible(false);
	topCharacterNode->setVisible(false);
	rightCharacterNode->setVisible(false);
}

void PlayPokerView::gameOverHandle()
{
    hideClock();
    stopClock();
    imgHuaPai->setVisible(false);
    
    if (touyouNode)
    {
        stopAction(touyouTimeline);
        touyouNode->removeFromParentAndCleanup(true);
        touyouNode = NULL;
    }
    for (int i = 0; i < 3; i++)
    {
        if (imgTouyou[i] != NULL)
        {
            imgTouyou[i]->removeFromParentAndCleanup(true);
            imgTouyou[i] = NULL;
        }
    }
}

void PlayPokerView::showTouyou(int i)
{
	Vec2 point;
	switch (i)
	{
	case 0:
		point = Vec2(80, 150);
		break;
	case 1:
		point = Vec2(150, 380);
		break;
	case 2:
		point = Vec2(570, 410);
		break;
	case 3:
		point = Vec2(845, 380);
		break;
	default:
		break;
	}
	switch (sucessesPlayer)
	{
	case 0:
		UIFrameCreate(touyou, "touyou.csb", rootNode, false)
		touyouNode->setPosition(point);
		PLayEffect("sounds/touyouEff.mp3")
// 		imgTouyou[0] = ImageView::create("outEnd0.png");
// 		imgTouyou[0]->setPosition(point);
// 		rootNode->addChild(imgTouyou[0]);
		break;
	case 1:
		imgTouyou[1] = ImageView::create("outEnd1.png");
		imgTouyou[1]->setPosition(point);
		rootNode->addChild(imgTouyou[1]);
		break;
	case 2:
		imgTouyou[2] = ImageView::create("outEnd2.png");
		imgTouyou[2]->setPosition(point);
		rootNode->addChild(imgTouyou[2]);
		break;
	default: 
		break;
	}

	sucessesPlayer++;

}

//显示玩家待机形象
void PlayPokerView::showDaiJiFace(int pos, int faceID)
{
	Node* node;
	switch (pos)
	{
	case 0:
		node = rootNode->getChildByName("me_character");
		break;
	case 1:
		node = rootNode->getChildByName("left_character");
		break;
	case 2:
		node = rootNode->getChildByName("top_character");
		break;
	case 3:
		node = rootNode->getChildByName("right_character");
		break;
	}
	node->setVisible(true);
	Action1 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_1"));
	Action2 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_2"));
	Action3 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_3"));
	Action4 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_4"));
	switch (faceID)
	{
	case 1:
		Action1->getAnimation()->play("a_2_daiji", -1, 1);
		Action1->setVisible(true);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 2:
		Action2->getAnimation()->play("b_2_daiji", -1, 1);
		Action1->setVisible(false);
		Action2->setVisible(true);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 3:
		Action3->getAnimation()->play("c_2_daiji", -1, 1);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(true);
		Action4->setVisible(false);
		break;
	case 4:
		Action4->getAnimation()->play("d_2_daiji", -1, 1);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(true);
		break;
	default:
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	}
}

//显示玩家出牌形象
void PlayPokerView::showChuPaiFace(int pos, int faceID)
{
	//
	desk = pos;
	face = faceID;

	Node* node;
	switch (pos)
	{
	case 0:
		node = rootNode->getChildByName("me_character");
		break;
	case 1:
		node = rootNode->getChildByName("left_character");
		break;
	case 2:
		node = rootNode->getChildByName("top_character");
		break;
	case 3:
		node = rootNode->getChildByName("right_character");
		break;
	}
	node->setVisible(true);
	Action1 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_1"));
	Action2 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_2"));
	Action3 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_3"));
	Action4 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_4"));
	switch (faceID)
	{
	case 1:
		Action1->getAnimation()->play("a_2_chupai", -1, 0);
		Action1->setVisible(true);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 2:
		Action2->getAnimation()->play("b_2_chupai", -1, 0);
		Action1->setVisible(false);
		Action2->setVisible(true);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 3:
		Action3->getAnimation()->play("c_2_chupai", -1, 0);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(true);
		Action4->setVisible(false);
		break;
	case 4:
		Action4->getAnimation()->play("d_2_chupai", -1, 0);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(true);
		break;
	default:
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	}

	this->scheduleOnce(schedule_selector(PlayPokerView::showDaiJiFaceHander),1.0f);
}

//显示玩家胜利形象
void PlayPokerView::showSuccessFace(int pos, int faceID)
{
	//
	desk = pos;
	face = faceID;
	showTouyou(pos);
	Node* node;
	switch (pos)
	{
	case 0:
		node = rootNode->getChildByName("me_character");
		break;
	case 1:
		node = rootNode->getChildByName("left_character");
		break;
	case 2:
		node = rootNode->getChildByName("top_character");
		break;
	case 3:
		node = rootNode->getChildByName("right_character");
		break;
	}
	node->setVisible(true);
	Action1 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_1"));
	Action2 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_2"));
	Action3 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_3"));
	Action4 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_4"));
	switch (faceID)
	{
	case 1:
		Action1->getAnimation()->play("a_2_shengli", -1, 0);
		Action1->setVisible(true);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 2:
		Action2->getAnimation()->play("b_2_shengli", -1, 0);
		Action1->setVisible(false);
		Action2->setVisible(true);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 3:
		Action3->getAnimation()->play("c_2_shengli", -1, 0);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(true);
		Action4->setVisible(false);
		break;
	case 4:
		Action4->getAnimation()->play("d_2_shengli", -1, 0);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(true);
		break;
	default:
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	}
	this->scheduleOnce(schedule_selector(PlayPokerView::showPokerAllOutFaceHander), 1.0f);
}

//显示玩家出完牌形象
void PlayPokerView::showPokerAllOutFace(int pos, int faceID)
{
	Node* node;
	switch (pos)
	{
	case 0:
		node = rootNode->getChildByName("me_character");
		break;
	case 1:
		node = rootNode->getChildByName("left_character");
		break;
	case 2:
		node = rootNode->getChildByName("top_character");
		break;
	case 3:
		node = rootNode->getChildByName("right_character");
		break;
	}
	node->setVisible(true);
	Action1 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_1"));
	Action2 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_2"));
	Action3 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_3"));
	Action4 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_4"));
	switch (faceID)
	{
	case 1:
		Action1->getAnimation()->play("a_2_shenglidaiji", -1, 1);
		Action1->setVisible(true);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 2:
		Action2->getAnimation()->play("b_2_shenglidaiji", -1, 1);
		Action1->setVisible(false);
		Action2->setVisible(true);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 3:
		Action3->getAnimation()->play("c_2_shenglidaiji", -1, 1);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(true);
		Action4->setVisible(false);
		break;
	case 4:
		Action4->getAnimation()->play("d_2_shenglidaiji", -1, 1);
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(true);
		break;
	default:
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	}
}


void PlayPokerView::showDaiJiFaceHander(float dt)
{
	showDaiJiFace(desk,face);
}

void PlayPokerView::showPokerAllOutFaceHander(float dt)
{
	showPokerAllOutFace(desk,face);
}

//剩余牌数
void PlayPokerView::hideAllPokerNum()
{
	leftPokerNum->setVisible(false);
	topPokerNum->setVisible(false);
	rightPokerNum->setVisible(false);
}

void PlayPokerView::showPokerNum(int desk, int pokerNum)
{
	Text*  txtLeft;
	switch (desk)
	{
		//本玩家
		case 0:
			return;
			//左边的玩家
		case 1:
			if (pokerNum == 0)
			{
				leftPokerNum->setVisible(false);
			}
			else
			{
				leftPokerNum->setVisible(true);
			}
			UIGet_Text("leftNum", leftPokerNum, txtLeft)
				break;
			//对面的玩家
		case 2:
			if (pokerNum == 0)
			{
				topPokerNum->setVisible(false);
			}
			else
			{
				topPokerNum->setVisible(true);
			}
			UIGet_Text("leftNum", topPokerNum, txtLeft)
			break;

			//右边的玩家
		case 3:
			if (pokerNum == 0)
			{
				rightPokerNum->setVisible(false);
			}
			else
			{
				rightPokerNum->setVisible(true);
			}

			UIGet_Text("leftNum", rightPokerNum, txtLeft)
				break;
	}
	txtLeft->setString(Tools::parseInt2String(pokerNum));
}

//显示本局倍率
void PlayPokerView::showBeiLv(int index)
{
		txtBeilv->setString(Tools::parseInt2String(index));
}

//显示
void PlayPokerView::showLunChang()
{
		txtLun->setString(Tools::parseInt2String(DATA->wMatchNowLuanci));
		txtChang->setString(Tools::parseInt2String(DATA->wMatchNowChangci));
}

























































































