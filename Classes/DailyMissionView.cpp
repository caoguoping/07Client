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




	canShowGetBtn = showGetBtn;
}

DailyMissionView::~DailyMissionView()
{
	rootNode->stopAllActions();
}

void DailyMissionView::initView()
{
	UIGet_Sprite("ImageFrame", rootNode, imgFrame)
		UIGet_ScrollView("ScrollView_1", imgFrame, scrImg)

		UIGet_Button("closeBtn",   imgFrame, closeBtn)
		UIGet_ImageView("Image_38", rootNode, Image_38)
		BTN_EVENT(closeBtn, 11007)
		BTN_EVENT(Image_38, 11007)

		//压住playerInfo
		Image_38->setGlobalZOrder(GOrderPlayerHead + 2);
	closeBtn->setGlobalZOrder(GOrderPlayerHead + 2);

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

				//压住playerInfo
				btnGet[i]->setGlobalZOrder(GOrderPlayerHead + 2);
			imgBlack[i]->setGlobalZOrder(GOrderPlayerHead + 2);
			btnGoto[i]->setGlobalZOrder(GOrderPlayerHead + 2);
			txtNowNum[i]->setGlobalZOrder(GOrderPlayerHead + 2);
			txtNeetNum[i]->setGlobalZOrder(GOrderPlayerHead + 2);
			txtNumLian[i]->setGlobalZOrder(GOrderPlayerHead + 2);

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
			btnGoto[dailyMisInfo[i].wMissionId - 1]->setVisible(true);
			btnGet[dailyMisInfo[i].wMissionId - 1]->setVisible(false);

		}
		else if (dailyMisInfo[i].Receive == 0)
		{
			//已完成没有领取
			btnGoto[dailyMisInfo[i].wMissionId - 1]->setVisible(false);
			btnGet[dailyMisInfo[i].wMissionId - 1]->setVisible(true);
		}
		else
		{
			//已经领取
			btnGoto[dailyMisInfo[i].wMissionId - 1]->setVisible(false);
			btnGet[dailyMisInfo[i].wMissionId - 1]->setVisible(false);
			txtNowNum[dailyMisInfo[i].wMissionId - 1]->setVisible(false);
			txtNeetNum[dailyMisInfo[i].wMissionId - 1]->setVisible(false);
			txtNumLian[dailyMisInfo[i].wMissionId - 1]->setVisible(false);
			imgBlack[dailyMisInfo[i].wMissionId - 1]->setVisible(true);
		}
	}
}

void DailyMissionView::clickGetBtn(Ref *pSender)
{
	PLayEffect(EFFECT_BTN)
	Button* tempB = static_cast<Button*>(pSender);
	int index = tempB->getTag();

	DBR_GR_UserLogonMissionRes info = dailyMisInfo[index];
	DWORD dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendGetMisAward(dwUserID, index + 1, info.wKindId);

}


void DailyMissionView::clickGotoBtn(Ref *pSender)
{
	PLayEffect(EFFECT_BTN)
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

