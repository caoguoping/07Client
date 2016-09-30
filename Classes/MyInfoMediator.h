#ifndef  _MyInfoMediator_
#define  _MyInfoMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"
#include "GameDataModel.h"
#include "PokerLogic.h"
#include "MyInfoView.h"
#include "DataManager.h"
#include "ShopView.h"
#include "ShopMediator.h"

class MyInfoMediator : public BlueSkyMediator
{
public:
	MyInfoMediator();
	~MyInfoMediator();
	/**
	开始执行函数
	*/
	void OnRegister();
	/**
	结束回收执行函数
	*/
	void onRemove();
	/*
	事件响应函数
	*/
	void onEvent(int i, void* data);
	Layer* getLayer();


private:
	MyInfoView* myInfoView;

	//增加金豆
	void clickAddGoldBtnHander();

	//增加钻石
	void clickAddZhuanBtnHander();

	void clickCloseBtnHander();
};

#endif