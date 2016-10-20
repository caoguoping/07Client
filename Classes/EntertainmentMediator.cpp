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
��ʼִ�к���
*/
void EntertainmentMediator::OnRegister()
{
	entertainmentView = (EntertainmentView*)getView();
	entertainmentView->initView();
}

/**
��������ִ�к���
*/
void EntertainmentMediator::onRemove()
{

}

/*
�¼���Ӧ����
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

