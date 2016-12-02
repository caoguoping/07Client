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
开始执行函数
*/
void CancelAutoMediator::OnRegister()
{
	cancelAutoView = (CancelAutoView*)getView();

	cancelAutoView->initView();
}

/**
结束回收执行函数
*/
void CancelAutoMediator::onRemove()
{

}

/*
事件响应函数
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
