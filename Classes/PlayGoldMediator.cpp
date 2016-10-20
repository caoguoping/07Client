#include "PlayGoldMediator.h"
//test
#include "InviteMediator.h"
#include "InviteView.h"

PlayGoldMediator::PlayGoldMediator()
{

}

PlayGoldMediator::~PlayGoldMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void PlayGoldMediator::OnRegister()
{
	playGoldView = (PlayGoldView*)getView();
	playGoldView->initView();

	//test

	creatView(new InviteView(), new InviteMediator());

}

/**
结束回收执行函数
*/
void PlayGoldMediator::onRemove()
{

}

/*
事件响应函数
*/
void PlayGoldMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::BACK_TO_HALL:
	case 12600:
		removeView(this);
		break;
	default:
		break;
	}
}

Layer* PlayGoldMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

