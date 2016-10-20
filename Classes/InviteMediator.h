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
	InviteView* inviteView;

	void clickCloseBtnHander();

};

#endif