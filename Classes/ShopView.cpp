#include "ShopView.h"
#include "DataManager.h"
#include "BlueSky.h"
#include "EventType.h"
#include "GameDataModel.h"
#include "SetMediator.h"
#include "SetView.h"

ShopView::ShopView(int id)
{
	rootNode = CSLoader::createNode("shop.csb");
	addChild(rootNode);
	rootNode->setScale(0.8f, 0.8f);
	rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.03f), ScaleTo::create(0.15f, 1.0f), nullptr));
	shopID = id;
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, ShopView, zhuanShiBtn, 10801, "zhuanShiBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, ShopView, goldBtn, 10802, "goldBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, ShopView, closeBtn, 10803, "closeBtn", NULL)

	UIGet_Node("FileNode_zuanshi", rootNode, shopItem[E_zuanshi])
	UIGet_Node("FileNode_jinbi", rootNode, shopItem[E_gold])
	currentTitle = id;


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
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		creatView(new SetView(), new SetMediator());
	}
	);






	Button* btnZuanTejia = static_cast<Button*>(shopItem[E_zuanshi]->getChildByName("Button_zhuanshi"));
	btnZuanTejia->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10804, -1));
	}
	);

	ScrollView*  scrZuanshi, *scrGold;
	UIGet_ScrollView("ScrollView_1", shopItem[E_zuanshi], scrZuanshi)
		UIGet_ScrollView("ScrollView_1", shopItem[E_gold], scrGold)
		Button* btnZuanTejia1 = static_cast<Button*>(scrZuanshi->getChildByName("Button_1"));
	btnZuanTejia1->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10805, -1));
	}
	);

	Button* btnZuanTejia2 = static_cast<Button*>(scrZuanshi->getChildByName("Button_1_0"));
	btnZuanTejia2->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10806, -1));
	}
	);

	Button* btnZuanTejia3 = static_cast<Button*>(scrZuanshi->getChildByName("Button_1_2"));
	btnZuanTejia3->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10807, -1));
	}
	);

	Button* btnZuanTejia4 = static_cast<Button*>(scrZuanshi->getChildByName("Button_1_2_0"));
	btnZuanTejia4->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10808, -1));
	}
	);

	//jinbi
	Button* tnZuanTejia = static_cast<Button*>(shopItem[E_gold]->getChildByName("Button_zhuanshi"));
	tnZuanTejia->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10809, -1));
	}
	);

	Button* tnZuanTejia1 = static_cast<Button*>(scrGold->getChildByName("Button_1"));
	tnZuanTejia1->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10810, -1));
	}
	);

	Button* tnZuanTejia2 = static_cast<Button*>(scrGold->getChildByName("Button_1_0"));
	tnZuanTejia2->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10811, -1));
	}
	);

	Button* tnZuanTejia3 = static_cast<Button*>(scrGold->getChildByName("Button_1_2"));
	tnZuanTejia3->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10812, -1));
	}
	);

	Button* tnZuanTejia4 = static_cast<Button*>(scrGold->getChildByName("Button_1_2_0"));
	tnZuanTejia4->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 10813, -1));
	}
	);

}

void ShopView::initView()
{
	switch (shopID)
	{

	case 0:
		showZuanShiView();
		break;
	case 1:
		showGoldView();
		break;

	default:
		break;
	}
}

void ShopView::showMyZuanShi(int num)
{
	txtDiamond->setString(Tools::parseInt2String(num));
}
void ShopView::showMyGold(int num)
{
	txtGold->setString(Tools::parseInt2String(num));
}

ShopView::~ShopView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(ShopView, zhuanShiBtn, 10801);
	BTN_REMOVE_TOUCH_EVENTLISTENER(ShopView, goldBtn, 10802);
	BTN_REMOVE_TOUCH_EVENTLISTENER(ShopView, closeBtn, 10803);

	delete rootNode;
	rootNode = NULL;

}

void ShopView::showZuanShiView()
{
	_zhuanShiBtn->setSelected(true);
	_goldBtn->setSelected(false);
	_zhuanShiBtn->setTouchEnabled(false);
	_goldBtn->setTouchEnabled(true);
	shopItem[E_zuanshi]->setVisible(true);
	shopItem[E_gold]->setVisible(false);


}

void ShopView::showGoldView()
{
	_zhuanShiBtn->setSelected(false);
	_goldBtn->setSelected(true);
	_zhuanShiBtn->setTouchEnabled(true);
	_goldBtn->setTouchEnabled(false);
	shopItem[E_zuanshi]->setVisible(false);
	shopItem[E_gold]->setVisible(true);
}

