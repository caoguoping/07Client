#ifndef  _ShopMediator_
#define  _ShopMediator_

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
#include "ShopView.h"

class ShopMediator : public BlueSkyMediator
{
public:
	ShopMediator();
	~ShopMediator();
	/**
	��ʼִ�к���
	*/
	void OnRegister();
	/**
	��������ִ�к���
	*/
	void onRemove();
	void refreshInfo();  //ˢ�½�Һ���ʯ
	/*
	�¼���Ӧ����
	*/
	void onEvent(int i, void* data);
	Layer* getLayer();

	int currentID;  //1 zuanshi, 2 jinbi;

	void clickCloseBtnHander();

	void getZuanShiHander(int index);

	ShopView* shopView;
};

#endif