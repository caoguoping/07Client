#include "ActivityView.h"
#include "DataManager.h"
#include "SendDataService.h"
#include "DataManager.h"
#include "SGTools.h"
#include "GameDataModel.h"
#include <sstream>

ActivityView::ActivityView(int actIndex)
{
	//std::srand(unsigned int(time(NULL)));
	rootNode = CSLoader::createNode("activity.csb");
	addChild(rootNode);

	;
	unsigned long dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendGetRank(dwUserID);


	//rootNode->setScale(0.1f, 0.1f);
	//rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.03), ScaleTo::create(0.1f, 1.0f), nullptr));

	myGold = static_cast<TextBMFont*>(rootNode->getChildByName("BitmapFontLabel_gold"));
	myZuanshi = static_cast<TextBMFont*>(rootNode->getChildByName("BitmapFontLabel_zuanshi"));

	actScrow = static_cast<PageView*>(rootNode->getChildByName("PageView_1"));
	mallItem[E_activity] = (actScrow->getChildByName("Panel_1"))->getChildByName("lotteryNode");
	mallItem[E_zuanshi] = (actScrow->getChildByName("Panel_2"))->getChildByName("rechargeNode");
	mallItem[E_myCup] = (actScrow->getChildByName("Panel_3"))->getChildByName("FileNode_myCup");


	spineIner = static_cast<Sprite*>(mallItem[E_activity]->getChildByName("spin_inner"));

	BTN_ADD_TOUCH_EVENTLISTENER(Button,ActivityView, closeBtn, 15001, "closeBtn", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, ActivityView, lotteryBtn, 15002, "lotteryBtn", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, ActivityView, rechargeBtn, 15003, "rechargeBtn", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, ActivityView, myCupBtn, 15010, "CheckBox_1", NULL);

	textZuanshi = static_cast<TextBMFont*>(mallItem[E_activity]->getChildByName("BitmapFontLabel_needZuan"));


	unsigned short count = DATA->chouJiangTime;
	unsigned short diamand = DATA->diamondNum;
	if (count == 0)
	{
		needZuanshi = 0;
	}
	else
	{
		needZuanshi = 20 + (count - 1) * 10;
	}


	char temp[12];
	sprintf(temp, "%d", needZuanshi);

	textZuanshi->setString(temp);

	//ת�̳齱
	Button* spinBtn = static_cast<Button*>(mallItem[E_activity]->getChildByName("Button_choujiang"));

	spinBtn->addClickEventListener(CC_CALLBACK_1(ActivityView::getSpin, this));

	currentTitle = actIndex;


	schedule(schedule_selector(ActivityView::updateTitle), 0.3f);

	UIGet_ScrollView("ScrollView_growth", mallItem[E_myCup], growthScroll);
	UIGet_ListView("ListView_rank", mallItem[E_myCup], rankList);
	UIGet_CheckBox("CheckBox_growth", mallItem[E_myCup], growthCheckBox);
	UIGet_CheckBox("CheckBox_rank", mallItem[E_myCup], rankCheckBox);
	UIGet_Text("Text_nowLevel", mallItem[E_myCup], txtMyLevel)
		UIGet_Text("Text_nowExp", mallItem[E_myCup], txtMyExp)
		UIGet_Text("Text_levelUpExp", mallItem[E_myCup], txtLevelUpExp)
		UIGet_LoadingBar("LoadingBar_exp", mallItem[E_myCup], loadingExp)

	UIClick(growthCheckBox, ActivityView::clickGrowth)
	UIClick(rankCheckBox, ActivityView::clickRank)

	ImageView* imgView1;
	std::string viewname = "Image_";

	for (int i = 0; i < 5; i++)
	{
		std::ostringstream osstr;
		osstr << viewname << i;

		UIGet_ImageView(osstr.str(), growthScroll, imgView1)
		UIGet_Text("Text_cannot", imgView1, txtCannot[i])
		UIGet_Button("Button_get", imgView1, btnGetGrowth[i])

		UIClick(btnGetGrowth[i], ActivityView::clickGetGrowth)

		btnGetGrowth[i]->setTag(i);
	}


		//clickGrowth(NULL);	

	switch (actIndex)
	{
		case 0:
			actScrow->setCurrentPageIndex(0);
			showLottery();
			break;
		case 1:
			actScrow->setCurrentPageIndex(1);
			showRecharge();
			break;
		case 2:
			actScrow->setCurrentPageIndex(2);
			showMyCup();
			break;
		default:
			break;
	}


	UIGet_Text("Text_54_3", mallItem[E_myCup], timesDay)
		UIGet_Text("Text_54_4", mallItem[E_myCup], timesHour)
		UIGet_Text("Text_54_5", mallItem[E_myCup], timesMin)
		UIGet_Text("Text_54_6", mallItem[E_myCup], timesSec)
	
}

