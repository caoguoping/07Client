#include "DailyMissionMediator.h"
#include "DataManager.h"
#include "ViewManager.h"
DailyMissionMediator::DailyMissionMediator()
{

}

DailyMissionMediator::~DailyMissionMediator()
{

}

/**
开始执行函数
*/
void DailyMissionMediator::OnRegister()
{
	dailyMissionView = (DailyMissionView*)getView();

	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	dailyMissionView->dailyMisInfo = pokerGameModel->dailyMisInfo;

	dailyMissionView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
结束回收执行函数
*/
void DailyMissionMediator::onRemove()
{

}

/*
事件响应函数
*/
void DailyMissionMediator::onEvent(int i, void* data)
{
	int index = -1;
	//PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	switch (i)
	{
	case 11007:
		clickCloseBtnHander();
		break;
	case 11008:
		index = *(int*)data;
		getActivityHander(index);
		break;
	case EventType::GAME_OVER:
		removeView(this);
		break;

	case 11010: // 刷新任务界面
		PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
		dailyMissionView->dailyMisInfo = pokerGameModel->dailyMisInfo;
		dailyMissionView->showAllMission();

	}
}

Layer* DailyMissionMediator::getLayer()
{
	return VIEW->uiLayer;
}

void DailyMissionMediator::clickCloseBtnHander()
{
	PLayEffect(EFFECT_BTN)
	removeView(this);
}

void DailyMissionMediator::getActivityHander(int index)
{
 	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));


// 	//下面要将该任务职位已领取状态

 	pokerGameModel->dailyMisInfo.at(index).Receive = 1;
 	dailyMissionView->dailyMisInfo = pokerGameModel->dailyMisInfo;



	DWORD dwUserID = DATA->myBaseData.dwUserID;

	unsigned short wMissionId = pokerGameModel->dailyMisInfo.at(index).wMissionId;
	unsigned short wKindID = pokerGameModel->dailyMisInfo.at(index).wKindId;

	((SendDataService*)getService(SendDataService::NAME))->sendGetMisAward(dwUserID,wMissionId,wKindID);

}
