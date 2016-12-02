#include "MyInfoView.h"
#include "SGTools.h"
#include "CallCppHelper.h"
#include "ShopMediator.h"
#include "ShopView.h"
#include "ViewManager.h"

MyInfoView::MyInfoView()
{
	rootNode = CSLoader::createNode("playerInfo.csb");
	addChild(rootNode);
    Button*  closeBtn;
    ImageView*   Image_1;
    UIGet_Button("closeBtn", rootNode, closeBtn)
    UIGet_ImageView("Image_1", rootNode, Image_1)
	BTN_EVENT(closeBtn, 11701)
	BTN_EVENT(Image_1, 11701)
}

MyInfoView::~MyInfoView()
{
	delete rootNode;
	rootNode = NULL;
}

void MyInfoView::initView()
{
	UIGet_Text("nameText", rootNode, txtName)
		UIGet_Text("Text_id", rootNode, txtId)
		Sprite  *spMy, *spOther;
	UIGet_Sprite("zi01_me", rootNode, spMy)
		UIGet_Sprite("zi01_other", rootNode, spOther)
		spMy->setVisible(true);
	spOther->setVisible(false);



	Button  *btnAddGold, *btnAddDiamond;
	UIGet_Text("Text_gold", rootNode, txtGold)
		UIGet_Button("Button_addGold", rootNode, btnAddGold)
		Layout*   lyDiamond;
	UIGet_Layout("Panel_diamond", rootNode, lyDiamond)
		UIGet_Text("Text_diamond", lyDiamond, txtDiamond)

		UIGet_Button("Button_addDiamond", lyDiamond, btnAddDiamond)

		btnAddGold->addClickEventListener([&](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
		creatView(new ShopView(1), new ShopMediator());
	}
	);
	btnAddDiamond->addClickEventListener([&](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
		creatView(new ShopView(0), new ShopMediator());
	}
	);


		Button*  btnAddFriend;
	UIGet_Button("addFriendBtn", rootNode, btnAddFriend)
		btnAddFriend->setVisible(false);


	txtId->setString(CallCppHelper::getInstance()->mUid);


	char temp[64];
	Text*   txtBeiza[4];
	for (int i = 0; i < 4; i++)
	{
		sprintf(temp, "Text_%d", i);
		UIGet_Text(temp, rootNode, txtBeiza[i])
			txtBeiza[i]->setVisible(true);
			txtBeiza[i]->setString(Tools::parseInt2String(DATA->myBaseData.wBeiZaNum[i]));
	}

}

void MyInfoView::showGold(int num)
{
	txtGold->setString(Tools::parseInt2String(num));
}

void MyInfoView::showZhuanShi(int num)
{
	txtDiamond->setString(Tools::parseInt2String(num));
}

void MyInfoView::showFace(int faceID)
{
	auto headNode = rootNode->getChildByName("headNode");
	ImageView* image1 = dynamic_cast<ImageView*>(headNode->getChildByName("character_1"));
	ImageView* image2 = dynamic_cast<ImageView*>(headNode->getChildByName("character_2"));
	ImageView* image3 = dynamic_cast<ImageView*>(headNode->getChildByName("character_3"));
	ImageView* image4 = dynamic_cast<ImageView*>(headNode->getChildByName("character_4"));
	switch (faceID)
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



void MyInfoView::showName(string name)
{
	txtName->setString(name);
}
