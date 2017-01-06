#include "DaoJuActionView.h"
#include "DataManager.h"

DaoJuActionView::DaoJuActionView()
{
	rootNode = CSLoader::createNode("daoju.csb");
	addChild(rootNode);
}

DaoJuActionView::~DaoJuActionView()
{

}

void DaoJuActionView::initView(int index, int fromDesk, int toDesk,int actionID)
{
	daoJuAction = CSLoader::createTimeline("daoju.csb");
	rootNode->runAction(daoJuAction);

	boom = dynamic_cast<Sprite*>(rootNode->getChildByName("boom"));
	egg = dynamic_cast<Sprite*>(rootNode->getChildByName("egg"));
	flower = dynamic_cast<Sprite*>(rootNode->getChildByName("flower"));
	heart = dynamic_cast<Sprite*>(rootNode->getChildByName("heart"));

	id = actionID;
	showAction(index, fromDesk, toDesk);
}

void DaoJuActionView::showAction(int index, int fromId,  int toDesk)
{
	if (index < 0 || index > 4)
	{
		return;
	}
	if (fromId < 0 || fromId >= 4)
	{
		return;
	}
	if (toDesk < 0 || toDesk >= 4)
	{
		return;
	}
	if (toDesk == fromId)
	{
		return;
	}
	switch (index)
	{
	case 0:
		boom->setVisible(false);
		egg->setVisible(false);
		flower->setVisible(false);
		heart->setVisible(false);
		break;
	case 1:
		boom->setVisible(false);
		egg->setVisible(true);
		flower->setVisible(false);
		heart->setVisible(false);
		if (toDesk == 0)
		{
			DATA->myBaseData.wBeiZaNum[0] ++;
		}
		break;
	case 2:
		boom->setVisible(true);
		egg->setVisible(false);
		flower->setVisible(false);
		heart->setVisible(false);
		if (toDesk == 0)
		{
			DATA->myBaseData.wBeiZaNum[1] ++;
		}
		break;
	case 3:
		boom->setVisible(false);
		egg->setVisible(false);
		flower->setVisible(false);
		heart->setVisible(true);
		if (toDesk == 0)
		{
			DATA->myBaseData.wBeiZaNum[2] ++;
		}
		break;
	case 4:
		boom->setVisible(false);
		egg->setVisible(false);
		flower->setVisible(true);
		heart->setVisible(false);
		if (toDesk == 0)
		{
			DATA->myBaseData.wBeiZaNum[3] ++;
		}
		break;
	}
	Size size = Director::sharedDirector()->getVisibleSize();
	Vec2 Poses[4], fromPos, destPos;
	Poses[0] = Vec2(170, 120);
	Poses[1] = Vec2(85, 326);
	Poses[2] = Vec2(480, 387);
	Poses[3] = Vec2(895, 326);
	rootNode->setPosition(Poses[fromId]);

	fromPos = Poses[fromId];
	destPos = Poses[toDesk];
	destPos.subtract(fromPos);

	daoJuAction->gotoFrameAndPlay(0, 4, true);
	//
	auto call1 = CallFunc::create(
		bind(&DaoJuActionView::showNextAction, this)
		);
	auto call2 = CallFunc::create(
		bind(&DaoJuActionView::removeAction, this)
		);
	this->runAction(Sequence::create
		(MoveTo::create(0.5f, destPos), 
		call1, 
		DelayTime::create(0.7f),
		call1,
		DelayTime::create(1.0f),
		call2,
		nullptr));
// 
// 	int toX = 0;
// 	int toY = 0;
// 	switch (toDesk)
// 	{
// 		//左边的玩家
// 		case 1:
// 			toX = size.width / 8;
// 			toY = size.height * 2 / 5;
// // 			this->runAction(Sequence::create(MoveTo::create(0.5f, Vec2(toX - 250, toY)), call1, DelayTime::create(1.5f),
// // 				call2, nullptr));
// 			this->runAction(Sequence::create(MoveTo::create(0.5f, Vec2(toX - 250, toY)), call1, DelayTime::create(1.5f),
// 				call2, nullptr));
// 			break;
// 		//对面的玩家
// 		case 2:
// 			toX = size.width / 2;
// 			toY = 280;
// 			this->runAction(Sequence::create(MoveTo::create(0.7f, Vec2(toX - 250, toY)), call1, DelayTime::create(1.5f),
// 				call2, nullptr));
// 			break;
// 		//右边的玩家
// 		case 3:
// 			toX = size.width * 7 / 8;
// 			toY = size.height * 2 / 5;
// 			this->runAction(Sequence::create(MoveTo::create(1.0f, Vec2(toX - 250, toY)), call1, DelayTime::create(1.5f),
// 				call2, nullptr));
// 			break;
// 	}
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
