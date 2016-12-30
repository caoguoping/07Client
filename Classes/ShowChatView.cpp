#include "ShowChatView.h"
#include "SGTools.h"
#include "UTF8.h"

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
	UIGet_Text("Text_1",rootNode, showNode)
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
	char chatName[64];
	sprintf(chatName, "chat%d", index);
	showNode->setString(UTF8String("chat", chatName));
	//2ÃëºóÒÆ³ýÁÄÌìÏÔÊ¾
	auto call1 = CallFunc::create(
		bind(&ShowChatView::hideChat, this)
		);
	this->runAction(Sequence::create(DelayTime::create(2.0f), call1, nullptr));
}


void ShowChatView::hideChat()
{
	blueSkyDispatchEvent(11501,new int(chatID));
}