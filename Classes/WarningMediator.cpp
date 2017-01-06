#include "WarningMediator.h"
#include "ViewManager.h"
#include "MusicService.h"
WarningMediator::WarningMediator()
{

}

WarningMediator::~WarningMediator()
{

}

/**
��ʼִ�к���
*/
void WarningMediator::OnRegister()
{
	warningView = (WarningView*)getView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
��������ִ�к���
*/
void WarningMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void WarningMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 11401:
		PLayEffect(BUTTON_CLICK)
		if (warningView->enterEventId >= 0)
		{
			blueSkyDispatchEvent(warningView->enterEventId);
		}
		removeView(this);
		break;
	case 11402:
		PLayEffect(BUTTON_CLICK)
		if (warningView->cancleEventId >= 0)
		{
			blueSkyDispatchEvent(warningView->cancleEventId);
		}
		removeView(this);
		break;
	case 11403:
		PLayEffect(BUTTON_CLICK)
		if (warningView->enterEventId >= 0)
		{
			blueSkyDispatchEvent(warningView->enterEventId);
		}
		removeView(this);
		break;
	case 11404:
		PLayEffect(BUTTON_CLICK)
		if (warningView->cancleEventId >= 0)
		{
			blueSkyDispatchEvent(warningView->cancleEventId);
		}
		removeView(this);
		break;
	}
}

Layer* WarningMediator::getLayer()
{
	return VIEW->TopLayer;
}
