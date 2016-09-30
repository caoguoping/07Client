#ifndef  _GongPaiActionMediator_
#define  _GongPaiActionMediator_

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
#include "GongPaiActionView.h"

class GongPaiActionMediator : public BlueSkyMediator
{
public:
	GongPaiActionMediator(int fromUserID = -1,int toUserID = -1);
	~GongPaiActionMediator();
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
	GongPaiActionView* gongPaiActionView;

	int fromUser = -1;
	int toUser = -1;
};

#endif