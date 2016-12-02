#include "CancelAutoMediator.h"
#include "ViewManager.h"
CancelAutoMediator::CancelAutoMediator()
{

}

CancelAutoMediator::~CancelAutoMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void CancelAutoMediator::OnRegister()
{
	cancelAutoView = (CancelAutoView*)getView();

	cancelAutoView->initView();
}

/**
��������ִ�к���
*/
void CancelAutoMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void CancelAutoMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::GAME_OVER:
	case 11101:
		removeView(this);
		break;
	}
}

Layer* CancelAutoMediator::getLayer()
{
	return VIEW->uiLayer;
}
