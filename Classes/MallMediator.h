#ifndef  _MallMediator_
#define  _MallMediator_

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
#include "MallView.h"
#include "DataManager.h"
#include "ShopView.h"
#include "ShopMediator.h"

class MallMediator : public BlueSkyMediator
{
public:
	MallMediator();
	~MallMediator();
	/**
	��ʼִ�к���
	*/
	void OnRegister();
	/**
	��������ִ�к���
	*/
	void onRemove();
	/*
	�¼���Ӧ����
	*/
	void onEvent(int i, void* data);
	Layer* getLayer();

private:

	MallView* mallView;

	void clickActivityBtnHander();
	void clickZuanShiBtnHander();
	void clickGoldBtnHander();
	void clickRewardBtnHander();
	void clickRechargeBtnHander();
	void getActivityHander(int index);
	void getZuanShiHander(int index);
	void getJiapiqiHander();


	void getGoldHander(int index);
	void getRewardHander(int index);
};

#endif