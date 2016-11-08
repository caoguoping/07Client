#ifndef  _SetMediator_
#define  _SetMediator_

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
#include "SetView.h"
#include "HelpView.h"
#include "HelpMediator.h"
#include "LoginView.h"
#include "LoginMediator.h"
#include "MusicService.h"
#include "PokerGameModel.h"

class SetMediator : public BlueSkyMediator
{
public:
	SetMediator();
	~SetMediator();
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
	SetView* setView1;

	void clickCloseBtnHander();
	void clickMusicBtnHander();
	void clickEffectBtnHander();
	void clickReLoginBtnHander();
	void clickHelpBtnHander();
};

#endif