#include "InviteMediator.h"
#include "UILayerService.h"

InviteMediator::InviteMediator()
{

}

InviteMediator::~InviteMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void InviteMediator::OnRegister()
{
	inviteView = (InviteView*)getView();

	inviteView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
结束回收执行函数
*/
void InviteMediator::onRemove()
{

}

/*
事件响应函数
*/
void InviteMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 17000:
		clickCloseBtnHander();
		break;
	}
}

Layer* InviteMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

void InviteMediator::clickCloseBtnHander()
{
	removeView(this);
}
