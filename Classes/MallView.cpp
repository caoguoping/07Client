#include "MallView.h"
#include "EventType.h"
#include "GameDataModel.h"
#include "SGTools.h"


/*
1.  120钻 100000金币  特价
2.  1钻   500金币
3.  36钻  18000金币
4.  90钻  45000金币
5.  160钻 80000金币


*/


MallView::MallView()
{
	rootNode = CSLoader::createNode("mall.csb");
	addChild(rootNode);
	//rootNode->setScale(0.1, 0.1);
	//rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.03), ScaleTo::create(0.1f, 1.0f), nullptr));

	actScrow =   static_cast<PageView*>( rootNode->getChildByName("PageView_2"));
	mallItem[E_activity] = actScrow->getChildByName("Panel_2")->getChildByName("FileNode_activity");
	mallItem[E_zuanshi] = actScrow->getChildByName("Panel_4")->getChildByName("FileNode_zuanshi");
	currentTitle = E_activity;

	BTN_ADD_TOUCH_EVENTLISTENER(Button, MallView, closeBtn, 11201, "closeBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, MallView, Image_99999, 99999, "Image_1", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, MallView, activityBtn, 11202, "activityBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, MallView, zuanShiBtn, 11203, "zuanShiBtn", NULL)
}

MallView::~MallView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(MallView, closeBtn, 11201);
	BTN_REMOVE_TOUCH_EVENTLISTENER(MallView, Image_99999, 99999);
	BTN_REMOVE_TOUCH_EVENTLISTENER(MallView, activityBtn, 11202);
	BTN_REMOVE_TOUCH_EVENTLISTENER(MallView, zuanShiBtn, 11203);
	unschedule(schedule_selector(MallView::updateTitle));
}


void MallView::updateTitle(float dt)
{
	ssize_t index = actScrow->getCurrentPageIndex();
	if (index == currentTitle)
	{
		return;
	} 
	else
	{
		currentTitle = index;
		switch (index)
		{
		case E_activity:
			_activityBtn->setSelected(true);
			_zuanShiBtn->setSelected(false);

			_activityBtn->setTouchEnabled(false);
			_zuanShiBtn->setTouchEnabled(true);

			break;

		case E_zuanshi:

			_activityBtn->setSelected(false);
			_zuanShiBtn->setSelected(true);

			_activityBtn->setTouchEnabled(true);
			_zuanShiBtn->setTouchEnabled(false);
			break;

		default:
			break;
		}
	}
	
}

void MallView::initView()
{


	Size size = Director::getInstance()->getVisibleSize();
	rootNode->setPosition(Vec2(size.width / 2,size.height / 2));


	Button* btnActzshi = static_cast<Button*>( mallItem[E_activity]->getChildByName("Button_18")); //精致礼包
	Button* btnActGold = static_cast<Button*>(mallItem[E_activity]->getChildByName("Button_18_0")); //豪华礼包

	Button* btnGoldChange1 = static_cast<Button*>(mallItem[E_zuanshi]->getChildByName("Button_11"));
	Button* btnGoldChange2 = static_cast<Button*>(mallItem[E_zuanshi]->getChildByName("Button_11_0"));
	Button* btnGoldChange3 = static_cast<Button*>(mallItem[E_zuanshi]->getChildByName("Button_11_1"));
	Button* btnGoldChange4 = static_cast<Button*>(mallItem[E_zuanshi]->getChildByName("Button_11_2"));
	Button* btnJiPaiqi = static_cast<Button*>(mallItem[E_zuanshi]->getChildByName("Button_11_2_0"));
	
	Node*  topNode;
	UIGet_Node("FileNode_1", rootNode, topNode)
		UIGet_Text("Text_gold", topNode, txtGold)
		UIGet_Text("Text_diamond", topNode, txtDiamond)

	schedule(schedule_selector(MallView::updateTitle), 0.5f);

	//activity 0
	btnActzshi->addClickEventListener([this](Ref* psender)
		{
			SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11211, -1));
		}
	);

	//activity 1
	btnActGold->addClickEventListener([this](Ref* psender)
		{
			SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11212, -1));
		}
	);


	btnGoldChange1->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11213, -1));
	}
	);
	btnGoldChange2->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11214, -1));
	}
	);

	btnGoldChange3->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11215, -1));
	}
	);

	btnGoldChange4->addClickEventListener([this](Ref* psender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11216, -1));
	}
	);

	btnJiPaiqi->addClickEventListener([this](Ref* psender)
	{ 
		//jipaiqi	
		SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
		blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warningBuy", 11217, -1));
	}
	);
	

}

void MallView::showActivityView()
{
	_activityBtn->setSelected(true);
	_zuanShiBtn->setSelected(false);


	_activityBtn->setTouchEnabled(false);
	_zuanShiBtn->setTouchEnabled(true);


// 	for (int i = E_activity; i < E_mallMax; i++)
// 	{
// 		mallItem[i]->setVisible(false);
// 	}
// 	mallItem[E_activity]->setVisible(true);
	actScrow->scrollToPage(E_activity);

}

void MallView::showZuanShiView()
{
	 	_activityBtn->setSelected(false);
	 	_zuanShiBtn->setSelected(true);


		_activityBtn->setTouchEnabled(true);
		_zuanShiBtn->setTouchEnabled(false);

// 		for (int i = E_activity; i < E_mallMax; i++)
// 		{
// 			mallItem[i]->setVisible(false);
// 		}
// 		mallItem[E_zuanshi]->setVisible(true);
		actScrow->scrollToPage(E_zuanshi);


}

