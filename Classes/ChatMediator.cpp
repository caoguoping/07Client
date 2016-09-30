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

		break;
	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	case 11301:
		clickChat1Hander();
		break;
	case 11302:
		clickChat2Hander();
		break;
	case 11303:
		clickChat3Hander();
		break;
	case 11304:
		clickChat4Hander();
		break;
	case 11305:
		clickChat5Hander();
		break;
	case 11306:
		clickChat6Hander();
		break;
	case 11307:
		clickChat7Hander();
		break;
	case 11308:
		clickChat8Hander();
		break;
	case 11309:
		clickChat9Hander();
		break;
	}
}

Layer* ChatMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->menuLayer;
}

void ChatMediator::clickChat1Hander()
{
	SEND->sendChat(1, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat2Hander()
{
	SEND->sendChat(2, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat3Hander()
{
	SEND->sendChat(3, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat4Hander()
{
	SEND->sendChat(4, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat5Hander()
{
	SEND->sendChat(5, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat6Hander()
{
	SEND->sendChat(6, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat7Hander()
{
	SEND->sendChat(7, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat8Hander()
{
	SEND->sendChat(8, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}

void ChatMediator::clickChat9Hander()
{
	SEND->sendChat(9, 0);
	blueSkyDispatchEvent(10622);
	removeView(this);
}