#ifndef  _LoginMediator_
#define  _LoginMediator_


#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PlayPokerView.h"
#include "PlayPokerMediator.h"
#include "SocketInitCommand.h"
#include <time.h>


class  LoginMediator : public BlueSkyMediator, public Node
{
public:
	LoginMediator(){};
	~LoginMediator();
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


	void callJavaLogin(void);


private:
	////
	//Button* visitorLoginBtn;

	////
	//Button* accountLoginBtn;

	//�˺������
	TextField* acountText;

	//���������
	TextField* passwordText;

	//
	TextField* ipText;

	//
	void clickRegistBtnHander();
	//
	void clickLoginBtnHander();

	////
	//bool clickVisitorLoginBtn(Touch *touch, Widget::TouchEventType type);

	////
	//bool clickAccountLoginBtn(Touch *touch, Widget::TouchEventType type);

	Text* text1;
};

#endif