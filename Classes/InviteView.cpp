#include "InviteView.h"
#include "SGTools.h"
#include "DataManager.h"

InviteView::InviteView()
{
	rootNode = CSLoader::createNode("invite.csb");
	addChild(rootNode);
	BTN_ADD_TOUCH_EVENTLISTENER(Button,InviteView, closeBtn, 17000, "closeBtn", NULL)
}

InviteView::~InviteView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(InviteView, closeBtn, 17000);
	delete rootNode;
	rootNode = NULL;
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

	int itemSize = DATA->vFriends.size();
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
			txtName->setString(DATA->vFriends.at(i).szNickName);

		sprintf(headName, "headshot_%d.png", DATA->vFriends.at(i).FaceID);
		imgHead->loadTexture(headName);
		lstInvite->pushBackCustomItem(oneLayout);

	}
}


void InviteView::clickInvite(Ref* pSender)
{

}