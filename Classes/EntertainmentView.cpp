#include "EntertainmentView.h"
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

EntertainmentView::EntertainmentView()
{

}

EntertainmentView::~EntertainmentView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(EntertainmentView, closeBtn, 12700);
	rootNode->stopAllActions();
	delete rootNode;
	rootNode = NULL;
}

void EntertainmentView::initView()
{
	SEND->sendFriendReq(DATA->myBaseData.dwUserID);
	rootNode = CSLoader::createNode("entertainment.csb");
	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	this->addChild(rootNode);
	
	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("entertainment.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);



	BTN_ADD_TOUCH_EVENTLISTENER(Button, EntertainmentView, closeBtn, 12700, "Button_close", "Image_frame")
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, EntertainmentView, imgBg, 12700, "Image_bg", NULL)

		UIGet_ImageView("Image_frame", rootNode, imgFrame)
		UIGet_Button("Button_0", imgFrame, btn0)
		UIGet_Button("Button_1", imgFrame, btn1)
		UIGet_Button("Button_2", imgFrame, btn2)




		btn0->setTag(0);  //ºÃÓÑ³¡
	btn1->setTag(1);
	btn2->setTag(2);
	UIClick(btn0, EntertainmentView::clickPlay)
		UIClick(btn1, EntertainmentView::clickPlay)
		UIClick(btn2, EntertainmentView::clickPlay)



}

void EntertainmentView::clickPlay(Ref* pSender)
{
	PLayEffect(EFFECT_BTN);
	Button*  btn = static_cast<Button*>(pSender);
	int tags = btn->getTag();
	long long golds = DATA->myBaseData.lUserScore;
	switch (tags)
	{
	case 0:

		if (golds < 3000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			DATA->bGameCate = DataManager::E_GameFriend;
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);
			blueSkyDispatchEvent(EventType::FRIEND_PLAY);
		}
		break;

	case 1:
		if (golds < 3000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			DATA->bGameCate = DataManager::E_GameTeam;
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);
		}
		break;
	case 2:
		if (golds < 2000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			DATA->bGameCate = DataManager::E_GameRandZhupai;
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE);
		}
		break;



	default:
		break;
	}


}