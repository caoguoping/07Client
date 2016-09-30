#ifndef  _ChatMediator_
#define  _ChatMediator_

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
#include "ChatView.h"

class ChatMediator : public BlueSkyMediator
{
public:
	ChatMediator();
	~ChatMediator();
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

	ChatView* chatView;

	void clickChat1Hander();
	void clickChat2Hander();
	void clickChat3Hander();
	void clickChat4Hander();
	void clickChat5Hander();
	void clickChat6Hander();
	void clickChat7Hander();
	void clickChat8Hander();
	void clickChat9Hander();
};

#endif