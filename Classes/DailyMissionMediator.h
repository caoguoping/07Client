#ifndef  _DailyMissionMediator_
#define  _DailyMissionMediator_

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
#include "DailyMissionView.h"
#include "DataManager.h"

class DailyMissionMediator : public BlueSkyMediator
{
public:
	DailyMissionMediator();
	~DailyMissionMediator();
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
	void clickCloseBtnHander();
	void getActivityHander(int index);
	//
	DailyMissionView* dailyMissionView;
};

#endif