void MallView::showGoldView()
{


}

void MallView::showRewardView()
{

}

void MallView::showMall(int mallType)
{

}

//
void MallView::actionNodeShow(int index)
{
	auto guangQuanNode = mallShowNode.at(index)->getChildByName("guangQuanNode");
	auto teJiaNode = mallShowNode.at(index)->getChildByName("teJiaNode");
	auto reXiaoNode = mallShowNode.at(index)->getChildByName("reXiaoNode");
	auto xianShiNode = mallShowNode.at(index)->getChildByName("xianShiNode");
	teJiaNode->setVisible(false);
	xianShiNode->setVisible(false);
}

void MallView::actionShow(float dt)
{
	for (int i = 0; i < mallShowNode.size(); i++)
	{
		reXiaoActionArr.at(i)->gotoFrameAndPlay(0, 12, false);
	}
}

/*
	显示商品标题
*/
void MallView::titleShow(int index, int wIndex)
{
	Node* mallTitleNode = mallShowNode.at(index)->getChildByName("mallTitleNode");

	ImageView* Image_1 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_1")); //1万金豆
	ImageView* Image_2 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_2")); //12万金豆
	ImageView* Image_3 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_3")); //40万金豆
	ImageView* Image_4 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_4")); //72万金豆
	ImageView* Image_5 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_5")); //150万金豆
	ImageView* Image_6 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_6")); //500万金豆
	ImageView* Image_7 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_7")); //双倍金币卡
	ImageView* Image_8 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_8")); //双倍积分卡
	ImageView* Image_9 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_9")); //记牌器
	ImageView* Image_10 = dynamic_cast<ImageView*>(mallTitleNode->getChildByName("Image_10")); //*

	Image_1->setVisible(false);
	Image_2->setVisible(false);
	Image_3->setVisible(false);
	Image_4->setVisible(false);
	Image_5->setVisible(false);
	Image_6->setVisible(false);
	Image_7->setVisible(false);
	Image_8->setVisible(false);
	Image_9->setVisible(false);
	Image_10->setVisible(false);

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

/*
	显示商品图片
	参数：index:商品编号，goodsType:商品类别（1：金币，2：钻石，3：道具）
	     wIndex:商品量（1~7）或道具类别（6：双倍金币卡，7：双倍积分卡，8：记牌器，9：小喇叭，10：大喇叭，11：入场券，12：蓝钻，13：白钻，14：红钻）
*/
void MallView::imageShow(int index, int goodsType, int wIndex)
{
	Node* goldImageNode = mallShowNode.at(index)->getChildByName("goldImageNode");
	Node* zuanShiImageNode = mallShowNode.at(index)->getChildByName("zuanShiImageNode");
	Node* daoJuImageNode = mallShowNode.at(index)->getChildByName("daoJuImageNode");
	goldImageNode->setVisible(false);
	zuanShiImageNode->setVisible(false);
	daoJuImageNode->setVisible(false);

	switch (goodsType)
	{
	case 1:
		goldImageNode->setVisible(true);
		goldOrZuanShiImage(goldImageNode, wIndex);
		break;
	case 2:
		zuanShiImageNode->setVisible(true);
		goldOrZuanShiImage(zuanShiImageNode, wIndex);
		break;
	case 3:
		daoJuImageNode->setVisible(true);
		daoJuImage(daoJuImageNode, wIndex);
		break;
	}
}

//
void MallView::goldOrZuanShiImage(Node* show, int value)
{

}

//
void MallView::daoJuImage(Node* show, int value)
{
	ImageView* doubleExpImage = dynamic_cast<ImageView*>(show->getChildByName("doubleExpImage"));
	ImageView* doubleGoldImage = dynamic_cast<ImageView*>(show->getChildByName("doubleGoldImage"));
	ImageView* jiPaiQiImage = dynamic_cast<ImageView*>(show->getChildByName("jiPaiQiImage"));
	doubleExpImage->setVisible(false);
	doubleGoldImage->setVisible(false);
	jiPaiQiImage->setVisible(false);

	switch (value)
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
}

//显示商品的价格
void MallView::costShow(int index,bool isCostRMB,int costNum)
{

}

void MallView::showMyZuanShi(int num)
{
	txtDiamond->setString(Tools::parseInt2String(num));
}
void MallView::showMyGold(int num)
{
	txtGold->setString(Tools::parseInt2String(num));
}

void MallView::showGoldNum(Node* goldNode, int num)
{

}

void MallView::clickGetBtn(Ref *pSender, int i)
{
	//
	//isClicked = !isClicked;
	//if (isClicked)
	//{
	//	nowIndex = i;
	//	image1Arr.at(i)->setVisible(false);
	//	image2Arr.at(i)->setVisible(true);
	//	isClicked = false;
	//	this->scheduleOnce(schedule_selector(MallView::buyItem), 0.5f);
	//	if (_activityBtn->isSelected())
	//	{
	//		blueSkyDispatchEvent(11207,new int(i));
	//	}
	//	else if (_zuanShiBtn->isSelected())
	//	{
	//		blueSkyDispatchEvent(11208, new int(i));
	//	}
	//	else if (_goldBtn->isSelected())
	//	{
	//		blueSkyDispatchEvent(11209, new int(i));
	//	}
	//	else if (_rewardBtn->isSelected())
	//	{
	//		blueSkyDispatchEvent(11210, new int(i));
	//	}
	//}
}

//
void MallView::buyItem(float dt)
{
	image1Arr.at(nowIndex)->setVisible(true);
	image2Arr.at(nowIndex)->setVisible(false);
	isClicked = true;
}