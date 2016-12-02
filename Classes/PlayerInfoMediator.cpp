#include "PlayerInfoMediator.h"
#include "ViewManager.h"
#include "SendDataService.h"
#include "TCPSocketService.h"
#include "FriendView.h"
#include "DataManager.h"

PlayerInfoMediator::PlayerInfoMediator(int deskID)
{
	clientDesk = deskID;
}

PlayerInfoMediator::~PlayerInfoMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void PlayerInfoMediator::OnRegister()
{
	playerInfoView = (PlayerInfoView*)getView();

	head = playerInfoView->rootNode->getChildByName("headNode");
	serviceDesk = DATAPlayerIndesk->getServiceChairID(clientDesk);
	playerInfoView->txtName->setString(DATAPlayerIndesk->DeskPlayerInfo[serviceDesk].szNickName);
	playerInfoView->txtGold->setString(Tools::parseLL2String(DATAPlayerIndesk->DeskPlayerInfo[serviceDesk].lScore));

	face = DATAPlayerIndesk->DeskPlayerInfo[serviceDesk].wFaceID;
	showHead();
	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
结束回收执行函数
*/
void PlayerInfoMediator::onRemove()
{

}

/*
事件响应函数
*/
void PlayerInfoMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::BACK_TO_HALL:
	case 10701:
		removeView(this);
		break;
	case 10702:
		clickEggBtnHander();
		break;
	case 10703:
		clickBoomBtnHander();
		break;
	case 10704:
		clickHeartBtnHander();
		break;
	case 10705:
		clickFlowerBtnHander();
		break;
	case 10706:
		clickAddFriendBtnHander();
		break;
	}
}

/*
显示层级设置函数
*/
Layer* PlayerInfoMediator::getLayer()
{
	return VIEW->uiLayer;
}

//
void PlayerInfoMediator::showHead()
{
	ImageView* image1 = dynamic_cast<ImageView*>(head->getChildByName("character_1"));
	ImageView* image2 = dynamic_cast<ImageView*>(head->getChildByName("character_2"));
	ImageView* image3 = dynamic_cast<ImageView*>(head->getChildByName("character_3"));
	ImageView* image4 = dynamic_cast<ImageView*>(head->getChildByName("character_4"));
	switch (face)
	{
	case 1:
		image1->setVisible(true);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 2:
		image1->setVisible(false);
		image2->setVisible(true);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 3:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(true);
		image4->setVisible(false);
		break;
	case 4:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(true);
		break;
	}
}

void PlayerInfoMediator::clickEggBtnHander()
{
// 	DAO_JU_ACTION* data = new DAO_JU_ACTION();
// 	data->index = 1;
// 	data->toDesk = clientDesk;
// 	data->fromDesk = 0;
// 
// 	blueSkyDispatchEvent(EventType::SHOW_DAO_JU_ACTION, data);

	CMD_C_USE_PROPERTY*  pData = new CMD_C_USE_PROPERTY();
	pData->wIndex = 1;
	pData->wChairID = DATAPlayerIndesk->getServiceChairID(0);
	pData->wTargetID = DATAPlayerIndesk->getServiceChairID(clientDesk);
	SEND_GAME->SendData(200, 13, pData, sizeof(CMD_C_USE_PROPERTY));

	removeView(this);
}

void PlayerInfoMediator::clickBoomBtnHander()
{
// 	DAO_JU_ACTION* data = new DAO_JU_ACTION();
// 	data->index = 2;
// 	data->toDesk = clientDesk;
// 	data->fromDesk = 0;
// 	blueSkyDispatchEvent(EventType::SHOW_DAO_JU_ACTION, data);

	CMD_C_USE_PROPERTY*  pData = new CMD_C_USE_PROPERTY();
	pData->wIndex = 2;
	pData->wChairID = DATAPlayerIndesk->getServiceChairID(0);
	pData->wTargetID = DATAPlayerIndesk->getServiceChairID(clientDesk);
	SEND_GAME->SendData(200, 13, pData, sizeof(CMD_C_USE_PROPERTY));

	removeView(this);
}

void PlayerInfoMediator::clickHeartBtnHander()
{
// 	DAO_JU_ACTION* data = new DAO_JU_ACTION();
// 	data->index = 3;
// 	data->toDesk = clientDesk;
// 	data->fromDesk = 0;
// 	blueSkyDispatchEvent(EventType::SHOW_DAO_JU_ACTION, data);

	CMD_C_USE_PROPERTY*  pData = new CMD_C_USE_PROPERTY();
	pData->wIndex = 3;
	pData->wChairID = DATAPlayerIndesk->getServiceChairID(0);
	pData->wTargetID = DATAPlayerIndesk->getServiceChairID(clientDesk);
	SEND_GAME->SendData(200, 13, pData, sizeof(CMD_C_USE_PROPERTY));

	removeView(this);
}

void PlayerInfoMediator::clickFlowerBtnHander()
{
// 	DAO_JU_ACTION* data = new DAO_JU_ACTION();
// 	data->index = 4;
// 	data->toDesk = clientDesk;
// 	data->fromDesk = 0;
// 	blueSkyDispatchEvent(EventType::SHOW_DAO_JU_ACTION, data);

	CMD_C_USE_PROPERTY*  pData = new CMD_C_USE_PROPERTY();
	pData->wIndex = 4;
	pData->wChairID = DATAPlayerIndesk->getServiceChairID(0);
	pData->wTargetID = DATAPlayerIndesk->getServiceChairID(clientDesk);
	SEND_GAME->SendData(200, 13, pData, sizeof(CMD_C_USE_PROPERTY));

	removeView(this);
}

void PlayerInfoMediator::clickAddFriendBtnHander()
{
	Tools::getInstance()->showSysMsgTouming(UTF8::getInstance()->getString("friend", "req"));
	int targetSvr = DATAPlayerIndesk->chair[clientDesk];
	DWORD  dwTargetId = DATAPlayerIndesk->DeskPlayerInfo[targetSvr].dwUserID;
	SEND->sendFriendOption(DATA->myBaseData.dwUserID, dwTargetId, FriendView::esInvite);
	playerInfoView->btnAddFriend->setColor(Color3B(64, 64, 64));
	playerInfoView->btnAddFriend->setTouchEnabled(false);
}
