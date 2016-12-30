#include "PlayGoldMediator.h"
#include "ViewManager.h"

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

		break;
	case 12600:
		//PLayEffect(EFFECT_BTN)
		removeView(this);
		break;
	default:
		break;
	}
}

Layer* PlayGoldMediator::getLayer()
{
	return VIEW->uiLayer;
}

