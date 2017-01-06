#include "PlayerInfoView.h"
#include "SGTools.h"
#include "CallCppHelper.h"
#include "ViewManager.h"
PlayerInfoView::PlayerInfoView()
{
	rootNode = CSLoader::createNode("playerInfo.csb");
	addChild(rootNode);

    Button  *closeBtn, *eggBtn,  *boomBtn,  *heartBtn,  *flowerBtn, *addFriendBtn;
    UIGet_Button("closeBtn", rootNode,     closeBtn)
    UIGet_Button("eggBtn", rootNode,       eggBtn)
    UIGet_Button("boomBtn", rootNode,      boomBtn)
    UIGet_Button("heartBtn", rootNode,     heartBtn)
    UIGet_Button("flowerBtn", rootNode,    flowerBtn)
    UIGet_Button("addFriendBtn", rootNode, addFriendBtn)
    


	ImageView* imgClose, *imgBg;

	UIGet_ImageView("Image_1", rootNode, imgClose)
		UIGet_ImageView("Image_bg", rootNode, imgBg)

	BTN_EVENT(closeBtn, 10701)
	BTN_EVENT(eggBtn, 10702)
	BTN_EVENT(boomBtn, 10703)
	BTN_EVENT(heartBtn, 10704)
	BTN_EVENT(flowerBtn, 10705)
	BTN_EVENT(addFriendBtn, 10706)
	BTN_EVENT(imgClose, 10701)

	//Ñ¹×¡playerInfo
	imgClose->setGlobalZOrder(GOrderPlayerHead + 2);
	imgBg->setGlobalZOrder(GOrderPlayerHead + 2);
	closeBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	eggBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	boomBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	heartBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	flowerBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	addFriendBtn->setGlobalZOrder(GOrderPlayerHead + 2);

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


	UIGet_Button("addFriendBtn", rootNode, btnAddFriend)
		btnAddFriend->setVisible(true);


	txtId->setString(CallCppHelper::getInstance()->mUid);


}




PlayerInfoView::~PlayerInfoView()
{

}
