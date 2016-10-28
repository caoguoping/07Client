#include "ViewPopup.h"
#include "DataManager.h"
#include "EventType.h"

ViewPopup::~ViewPopup()
{

}
ViewPopup* ViewPopup::create(DWORD dwKinds, void*  data)
{
	ViewPopup * pViewPopup = new ViewPopup();
	if (pViewPopup)
	{
		pViewPopup->dwKind = dwKinds;
		pViewPopup->friendInvite = (CMD_SUB_C_INVITE_ENTER_GAME*)data;
		pViewPopup->initView();
		pViewPopup->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pViewPopup);
	}
		
	return pViewPopup;
}

void ViewPopup::clickBtnNo(Ref* pSender)
{
	switch (dwKind)
	{
	case ViewPopup::popupFriendInvite:
		this->removeFromParentAndCleanup(true);
		break;

	default:
		break;
	}
}

void ViewPopup::clickBtnOk(Ref* pSender)
{
	switch (dwKind)
	{
	case ViewPopup::popupFriendInvite:

		if (friendInvite->wIsFriend == 1)
		{
			DATA->bGameCate = DataManager::E_GameFriendPassive;
		} 
		else
		{
			DATA->bGameCate = DataManager::E_GameTeamPassive;
		}

		DATA->wFriendPassiveTableId = friendInvite->wTableID;
		DATA->wFriendPassiveChairId = friendInvite->wChairID;
		logV("tableId %d, chairId %d", DATA->wFriendPassiveTableId, DATA->wFriendPassiveChairId = friendInvite->wChairID);

		DispatchEvent(EventType::CONNECT_GAME_SERVICE, new int(0));
		DATAPlayerIndesk->ccNun = 0;
		this->removeFromParentAndCleanup(true);
		break;

	default:
		break;
	}
}

void* ViewPopup::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}

void ViewPopup::clickClose(Ref* pSender)
{
	switch (dwKind)
	{
	case ViewPopup::popupFriendInvite:

		break;

	default:
		break;
	}
}

void ViewPopup::initView()
{
	logP
	switch (dwKind)
	{
	case ViewPopup::popupFriendInvite:
		rootNode = CSLoader::createNode("friendInvite.csb");
		UIGet_Button("Button_OK", rootNode, btnOK)
			UIGet_Button("Button_no", rootNode, btnNo)
			UIGet_Text("Text_name", rootNode, txtName)
			UIGet_Button("Button_close", rootNode, btnClose)
			UIGet_ImageView("Image_close", rootNode, imgCLose)
			btnClose->setVisible(false);
		txtName->setString(friendInvite->strName);
		UIClick(btnOK, ViewPopup::clickBtnOk)
			UIClick(btnNo, ViewPopup::clickBtnNo)

		break;

	default: 
		break;
	}





	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	this->addChild(rootNode);

}

void ViewPopup::updatePopup(void* data)
{



}