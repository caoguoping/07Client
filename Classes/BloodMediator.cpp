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
开始执行函数
*/
void BloodMediator::OnRegister()
{
	bloodView = (BloodView*)getView();
	bloodView->initView();
}

/**
结束回收执行函数
*/
void BloodMediator::onRemove()
{

}

/*
事件响应函数
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

