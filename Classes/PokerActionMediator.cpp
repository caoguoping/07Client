#include "PokerActionMediator.h"

PokerActionMediator::PokerActionMediator()
{

}

PokerActionMediator::~PokerActionMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void PokerActionMediator::OnRegister()
{
	tonghuashun = CSLoader::createTimeline("tongHuaShun.csb");
	huojian = CSLoader::createTimeline("huoJian.csb");
	feiji = CSLoader::createTimeline("feiji.csb");
	boom = CSLoader::createTimeline("boom.csb");
	kanggong = CSLoader::createTimeline("kangGong.csb");
	//
	getView()->rootNode->runAction(tonghuashun);
	getView()->rootNode->runAction(huojian);
	getView()->rootNode->runAction(feiji);
	getView()->rootNode->runAction(boom);
	getView()->rootNode->runAction(kanggong);

	tongHuaShun = dynamic_cast<Node*>(getView()->rootNode->getChildByName("tonghuashun"));
	huoJian = dynamic_cast<Node*>(getView()->rootNode->getChildByName("huojian"));
	feiJi = dynamic_cast<Node*>(getView()->rootNode->getChildByName("feiji"));
	Boom = dynamic_cast<Node*>(getView()->rootNode->getChildByName("boom"));
	kangGong = dynamic_cast<Node*>(getView()->rootNode->getChildByName("kanggong"));

	showNode(0);

	//设置显示位置
	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(Vec2(size.width / 2, size.height / 2));
}

/**
结束回收执行函数
*/
void PokerActionMediator::onRemove()
{

}

/*
事件响应函数
*/
void PokerActionMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::TONG_HUA_SHUN:
		showNode(1);
		tonghuashun->gotoFrameAndPlay(0, 40, false);
		break;
	case EventType::HUO_JIAN:
		showNode(2);
		huojian->gotoFrameAndPlay(0, 38, false);
		break;
	case EventType::FEI_JI:
		showNode(3);
		feiji->gotoFrameAndPlay(0, 38, false);
		break;
	case EventType::BOOM:
		showNode(4);
		boom->gotoFrameAndPlay(0, 39, false);
		boom->setDuration(1.0f);
		break;
	case EventType::KANG_GONG:
		showNode(5);
		kanggong->gotoFrameAndPlay(0, 68, false);
		break;

	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	}
}

Layer* PokerActionMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

void PokerActionMediator::showNode(int id)
{
	tongHuaShun->setVisible(false);
	huoJian->setVisible(false);
	feiJi->setVisible(false);
	Boom->setVisible(false);
	kangGong->setVisible(false);

	switch (id)
	{
	case 0:
		break;
	case 1:
		tongHuaShun->setVisible(true);
		break;
	case 2:
		huoJian->setVisible(true);
		break;
	case 3:
		feiJi->setVisible(true);
		break;
	case 4:
		Boom->setVisible(true);
		break;
	case 5:
		kangGong->setVisible(true);
		break;

	}
}