#ifndef  _PokerActionMediator_
#define  _PokerActionMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"

class PokerActionMediator : public BlueSkyMediator
{
public:
	PokerActionMediator();
	~PokerActionMediator();
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
	cocostudio::timeline::ActionTimeline* tonghuashun;
	cocostudio::timeline::ActionTimeline* huojian;
	cocostudio::timeline::ActionTimeline* feiji;
	cocostudio::timeline::ActionTimeline* boom;
	cocostudio::timeline::ActionTimeline* kanggong;

	Node* tongHuaShun;
	Node* huoJian;
	Node* feiJi;
	Node* Boom;
	Node* kangGong;

	void showNode(int id);
};

#endif