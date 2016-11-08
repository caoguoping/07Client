#include "PlayGoldView.h"
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



PlayGoldView::PlayGoldView()
{

}

PlayGoldView::~PlayGoldView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayGoldView, closeBtn, 12600);
	rootNode->stopAllActions();
	delete rootNode;
	rootNode = NULL;
}

void PlayGoldView::initView()
{
	rootNode = CSLoader::createNode("playGold.csb");
	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	this->addChild(rootNode);

	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("playGold.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);

	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayGoldView, closeBtn, 12600, "Button_close", "Image_frame");
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, PlayGoldView, imgBg, 12600, "Image_bg", NULL);

	UIGet_ImageView("Image_frame", rootNode, imgFrame)
		UIGet_Button("Button_1", imgFrame, btn1)
		UIGet_Button("Button_2", imgFrame, btn2)
		UIGet_Button("Button_3", imgFrame, btn3)



		btn1->setTag(0);
	btn2->setTag(1);
	btn3->setTag(2);
	UIClick(btn1, PlayGoldView::clickPlay)
		UIClick(btn2, PlayGoldView::clickPlay)
		UIClick(btn3, PlayGoldView::clickPlay)


}

void PlayGoldView::clickPlay(Ref* pSender)
{
	Button*  btn = static_cast<Button*>(pSender);
	int tags = btn->getTag();
	long long golds = DATA->myBaseData.lUserScore;
	DATA->bGameCate = DataManager::E_GameCateNormal;
	switch (tags)
	{
	case 0:

		if (golds < 500)
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
		if (golds < 2000)
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
		if (golds < 10000)
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