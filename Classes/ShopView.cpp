#include "ShopView.h"
#include "DataManager.h"
#include "BlueSky.h"
#include "EventType.h"
#include "GameDataModel.h"
#include "SetMediator.h"
#include "SetView.h"
#include "ViewManager.h"
#include "SGTools.h"

ShopView::ShopView(int id)
{
	rootNode = CSLoader::createNode("shop.csb");
	addChild(rootNode);
	rootNode->setScale(0.8f, 0.8f);
	rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.03f), ScaleTo::create(0.15f, 1.0f), nullptr));
	shopID = id;

	UIGet_CheckBox("zhuanShiBtn", rootNode, zhuanShiBtn)
		UIGet_CheckBox("goldBtn", rootNode, goldBtn)
		UIGet_Button("closeBtn", rootNode, closeBtn)
		UIClickCheck(zhuanShiBtn, ShopView::showZuanShiView)
		UIClickCheck(goldBtn, ShopView::showGoldView)
	BTN_EVENT(closeBtn, 10803	)

	UIGet_Node("FileNode_zuanshi", rootNode, shopItem[E_zuanshi])
	UIGet_Node("FileNode_jinbi", rootNode, shopItem[E_gold])
	currentTitle = id;

	Button*  chargeBtns[10];
	ScrollView*  scrZuanshi, *scrGold;
	UIGet_ScrollView("ScrollView_1", shopItem[E_zuanshi], scrZuanshi)
	UIGet_ScrollView("ScrollView_1", shopItem[E_gold], scrGold)

	UIGet_Button("Button_0", shopItem[E_zuanshi], chargeBtns[0])
	UIGet_Button("Button_1", scrZuanshi, chargeBtns[1])
	UIGet_Button("Button_2", scrZuanshi, chargeBtns[2])
	UIGet_Button("Button_3", scrZuanshi, chargeBtns[3])
	UIGet_Button("Button_4", scrZuanshi, chargeBtns[4])

	UIGet_Button("Button_5", shopItem[E_gold], chargeBtns[5])
	UIGet_Button("Button_6", scrGold, chargeBtns[6])
	UIGet_Button("Button_7", scrGold, chargeBtns[7])
	UIGet_Button("Button_8", scrGold, chargeBtns[8])
	UIGet_Button("Button_9", scrGold, chargeBtns[9])

	for (int i = 0; i < 10; i ++)
	{
		chargeBtns[i]->setTag(i);
		UIClick(chargeBtns[i], ShopView::clickChargeBtn)
	}

	//top
	Node*  topNode;
	UIGet_Node("FileNode_top", rootNode, topNode)
		UIGet_Text("Text_gold", topNode, txtGold)
		UIGet_Text("Text_diamond", topNode, txtDiamond)
		txtGold->setString(Tools::parseInt2String(DATA->myBaseData.lUserScore));
	txtDiamond->setString(Tools::parseInt2String(DATA->myBaseData.rmb));
	Button   *btnAddGold, *btnAddDiamond, *btnSetting;
	UIGet_Button("Button_addGold", topNode, btnAddGold)
		UIGet_Button("Button_addDiamond", topNode, btnAddDiamond)
		UIGet_Button("Button_setting", topNode, btnSetting)
		btnAddDiamond->setTouchEnabled(false);
	btnAddGold->setTouchEnabled(false);

	btnSetting->addClickEventListener([&](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
			creatView(new SetView(), new SetMediator());
	}
	);
}

void ShopView::initView()
{
	switch (shopID)
	{

	case 0:
		showZuanShiView(NULL, CheckBox::EventType::SELECTED);
		break;
	case 1:
		showGoldView(NULL, CheckBox::EventType::SELECTED);
		break;

	default:
		break;
	}
}

void ShopView::showMyZuanShi(int num)
{
	txtDiamond->setString(Tools::parseInt2String(num));
}
void ShopView::showMyGold(SCORE num)
{
	txtGold->setString(Tools::parseInt2String(num));
}

ShopView::~ShopView()
{
	delete rootNode;
	rootNode = NULL;

}

void ShopView::showZuanShiView(Ref*  pSender, CheckBox::EventType type)
{
	PLayEffect(EFFECT_BTN);
	zhuanShiBtn->setSelected(true);
	goldBtn->setSelected(false);
	zhuanShiBtn->setTouchEnabled(false);
	goldBtn->setTouchEnabled(true);
	shopItem[E_zuanshi]->setVisible(true);
	shopItem[E_gold]->setVisible(false);


}

void ShopView::showGoldView(Ref*  pSender, CheckBox::EventType type)
{
	zhuanShiBtn->setSelected(false);
	goldBtn->setSelected(true);
	zhuanShiBtn->setTouchEnabled(true);
	goldBtn->setTouchEnabled(false);
	shopItem[E_zuanshi]->setVisible(false);
	shopItem[E_gold]->setVisible(true);
}

void ShopView::clickChargeBtn(Ref* pSender)
{
	Button*  btn = static_cast<Button*>(pSender);
	int itags = btn->getTag();
	PLayEffect(EFFECT_BTN)
	blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", (10804 + itags), -1));
}
