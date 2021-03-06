#include "SetMediator.h"
#include "ViewManager.h"
SetMediator::SetMediator()
{

}

SetMediator::~SetMediator()
{

}

/**
开始执行函数
*/
void SetMediator::OnRegister()
{
	setView = (SetView*)getView();
	setView->initView();
	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
结束回收执行函数
*/
void SetMediator::onRemove()
{

}

/*
事件响应函数
*/
void SetMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 14001:
		PLayEffect(EFFECT_BTN)
		clickCloseBtnHander();
		break;
	case 14005:
		clickReLoginBtnHander();
		break;
	case 14006:
		clickHelpBtnHander();
		break;
	}
}

Layer* SetMediator::getLayer()
{
	logV("$$$$$$$$$$$$$ setMediator layer %p\n", VIEW->uiLayer);
	return VIEW->uiLayer;
}

void SetMediator::clickCloseBtnHander()
{
	removeView(this);
}

void SetMediator::clickReLoginBtnHander()
{
	//清空任务信息数据
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	pokerGameModel->dailyMisInfo.clear();
	pokerGameModel->mallGoodsInfo.clear();
	pokerGameModel->packageItem.clear();

	creatView(new LoginView(),new LoginMediator());
	blueSkyDispatchEvent(EventType::RE_LOGIN);
	removeView(this);
}

void SetMediator::clickHelpBtnHander()
{
	creatView(new HelpView(),new HelpMediator());
	removeView(this);
}
