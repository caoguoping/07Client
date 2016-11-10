#include "LobbyView.h"
#include "SGTools.h"
#include "ActivityMediator.h"
#include "ActivityView.h"
#include "UTF8.h"
#include "DataManager.h"
#include "ViewManager.h"

#include "InDeskService.h"
#include "MatchView.h"
#include "MatchMediator.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"
#include "GameDataModel.h"
#include "PokerLogic.h"
#include "SevenDayGiftView.h"
#include "SetView.h"
#include "PackageView.h"
#include "MallView.h"
#include "SetMediator.h"
#include "SevenDayGiftMediator.h"
#include "PackageMediator.h"
#include "MallMediator.h"
#include "MyInfoMediator.h"
#include "MyInfoView.h"
#include "FriendMediator.h"
#include "FriendView.h"
#include "PlayGoldMediator.h"
#include "PlayGoldView.h"
#include "ViewManager.h"
#include "EntertainmentMediator.h"
#include "EntertainmentView.h"
#include "BloodMediator.h"
#include "BloodView.h"

#define FOLD_TIME 0.1

LobbyView::LobbyView()
{
	VIEW->nowViewTag = ViewManager::eViewMain;
	rootNode = CSLoader::createNode("NewLobby.csb");
	addChild(rootNode);

	UIGet_Button("Button_task", rootNode, mBtnTask)
		UIClick(mBtnTask, LobbyView::clickBtnTask)

		UIGet_Button("signatureBtn", rootNode, mBtnSignature)
		UIClick(mBtnSignature, LobbyView::clickBtnSignature)

		UIGet_Button("setBtn", rootNode, mBtnSetting)
		UIClick(mBtnSetting, LobbyView::clickBtnSetting)


		UIGet_ScrollView("ScrollView_button", rootNode, scrBtn)

		UIGet_Button("Button_playGold", scrBtn, mBtnPlayGold)
		UIClick(mBtnPlayGold, LobbyView::clickBtnPlayGold)

		UIGet_Button("Button_entertainment", scrBtn, mBtnEntertainment)
		UIClick(mBtnEntertainment, LobbyView::clickBtnEntertainment)

		UIGet_Button("Button_match", scrBtn, mBtnMatch)
		UIClick(mBtnMatch, LobbyView::clickBtnMatch)

		UIGet_Button("Button_blood", scrBtn, mBtnBlood)
		UIClick(mBtnBlood, LobbyView::clickBtnBlood)



		UIGet_Button("Button_fastStart", rootNode, mBtnFast)
		UIClick(mBtnFast, LobbyView::clickBtnFast)

		UIGet_Button("firstPunchBtn", rootNode, mBtnCharge)
		UIClick(mBtnCharge, LobbyView::clickBtnCharge)

		UIGet_Button("shopBtn", rootNode, mBtnShop)
		UIClick(mBtnShop, LobbyView::clickBtnShop)

		UIGet_Button("activityBtn", rootNode, mBtnActivity)
		UIClick(mBtnActivity, LobbyView::clickBtnActivity)

		UIGet_Button("packageBtn", rootNode, mBtnPackage)
		UIClick(mBtnPackage, LobbyView::clickBtnPackage)

		UIGet_Button("Button_friend", rootNode, mBtnFriend)
		UIClick(mBtnFriend, LobbyView::clickBtnFriend)

		UIGet_Button("Button_head", rootNode, mBtnHead)
		UIClick(mBtnHead, LobbyView::clickBtnHead)

		UIGet_Node("headNode", rootNode, headNode)
		UIGet_Button("Button_gold", headNode, mBtnAddWealth)
		UIClick(mBtnAddWealth, LobbyView::clickBtnAddWealth)

		UIGet_Button("Button_diamond", headNode, mBtnAddDiamond)
		UIClick(mBtnAddDiamond, LobbyView::clickBtnAddDiamond)

		UIGet_Text("myName_0_3", headNode, txtPlayerName)
		UIGet_Text("Text_gold", headNode, txtGold)
		UIGet_Text("Text_diamond", headNode, txtDiamond)
		UIGet_Text("Text_id", headNode, txtId)
}

