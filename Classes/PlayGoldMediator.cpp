#include "PlayGoldMediator.h"


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
