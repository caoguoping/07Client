#include "SevenDayGiftMediator.h"
#include "DataManager.h"
#include "ViewManager.h"
SevenDayGiftMediator::SevenDayGiftMediator(bool isShowCloseBtn)
{
	ShowCloseBtn = isShowCloseBtn;
}

SevenDayGiftMediator::~SevenDayGiftMediator()
{

}

/**
��ʼִ�к���
*/
void SevenDayGiftMediator::OnRegister()
{
	sevenDayGiftView = (SevenDayGiftView*)getView();
	sevenDayGiftView->initView(ShowCloseBtn);

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
��������ִ�к���
*/
void SevenDayGiftMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void SevenDayGiftMediator::onEvent(int i, void* data)
{
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	switch (i)
	{
	case 10901:
		clickGetGiftBtnHander();
		break;
	case 10902:
		PLayEffect(EFFECT_BTN)
		clickCloseBtnHander();
		break;
// 	case EventType::SEVEN_LOGIN_INFO:
// 		sevenDayGiftView->nowDay = DATA->sevenLogin.LogonCnt;
// 		sevenDayGiftView->showGift();
// 		break;
	}
}

Layer* SevenDayGiftMediator::getLayer()
{
	return VIEW->uiLayer;
}


void SevenDayGiftMediator::clickGetGiftBtnHander()
{
// 	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
// 	WORD loginCnt = gameDataModel->player[0].loginCnt;
// 	DWORD dwUserID = DATA->myBaseData.dwUserID;
// 
// 	//������Լ��޸Ľ����Ƿ��һ�ε�¼��ʶ������Ҫ�ŵ�������Ϣ�У�
// 	DATA->myBaseData.isFirstLogin = 0;
// 
// 	//
// 	removeView(this);
}

void SevenDayGiftMediator::clickCloseBtnHander()
{
	removeView(this);
}
