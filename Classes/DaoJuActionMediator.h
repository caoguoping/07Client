#ifndef  _DaoJuActionMediator_
#define  _DaoJuActionMediator_

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
#include "DaoJuActionView.h"

class DaoJuActionMediator : public BlueSkyMediator
{
public:
	DaoJuActionMediator(DAO_JU_ACTION data);
	~DaoJuActionMediator();
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
	DaoJuActionView* daoJuActionView;

	//
	int index = -1;
	int toDeskID = -1;
	int id = -1;
};

#endif