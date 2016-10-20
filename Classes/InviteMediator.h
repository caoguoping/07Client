#ifndef  _InviteMediator_
#define  _InviteMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "SendDataService.h"
#include "InviteView.h"


class InviteMediator : public BlueSkyMediator
{
public:
	InviteMediator();
	~InviteMediator();
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
	InviteView* inviteView;

	void clickCloseBtnHander();

};

#endif