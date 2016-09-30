#ifndef  _PlayerInfoMediator_
#define  _PlayerInfoMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "head.h"
#include "UIUtil.h"
#include "PlayerInDeskModel.h"
#include "PokerGameModel.h"
#include "PlayerInfoView.h"

class PlayerInfoMediator : public BlueSkyMediator
{
public:
	PlayerInfoMediator(int deskID);
	~PlayerInfoMediator();

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
	/*
	显示层级设置函数
	*/
	Layer* getLayer();

public:
		PlayerInfoView*  playerInfoView;
	//头像
	Node* head;

	//
	int clientDesk = -1;
	int serviceDesk = -1;
	int face = -1;

	//
	void showHead();

	void clickEggBtnHander();
	void clickBoomBtnHander();
	void clickHeartBtnHander();
	void clickFlowerBtnHander();
	void clickAddFriendBtnHander();
};


#endif