ActivityView::~ActivityView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(ActivityView, closeBtn, 15001);
	BTN_REMOVE_TOUCH_EVENTLISTENER(ActivityView, lotteryBtn, 15002);
	BTN_REMOVE_TOUCH_EVENTLISTENER(ActivityView, rechargeBtn, 15003);
	BTN_REMOVE_TOUCH_EVENTLISTENER(ActivityView, myCupBtn, 15010);
//	BTN_REMOVE_TOUCH_EVENTLISTENER(ActivityView, Button_1, 99999);

	delete rootNode;	
	rootNode = NULL;
}


void ActivityView::getSpinReward()
{
	unsigned short count = DATA->chouJiangTime;
	unsigned short diamand = DATA->diamondNum;

	if (count == 0)
	{
		needZuanshi = 0;
	}
	else
	{
		needZuanshi = 20 + (count - 1) * 10;
	}

	char temp[12];
	sprintf(temp, "%d", needZuanshi);

	textZuanshi->setString(temp);
	DATA->myBaseData.rmb = diamand;
	updateInfo();
}

void ActivityView::setTimes(float dt)
{
	//�ݶ����7��
	unsigned int openTime = DATA->myRankInfo.openTime;
	time_t nowTime = time(NULL);
	time_t leftTime = 7 * 24 * 60 * 60 + openTime - nowTime;
	
	int day, hour, min, sec;
	day = leftTime / (3600 * 24);
	hour = (leftTime % (3600 * 24)) / 3600;
	min = (leftTime - (day * 24 + hour) * 3600) / 60;
	sec = leftTime - (day * 24 + hour) * 3600 - min * 60;

	timesDay->setString(Tools::parseInt2String(day));
	timesHour->setString(Tools::parseInt2String(hour));
	timesMin->setString(Tools::parseInt2String(min));
	timesSec->setString(Tools::parseInt2String(sec));

}



void ActivityView::updateInfo()
{
	;
	showMyGold(DATA->myBaseData.lUserScore);
	showMyZuanShi(DATA->myBaseData.rmb);
}



void ActivityView::clickGetGrowth(Ref* psender)
{
	//myRankInfo = new CMD_GP_CupInfo();
	Button* tempB = static_cast<Button*>(psender);
	if (!tempB)
		return;
	;
	unsigned long dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendGetGrowth(dwUserID, (tempB->getTag()+1));
	btnGetGrowth[0]->setEnabled(false);
}

void ActivityView::clickGrowth(Ref* psender)
{
	growthCheckBox->setSelected(true);
	rankCheckBox->setSelected(false);

	growthCheckBox->setTouchEnabled(false);
	rankCheckBox->setTouchEnabled(true);

	growthScroll->setVisible(true);
	rankList->setVisible(false);
}

void ActivityView::clickRank(Ref* psender)
{
	growthCheckBox->setSelected(false);
	rankCheckBox->setSelected(true);

	growthCheckBox->setTouchEnabled(true);
	rankCheckBox->setTouchEnabled(false);

	growthScroll->setVisible(false);
	rankList->setVisible(true);

	rankList->removeAllChildrenWithCleanup(true);
	tagCupRankingInfos rankInfo =  DATA->myRankInfo.rankingInfo;
	unsigned int num = rankInfo.dwNum;

#define RANK_ITEM_HEIGHT 65
	rankList->setItemsMargin(RANK_ITEM_HEIGHT + 10 );

	for (int i = 0; i < num; i++)
	{
		Node* rankNode = CSLoader::createNode("rankNode.csb");
		Layout*  oneRank = Layout::create();
		oneRank->addChild(rankNode);
		rankNode->setPosition(Vec2(200, -RANK_ITEM_HEIGHT * 0.5));
		Text  *rank, *name, *exp;
		ImageView*  head;
		UIGet_Text("Text_rank", rankNode, rank)
			UIGet_Text("Text_name", rankNode, name)
			UIGet_Text("Text_exp", rankNode, exp)
			UIGet_ImageView("Image_head", rankNode, head)
		rank->setString(Tools::parseInt2String(i + 1));
		name->setString(rankInfo.dwRankingInfos[i].szNickName);
		exp->setString(Tools::parseInt2String(rankInfo.dwRankingInfos[i].cExp));
		rankList->pushBackCustomItem(oneRank);

		char headName[64];
		sprintf(headName, "headshot_%d_s.png", rankInfo.dwRankingInfos[i].faceId);
		head->loadTexture(headName);
	}

	Layout*   layoutFate = Layout::create();
	rankList->pushBackCustomItem(layoutFate);
}


