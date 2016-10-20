#include "EntertainmentMediator.h"


EntertainmentMediator::EntertainmentMediator()
{

}

EntertainmentMediator::~EntertainmentMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void EntertainmentMediator::OnRegister()
{
	entertainmentView = (EntertainmentView*)getView();
	entertainmentView->initView();
}

/**
结束回收执行函数
*/
void EntertainmentMediator::onRemove()
{

}

/*
事件响应函数
*/
void EntertainmentMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::BACK_TO_HALL:
	case 12700:
		removeView(this);
		break;
	default:
		break;
	}
}

Layer* EntertainmentMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

