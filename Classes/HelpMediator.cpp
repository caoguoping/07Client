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
��ʼִ�к���
*/
void HelpMediator::OnRegister()
{
	helpView = (HelpView*)getView();

	helpView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
��������ִ�к���
*/
void HelpMediator::onRemove()
{

}

/*
�¼���Ӧ����
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
