#ifndef  _SevenDayGiftMediator_
#define  _SevenDayGiftMediator_

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
#include "SevenDayGiftView.h"
#include "DataManager.h"
#include "SendDataService.h"

class SevenDayGiftMediator : public BlueSkyMediator
{
public:
	SevenDayGiftMediator(bool isShowCloseBtn = true);
	~SevenDayGiftMediator();
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
	//
	SevenDayGiftView* sevenDayGiftView;

	void clickGetGiftBtnHander();
	void clickCloseBtnHander();

	bool ShowCloseBtn;
};


#endif