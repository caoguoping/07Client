#include "MyInfoMediator.h"
#include "DataManager.h"
#include "ViewManager.h"
MyInfoMediator::MyInfoMediator()
{

}

MyInfoMediator::~MyInfoMediator()
{

}

/**
开始执行函数
*/
void MyInfoMediator::OnRegister()
{
	myInfoView = (MyInfoView*)getView();

	myInfoView->initView();

	myInfoView->showName(DATA->myBaseData.szNickName);
	myInfoView->showGold(DATA->myBaseData.lUserScore);
	myInfoView->showZhuanShi(DATA->myBaseData.rmb);
	myInfoView->showFace(DATA->myBaseData.wFaceID);

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
结束回收执行函数
*/
void MyInfoMediator::onRemove()
{

}

/*
事件响应函数
*/
void MyInfoMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 11701:
		PLayEffect(EFFECT_BTN)
		clickCloseBtnHander();
		break;
	case 10702:
		clickAddGoldBtnHander();
		break;
	case 10703:
		clickAddZhuanBtnHander();
		break;
	case EventType::INSURESUCCESS:
		myInfoView->showGold(DATA->myBaseData.lUserScore);
		myInfoView->showZhuanShi(DATA->myBaseData.rmb);
		break;
	}
}

Layer* MyInfoMediator::getLayer()
{
	return VIEW->uiLayer;
}

void MyInfoMediator::clickCloseBtnHander()
{
	removeView(this);
}

//增加金豆
void MyInfoMediator::clickAddGoldBtnHander()
{
	creatView(new ShopView(1), new ShopMediator());
	removeView(this);
}

//增加钻石
void MyInfoMediator::clickAddZhuanBtnHander()
{
	creatView(new ShopView(0), new ShopMediator());
	removeView(this);
}