void ActivityView::startLottery()
{


	;
	showMyGold(DATA->myBaseData.lUserScore);
	showMyZuanShi(DATA->diamondNum);
	unsigned long dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendGambling(dwUserID, 0, wpIndex);
}

void ActivityView::getSpin(Ref* psender)
{
	wpIndex = int(rand_0_1() * 8) + 1;
	SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");

	if (DATA->myBaseData.rmb < needZuanshi)
	{
		//��ʯ����
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
		blueSkyDispatchEvent(11201);
	}
	else
	{
		spineIner->setRotation(0);
		ActionInterval* rot = RotateBy::create(3.0f + 0.2 * wpIndex, 1080 - 45 * (wpIndex - 1));

		auto act = Sequence::create(
			EaseInOut::create(rot, 3.0f),
			CallFunc::create(CC_CALLBACK_0(ActivityView::startLottery, this)),
			NULL
			);
		spineIner->runAction(act);

		blueSkyDispatchEvent(20050);

	}

}

void ActivityView::initView()
{

}

void ActivityView::showMyZuanShi(int num)
{
	char temp[16];
	sprintf(temp, "%d", num);
	myZuanshi->setString(temp);
}
void ActivityView::showMyGold(int num)
{
	char temp[16];
	sprintf(temp, "%d", num);
	myGold->setString(temp);
}

void ActivityView::updateTitle(float dt)
{
	ssize_t index = actScrow->getCurrentPageIndex();
	if (index == currentTitle)
	{
		return;
	}
	else
	{
		currentTitle = index;
		switch (index)
		{
		case E_activity:
			_lotteryBtn->setSelected(true);
			_rechargeBtn->setSelected(false);
			_myCupBtn->setSelected(false);

			_lotteryBtn->setTouchEnabled(false);
			_rechargeBtn->setTouchEnabled(true);
			_myCupBtn->setTouchEnabled(true);

			break;

		case E_zuanshi:

			_lotteryBtn->setSelected(false);
			_rechargeBtn->setSelected(true);
			_myCupBtn->setSelected(false);

			_lotteryBtn->setTouchEnabled(true);
			_rechargeBtn->setTouchEnabled(false);
			_myCupBtn->setTouchEnabled(true);
			break;

		case E_myCup:

			_lotteryBtn->setSelected(false);
			_rechargeBtn->setSelected(false);
			_myCupBtn->setSelected(true);

			_lotteryBtn->setTouchEnabled(true);
			_rechargeBtn->setTouchEnabled(true);
			_myCupBtn->setTouchEnabled(false);
			break;

		default:
			break;
		}
	}

}

void ActivityView::showLottery()
{
	_lotteryBtn->setSelected(true);
	_rechargeBtn->setSelected(false);
	_myCupBtn->setSelected(false);

	_lotteryBtn->setTouchEnabled(false);
	_rechargeBtn->setTouchEnabled(true);
	_myCupBtn->setTouchEnabled(true);
	actScrow->scrollToPage(E_activity);

	char needZ[16];
	sprintf(needZ, "%d", needZuanshi);
	textZuanshi->setString(needZ);

}

void ActivityView::showRecharge()
{
	_lotteryBtn->setSelected(false);
	_rechargeBtn->setSelected(true);
	_myCupBtn->setSelected(false);

	_lotteryBtn->setTouchEnabled(true);
	_rechargeBtn->setTouchEnabled(false);
	_myCupBtn->setTouchEnabled(true);
	actScrow->scrollToPage(E_zuanshi);

}

void ActivityView::showMyCup()
{
	_lotteryBtn->setSelected(false);
	_rechargeBtn->setSelected(false);
	_myCupBtn->setSelected(true);

	_lotteryBtn->setTouchEnabled(true);
	_rechargeBtn->setTouchEnabled(true);
	_myCupBtn->setTouchEnabled(false);
	actScrow->scrollToPage(E_myCup);

	//����
// 	txtMyLevel->setString(Tools::parseInt2String(myRankInfo.cLevel));
	setLevelAndPercent(DATA->myRankInfo.cExp);
}


