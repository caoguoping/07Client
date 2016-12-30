#include "EntertainmentMediator.h"
#include "ViewManager.h"

EntertainmentMediator::EntertainmentMediator()
{

}

EntertainmentMediator::~EntertainmentMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void EntertainmentMediator::OnRegister()
{
	entertainmentView = (EntertainmentView*)getView();
	entertainmentView->initView();
}

/**
结束回收执行函数
*/
void EntertainmentMediator::onRemove()
{

}

/*
事件响应函数
*/
void EntertainmentMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::BACK_TO_HALL:
	case 12700:
		//PLayEffect(EFFECT_BTN)
		removeView(this);
		break;
	case FRIEND_LIST:
		DATA->vFriendLine.clear();
		for (int i = 0; i < DATA->vFriends.size(); i ++)
		{
			if (DATA->vFriends.at(i).bStates == 1)
			{
				DATA->vFriendLine.push_back(DATA->vFriends.at(i));
			}
		}
		break;
	default:
		break;
	}
}

Layer* EntertainmentMediator::getLayer()
{
	return VIEW->uiLayer;
}

