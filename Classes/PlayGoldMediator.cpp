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
��ʼִ�к���
*/
void PlayGoldMediator::OnRegister()
{
	playGoldView = (PlayGoldView*)getView();
	playGoldView->initView();


}

/**
��������ִ�к���
*/
void PlayGoldMediator::onRemove()
{

}

/*
�¼���Ӧ����
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