LobbyView::~LobbyView()
{
	delete rootNode;
	rootNode = NULL;
}


void LobbyView::clickBtnFold(Ref* pSender)  //折叠按钮
{
	FiniteTimeAction*  seq = Sequence::create(
		ScaleTo::create(FOLD_TIME, 0.1f, 1.0f), 
		Hide::create(),
		NULL
		);
	FiniteTimeAction*  seq1 = Sequence::create(
		ScaleTo::create(FOLD_TIME, 0.1f, 1.0f),
		Hide::create(),
		NULL
		);
	pgAd->runAction(seq1);
	imgPageBg->runAction(seq);
	scrBtn->runAction(MoveBy::create(FOLD_TIME, Vec2(-250, 0)));
}

void LobbyView::clickBtnUnfold(Ref* pSender)  //点击展开按钮
{
	FiniteTimeAction*  seq = Sequence::create(
		ScaleTo::create(0, 0.1f, 1.0f),
		Show::create(),
		ScaleTo::create(FOLD_TIME, 1.0f, 1.0f),
		NULL
		);
	FiniteTimeAction*  seq1 = Sequence::create(
		ScaleTo::create(0, 0.1f, 1.0f),
		Show::create(),
		ScaleTo::create(FOLD_TIME, 1.0f, 1.0f),
		NULL
		);
	pgAd->runAction(seq1);
	imgPageBg->runAction(seq);
	scrBtn->runAction(MoveBy::create(FOLD_TIME, Vec2(250, 0)));
}


void LobbyView::initView()
{
// 	if (MusicService::getInstance()->isMusicOn)
// 	{
// 		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
// 	}

	currentAd = 0;
	//广告页
	UIGet_PageView("PageView_ad", rootNode, pgAd)
	UIGet_ImageView("Image_Adbg", rootNode, imgPageBg)
	UIGet_Button("Button_fold", imgPageBg, btnFold)
	UIGet_Button("Button_unFold", rootNode, btnUnfold)
	UIClick(btnFold, LobbyView::clickBtnFold)
	UIClick(btnUnfold, LobbyView::clickBtnUnfold)


		UIGet_Button("Button_10", imgPageBg, btnAdIndicator[E_choujiang])
		UIGet_Button("Button_10_0", imgPageBg, btnAdIndicator[E_recharge])
		UIGet_Button("Button_10_1", imgPageBg, btnAdIndicator[E_myCup])

		Layout  *panel1, *panel2, *panel3;
	UIGet_Layout("Panel_1", pgAd, panel1)
		UIGet_Layout("Panel_2", pgAd, panel2)
		UIGet_Layout("Panel_3", pgAd, panel3)
		UIGet_Button("Button_1", panel1, btnAd[E_choujiang])
		UIGet_Button("Button_1_0", panel2, btnAd[E_recharge])
		UIGet_Button("Button_1_1", panel3, btnAd[E_myCup])

		btnAd[E_choujiang]->setTag(E_choujiang);
	    btnAd[E_recharge]->setTag(E_recharge);
	    btnAd[E_myCup]->setTag(E_myCup);
		UIClick(btnAd[E_choujiang], LobbyView::callAdselect)
			UIClick(btnAd[E_recharge], LobbyView::callAdselect)
			UIClick(btnAd[E_myCup], LobbyView::callAdselect)

		schedule(schedule_selector(LobbyView::adUpdate), 5.0f);

		fastBtnAction = CSLoader::createTimeline("fastStart.csb");
		rootNode->runAction(fastBtnAction);
		fastBtnAction->gotoFrameAndPlay(0, true);


		
}

