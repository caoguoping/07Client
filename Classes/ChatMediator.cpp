#include "ChatMediator.h"

ChatMediator::ChatMediator()
{

}

ChatMediator::~ChatMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void ChatMediator::OnRegister()
{
	chatView = (ChatView*)getView();

	chatView->initView();
}

/**
结束回收执行函数
*/
void ChatMediator::onRemove()
{

}

/*
事件响应函数
*/
void ChatMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 11310:
	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	case 11301:
		clickChatHander(1);
		break;
	case 11302:
		clickChatHander(2);
		break;
	case 11303:
		clickChatHander(3);
		break;
	case 11304:
		clickChatHander(4);
		break;
	case 11305:
		clickChatHander(5);
		break;
	case 11306:
		clickChatHander(6);
		break;
	case 11307:
		clickChatHander(7);
		break;
	case 11308:
		clickChatHander(8);
		break;
	case 11309:
		clickChatHander(9);
		break;
	}
}

Layer* ChatMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->menuLayer;
}

void ChatMediator::clickChatHander(WORD wItem)
{
	SEND->sendChat(wItem, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}
