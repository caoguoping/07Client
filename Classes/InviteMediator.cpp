#include "InviteMediator.h"
#include "UILayerService.h"

InviteMediator::InviteMediator()
{

}

InviteMediator::~InviteMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void InviteMediator::OnRegister()
{
	inviteView = (InviteView*)getView();

	inviteView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
��������ִ�к���
*/
void InviteMediator::onRemove()
{

}

void InviteMediator::handleOndeskInfo(void* data)
{
	OnDeskPlayerInfo  onDeskInfo = *(OnDeskPlayerInfo*)data;
	int clientChairId = DATAPlayerIndesk->chair[onDeskInfo.wChairID % 4];


}

/*
�¼���Ӧ����
*/
void InviteMediator::onEvent(int i, void* data)
{

	switch (i)
	{
	case 17000:
		clickCloseBtnHander();
		break;

	case OTHER_PLAYER_ON_DESK:
		handleOndeskInfo(data);
		break;
	}
}

Layer* InviteMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

void InviteMediator::clickCloseBtnHander()
{
	removeView(this);
}