UIEnableClick(mBtnTask, LobbyView, enableBtnTask)
UIEnableClick(mBtnSignature, LobbyView, enableBtnSignature)
UIEnableClick(mBtnSetting, LobbyView, enableBtnSetting)
UIEnableClick(mBtnPlayGold, LobbyView, enableBtnPlayGold)
UIEnableClick(mBtnEntertainment, LobbyView, enableBtnEntertainment)
UIEnableClick(mBtnMatch, LobbyView, enableBtnMatch)
UIEnableClick(mBtnBlood, LobbyView, enableBtnBlood)
UIEnableClick(mBtnFast, LobbyView, enableBtnFast)
UIEnableClick(mBtnCharge, LobbyView, enableBtnCharge)
UIEnableClick(mBtnShop, LobbyView, enableBtnShop)
UIEnableClick(mBtnActivity, LobbyView, enableBtnActivity)
UIEnableClick(mBtnPackage, LobbyView, enableBtnPackage)
UIEnableClick(mBtnHead, LobbyView, enableBtnHead)
UIEnableClick(mBtnAddWealth, LobbyView, enableBtnAddWealth)
UIEnableClick(mBtnAddDiamond, LobbyView, enableBtnAddDiamond)
UIEnableClick(mBtnFriend, LobbyView, enableBtnFriend)

void LobbyView::clickBtnTask(Ref* psender)
{
	UIDisableClick(mBtnTask, LobbyView, enableBtnTask)
		creatView(new DailyMissionView(), new DailyMissionMediator());
}

void LobbyView::clickBtnSignature(Ref* psender)
{
	UIDisableClick(mBtnSignature, LobbyView, enableBtnSignature)
		creatView(new SevenDayGiftView(), new SevenDayGiftMediator());
}

void LobbyView::clickBtnSetting(Ref* psender)
{
	UIDisableClick(mBtnSetting, LobbyView, enableBtnSetting)
		creatView(new SetView(), new SetMediator());
}

void LobbyView::clickBtnPlayGold(Ref* psender)
{
	UIDisableClick(mBtnPlayGold, LobbyView, enableBtnPlayGold)
		creatView(new PlayGoldView(), new PlayGoldMediator());

}

void LobbyView::clickBtnEntertainment(Ref* psender)
{
	UIDisableClick(mBtnEntertainment, LobbyView, enableBtnEntertainment)
		creatView(new EntertainmentView(), new EntertainmentMediator());
}

void LobbyView::clickBtnMatch(Ref* psender)
{
	UIDisableClick(mBtnMatch, LobbyView, enableBtnMatch)
		DATA->bGameCate = DataManager::E_GameCateMatch;
	creatView(new MatchView(), new MatchMediator());
}

void LobbyView::clickBtnBlood(Ref* psender)
{
	UIDisableClick(mBtnBlood, LobbyView, enableBtnBlood)
		DATA->bGameCate = DataManager::E_GameBlood;
		creatView(new BloodView(), new BloodMediator());
}

void LobbyView::clickBtnFast(Ref* psender)
{
	UIDisableClick(mBtnFast, LobbyView, enableBtnFast)
		DATA->bGameCate = DataManager::E_GameCateNormal;
	SCORE golds = DATA->myBaseData.lUserScore;

	int cof = 80;  
	if (golds <= 500)
	{
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		return;
	}
	else if (golds > 500 && golds * cof / 100 <= 2000)
	{
		DATA->bGameCateSub = 0;
		blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);

	}
	else if (golds * cof / 100 > 2000 && golds * cof / 100 <= 10000)
	{
		DATA->bGameCateSub = 1;
		blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);

	}
	else if (golds * cof / 100 > 10000)
	{
		DATA->bGameCateSub = 2;
		blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);

	}
}

void LobbyView::clickBtnCharge(Ref* psender)
{
	UIDisableClick(mBtnCharge, LobbyView, enableBtnCharge)
		creatView(new ShopView(0), new ShopMediator());   //0 ： zuanshi
}

void LobbyView::clickBtnShop(Ref* psender)
{
	UIDisableClick(mBtnShop, LobbyView, enableBtnShop)
		creatView(new MallView(), new MallMediator());
}


void LobbyView::clickBtnActivity(Ref* psender)
{
	UIDisableClick(mBtnActivity, LobbyView, enableBtnActivity)
		creatView(new ActivityView(), new ActivityMediator());
}

void LobbyView::clickBtnPackage(Ref* psender)
{
	UIDisableClick(mBtnPackage, LobbyView, enableBtnPackage)
		creatView(new PackageView(), new PackageMediator());
}

