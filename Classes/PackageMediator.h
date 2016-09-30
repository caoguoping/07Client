#ifndef  _PackageMediator_
#define  _PackageMediator_

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
#include "PackageView.h"
#include "DataManager.h"

class PackageMediator : public BlueSkyMediator
{
public:
	PackageMediator();
	~PackageMediator();
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

	PackageView* packageView;

	void clickUseBtnHander();

	//��ǰѡ�е��ǵڼ�����Ʒ
	int nowIndex = 0;
};

#endif