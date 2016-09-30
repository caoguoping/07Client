#include "ShowChatMediator.h"

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
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

//
void ShowChatMediator::playChatMusic(int face, int index)
{
	//女
	if (face == 1 || face == 4)
	{
		switch (index)
		{
		case 1:
			blueSkyDispatchEvent(20030);
			break;
		case 2:
			blueSkyDispatchEvent(20032);
			break;
		case 3:
			blueSkyDispatchEvent(20034);
			break;
		case 4:
			blueSkyDispatchEvent(20036);
			break;
		case 5:
			blueSkyDispatchEvent(20038);
			break;
		case 6:
			blueSkyDispatchEvent(20040);
			break;
		case 7:
			blueSkyDispatchEvent(20042);
			break;
		case 8:
			blueSkyDispatchEvent(20044);
			break;
		case 9:
			blueSkyDispatchEvent(20046);
			break;
		}
	}
	else if (face == 2 || face == 3)
	{
		switch (index)
		{
		case 1:
			blueSkyDispatchEvent(20029);
			break;
		case 2:
			blueSkyDispatchEvent(20031);
			break;
		case 3:
			blueSkyDispatchEvent(20033);
			break;
		case 4:
			blueSkyDispatchEvent(20035);
			break;
		case 5:
			blueSkyDispatchEvent(20037);
			break;
		case 6:
			blueSkyDispatchEvent(20039);
			break;
		case 7:
			blueSkyDispatchEvent(20041);
			break;
		case 8:
			blueSkyDispatchEvent(20043);
			break;
		case 9:
			blueSkyDispatchEvent(20045);
			break;
		}
	}
	
}