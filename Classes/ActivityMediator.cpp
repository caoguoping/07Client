#include "ActivityMediator.h"
#include "DataManager.h"

ActivityMediator::ActivityMediator()
{

}

ActivityMediator::~ActivityMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void ActivityMediator::OnRegister()
{
	activityView = (ActivityView*)getView();
	activityView->initView();


	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
	updateInfo();
}

void ActivityMediator::updateInfo()
{

		activityView->showMyGold(DATA->myBaseData.lUserScore);
		activityView->showMyZuanShi(DATA->myBaseData.rmb);
}

/**
结束回收执行函数
*/
void ActivityMediator::onRemove()
{

}

/*
事件响应函数
*/
void ActivityMediator::onEvent(int i, void* data)
{
	int index = -1;
	
	;
	switch (i)
	{
	case 15001:
		clickCloseBtnHander();
		break;
	case 15002:
		clickLotteryBtnHander();
		break;
	case 15003:
		clickRechargeBtnHander();
		break;
	case 15010:
		clickMyCupBtnHander();
		break;
	case 15004:
		clickGetLotteryBtnHander();
		break;
	case 15005:
		index = *(int*)data;
		getRechargeAwardHander(index);
		break;
	case 15006:
		getLotteryAwardHander();
		break;

		//paihang
	case 15020:
	{
		CMD_GP_CupInfo*  cupInfo = (CMD_GP_CupInfo*)data;
		DATA->saveRankData(cupInfo);
		DATA->myRankInfo.cLevel = activityView->setLevelAndPercent(cupInfo->cExp);
		activityView->setCupAwardsInfo(cupInfo->awards, DATA->myRankInfo.cLevel);
		//activityView->setTimes(cupInfo->openTime);
		break;
	}
	
	case 15021:
	{
		CMD_GP_CupAwards cupAwardsInfo;
		cupAwardsInfo = *(CMD_GP_CupAwards*)data;
		updateCupAward(cupAwardsInfo);
		break;
	}

	case EventType::GET_GAMBLING_REWARD:
		CMD_GP_User_Gambling gamblingData;
		gamblingData = *(CMD_GP_User_Gambling*)data;
		activityView->getSpinReward();
		//updateInfo();
		break;

// // // 		activityView->startLottery(gamblingData.Gambling, gamblingData.GamblingCnt);
// // 		activityView->lotteryIndex = gamblingData.Gambling;
// // 		activityView->lotteryTimes = gamblingData.GamblingCnt;
// 
// 
// 		break;
	case EventType::INSURESUCCESS:
		updateInfo();
		break;



		}

}

Layer* ActivityMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

void ActivityMediator::clickCloseBtnHander()
{
	removeView(this);
}

void ActivityMediator::clickLotteryBtnHander()
{
	activityView->showLottery();
}

void ActivityMediator::clickRechargeBtnHander()
{
	activityView->showRecharge();
}

void ActivityMediator::clickMyCupBtnHander()
{
	activityView->showMyCup();
}

void ActivityMediator::clickGetLotteryBtnHander()
{

}

void ActivityMediator::getRechargeAwardHander(int index)
{

}
void ActivityMediator::getLotteryAwardHander()
{
// 	blueSkyDispatchEvent(11905);
// 	//加金币
// 	;
// 	DATA->myBaseData.lUserScore += activityView ;
// 	blueSkyDispatchEvent(EventType::INSURESUCCESS);
// 
// 	//显示金币增加信息
// 	MessageVO* data = new  MessageVO();
// 	data->type = 2;
// 	char t[256];
// 	sprintf(t, "%d", lotteryIndex);
// 	string name = t;
// 	data->name = name;
// 	blueSkyDispatchEvent(11901, data);
}

void ActivityMediator::updateCupAward(CMD_GP_CupAwards info)
{
	if (info.flag == 1)
	{
		// 成功
		DATA->myRankInfo.awards = info.dwAwards;
		activityView->setCupAwardsInfo(info.dwAwards, DATA->myRankInfo.cLevel);
	}
	else
	{
		// 失败
	}
}