void ActivityView::showRechargeGift()
{

}

//
void ActivityView::clickGetBtn(Ref *pSender, int i)
{
	//isClicked = !isClicked;
	if (isClicked)
	{
		isClicked = false;
		this->scheduleOnce(schedule_selector(ActivityView::buyItem), 0.5f);
		blueSkyDispatchEvent(15005, new int(i));
	}
}

//
void ActivityView::buyItem(float dt)
{
	isClicked = true;
}

//
void ActivityView::showRechargeGiftState(Node* show, bool canGet,int index)
{
	getBtnArr.at(index)->setVisible(canGet);
	Text* text1 = dynamic_cast<Text*>(show->getChildByName("text1"));
	Text* numText = dynamic_cast<Text*>(show->getChildByName("numText"));
	
	text1->setVisible(!canGet);
	numText->setVisible(!canGet);
}

//
void ActivityView::showLotteryNum(int index)
{

}

void ActivityView::showLotteryGift(int index)
{

}

void ActivityView::setCupAwardsInfo(unsigned short awardsinfo, int cuplvl)
{
	if (cuplvl <= 0)
		return;
	int index = (cuplvl + 1) / 2;
	if (index > 5) index = 5;

	for (int i = 1; i <= index; i++)
	{
		txtCannot[i - 1]->setVisible(false);
		btnGetGrowth[i - 1]->setVisible(true);
		
		unsigned short temps = pow(10, (i - 1));
		if (awardsinfo / temps == 0)
		{
			//������ȡ
			btnGetGrowth[i - 1]->setEnabled(true);
		}
		else
		{
			btnGetGrowth[i - 1]->setEnabled(false);
		}

	}

}

int ActivityView::setLevelAndPercent (int totalExp)
{
	int myExp, levelUpExp, myLevl;
	if (totalExp < 100)
	{
		myExp = totalExp;
		levelUpExp = 100;
		myLevl = 0;
	} 
	else if (totalExp < 300)
	{
		myExp = totalExp - 100;
		levelUpExp = 300 - 100;
		myLevl = 1;
	}
	else if (totalExp < 600)
	{
		myExp = totalExp - 300;
		levelUpExp = 600 - 300;
		myLevl = 2;
	}
	else if (totalExp < 900)
	{
		myExp = totalExp - 600;
		levelUpExp = 900 - 600;
		myLevl = 3;
	}
	else if (totalExp < 1500)
	{
		myExp = totalExp - 900;
		levelUpExp = 1500 - 900;
		myLevl = 4;
	}
	else if (totalExp < 2000)
	{
		myExp = totalExp - 1500;
		levelUpExp = 2000 - 1500;
		myLevl = 5;
	}
	else if (totalExp < 3000)
	{
		myExp = totalExp - 2000;
		levelUpExp = 3000 - 2000 ;
		myLevl = 6;
	}
	else if (totalExp < 5000)
	{
		myExp =totalExp - 3000;
		levelUpExp = 5000 - 3000;
		myLevl = 7;
	}
	else if (totalExp < 8000)
	{
		myExp = totalExp - 5000;
		levelUpExp = 8000 - 5000;
		myLevl = 8;
	}
	else if (totalExp < 120000)
	{
		myExp = totalExp - 8000;
		levelUpExp = 120000 - 8000;
		myLevl = 9;
	}
	else if (totalExp < 160000)
	{
		myExp = totalExp - 120000;
		levelUpExp = 16000 - 120000;
		myLevl = 10;
	}
	else if (totalExp > 160000)
	{
		myExp = 160000;
		levelUpExp = 160000;
		myLevl = 11;
	}

	txtMyLevel->setString(Tools::parseInt2String(myLevl));
	txtMyExp->setString(Tools::parseInt2String(myExp));
	txtLevelUpExp->setString(Tools::parseInt2String(levelUpExp));
	loadingExp->setPercent(myExp * 100 / levelUpExp);
	log("cocos2d-x myLevel %d", myLevl);
	log("cocos2d-x myExp %d", myExp);

	unschedule(schedule_selector(ActivityView::setTimes));
	schedule(schedule_selector(ActivityView::setTimes), 1.0f);
	
	return myLevl;
}
