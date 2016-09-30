#include "PlayPokerView.h"
#include "SGTools.h"
#include "DataManager.h"
#include "ViewManager.h"



PlayPokerView::PlayPokerView()
{
	rootNode = CSLoader::createNode("PlayScene.csb");
	addChild(rootNode);

	touyou = CSLoader::createTimeline("touyou.csb");
	touyouNode = CSLoader::createNode("touyou.csb");
	rootNode->addChild(touyouNode);
	rootNode->runAction(touyou);
	touyouNode->setVisible(false);

	//划牌触摸
	imgHuaPai = ImageView::create("toumingBig2.png");
	VIEW->mainScene->addChild(imgHuaPai, 1000);
	imgHuaPai->setAnchorPoint(Vec2(0, 0));
	imgHuaPai->setPosition(Vec2(234, 50));
	imgHuaPai->setTouchEnabled(true);
	imgHuaPai->addTouchEventListener(CC_CALLBACK_2(PlayPokerView::onTouchesHuapai, this));
	imgHuaPai->setVisible(false);

	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, fanhui_btn, 10601, "fanhui_btn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, liaotian_Btn, 10602, "liaotian_Btn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, chupai_Btn, 10603, "chupai_Btn", "ProjectNode_1");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, tishi_Btn, 10604, "tishi_Btn", "ProjectNode_1");//
//	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, buchu_Btn, 10605, "buchu_Btn", "ProjectNode_1");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, jingongBtn, 10606, "jingongBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, huangongBtn, 10607, "huangongBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, lookTableBtn, 10608, "lookTableBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, tonghuashun_Btn, 10609, "tonghuashun_Btn", "ProjectNode_3");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, lichengyipai_Btn, 10610, "lichengyipai_Btn", "ProjectNode_3");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, chongxinglipai_Btn, 10611, "chongxinglipai_Btn", "ProjectNode_3");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, jipaiqi_Btn, 10612, "jipaiqi_Btn", "ProjectNode_5");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, tuoguan_Btn, 10613, "tuoguan_Btn", "ProjectNode_5");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, clear_btn, 10614, "clear_btn", "ProjectNode_5");//
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, clickMeBtn, 10618, "clickBtn", "me_character");
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, clickLeftBtn, 10619, "clickBtn", "left_character");
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, clickTopBtn, 10620, "clickBtn", "top_character");
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, clickRightBtn, 10621, "clickBtn", "right_character");
//	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayPokerView, getGoldBtn, 10615, "getGoldBtn", "ProjectNode_5");
}
PlayPokerView::~PlayPokerView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, fanhui_btn, 10601);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, liaotian_Btn, 10602);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, chupai_Btn, 10603);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, tishi_Btn, 10604);//
//	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, buchu_Btn, 10605);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, jingongBtn, 10606);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, huangongBtn, 10607);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, lookTableBtn, 10608);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, tonghuashun_Btn, 10609);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, lichengyipai_Btn, 10610);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, chongxinglipai_Btn, 10611);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, jipaiqi_Btn, 10612);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, tuoguan_Btn, 10613);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, clear_btn, 10614);//
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, clickMeBtn, 10618);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, clickLeftBtn, 10619);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, clickTopBtn, 10620);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, clickRightBtn, 10621);
	//BTN_REMOVE_TOUCH_EVENTLISTENER(PlayPokerView, getGoldBtn, 10615);
	delete rootNode;
	rootNode = NULL;
}

void PlayPokerView::onTouchesHuapai(Ref*  pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		break;
	case Widget::TouchEventType::ENDED:
		break;
	case Widget::TouchEventType::MOVED:
		break;
	default:
		break;
	}
}

void PlayPokerView::viewInit()
{

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
	myClockText->setZOrder(myTimer->getZOrder() + 1);

	leftClock->addChild(leftTimer);
	leftTimer->setPosition(Vec2(0, -7));
	leftClockText->setZOrder(leftTimer->getZOrder() + 1);

	topClock->addChild(topTimer);
	topTimer->setPosition(Vec2(0, -7));
	topClockText->setZOrder(topTimer->getZOrder() + 1);

	rightClock->addChild(rightTimer);
	rightTimer->setPosition(Vec2(0, -7));
	rightClockText->setZOrder(rightTimer->getZOrder() + 1);

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

	//
	pipeiAction = dynamic_cast<cocostudio::Armature*>(rootNode->getChildByName("pipeiAction"));
	showPiPei(true);


	//倍率与轮场
	Node* paiFenNode = rootNode->getChildByName("ProjectNode_4");
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
		else if (DATA->bGameCate == DataManager::E_GameCateNormal)
		{
			imgLunChang->setVisible(false);
			imgBeilv->setVisible(true);
		}

	//
//	_getGoldBtn->setVisible(false);

		VIEW->hideViewPlayGold();
}

