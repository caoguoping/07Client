#include "ShowChatMediator.h"
#include "MusicService.h"
#include "ViewManager.h"
ShowChatMediator::ShowChatMediator(int desk, int index,int chat)
{
	deskID = desk;
	indexID = index;
	chatID = chat;
}

ShowChatMediator::~ShowChatMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void ShowChatMediator::OnRegister()
{
	showChatView = (ShowChatView*)getView();

	showChatView->initView(deskID,indexID,chatID);

	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));

	int SChair = playerInDeskModel->getServiceChairID(deskID);

	int face = playerInDeskModel->DeskPlayerInfo[SChair].wFaceID;
	
	//播放音效
	playChatMusic(face,indexID);
}

/**
结束回收执行函数
*/
void ShowChatMediator::onRemove()
{

}

/*
事件响应函数
*/
void ShowChatMediator::onEvent(int i, void* data)
{
	int chat;
	switch (i)
	{
	case 11501:
		chat = *(int*)data;
		if (chat == chatID)
			removeView(this);
		break;
	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	}
}

Layer* ShowChatMediator::getLayer()
{
	return VIEW->uiLayer;
}

//
void ShowChatMediator::playChatMusic(int face, int index)
{
	//女
	if (face == 1 || face == 2)
	{
		switch (index)
		{
		case 1:
			PLayEffect(HURRY_NV);
			break;
		case 2:
			PLayEffect(PERFORM_NV);
			break;
		case 3:
			PLayEffect(FRIEND_NV);
			break;
		case 4:
			PLayEffect(LEAVE_NV);
			break;
		case 5:
			PLayEffect(BOOM_HOOM_NV);
			break;
		case 6:
			PLayEffect(COOPERATE_NV);
			break;
		case 7:
			PLayEffect(HELLO_NV);
			break;
		case 8:
			PLayEffect(COMBINE_NV);
			break;
		case 9:
			PLayEffect(APOLOGY_NV);
			break;
		}
	}
	else if (face == 3 || face == 4)
	{
		switch (index)
		{
		case 1:
			PLayEffect(HURRY_NAN);
			break;
		case 2:
			PLayEffect(PERFORM_NAN);
			break;
		case 3:
			PLayEffect(FRIEND_NAN);
			break;
		case 4:
			PLayEffect(LEAVE_NAN);
			break;
		case 5:
			PLayEffect(BOOM_HOOM_NAN);
			break;
		case 6:
			PLayEffect(COOPERATE_NAN);
			break;
		case 7:
			PLayEffect(HELLO_NAN);
			break;
		case 8:
			PLayEffect(COMBINE_NAN);
			break;
		case 9:
			PLayEffect(APOLOGY_NAN);
			break;
		}
	}
	
}
