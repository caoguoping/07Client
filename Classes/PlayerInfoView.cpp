#include "PlayerInfoView.h"
#include "SGTools.h"
#include "CallCppHelper.h"
#include "ViewManager.h"
PlayerInfoView::PlayerInfoView()
{
	rootNode = CSLoader::createNode("playerInfo.csb");
	addChild(rootNode);


	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("playerInfo.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);

	Sprite*  spBg;
	UIGet_Sprite("ImageFrame", rootNode, spBg)

	
	UIGet_Button("closeBtn", spBg, closeBtn)
		UIGet_Button("eggBtn", spBg, eggBtn)
		UIGet_Button("boomBtn", spBg, boomBtn)
		UIGet_Button("heartBtn", spBg, heartBtn)
		UIGet_Button("flowerBtn", spBg, flowerBtn)
		UIGet_Button("addFriendBtn", spBg, addFriendBtn)
		UIGet_Button("Button_addGold", spBg, btnAddGold)
		btnAddGold->setVisible(false);

	ImageView* imgClose;


	UIGet_ImageView("Image_1", rootNode, imgClose)

	BTN_EVENT(closeBtn, 10701)
	BTN_EVENT(eggBtn, 10702)
	BTN_EVENT(boomBtn, 10703)
	BTN_EVENT(heartBtn, 10704)
	BTN_EVENT(flowerBtn, 10705)
	BTN_EVENT(addFriendBtn, 10706)
	BTN_EVENT(imgClose, 10701)

	//ѹסplayerInfo
	imgClose->setGlobalZOrder(GOrderPlayerHead + 2);
	closeBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	eggBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	boomBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	heartBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	flowerBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	addFriendBtn->setGlobalZOrder(GOrderPlayerHead + 2);



	UIGet_Text("nameText", spBg, txtName)
		UIGet_Text("Text_id", spBg, txtId)
	Sprite  *spMy, *spOther;
	UIGet_Sprite("zi01_me", spBg, spMy)
		UIGet_Sprite("zi01_other", spBg, spOther)
		spMy->setVisible(false);
	spOther->setVisible(true);

	UIGet_Text("Text_gold", spBg, txtGold)
		Layout*   lyDiamond;
	UIGet_Layout("Panel_diamond", spBg, lyDiamond)
		lyDiamond->setVisible(false);


	UIGet_Button("addFriendBtn", spBg, btnAddFriend)
		btnAddFriend->setVisible(true);


	txtId->setString(CallCppHelper::getInstance()->mUid);


}

PlayerInfoView::~PlayerInfoView()
{

}