void LobbyView::clickBtnHead(Ref* psender)
{
	UIDisableClick(mBtnHead, LobbyView, enableBtnHead)
		creatView(new MyInfoView(), new MyInfoMediator());
}

void LobbyView::clickBtnAddWealth(Ref* psender)
{
	UIDisableClick(mBtnAddWealth, LobbyView, enableBtnAddWealth)
		creatView(new ShopView(1), new ShopMediator());
}

void LobbyView::clickBtnAddDiamond(Ref* psender)
{
	UIDisableClick(mBtnAddDiamond, LobbyView, enableBtnAddDiamond)
		creatView(new ShopView(0), new ShopMediator());
}

void LobbyView::clickBtnFriend(Ref* psender)
{
	UIDisableClick(mBtnFriend, LobbyView, enableBtnFriend)
		creatView(new FriendView(), new FriendMediator());

}

void LobbyView::adUpdate(float dt)
{
	currentAd++; 
	if (currentAd < E_adMax)
	{
		pgAd->scrollToPage(currentAd);
		
	}
	else if (currentAd == E_adMax)
	{
		currentAd = E_choujiang;
		pgAd->setCurPageIndex(E_choujiang);
	}
	for (int i = 0; i < E_adMax; i ++)
	{
		btnAdIndicator[i]->setEnabled(false);
	}
	btnAdIndicator[currentAd]->setEnabled(true);
	
}

void LobbyView::callAdselect(Ref* psender)
{
	Button* btnClicked = static_cast<Button*>(psender);
	int tags = btnClicked->getTag();
	creatView(new ActivityView(tags), new ActivityMediator());


}

void LobbyView::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		break;
	case Widget::TouchEventType::MOVED:	
		break;
	case Widget::TouchEventType::ENDED:
		break;
	case Widget::TouchEventType::CANCELED:		
		break;
	default:
		break;
	}
}

void LobbyView::runBtnAction(float dt)
{

}

void LobbyView::stopBtnAction(float dt)
{

}

//显示个人头像
void LobbyView::showHeadImage(int index)
{
	ImageView* image1 = dynamic_cast<ImageView*>(headNode->getChildByName("character_1"));
	ImageView* image2 = dynamic_cast<ImageView*>(headNode->getChildByName("character_2"));
	ImageView* image3 = dynamic_cast<ImageView*>(headNode->getChildByName("character_3"));
	ImageView* image4 = dynamic_cast<ImageView*>(headNode->getChildByName("character_4"));
	image1->setVisible(false);
	image2->setVisible(false);
	image3->setVisible(false);
	image4->setVisible(false);
	switch (index)
	{
	case 1:
		image1->setVisible(true);
		break;
	case 2:
		image2->setVisible(true);
		break;
	case 3:
		image3->setVisible(true);
		break;
	case 4:
		image4->setVisible(true);
		break;
	}
}

//显示金币数量
void LobbyView::showGold(int gold)
{
	txtGold->setString(Tools::parseInt2String(gold));
}

//
void LobbyView::ScrollEvent(Ref* target, ScrollviewEventType type)
{
	switch (type)
	{
		case ScrollviewEventType::SCROLLVIEW_EVENT_BOUNCE_RIGHT:
			rightImage1->setVisible(false);
			rightImage2->setVisible(false);
			leftImage1->setVisible(true);
			leftImage2->setVisible(false);
			break;
		case ScrollviewEventType::SCROLLVIEW_EVENT_BOUNCE_LEFT:
			//if (ScrollView_1->getInnerContainerPosition().x > 0)
			//{
				//leftImage1->setVisible(false);
				//leftImage2->setVisible(true);
			//}
			//else
			//{
				leftImage1->setVisible(false);
				leftImage2->setVisible(false);
			//}
			rightImage1->setVisible(true);
			rightImage2->setVisible(false);
			break;
		case ScrollviewEventType::SCROLLVIEW_EVENT_SCROLLING:
			rightImage1->setVisible(true);
			rightImage2->setVisible(false);
			leftImage1->setVisible(true);
			leftImage2->setVisible(false);
			break;
	}

}