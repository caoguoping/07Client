#ifndef  _MessageShowMediator_
#define  _MessageShowMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "MessageShowView.h"
#include "PokerGameModel.h"

class MessageShowMediator : public BlueSkyMediator
{
public:
	MessageShowMediator();
	~MessageShowMediator();
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

	//
	bool canShowMessage = true;

private:
	MessageShowView* messageShowView;
};

#endif