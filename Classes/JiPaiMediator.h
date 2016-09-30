#ifndef  _JiPaiMediator_
#define  _JiPaiMediator_

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

class JiPaiMediator : public BlueSkyMediator
{
public:
	JiPaiMediator();
	~JiPaiMediator();
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
	Text* daGuiNum;
	Text* xiaoGuiNum;
	Text* Num[14];    //0:kong  1:A, 2:2 .....

	//ͳ�Ʋ���ʾ�����Ѿ���������
	void showAllOutPoker();
	void showPushPoker();

	//
	bool canShow = false;

};


#endif