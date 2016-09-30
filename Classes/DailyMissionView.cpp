#include "DailyMissionView.h"
#include "DataManager.h"
#include "SendDataService.h"
#include "SGTools.h"
#include "UTF8.h"

DailyMissionView::DailyMissionView(bool showGetBtn)
{
	rootNode = CSLoader::createNode("dailyMission.csb");
	addChild(rootNode);
	//rootNode->setScale(0.1, 0.1);
	//rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.1), ScaleTo::create(0.2f, 1.0f), nullptr));
	BTN_ADD_TOUCH_EVENTLISTENER(Button, DailyMissionView, closeBtn, 11007, "closeBtn", NULL)
		BTN_ADD_TOUCH_EVENTLISTENER(ImageView, DailyMissionView, Image_38, 11007, "Image_38", NULL);
	canShowGetBtn = showGetBtn;
}

DailyMissionView::~DailyMissionView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(DailyMissionView, closeBtn, 11007);
	BTN_REMOVE_TOUCH_EVENTLISTENER(DailyMissionView, Image_38, 11007);

	delete rootNode;
	rootNode = NULL;
}

void DailyMissionView::initView()
{
	UIGet_ScrollView("ScrollView_1", rootNode, activityView)
		UIGet_Node("FileNode_1", activityView, taskNodes[0])
		UIGet_Node("FileNode_2", activityView, taskNodes[1])
		UIGet_Node("FileNode_3", activityView, taskNodes[2])
		UIGet_Node("FileNode_4", activityView, taskNodes[3])
		UIGet_Node("FileNode_5", activityView, taskNodes[4])
		UIGet_Node("FileNode_6", activityView, taskNodes[5])

		char tempStr[12];
		for (int i = 0; i < 6; i ++)
		{
			UIGet_Text("Text_description", taskNodes[i], txtDescrip[i])
			UIGet_Text("Text_reward", taskNodes[i], txtReward[i])
			UIGet_Text("Text_now", taskNodes[i], txtNowNum[i])
			UIGet_Text("Text_now_0", taskNodes[i], txtNowNum0[i])
			UIGet_Text("Text_need", taskNodes[i], txtNeetNum[i])
			UIGet_Button("Button_get", taskNodes[i], btnGet[i])
			UIGet_Button("Button_goto", taskNodes[i], btnGoto[i])
			UIGet_ImageView("Image_normal", taskNodes[i], imgNormal[i])
			UIGet_ImageView("Image_black", taskNodes[i], imgBlack[i])
			UIGet_ImageView("Image_receive", taskNodes[i], imgReceive[i])
			sprintf(tempStr, "%d", i + 1);
			txtDescrip[i]->setString(UTF8::getInstance()->getString("task", tempStr));

			btnGet[i]->setTag(i);
			UIClick(btnGet[i], DailyMissionView::clickGetBtn);

			btnGoto[i]->setTag(i);
			UIClick(btnGoto[i], DailyMissionView::clickGotoBtn)

		}	

	 	activityView->setScrollBarEnabled(false);
// 
// 	//显示全部任务完成情况
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
			txtNowNum0[i]->setVisible(false);
			imgBlack[i]->setVisible(true);
			imgReceive[i]->setVisible(true);
		}

	}
	
}

void DailyMissionView::showMission()
{
	
}

void DailyMissionView::clickGetBtn(Ref *pSender)
{
	//isClicked = !isClicked;
	Button* tempB = static_cast<Button*>(pSender);
	if (!tempB)
		return;

	int index = tempB->getTag();
	if ((index < 0) && (index > dailyMisInfo.size()-1))
		return;

	DBR_GR_UserLogonMissionRes info = dailyMisInfo[index];


	
	;
	unsigned long dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendGetMisAward(dwUserID, info.wMissionId, info.wKindId);

}


void DailyMissionView::clickGotoBtn(Ref *pSender)
{
	Button* tempB = static_cast<Button*>(pSender);
	int index = tempB->getTag();
	if ((index < 0) && (index > dailyMisInfo.size() - 1))
		return;
	switch (index)
	{
	case 0:
	case  1:
	case 2:
		blueSkyDispatchEvent(10205, NULL);
		blueSkyDispatchEvent(11007, NULL);
		break;
	case 3:
		break;

	case 4:
		break;

	case 5:
		blueSkyDispatchEvent(12101, NULL);
		blueSkyDispatchEvent(11007, NULL);
		break;

	default: 
		break;
	}

}



