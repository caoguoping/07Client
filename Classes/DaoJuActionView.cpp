#include "DaoJuActionView.h"

DaoJuActionView::DaoJuActionView()
{
	rootNode = CSLoader::createNode("daoju.csb");
	addChild(rootNode);
}

DaoJuActionView::~DaoJuActionView()
{
	delete rootNode;
	rootNode = NULL;
}

void DaoJuActionView::initView(int index, int toDesk,int actionID)
{
	daoJuAction = CSLoader::createTimeline("daoju.csb");
	rootNode->runAction(daoJuAction);

	boom = dynamic_cast<Sprite*>(rootNode->getChildByName("boom"));
	egg = dynamic_cast<Sprite*>(rootNode->getChildByName("egg"));
	flower = dynamic_cast<Sprite*>(rootNode->getChildByName("flower"));
	heart = dynamic_cast<Sprite*>(rootNode->getChildByName("heart"));

	id = actionID;
	showAction(index, toDesk);
}

void DaoJuActionView::showAction(int index, int toDesk)
{
	//this->stopAllActions();

	Size size = Director::sharedDirector()->getVisibleSize();
	rootNode->setPosition(Vec2(250,100));
	switch (index)
	{
		case 0:
			boom->setVisible(false);
			egg->setVisible(false);
			flower->setVisible(false);
			heart->setVisible(false);
			break;
		case 2:
			boom->setVisible(true);
			egg->setVisible(false);
			flower->setVisible(false);
			heart->setVisible(false);
			break;
		case 1:
			boom->setVisible(false);
			egg->setVisible(true);
			flower->setVisible(false);
			heart->setVisible(false);
			break;
		case 4:
			boom->setVisible(false);
			egg->setVisible(false);
			flower->setVisible(true);
			heart->setVisible(false);
			break;
		case 3:
			boom->setVisible(false);
			egg->setVisible(false);
			flower->setVisible(false);
			heart->setVisible(true);
			break;
	}

	if (toDesk == 0)
	{
		return;
	}

	daoJuAction->gotoFrameAndPlay(0, 4, true);
	//
	auto call1 = CallFunc::create(
		bind(&DaoJuActionView::showNextAction, this)
		);
	auto call2 = CallFunc::create(
		bind(&DaoJuActionView::removeAction, this)
		);

	int toX = 0;
	int toY = 0;
	switch (toDesk)
	{
		//左边的玩家
		case 1:
			toX = size.width / 8;
			toY = size.height * 2 / 5;
			this->runAction(Sequence::create(MoveTo::create(0.5f, Vec2(toX - 250, toY)), call1, DelayTime::create(1.5f),
				call2, nullptr));
			break;
		//对面的玩家
		case 2:
			toX = size.width / 2;
			toY = 280;
			this->runAction(Sequence::create(MoveTo::create(0.7f, Vec2(toX - 250, toY)), call1, DelayTime::create(1.5f),
				call2, nullptr));
			break;
		//右边的玩家
		case 3:
			toX = size.width * 7 / 8;
			toY = size.height * 2 / 5;
			this->runAction(Sequence::create(MoveTo::create(1.0f, Vec2(toX - 250, toY)), call1, DelayTime::create(1.5f),
				call2, nullptr));
			break;
	}
}

void DaoJuActionView::showNextAction()
{
	daoJuAction->gotoFrameAndPlay(5, 70, false);
}

void DaoJuActionView::removeAction()
{
	int* data = new int(id);
	blueSkyDispatchEvent(11801, data);
}
