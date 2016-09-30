#include "ShowChatView.h"

ShowChatView::ShowChatView()
{
	rootNode = CSLoader::createNode("showChat.csb");
	addChild(rootNode);
	rootNode->setScale(0.1, 0.1);
	rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.1), ScaleTo::create(0.1f, 1.0f), nullptr));
}

ShowChatView::~ShowChatView()
{

}

void ShowChatView::initView(int desk,int index,int chat)
{
	deskID = desk;
	chatID = chat;
	showNode = rootNode->getChildByName("showNode");
	leftImage = dynamic_cast<ImageView*>(rootNode->getChildByName("leftImage"));
	rightImage = dynamic_cast<ImageView*>(rootNode->getChildByName("rightImage"));

	Size size = Director::sharedDirector()->getVisibleSize();
	switch (desk)
	{
	case 0:
		rootNode->setPosition(Vec2(337 * size.width / 960, 168 * size.height / 540));
		leftImage->setVisible(true);
		rightImage->setVisible(false);
		break;
	case 1:
		rootNode->setPosition(Vec2(252 * size.width / 960, 400 * size.height / 540));
		leftImage->setVisible(true);
		rightImage->setVisible(false);
		break;
	case 2:
		rootNode->setPosition(Vec2(644 * size.width / 960, 438 * size.height / 540));
		leftImage->setVisible(true);
		rightImage->setVisible(false);
		break;
	case 3:
		rootNode->setPosition(Vec2(705 * size.width / 960, 381 * size.height / 540));
		leftImage->setVisible(false);
		rightImage->setVisible(true);
		break;
	}

	showChat(index);
}

void ShowChatView::showChat(int index)
{
	ImageView* chat1 = dynamic_cast<ImageView*>(showNode->getChildByName("chat1"));
	ImageView* chat2 = dynamic_cast<ImageView*>(showNode->getChildByName("chat2"));
	ImageView* chat3 = dynamic_cast<ImageView*>(showNode->getChildByName("chat3"));
	ImageView* chat4 = dynamic_cast<ImageView*>(showNode->getChildByName("chat4"));
	ImageView* chat5 = dynamic_cast<ImageView*>(showNode->getChildByName("chat5"));
	ImageView* chat6 = dynamic_cast<ImageView*>(showNode->getChildByName("chat6"));
	ImageView* chat7 = dynamic_cast<ImageView*>(showNode->getChildByName("chat7"));
	ImageView* chat8 = dynamic_cast<ImageView*>(showNode->getChildByName("chat8"));
	ImageView* chat9 = dynamic_cast<ImageView*>(showNode->getChildByName("chat9"));

	switch (index)
	{
	case 1:
		chat1->setVisible(true);
		chat2->setVisible(false);
		chat3->setVisible(false);
		chat4->setVisible(false);
		chat5->setVisible(false);
		chat6->setVisible(false);
		chat7->setVisible(false);
		chat8->setVisible(false);
		chat9->setVisible(false);
		break;
	case 2:
		chat1->setVisible(false);
		chat2->setVisible(true);
		chat3->setVisible(false);
		chat4->setVisible(false);
		chat5->setVisible(false);
		chat6->setVisible(false);
		chat7->setVisible(false);
		chat8->setVisible(false);
		chat9->setVisible(false);
		break;
	case 3:
		chat1->setVisible(false);
		chat2->setVisible(false);
		chat3->setVisible(true);
		chat4->setVisible(false);
		chat5->setVisible(false);
		chat6->setVisible(false);
		chat7->setVisible(false);
		chat8->setVisible(false);
		chat9->setVisible(false);
		break;
	case 4:
		chat1->setVisible(false);
		chat2->setVisible(false);
		chat3->setVisible(false);
		chat4->setVisible(true);
		chat5->setVisible(false);
		chat6->setVisible(false);
		chat7->setVisible(false);
		chat8->setVisible(false);
		chat9->setVisible(false);
		break;
	case 5:
		chat1->setVisible(false);
		chat2->setVisible(false);
		chat3->setVisible(false);
		chat4->setVisible(false);
		chat5->setVisible(true);
		chat6->setVisible(false);
		chat7->setVisible(false);
		chat8->setVisible(false);
		chat9->setVisible(false);
		break;
	case 6:
		chat1->setVisible(false);
		chat2->setVisible(false);
		chat3->setVisible(false);
		chat4->setVisible(false);
		chat5->setVisible(false);
		chat6->setVisible(true);
		chat7->setVisible(false);
		chat8->setVisible(false);
		chat9->setVisible(false);
		break;
	case 7:
		chat1->setVisible(false);
		chat2->setVisible(false);
		chat3->setVisible(false);
		chat4->setVisible(false);
		chat5->setVisible(false);
		chat6->setVisible(false);
		chat7->setVisible(true);
		chat8->setVisible(false);
		chat9->setVisible(false);
		break;
	case 8:
		chat1->setVisible(false);
		chat2->setVisible(false);
		chat3->setVisible(false);
		chat4->setVisible(false);
		chat5->setVisible(false);
		chat6->setVisible(false);
		chat7->setVisible(false);
		chat8->setVisible(true);
		chat9->setVisible(false);
		break;
	case 9:
		chat1->setVisible(false);
		chat2->setVisible(false);
		chat3->setVisible(false);
		chat4->setVisible(false);
		chat5->setVisible(false);
		chat6->setVisible(false);
		chat7->setVisible(false);
		chat8->setVisible(false);
		chat9->setVisible(true);
		break;
	}

	//2ÃëºóÒÆ³ýÁÄÌìÏÔÊ¾
	auto call1 = CallFunc::create(
		//CC_CALLBACK_2(PlayPokerView::hideChat, desk)
		bind(&ShowChatView::hideChat, this)
		);
	this->runAction(Sequence::create(DelayTime::create(2.0f), call1, nullptr));
	//this->scheduleOnce(schedule_selector(PlayPokerView::clockShow), 2.0f);
}


void ShowChatView::hideChat()
{
	blueSkyDispatchEvent(11501,new int(chatID));
}