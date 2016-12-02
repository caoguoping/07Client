#include "MallView.h"
#include "EventType.h"
#include "GameDataModel.h"
#include "SGTools.h"
#include "DataManager.h"
#include "ShopMediator.h"
#include "ShopView.h"
#include "SetMediator.h"
#include "SetView.h"


MallView::MallView()
{
	rootNode = CSLoader::createNode("mall.csb");
	addChild(rootNode);
	rootNode->setScale(0.8f, 0.8f);
	rootNode->runAction(Sequence::create(
		ScaleTo::create(0.2f, 1.03f),
		ScaleTo::create(0.15f, 1.0f),
		nullptr));
	mallItem[E_activity] = rootNode->getChildByName("FileNode_activity");
	mallItem[E_zuanshi] = rootNode->getChildByName("FileNode_zuanshi");
	currentTitle = E_activity;

	UIGet_Button("closeBtn", rootNode, closeBtn)
	UIGet_CheckBox("activityBtn", rootNode, activityBtn)
	UIGet_CheckBox("zuanShiBtn", rootNode, zuanShiBtn)
	BTN_EVENT(closeBtn, 11201)
	BTN_EVENT(activityBtn, 11202)
	BTN_EVENT(zuanShiBtn, 11203)
}

MallView::~MallView()
{

}



void MallView::initView()
{


	Size size = Director::getInstance()->getVisibleSize();
	rootNode->setPosition(Vec2(size.width / 2,size.height / 2));
	ScrollView  *scrItem;
	UIGet_ScrollView("ScrollView_1", mallItem[E_activity], scrItem)
		UIGet_ImageView("Image_0", scrItem, imgHuodong[0])
		UIGet_ImageView("Image_1", scrItem, imgHuodong[1])
		UIGet_Button("Button_buy", imgHuodong[0], btnHuodong[0])
		UIGet_Button("Button_buy", imgHuodong[1], btnHuodong[1])

		ScrollView  *scrItem2;
	UIGet_ScrollView("ScrollView_1", mallItem[E_zuanshi], scrItem2)
		char temp[64];
	for (int i = 0; i < 5; i++)
	{
		sprintf(temp, "Image_%d", i);
		UIGet_ImageView(temp, scrItem2, imgZuanshi[i])
			UIGet_Button("Button_buy",imgZuanshi[i], btnZuanshi[i])
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
	btnSetting->addClickEventListener([&](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
		creatView(new SetView(), new SetMediator());
	}
	);



	//activity 0
	btnHuodong[0]->addClickEventListener([this](Ref* psender)
		{
			PLayEffect(EFFECT_BTN)
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11211, -1));
		}
	);

	//activity 1
	btnHuodong[1]->addClickEventListener([this](Ref* psender)
		{
			PLayEffect(EFFECT_BTN)
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11212, -1));
		}
	);


	btnZuanshi[0]->addClickEventListener([this](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11213, -1));
	}
	);
	btnZuanshi[1]->addClickEventListener([this](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11214, -1));
	}
	);

	btnZuanshi[2]->addClickEventListener([this](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11215, -1));
	}
	);

	btnZuanshi[3]->addClickEventListener([this](Ref* psender)
	{
		PLayEffect(EFFECT_BTN)
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11216, -1));
	}
	);

	btnZuanshi[4]->addClickEventListener([this](Ref* psender)
	{ 
		//jipaiqi	
		PLayEffect(EFFECT_BTN)
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11217, -1));
	}
	);
	
	showActivityView();
}

void MallView::showActivityView()
{
	activityBtn->setSelected(true);
	zuanShiBtn->setSelected(false);
	activityBtn->setTouchEnabled(false);
	zuanShiBtn->setTouchEnabled(true);

	mallItem[E_activity]->setVisible(true);
	mallItem[E_zuanshi]->setVisible(false);
}

void MallView::showZuanShiView()
{
	 	activityBtn->setSelected(false);
	 	zuanShiBtn->setSelected(true);
		activityBtn->setTouchEnabled(true);
		zuanShiBtn->setTouchEnabled(false);
		mallItem[E_activity]->setVisible(false);
		mallItem[E_zuanshi]->setVisible(true);
}

void MallView::showGoldView()
{


}

void MallView::showRewardView()
{

}


/*
	显示商品标题
	switch (wIndex)
	{
		//双倍金币卡
	case 6:
		Image_7->setVisible(true);
		break;

		//双倍经验卡
	case 7:
		Image_8->setVisible(true);
		break;

		//记牌器
	case 8:
		Image_9->setVisible(true);
		break;
		
		//小喇叭
	case 9:
		break;
		//大喇叭
	case 10:
		break;
		//入场券
	case 11:
		break;
		//蓝钻
	case 12:
		break;
		//白钻
	case 13:
		break;
		//红钻
	case 14:
		break;
	}
}
*/
/*
	显示商品图片
	参数：index:商品编号，goodsType:商品类别（1：金币，2：钻石，3：道具）
	     wIndex:商品量（1~7）或道具类别（6：双倍金币卡，7：双倍积分卡，8：记牌器，9：小喇叭，10：大喇叭，11：入场券，12：蓝钻，13：白钻，14：红钻）
*/


//

/***	switch (value)
	{
		//双倍金币卡
	case 6:
		doubleGoldImage->setVisible(true);
		break;
		//双倍积分卡
	case 7:
		doubleExpImage->setVisible(true);
		break;
		//记牌器
	case 8:
		jiPaiQiImage->setVisible(true);
		break;
		//小喇叭
	case 9:
		break;
		//大喇叭
	case 10:
		break;
		//入场券
	case 11:
		break;
		//蓝钻
	case 12:
		break;
		//白钻
	case 13:
		break;
		//红钻
	case 14:
		break;
	}
	*/


void MallView::showMyZuanShi(int num)
{
	txtDiamond->setString(Tools::parseInt2String(num));
}
void MallView::showMyGold(int num)
{
	txtGold->setString(Tools::parseInt2String(num));
}
