#include "SevenDayGiftView.h"

SevenDayGiftView::SevenDayGiftView()
{
	rootNode = CSLoader::createNode("sevenDayGift.csb");
	addChild(rootNode);
	//rootNode->setScale(0.1, 0.1);
	//rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.1), ScaleTo::create(0.1f, 1.0f), nullptr));
	BTN_ADD_TOUCH_EVENTLISTENER(Button, SevenDayGiftView, getGiftBtn, 10901, "getGiftBtn", NULL)
		BTN_ADD_TOUCH_EVENTLISTENER(Button, SevenDayGiftView, closeBtn, 10902, "closeBtn", NULL)
		BTN_ADD_TOUCH_EVENTLISTENER(ImageView, SevenDayGiftView, Image_38, 10902, "Image_38", NULL)
}

SevenDayGiftView::~SevenDayGiftView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(SevenDayGiftView, getGiftBtn, 10901);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SevenDayGiftView, closeBtn, 10902);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SevenDayGiftView, Image_38, 10902);

	delete rootNode;
	rootNode = NULL;
}

void SevenDayGiftView::initView(bool isShowCloseBtn)
{
	_closeBtn->setVisible(isShowCloseBtn);

	//第一天
	day1_1 = dynamic_cast<ImageView*>(rootNode->getChildByName("day1_1"));
	day1_2 = dynamic_cast<ImageView*>(rootNode->getChildByName("day1_2"));
	day1_3 = dynamic_cast<ImageView*>(rootNode->getChildByName("day1_3"));

	//第2天
	day2_1 = dynamic_cast<ImageView*>(rootNode->getChildByName("day2_1"));
	day2_2 = dynamic_cast<ImageView*>(rootNode->getChildByName("day2_2"));
	day2_3 = dynamic_cast<ImageView*>(rootNode->getChildByName("day2_3"));

	//第3天
	day3_1 = dynamic_cast<ImageView*>(rootNode->getChildByName("day3_1"));
	day3_2 = dynamic_cast<ImageView*>(rootNode->getChildByName("day3_2"));
	day3_3 = dynamic_cast<ImageView*>(rootNode->getChildByName("day3_3"));

	//第4天
	day4_1 = dynamic_cast<ImageView*>(rootNode->getChildByName("day4_1"));
	day4_2 = dynamic_cast<ImageView*>(rootNode->getChildByName("day4_2"));
	day4_3 = dynamic_cast<ImageView*>(rootNode->getChildByName("day4_3"));

	//第5天
	day5_1 = dynamic_cast<ImageView*>(rootNode->getChildByName("day5_1"));
	day5_2 = dynamic_cast<ImageView*>(rootNode->getChildByName("day5_2"));
	day5_3 = dynamic_cast<ImageView*>(rootNode->getChildByName("day5_3"));

	//第6天
	day6_1 = dynamic_cast<ImageView*>(rootNode->getChildByName("day6_1"));
	day6_2 = dynamic_cast<ImageView*>(rootNode->getChildByName("day6_2"));
	day6_3 = dynamic_cast<ImageView*>(rootNode->getChildByName("day6_3"));

	//第7天
	day7_1 = dynamic_cast<ImageView*>(rootNode->getChildByName("day7_1"));
	day7_2 = dynamic_cast<ImageView*>(rootNode->getChildByName("day7_2"));
	day7_3 = dynamic_cast<ImageView*>(rootNode->getChildByName("day7_3"));

	//领取奖励
	getGiftBtn = dynamic_cast<Button*>(rootNode->getChildByName("getGiftBtn"));

	//明日再来领取
	noGiftImage1 = dynamic_cast<ImageView*>(rootNode->getChildByName("noGiftImage1"));
	noGiftImage2 = dynamic_cast<ImageView*>(rootNode->getChildByName("noGiftImage2"));

	//
	showGift();
}

//显示奖励领取情况
void SevenDayGiftView::showGift()
{
	switch (nowDay % 7)
	{
	case 1:
		//showDay1Gift(!canGetGiftToday);
		showDay1Gift(true);
		showDay2Gift(false);
		showDay3Gift(false);
		showDay4Gift(false);
		showDay5Gift(false);
		showDay6Gift(false);
		showDay7Gift(false);
		break;
	case 2:
		showDay1Gift(true);
		//showDay2Gift(!canGetGiftToday);
		showDay2Gift(true);
		showDay3Gift(false);
		showDay4Gift(false);
		showDay5Gift(false);
		showDay6Gift(false);
		showDay7Gift(false);
		break;
	case 3:
		showDay1Gift(true);
		showDay2Gift(true);
		//showDay3Gift(!canGetGiftToday);
		showDay3Gift(true);
		showDay4Gift(false);
		showDay5Gift(false);
		showDay6Gift(false);
		showDay7Gift(false);
		break;
	case 4:
		showDay1Gift(true);
		showDay2Gift(true);
		showDay3Gift(true);
		//showDay4Gift(!canGetGiftToday);
		showDay4Gift(true);
		showDay5Gift(false);
		showDay6Gift(false);
		showDay7Gift(false);
		break;
	case 5:
		showDay1Gift(true);
		showDay2Gift(true);
		showDay3Gift(true);
		showDay4Gift(true);
		//showDay5Gift(!canGetGiftToday);
		showDay5Gift(true);
		showDay6Gift(false);
		showDay7Gift(false);
		break;
	case 6:
		showDay1Gift(true);
		showDay2Gift(true);
		showDay3Gift(true);
		showDay4Gift(true);
		showDay5Gift(true);
		//showDay6Gift(!canGetGiftToday);
		showDay6Gift(true);
		showDay7Gift(false);
		break;
	case 0:
		showDay1Gift(true);
		showDay2Gift(true);
		showDay3Gift(true);
		showDay4Gift(true);
		showDay5Gift(true);
		showDay6Gift(true);
		//showDay7Gift(!canGetGiftToday);
		showDay7Gift(true);
		break;
	}
	//getGiftBtn->setVisible(canGetGiftToday);
	//noGiftImage1->setVisible(!canGetGiftToday);
	//noGiftImage2->setVisible(!canGetGiftToday);
	getGiftBtn->setVisible(false);
	noGiftImage1->setVisible(true);
	noGiftImage2->setVisible(true);
}

void SevenDayGiftView::showDay1Gift(bool isGet)
{
	day1_1->setVisible(!isGet);
	day1_2->setVisible(isGet);
	day1_3->setVisible(isGet);
}

void SevenDayGiftView::showDay2Gift(bool isGet)
{
	day2_1->setVisible(!isGet);
	day2_2->setVisible(isGet);
	day2_3->setVisible(isGet);
}

void SevenDayGiftView::showDay3Gift(bool isGet)
{
	day3_1->setVisible(!isGet);
	day3_2->setVisible(isGet);
	day3_3->setVisible(isGet);
}

void SevenDayGiftView::showDay4Gift(bool isGet)
{
	day4_1->setVisible(!isGet);
	day4_2->setVisible(isGet);
	day4_3->setVisible(isGet);
}

void SevenDayGiftView::showDay5Gift(bool isGet)
{
	day5_1->setVisible(!isGet);
	day5_2->setVisible(isGet);
	day5_3->setVisible(isGet);
}

void SevenDayGiftView::showDay6Gift(bool isGet)
{
	day6_1->setVisible(!isGet);
	day6_2->setVisible(isGet);
	day6_3->setVisible(isGet);
}

void SevenDayGiftView::showDay7Gift(bool isGet)
{
	day7_1->setVisible(!isGet);
	day7_2->setVisible(isGet);
	day7_3->setVisible(isGet);
}