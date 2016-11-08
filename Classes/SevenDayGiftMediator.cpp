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
��ʼִ�к���
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

	//������Լ��޸Ľ����Ƿ��һ�ε�¼��ʶ������Ҫ�ŵ�������Ϣ�У�
	DATA->myBaseData.isFirstLogin = 0;

	//
	removeView(this);
}

void SevenDayGiftMediator::clickCloseBtnHander()
{
	removeView(this);
}