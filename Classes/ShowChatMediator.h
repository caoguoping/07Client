#ifndef  _ShowChatMediator_
#define  _ShowChatMediator_

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
#include "ShowChatView.h"

class ShowChatMediator : public BlueSkyMediator
{
public:
	ShowChatMediator(int desk, int index , int chat);
	~ShowChatMediator();
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

	ShowChatView* showChatView;

	int deskID = -1;
	int indexID = -1;
	int chatID = -1;

	void playChatMusic(int face,int index);
};

#endif