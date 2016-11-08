#include "SevenDayGiftMediator.h"
#include "DataManager.h"

SevenDayGiftMediator::SevenDayGiftMediator(bool isShowCloseBtn)
{
	ShowCloseBtn = isShowCloseBtn;
}

SevenDayGiftMediator::~SevenDayGiftMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void SevenDayGiftMediator::OnRegister()
{
	sevenDayGiftView = (SevenDayGiftView*)getView();
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	sevenDayGiftView->canGetGiftToday = DATA->myBaseData.isFirstLogin;
	sevenDayGiftView->nowDay = gameDataModel->player[0].loginCnt;
	sevenDayGiftView->initView(ShowCloseBtn);

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
结束回收执行函数
*/
void SevenDayGiftMediator::onRemove()
{

}

/*
事件响应函数
*/
void SevenDayGiftMediator::onEvent(int i, void* data)
{
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	DBO_GP_Seven_Logon sevenLoginInfo;
	switch (i)
	{
	case 10901:
		clickGetGiftBtnHander();
		break;
	case 10902:
		clickCloseBtnHander();
		break;
	case EventType::SEVEN_LOGIN_INFO:
		sevenLoginInfo = *(DBO_GP_Seven_Logon*)data;
		sevenDayGiftView->nowDay = sevenLoginInfo.LogonCnt;
		gameDataModel->player[0].loginCnt = sevenLoginInfo.LogonCnt;
		sevenDayGiftView->showGift();
		break;
	}
}

Layer* SevenDayGiftMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}


void SevenDayGiftMediator::clickGetGiftBtnHander()
{
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	WORD loginCnt = gameDataModel->player[0].loginCnt;
	DWORD dwUserID = DATA->myBaseData.dwUserID;

	//这边先自己修改今天是否第一次登录标识（后面要放到返回消息中）
	DATA->myBaseData.isFirstLogin = 0;

	//
	removeView(this);
}

void SevenDayGiftMediator::clickCloseBtnHander()
{
	removeView(this);
}