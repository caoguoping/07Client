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
	/*
	��ʾ�㼶���ú���
	*/
	Layer* getLayer();

public:
		PlayerInfoView*  playerInfoView;
	//ͷ��
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