//
void DailyMissionView::buyItem(float dt)
{
	
	//isClicked = true;
}

//显示单个任务完成情况
void DailyMissionView::showMissionState(Node* show, unsigned short isCompleted, unsigned short hasGetAward, int index)
{
	//显示完成情况
	ImageView* completeImage = dynamic_cast<ImageView*>(show->getChildByName("completeImage"));
	ImageView* uncompleteImage = dynamic_cast<ImageView*>(show->getChildByName("uncompleteImage"));
	ImageView* noAwardImage = dynamic_cast<ImageView*>(show->getChildByName("noAwardImage"));
	Button* getAwardBtn = dynamic_cast<Button*>(show->getChildByName("getAwardBtn"));
	if (hasGetAward == 0 && isCompleted == 1)
	{
		completeImage->setVisible(false);
		uncompleteImage->setVisible(false);
		noAwardImage->setVisible(false);
		if (canShowGetBtn)
			getAwardBtn->setVisible(true);
		else
			getAwardBtn->setVisible(false);
	}
	else if (isCompleted == 0 && hasGetAward == 1)
	{
		completeImage->setVisible(true);
		uncompleteImage->setVisible(false);
		getAwardBtn->setVisible(false);
		noAwardImage->setVisible(true);
	}
	else if (isCompleted != 0)
	{
		completeImage->setVisible(false);
		uncompleteImage->setVisible(true);
		getAwardBtn->setVisible(false);
		noAwardImage->setVisible(true);
	}

	//显示完成条件
	showMisCondition(show,index);
}

//显示完成条件
void DailyMissionView::showMisCondition(Node* show,int index)
{
	//
	Text* text1_1 = dynamic_cast<Text*>(show->getChildByName("text1_1"));
	Text* text1_2 = dynamic_cast<Text*>(show->getChildByName("text1_2"));
	Text* text1_3 = dynamic_cast<Text*>(show->getChildByName("text1_3"));
	Text* text1_4 = dynamic_cast<Text*>(show->getChildByName("text1_4"));

	Text* text2_1 = dynamic_cast<Text*>(show->getChildByName("text2_1"));
	Text* text2_2 = dynamic_cast<Text*>(show->getChildByName("text2_2"));
	Text* text2_3 = dynamic_cast<Text*>(show->getChildByName("text2_3"));
	Text* text2_4 = dynamic_cast<Text*>(show->getChildByName("text2_4"));

	Text* text3_1 = dynamic_cast<Text*>(show->getChildByName("text3_1"));
	Text* text3_2 = dynamic_cast<Text*>(show->getChildByName("text3_2"));
	Text* text3_3 = dynamic_cast<Text*>(show->getChildByName("text3_3"));
	Text* text3_4 = dynamic_cast<Text*>(show->getChildByName("text3_4"));

	text1_1->setVisible(false);
	text1_2->setVisible(false);
	text1_3->setVisible(false);
	text1_4->setVisible(false);
	text2_1->setVisible(false);
	text2_2->setVisible(false);
	text2_3->setVisible(false);
	text2_4->setVisible(false);
	text3_1->setVisible(false);
	text3_2->setVisible(false);
	text3_3->setVisible(false);
	text3_4->setVisible(false);

	//
	int num = dailyMisInfo.at(index).dwValue;
	char t[256];
	sprintf(t, "%d", num);
	switch (dailyMisInfo.at(index).wMissionId)
	{
		//头游
		case 1:
			text2_1->setVisible(true);
			text2_2->setVisible(true);
			text2_3->setVisible(true);
			text2_4->setVisible(true);
			text2_2->setString(t);
			break;
		//赢
		case 2:
			text1_1->setVisible(true);
			text1_2->setVisible(true);
			text1_3->setVisible(true);
			text1_4->setVisible(true);
			text1_2->setString(t);
			break;
		//对局
		case 3:
			text3_1->setVisible(true);
			text3_2->setVisible(true);
			text3_3->setVisible(true);
			text3_4->setVisible(true);
			text3_2->setString(t);
			break;
	}
}