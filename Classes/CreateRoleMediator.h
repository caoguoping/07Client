#ifndef  _CreateRoleMediator_
#define  _CreateRoleMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "head.h"
#include "UIUtil.h"
#include "SocketInitCommand.h"
#include "CreateRoleView.h"
#include "UTF8.h"
#include <vector>

class CreateRoleMediator : public BlueSkyMediator
{
public:
	CreateRoleMediator(registLogin data);
	~CreateRoleMediator();

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

private:
	TextField* nameText;
	CreateRoleView* createRoleView;

	//��ɫѡ��
	void clickCharacter1BtnHander();
	void clickCharacter2BtnHander();
	void clickCharacter3BtnHander();
	void clickCharacter4BtnHander();

	//����ǳ�
	void clickAutoBtnHander();

	//ȷ��
	void clickCreateBtnHander();

	//��ɫ����ID
	int faceID = 3;

	//
	registLogin* rLogin;
//	vector<string>* name1;
	vector<string>* name2;
	vector<string>* name3;
};


#endif