#include "InviteView.h"
#include "SGTools.h"
#include "DataManager.h"
#include "SendDataService.h"
#include "TCPSocketService.h"

InviteView::InviteView(int i)
{
	iChairId = i;
	rootNode = CSLoader::createNode("invite.csb");
	addChild(rootNode);
		UIGet_Button("closeBtn", rootNode, closeBtn)
		BTN_EVENT(closeBtn, 17000)
}

InviteView::~InviteView()
{

}

void InviteView::initView()
{
	UIGet_ListView("ListView_invite", rootNode, lstInvite)
		showFriends();
}

void InviteView::showFriends()
{
	int itemHeigth = 99;
	int halfItemWidth = 350 * 0.5;
	lstInvite->removeAllChildrenWithCleanup(true);
	lstInvite->setItemsMargin(itemHeigth + 10);

	int itemSize = DATA->vFriendLine.size();
	for (int i = 0; i < itemSize; i++)
	{
		Node* oneNode = CSLoader::createNode("InviteCell.csb");
		Layout*  oneLayout = Layout::create();
		oneLayout->addChild(oneNode);
		oneNode->setPosition(Vec2(halfItemWidth, -itemHeigth * 0.5 - 10));

		char headName[64];
		Text   *txtName;
		ImageView*  imgHead;
		Button*   btnAdd;

		UIGet_Text("Text_name", oneNode, txtName)
			UIGet_ImageView("Image_head", oneNode, imgHead)
			UIGet_Button("Button_join", oneNode, btnAdd)
			btnAdd->setTag(i);
		UIClick(btnAdd, InviteView::clickInvite)
			txtName->setString(DATA->vFriendLine.at(i).szNickName);

		sprintf(headName, "headshot_%d.png", DATA->vFriendLine.at(i).FaceID);
		imgHead->loadTexture(headName);
		lstInvite->pushBackCustomItem(oneLayout);

	}
	Layout*   layoutFate = Layout::create();
	lstInvite->pushBackCustomItem(layoutFate);
}


void InviteView::clickInvite(Ref* pSender)
{
	Button*   btnInvite = static_cast<Button*>(pSender);
	int iWhich = btnInvite->getTag();
	

	CMD_SUB_S_INVITE_ENTER_GAME stInvite;
	stInvite.dwTargetID = DATA->vFriendLine.at(iWhich).dwUserID; //target id
	stInvite.dwUserID = DATA->myBaseData.dwUserID;
	stInvite.wChairID = DATA->wFriendFieldChairId + iChairId;
	stInvite.wTableID = DATA->wFriendFieldTableId;
	stInvite.wGameID = 2;
	if (DATA->bGameCate == DataManager::E_GameFriend)
	{
		stInvite.wIsFriend = 1;
	} 
	else if (DATA->bGameCate == DataManager::E_GameTeam)
	{
		stInvite.wIsFriend = 0;
	}


	/*memcpy(stInvite.strName, DATA->vFriendLine.at(iWhich).szNickName.c_str(), 64);*/
	memcpy(stInvite.strName, DATA->myBaseData.szNickName.c_str() , 64);
	SEND_LOGIN->SendData(6, 15, &stInvite, sizeof(CMD_SUB_S_INVITE_ENTER_GAME));

	blueSkyDispatchEvent(17000);
}