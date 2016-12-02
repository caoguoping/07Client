#include "HelpMediator.h"
#include "ViewManager.h"
HelpMediator::HelpMediator()
{

}

HelpMediator::~HelpMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void HelpMediator::OnRegister()
{
	helpView = (HelpView*)getView();

	helpView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
结束回收执行函数
*/
void HelpMediator::onRemove()
{

}

/*
事件响应函数
*/
void HelpMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 13001:
		clickCloseBtnHander();
		break;
	}
}

Layer* HelpMediator::getLayer()
{
	return VIEW->uiLayer;
}

void HelpMediator::clickCloseBtnHander()
{
	removeView(this);
}
