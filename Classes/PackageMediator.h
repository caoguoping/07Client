#ifndef  _PackageMediator_
#define  _PackageMediator_

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
#include "PackageView.h"
#include "DataManager.h"

class PackageMediator : public BlueSkyMediator
{
public:
	PackageMediator();
	~PackageMediator();
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

	PackageView* packageView;

	void clickUseBtnHander();

	//当前选中的是第几个物品
	int nowIndex = 0;
};

#endif