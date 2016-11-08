#include "MallMediator.h"
#include "PlatFormControl.h"
#include "SGTools.h"
#include "DataManager.h"

MallMediator::MallMediator()
{
	log("cocos2d-x mallMediator");
}

MallMediator::~MallMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void MallMediator::OnRegister()
{
	mallView = (MallView*)getView();

	//
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
// 	for (DWORD i = 0; i < pokerGameModel->mallGoodsInfo.size(); i++)
// 	{
// 			mallView->mallGoodsInfo.push_back(pokerGameModel->mallGoodsInfo.at(i));
// 	}

	int gold = DATA->myBaseData.lUserScore;
	mallView->initView();
	mallView->showMyGold(gold);
	mallView->showMyZuanShi(DATA->myBaseData.rmb);
	mallView->showActivityView();
}

/**
结束回收执行函数
*/
void MallMediator::onRemove()
{

}


/*
wKindId ,物品id
1， 2， 3， 4 钻石换金币
5， 6 活动
7 记牌器
*/

/*
事件响应函数  //11201 --  11300  :MallView
*/
void MallMediator::onEvent(int i, void* data)
{
	int index = -1;
	switch (i)
	{
	case 11201:
		removeView(this);
		break;

		//four  category
	case 11202:
		clickActivityBtnHander();
		break;
	case 11203:
		clickZuanShiBtnHander();
		break;
// 	case 11204:
// 		clickGoldBtnHander();
// 		break;
// 	case 11205:
// 		clickRewardBtnHander();
//		break;
// 	case 11206:
// 		clickRechargeBtnHander();
// 		break;


	case 11211:  //active 0   1000gold + 1 jipaiqi
		getActivityHander(0);
		break;

	case 11212:    //active1  45000 gold + 15 jipaiqi
		getActivityHander(1);
		break;


		//zuanshi to gold 
	case 11213: 
		getGoldHander(0);
		break;
	case 11214:
		getGoldHander(1);
		break;
	case 11215:
		getGoldHander(2);
		break;
	case 11216:
		getGoldHander(3);
		break;

		//jipaiqi
	case 11217:
		getJiapiqiHander();
		break;

	case EventType::INSURESUCCESS:
		mallView->showMyGold(DATA->myBaseData.lUserScore);
		mallView->showMyZuanShi(DATA->myBaseData.rmb);
		break;
	}
}

Layer* MallMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

void MallMediator::clickActivityBtnHander()
{
	mallView->showActivityView();
}
void MallMediator::clickZuanShiBtnHander()
{
	mallView->showZuanShiView();
}
void MallMediator::clickGoldBtnHander()
{
	mallView->showGoldView();
}
void MallMediator::clickRewardBtnHander()
{
	mallView->showRewardView();
}
void MallMediator::clickRechargeBtnHander()
{
	creatView(new ShopView(0),new ShopMediator());
	removeView(this);
}

//购买物品(index为第几个物品，从0开始)
void MallMediator::getActivityHander(int index)
{
	//blueSkyDispatchEvent(20050);  //声音
	;

	switch (index)
	{
		//1000Gold + 1jipaiqi
	case 0:
		if (DATA->myBaseData.rmb < 1)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
			blueSkyDispatchEvent(11201);
		}
		else
		{
			//wkinderId  wuping id 5
			((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 5);
		}
		break;
		
		//45000Gold + 15jipaiqi  //wkinderId  wuping id 6
	case 1:
		if (DATA->myBaseData.rmb < 30)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
			blueSkyDispatchEvent(11201);
		}
		else
		{
			((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 6);
		}
		break;
	default:
		break;

	}
}

//chongzhi  SDKs
void MallMediator::getZuanShiHander(int index)
{

}
void MallMediator::getGoldHander(int index)
{
	SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
	//blueSkyDispatchEvent(20050);  //声音
	;
	((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 1);

	switch (index)
	{
	case 0:   
		//1zuan   1, 2, 3, 4 kindID
		if (DATA->myBaseData.rmb < 1)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
			blueSkyDispatchEvent(11201);
		}
		else
		{
			((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 1);
		}
		break;

	case 1:
		if (DATA->myBaseData.rmb < 10)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
			blueSkyDispatchEvent(11201);
		}
		else
		{
			((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 2);
		}
		break;

	case 2:
		if (DATA->myBaseData.rmb < 30)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
			blueSkyDispatchEvent(11201);
		}
		else
		{
			((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 3);
		}
		break;

	case 3:
		if (DATA->myBaseData.rmb < 100)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
			blueSkyDispatchEvent(11201);
		}
		else
		{
			((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 4);
		}
		break;

	default:
		break;

	}
}

void MallMediator::getJiapiqiHander()
{
	//blueSkyDispatchEvent(20050);  //声音
	;

	if (DATA->myBaseData.rmb < 1)
	{
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning3", 30002, -1));
		blueSkyDispatchEvent(11201);
	}
	else
	{
		//wkinderId  wuping id 7
		((SendDataService *)getService(SendDataService::NAME))->sendBuyItems(DATA->myBaseData.dwUserID, 1, 7);
	}
}



void MallMediator::getRewardHander(int index)
{

}