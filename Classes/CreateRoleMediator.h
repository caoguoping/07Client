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
	开始执行函数
	*/
	void OnRegister();
	/**
	结束回收执行函数
	*/
	void onRemove();
	/*
	事件响应函数
	*/
	void onEvent(int i, void* data);
	/*
	显示层级设置函数
	*/
	Layer* getLayer();

private:
	TextField* nameText;
	CreateRoleView* createRoleView;

	//角色选择
	void clickCharacter1BtnHander();
	void clickCharacter2BtnHander();
	void clickCharacter3BtnHander();
	void clickCharacter4BtnHander();

	//随机昵称
	void clickAutoBtnHander();

	//确定
	void clickCreateBtnHander();

	//角色形象ID
	int faceID = 3;

	//
	registLogin* rLogin;
//	vector<string>* name1;
	vector<string>* name2;
	vector<string>* name3;
};


#endif