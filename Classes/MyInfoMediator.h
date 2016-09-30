#ifndef  _MyInfoMediator_
#define  _MyInfoMediator_

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
#include "MyInfoView.h"
#include "DataManager.h"
#include "ShopView.h"
#include "ShopMediator.h"

class MyInfoMediator : public BlueSkyMediator
{
public:
	MyInfoMediator();
	~MyInfoMediator();
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
	MyInfoView* myInfoView;

	//���ӽ�
	void clickAddGoldBtnHander();

	//������ʯ
	void clickAddZhuanBtnHander();

	void clickCloseBtnHander();
};

#endif