void PlayPokerView::showPiPei(bool show)
{
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
	myClockText->setString("30");
	rightClockText->setString("30");
	topClockText->setString("30");
	leftClockText->setString("30");

	myTimer->setPercentage(100);
	leftTimer->setPercentage(100);
	topTimer->setPercentage(100);
	rightTimer->setPercentage(100);

}
void PlayPokerView::clockShow(float dt)
{
	if (time > 30)
		return;
	char a[256];
	int i = 30 - time;
	sprintf(a, "%d", i);
	string m = a;
	myClockText->setString(m);
	rightClockText->setString(m);
	topClockText->setString(m);
	leftClockText->setString(m);

	myTimer->setPercentage(i * 10 / 3);
	rightTimer->setPercentage(i * 10 / 3);
	topTimer->setPercentage(i * 10 / 3);
	leftTimer->setPercentage(i * 10 / 3);








	//倒数10秒时开始播放计时器音效
	if (time > 19)
	{
		blueSkyDispatchEvent(20053);
	}
	if (time == 30 && myClock->isVisible())
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


void PlayPokerView::showTouyou(int i)
{
	sucessesPlayer++;
	if (sucessesPlayer == 1)
	{
		touyou->gotoFrameAndPlay(0, false);
		Vec2 point;
		switch (i)
		{
		case 0:
			point = Vec2(80, 150);
			break;
		case 1:
			point = Vec2(80, 380);
			break;
		case 2:
			point = Vec2(570, 410);
			break;
		case 3:
			point = Vec2(875, 380);
			break;
		default:
			break;
		}
		touyouNode->setPosition(point);
		touyouNode->setVisible(true);
	}


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

	//auto call1 = CallFunc::create(
	//	CC_CALLBACK_2(PlayPokerView::showDaiJiFace, this,pos,faceID)
	//	);

	//
	//this->runAction(Sequence::create(DelayTime::create(1),nullptr));

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


	//auto call1 = CallFunc::create(
	//	CC_CALLBACK_2(PlayPokerView::showDaiJiFace, this, pos, faceID)
	//	);

	//
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
	Node* pokerNumberShow;
	ImageView* pokerLeft;
	ImageView* noPoker;
	switch (desk)
	{
		//本玩家
		case 0:
			return;
			break;
		//右边的玩家
		case 3:
			rightPokerNum->setVisible(true);
			pokerNumberShow = rightPokerNum->getChildByName("numberNode");
			pokerLeft = dynamic_cast<ImageView*>(rightPokerNum->getChildByName("pokerLeft"));
			noPoker = dynamic_cast<ImageView*>(rightPokerNum->getChildByName("noPoker"));
			break;
			//对面的玩家
		case 2:
			topPokerNum->setVisible(true);
			pokerNumberShow = topPokerNum->getChildByName("numberNode");
			pokerLeft = dynamic_cast<ImageView*>(topPokerNum->getChildByName("pokerLeft"));
			noPoker = dynamic_cast<ImageView*>(topPokerNum->getChildByName("noPoker"));
			break;
			//左边的玩家
		case 1:
			leftPokerNum->setVisible(true);
			pokerNumberShow = leftPokerNum->getChildByName("numberNode");
			pokerLeft = dynamic_cast<ImageView*>(leftPokerNum->getChildByName("pokerLeft"));
			noPoker = dynamic_cast<ImageView*>(leftPokerNum->getChildByName("noPoker"));
			break;
	}

	//
	ImageView* image1 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_1"));
	ImageView* image2 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_2"));
	ImageView* image3 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_3"));
	ImageView* image4 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_4"));
	ImageView* image5 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_5"));
	ImageView* image6 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_6"));
	ImageView* image7 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_7"));
	ImageView* image8 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_8"));
	ImageView* image9 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_9"));
	ImageView* image10 = dynamic_cast<ImageView*>(pokerNumberShow->getChildByName("Image_10"));

	switch (pokerNum)
	{
	case 0:
		pokerNumberShow->setVisible(false);
		pokerLeft->setVisible(false);
		noPoker->setVisible(true);
		break;
	case 1:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(true);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 2:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(true);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 3:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(true);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 4:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(true);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 5:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(true);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 6:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(true);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 7:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(true);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 8:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(true);
		image9->setVisible(false);
		image10->setVisible(false);
		break;
	case 9:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(true);
		image10->setVisible(false);
		break;
	case 10:
		pokerNumberShow->setVisible(true);
		pokerLeft->setVisible(true);
		noPoker->setVisible(false);
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		image5->setVisible(false);
		image6->setVisible(false);
		image7->setVisible(false);
		image8->setVisible(false);
		image9->setVisible(false);
		image10->setVisible(true);
		break;
	}
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

void PlayPokerView::showJiPaiQiBtn(bool show)
{
	_jipaiqi_Btn->setTouchEnabled(show);
	if (!show)
		_jipaiqi_Btn->setColor(ccc3(128, 128, 128));
	else
		_jipaiqi_Btn->setColor(ccc3(255, 255, 255));
}
























































































