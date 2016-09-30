#include "GongPaiActionMediator.h"

GongPaiActionMediator::GongPaiActionMediator(int fromUserID, int toUserID)
{
	fromUser = fromUserID;
	toUser = toUserID;
}

GongPaiActionMediator::~GongPaiActionMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void GongPaiActionMediator::OnRegister()
{
	gongPaiActionView = (GongPaiActionView*)getView();

	gongPaiActionView->initView(fromUser, toUser);
}

/**
��������ִ�к���
*/
void GongPaiActionMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void GongPaiActionMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 11601:
		removeView(this);
		break;
	}
}

Layer* GongPaiActionMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}
