#include "BloodView.h"
#include "UTF8.h"
#include "SGTools.h"
#include "DataManager.h"
#include "ShopMediator.h"
#include "ShopView.h"
#include "SetMediator.h"
#include "SetView.h"
#include "ViewManager.h"
#include "EventType.h"
#include "GameDataModel.h"
#include "PlayerInDeskModel.h"

BloodView::BloodView()
{

}

BloodView::~BloodView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(BloodView, closeBtn, 12800);
	delete rootNode;
	rootNode = NULL;
}

void BloodView::initView()
{
	rootNode = CSLoader::createNode("blood.csb");
	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	this->addChild(rootNode);

	BTN_ADD_TOUCH_EVENTLISTENER(Button, BloodView, closeBtn, 12800, "Button_close", NULL)


	UIGet_Button("Button_1", rootNode, btn1)
		UIGet_Button("Button_2", rootNode, btn2)
		UIGet_Button("Button_3", rootNode, btn3)

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
		btnAddGold->addClickEventListener([&](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		creatView(new ShopView(1), new ShopMediator());
	}
	);
	btnAddDiamond->addClickEventListener([&](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		creatView(new ShopView(0), new ShopMediator());
	}
	);
	btnSetting->addClickEventListener([&](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		creatView(new SetView(), new SetMediator());
	}
	);

		btn1->setTag(1);
	btn2->setTag(2);
	btn3->setTag(3);
	UIClick(btn1, BloodView::clickPlay)
		UIClick(btn2, BloodView::clickPlay)
		UIClick(btn3, BloodView::clickPlay)



}

void BloodView::clickPlay(Ref* pSender)
{
	Button*  btn = static_cast<Button*>(pSender);
	int tags = btn->getTag();
	long long golds = DATA->myBaseData.lUserScore;
	DATA->bGameCate = DataManager::E_GameCateNormal;
	switch (tags)
	{
	case 1:

		if (golds < 500)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE, new int(0));
			((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->ccNun = 0;
		}
		break;
	case 2:
		if (golds < 2000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE, new int(1));
			((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->ccNun = 1;

		}
		break;
	case 3:
		if (golds < 10000)
		{
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "warning", "warning2", 30001, -1));
		}
		else
		{
			blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE, new int(2));
			((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->ccNun = 2;
		}
		break;
	default:
		break;
	}


}