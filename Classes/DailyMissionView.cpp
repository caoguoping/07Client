#include "DailyMissionView.h"
#include "DataManager.h"
#include "SendDataService.h"
#include "SGTools.h"
#include "UTF8.h"
#include "ShopMediator.h"
#include "ShopView.h"
#include "FriendMediator.h"
#include "FriendView.h"
#include "ViewManager.h"


DailyMissionView::DailyMissionView(bool showGetBtn)
{
	rootNode = CSLoader::createNode("dailyMission.csb");
	addChild(rootNode);

	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("dailyMission.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);

	BTN_ADD_TOUCH_EVENTLISTENER(Button, DailyMissionView, closeBtn, 11007, "closeBtn", "ImageFrame")
		BTN_ADD_TOUCH_EVENTLISTENER(ImageView, DailyMissionView, Image_38, 11007, "Image_38", NULL);
	canShowGetBtn = showGetBtn;
}

DailyMissionView::~DailyMissionView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(DailyMissionView, closeBtn, 11007);
	BTN_REMOVE_TOUCH_EVENTLISTENER(DailyMissionView, Image_38, 11007);

	rootNode->stopAllActions();
	delete rootNode;
	rootNode = NULL;
}

void DailyMissionView::initView()
{
	UIGet_Sprite("ImageFrame", rootNode, imgFrame)
		UIGet_ScrollView("ScrollView_1", imgFrame, scrImg)

		char tempStr[64];
		for (int i = 0; i < 6; i ++)
		{
			sprintf(tempStr, "Image_normal%d", i);
			UIGet_ImageView(tempStr, scrImg,imgNormal[i])
			UIGet_Text("Text_now", imgNormal[i], txtNowNum[i])
			UIGet_Text("Text_need", imgNormal[i], txtNeetNum[i])
			UIGet_Text("Text_now_0", imgNormal[i], txtNumLian[i])
			UIGet_Button("Button_get", imgNormal[i], btnGet[i])
			UIGet_Button("Button_goto", imgNormal[i], btnGoto[i])
			UIGet_ImageView("Image_black", imgNormal[i], imgBlack[i])

			btnGet[i]->setTag(i);
			UIClick(btnGet[i], DailyMissionView::clickGetBtn);

			btnGoto[i]->setTag(i);
			UIClick(btnGoto[i], DailyMissionView::clickGotoBtn)

		}	

	 	showAllMission();


}

void DailyMissionView::showAllMission()
{
	int num = dailyMisInfo.size();
	if (num > 3) num = 3;

	for (int i = 0; i < 6; i++)
	{
		if (i>(num - 1)) break;

		txtNowNum[i]->setString(Tools::parseInt2String(dailyMisInfo[i].dwValue > 3 ? 3 : dailyMisInfo[i].dwValue));
		if (dailyMisInfo[i].Complete == 1)
		{
			//没有完成
			btnGoto[i]->setVisible(true);
			btnGet[i]->setVisible(false);

		}
		else if (dailyMisInfo[i].Receive == 0)
		{
			//已完成没有领取
			btnGoto[i]->setVisible(false);
			btnGet[i]->setVisible(true);
		}
		else
		{
			//已经领取
			btnGoto[i]->setVisible(false);
			btnGet[i]->setVisible(false);
			txtNowNum[i]->setVisible(false);
			txtNeetNum[i]->setVisible(false);
			txtNumLian[i]->setVisible(false);
			imgBlack[i]->setVisible(true);
		}
	}
}

void DailyMissionView::clickGetBtn(Ref *pSender)
{
	Button* tempB = static_cast<Button*>(pSender);
	if (!tempB)
		return;
	int index = tempB->getTag();
	if ((index < 0) && (index > dailyMisInfo.size()-1))
		return;

	DBR_GR_UserLogonMissionRes info = dailyMisInfo[index];
	DWORD dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendGetMisAward(dwUserID, info.wMissionId, info.wKindId);

}


void DailyMissionView::clickGotoBtn(Ref *pSender)
{
	//打牌中不能进去
	if (VIEW->nowViewTag == ViewManager::eViewGame)
	{
		blueSkyDispatchEvent(11007, NULL);
		return;
	}

	Button* tempB = static_cast<Button*>(pSender);
	int index = tempB->getTag();
	if ((index < 0) && (index > dailyMisInfo.size() - 1))
		return;
	SCORE golds = DATA->myBaseData.lUserScore;
	int cof = 80;
	switch (index)
	{
	case 0:
	case 1:
	case 2:
		//快速开始
		DATA->bGameCate = DataManager::E_GameCateNormal;
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
		blueSkyDispatchEvent(11007, NULL);
		break;
	case 3:
		creatView(new FriendView(), new FriendMediator());
		blueSkyDispatchEvent(11007, NULL);
		break;

	case 4:
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
		blueSkyDispatchEvent(11007, NULL);
		break;

	case 5:
		creatView(new ShopView(0), new ShopMediator());
		blueSkyDispatchEvent(11007, NULL);
		break;

	default: 
		break;
	}

}

