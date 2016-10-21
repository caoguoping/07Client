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

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(Vec2(450 * size.width / 960,512 * size.height / 540));
	getView()->rootNode->setVisible(false);

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
	case EventType::GAME_OVER:
	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	case 12201:
		getView()->rootNode->setVisible(true);
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

