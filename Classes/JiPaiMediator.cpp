#include "JiPaiMediator.h"
#include "DataManager.h"

JiPaiMediator::JiPaiMediator()
{

}

JiPaiMediator::~JiPaiMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void JiPaiMediator::OnRegister()
{
	daGuiNum  = dynamic_cast<Text*>(getView()->rootNode->getChildByName("daGuiNum"));
	xiaoGuiNum = dynamic_cast<Text*>(getView()->rootNode->getChildByName("xiaoGuiNum"));
	Num[1] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("ANum"));
	Num[13] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("KNum"));
	Num[12] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("QNum"));
	Num[11] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("JNum"));
	Num[10] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("10Num"));
	Num[9] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("9Num"));
	Num[8] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("8Num"));
	Num[7] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("7Num"));
	Num[6] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("6Num"));
	Num[5] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("5Num"));
	Num[4] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("4Num"));
	Num[3] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("3Num"));
	Num[2] = dynamic_cast<Text*>(getView()->rootNode->getChildByName("2Num"));

	//getView()->rootNode->setVisible(true);
	//showAllOutPoker();
	//showPushPoker();
	//for test


	//
	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(Vec2(450 * size.width / 960,512 * size.height / 540));
	//getView()->rootNode->setVisible(false);
}

/**
结束回收执行函数
*/
void JiPaiMediator::onRemove()
{

}

/*
事件响应函数
*/
void JiPaiMediator::onEvent(int i, void* data)
{
	switch (i)
	{
		//点击记牌器
// 	case 10612:
// 		if (canShow)
// 		{
// 			isVisible = getView()->rootNode->isVisible();
// 			getView()->rootNode->setVisible(!isVisible);
// 		}
// 		break;
	case EventType::GAME_OVER:
	case EventType::REV_PLAYER_OUT_POKER:
		showAllOutPoker();
		break;
	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	case 12201:
		canShow = true;
		getView()->rootNode->setVisible(true);
		break;
	case EventType::SHOW_PLAYER_ON_DESK:
		canShow = false;
		getView()->rootNode->setVisible(false);
		break;

	case EventType::PUSH_JIPAIQI:
		showPushPoker();
		break;
	}
}

//放到工具层
Layer* JiPaiMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->menuLayer;
}

void JiPaiMediator::showPushPoker()
{
	char temp[16];
	for (int i = 1; i <= 13; i++)
	{
		sprintf(temp, "%d", DATA->jipai[i]);
		Num[i]->setString(temp);
	}
	sprintf(temp, "%d", DATA->jipai[17]);
	daGuiNum->setString(temp);

	sprintf(temp, "%d", DATA->jipai[16]);
	xiaoGuiNum->setString(temp);
}

//
void JiPaiMediator::showAllOutPoker()
{
// 	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
// 
// 	//先统计
// 	//vector<PokerVO*> allOutPokerArr = {};
// 	//for (int i = 0; i < 4; i++)
// 	//{
// 	//	for (int j = 0; j < gameDataModel->player[i].allOutPokerArr.size(); j++)
// 	//	{
// 	//		allOutPokerArr.push_back(gameDataModel->player[i].allOutPokerArr.at(j));
// 	//	}
// 	//}
// 
// 	vector<int> allOutPokerID = {};
// 	for (int i = 0; i < 4; i++)
// 	{
// 		for (int j = 0; j < gameDataModel->player[i].allOutPokerArrID.size(); j++)
// 		{
// 			allOutPokerID.push_back(*(gameDataModel->player[i].allOutPokerArrID.at(j)));
// 		}
// 	}
// 
// 	//储存所有牌值的牌数量（2~大王）
// 	vector<int> pokerNum = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// 	for (int i = 0; i < allOutPokerID.size(); i++)
// 	{
// 		//int num = PokerLogic::getPokerNum2(allOutPokerArr.at(i)->pokerID);
// 		int num = PokerLogic::getPokerNum2(allOutPokerID.at(i));
// 		if (num > 12)
// 			num = num - 2;
// 
// 		if (num > -1)
// 			pokerNum.at(num) = pokerNum.at(num) + 1;
// 	}
// 
// 	//显示
// 	for (int i = 0; i < pokerNum.size(); i++)
// 	{
// 		char t[256];
// 		int n = 0;
// 		if (i < 13)
// 			n = 8 - pokerNum.at(i);
// 		else
// 			n = 2 - pokerNum.at(i);
// 		sprintf(t, "%d", n);
// 		string s = t;
// 
// 		switch (i)
// 		{
// 		case 0:
// 			Num2->setString(s);
// 			break;
// 		case 1:
// 			Num3->setString(s);
// 			break;
// 		case 2:
// 			Num4->setString(s);
// 			break;
// 		case 3:
// 			Num5->setString(s);
// 			break;
// 		case 4:
// 			Num6->setString(s);
// 			break;
// 		case 5:
// 			Num7->setString(s);
// 			break;
// 		case 6:
// 			Num8->setString(s);
// 			break;
// 		case 7:
// 			Num9->setString(s);
// 			break;
// 		case 8:
// 			Num10->setString(s);
// 			break;
// 		case 9:
// 			JNum->setString(s);
// 			break;
// 		case 10:
// 			QNum->setString(s);
// 			break;
// 		case 11:
// 			KNum->setString(s);
// 			break;
// 		case 12:
// 			Num1->setString(s);
// 			break;
// 		case 13:
// 			xiaoGuiNum->setString(s);
// 			break;
// 		case 14:
// 			daGuiNum->setString(s);
// 			break;
// 		}
// 	}
// 

}
