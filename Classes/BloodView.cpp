#include "BloodView.h"
#include "UTF8.h"
#include "SGTools.h"
#include "DataManager.h"
#include "ShopMediator.h"
#include "ShopView.h"
#include "SetMediator.h"
#include "SetView.h"
#include "ViewManager.h"
#include "EventType.h"
#include "GameDataModel.h"
#include "PlayerInDeskModel.h"

BloodView::BloodView()
{

}

BloodView::~BloodView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(BloodView, closeBtn, 12800);
	rootNode->stopAllActions();
	delete rootNode;
	rootNode = NULL;
}

void BloodView::initView()
{
	rootNode = CSLoader::createNode("blood.csb");
	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	this->addChild(rootNode);

	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("blood.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);

	BTN_ADD_TOUCH_EVENTLISTENER(Button, BloodView, closeBtn, 12800, "Button_close", "Image_frame")
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, BloodView, imgBg, 12800, "Image_bg", NULL)

		UIGet_ImageView("Image_frame", rootNode, imgFrame)
		UIGet_Button("Button_1", imgFrame, btn1)
		UIGet_Button("Button_2", imgFrame, btn2)
		UIGet_Button("Button_3", imgFrame, btn3)

		btn1->setTag(0);
	btn2->setTag(1);
	btn3->setTag(2);
	UIClick(btn1, BloodView::clickPlay)
		UIClick(btn2, BloodView::clickPlay)
		UIClick(btn3, BloodView::clickPlay)

}

void BloodView::clickPlay(Ref* pSender)
{
	PLayEffect(EFFECT_BTN);
	Button*  btn = static_cast<Button*>(pSender);
	int tags = btn->getTag();
	long long golds = DATA->myBaseData.lUserScore;
	DATA->bGameCate = DataManager::E_GameBlood;
	switch (tags)
	{
	case 0:

		if (golds < 20000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			DATA->bGameCateSub = 0;
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);
		}
		break;
	case 1:
		if (golds < 50000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			DATA->bGameCateSub = 1;
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);
		}
		break;
	case 2:
		if (golds < 100000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			DATA->bGameCateSub = 2;
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);


		}
		break;
	default:
		break;
	}


}