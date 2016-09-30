#include "ViewPlayGold.h"
#include "UTF8.h"
#include "SGTools.h"
#include "DataManager.h"
#include "ViewManager.h"
#include "EventType.h"
#include "GameDataModel.h"
#include "PlayerInDeskModel.h"

ViewPlayGold::~ViewPlayGold()
{
	
}
ViewPlayGold* ViewPlayGold::create()
{
	ViewPlayGold * pViewPlayGold = new ViewPlayGold();
	if (pViewPlayGold)
	{
		pViewPlayGold->initView();
		pViewPlayGold->autorelease();
	}
	else
		CC_SAFE_DELETE(pViewPlayGold);
	return pViewPlayGold;
}

void ViewPlayGold::initView()
{
	rootNode = CSLoader::createNode("playGold.csb");
	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	this->addChild(rootNode);

	UIGet_Button("Button_1", rootNode, btn1)
		UIGet_Button("Button_2", rootNode, btn2)
		UIGet_Button("Button_3", rootNode, btn3)

		Node*  topNode;
	Button*  btnBack;
	UIGet_Node("FileNode_1", rootNode, topNode)
	UIGet_Button("Button_close", rootNode, btnBack)
	UIClick(btnBack, ViewPlayGold::clickback)

	btn1->setTag(1);
	btn2->setTag(2);
	btn3->setTag(3);
	UIClick(btn1, ViewPlayGold::clickPlay)
		UIClick(btn2, ViewPlayGold::clickPlay)
		UIClick(btn3, ViewPlayGold::clickPlay)

		UIGet_Text("Text_gold", topNode, txtGold)
		UIGet_Text("Text_diamond", topNode, txtDiamond)
		txtGold->setString(Tools::parseInt2String(DATA->myBaseData.lUserScore));
	txtDiamond->setString(Tools::parseInt2String(DATA->myBaseData.rmb));

}

void ViewPlayGold::updatePlayGold(void* data)
{


}

void ViewPlayGold::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}

void* ViewPlayGold::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}

void ViewPlayGold::clickback(Ref* pSender)
{
	VIEW->hideViewPlayGold();
}

void ViewPlayGold::clickPlay(Ref* pSender)
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