#include "BloodMediator.h"
#include "ViewManager.h"

BloodMediator::BloodMediator()
{

}

BloodMediator::~BloodMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void BloodMediator::OnRegister()
{
	bloodView = (BloodView*)getView();
	bloodView->initView();
}

/**
��������ִ�к���
*/
void BloodMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void BloodMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::BACK_TO_HALL:
	case 12800:
	//	PLayEffect(EFFECT_BTN)
		removeView(this);
		break;
	default:
		break;
	}
}

Layer* BloodMediator::getLayer()
{
	return VIEW->uiLayer;
}

