#include "PlayerInfoView.h"
#include "SGTools.h"
#include "CallCppHelper.h"
PlayerInfoView::PlayerInfoView()
{
	rootNode = CSLoader::createNode("playerInfo.csb");
	
	addChild(rootNode);

	rootNode->setScale(0.8f, 0.8f);
	rootNode->runAction(Sequence::create(
		ScaleTo::create(0.2f, 1.03f),
		ScaleTo::create(0.15f, 1.0f),
		nullptr));
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayerInfoView, closeBtn, 10701, "closeBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayerInfoView, eggBtn, 10702, "eggBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayerInfoView, boomBtn, 10703, "boomBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayerInfoView, heartBtn, 10704, "heartBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayerInfoView, flowerBtn, 10705, "flowerBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PlayerInfoView, addFriendBtn, 10706, "addFriendBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, PlayerInfoView, Image_close, 10701, "Image_1", NULL)


//	_Image_1->setGlobalZOrder(11);   //¸Ç¹ýplaySceneLayer

	UIGet_Text("nameText", rootNode, txtName)
	UIGet_Text("Text_id", rootNode, txtId)
	Sprite  *spMy, *spOther;
	UIGet_Sprite("zi01_me", rootNode, spMy)
		UIGet_Sprite("zi01_other", rootNode, spOther)
		spMy->setVisible(false);
	spOther->setVisible(true);

	UIGet_Text("Text_gold", rootNode, txtGold)
		Layout*   lyDiamond;
	UIGet_Layout("Panel_diamond", rootNode, lyDiamond)
		lyDiamond->setVisible(false);

		Button*  btnAddFriend;
	UIGet_Button("addFriendBtn", rootNode, btnAddFriend)
		btnAddFriend->setVisible(true);


	txtId->setString(CallCppHelper::getInstance()->mUid);


}




PlayerInfoView::~PlayerInfoView()
{
	delete rootNode;
	rootNode = NULL;
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayerInfoView, closeBtn, 10701);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayerInfoView, eggBtn, 10702);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayerInfoView, boomBtn, 10703);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayerInfoView, heartBtn, 10704);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayerInfoView, flowerBtn, 10705);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayerInfoView, addFriendBtn, 10706);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PlayerInfoView, Image_close, 10701);
}