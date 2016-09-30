#include "ChatView.h"

ChatView::ChatView()
{
	rootNode = CSLoader::createNode("chat.csb");
	addChild(rootNode);
}

ChatView::~ChatView()
{

}

void ChatView::initView()
{
	layout = dynamic_cast<ScrollView*>(rootNode->getChildByName("ScrollView_1"));
	layout->setScrollBarEnabled(false);
	Image_1 = dynamic_cast<ImageView*>(layout->getChildByName("Image_1"));
	Image_2 = dynamic_cast<ImageView*>(layout->getChildByName("Image_2"));
	Image_3 = dynamic_cast<ImageView*>(layout->getChildByName("Image_3"));
	Image_4 = dynamic_cast<ImageView*>(layout->getChildByName("Image_4"));
	Image_5 = dynamic_cast<ImageView*>(layout->getChildByName("Image_5"));
	Image_6 = dynamic_cast<ImageView*>(layout->getChildByName("Image_6"));
	Image_7 = dynamic_cast<ImageView*>(layout->getChildByName("Image_7"));
	Image_8 = dynamic_cast<ImageView*>(layout->getChildByName("Image_8"));
	Image_9 = dynamic_cast<ImageView*>(layout->getChildByName("Image_9"));

	Image_1->addTouchEventListener(Image_1, toucheventselector(ChatView::clickImage1));
	Image_2->addTouchEventListener(Image_2, toucheventselector(ChatView::clickImage2));
	Image_3->addTouchEventListener(Image_3, toucheventselector(ChatView::clickImage3));
	Image_4->addTouchEventListener(Image_4, toucheventselector(ChatView::clickImage4));
	Image_5->addTouchEventListener(Image_5, toucheventselector(ChatView::clickImage5));
	Image_6->addTouchEventListener(Image_6, toucheventselector(ChatView::clickImage6));
	Image_7->addTouchEventListener(Image_7, toucheventselector(ChatView::clickImage7));
	Image_8->addTouchEventListener(Image_8, toucheventselector(ChatView::clickImage8));
	Image_9->addTouchEventListener(Image_9, toucheventselector(ChatView::clickImage9));

	show1 = layout->getChildByName("show1");
	show2 = layout->getChildByName("show2");
	show3 = layout->getChildByName("show3");
	show4 = layout->getChildByName("show4");
	show5 = layout->getChildByName("show5");
	show6 = layout->getChildByName("show6");
	show7 = layout->getChildByName("show7");
	show8 = layout->getChildByName("show8");
	show9 = layout->getChildByName("show9");

	//
	showChat(show1, 1);
	showChat(show2, 2);
	showChat(show3, 3);
	showChat(show4, 4);
	showChat(show5, 5);
	showChat(show6, 6);
	showChat(show7, 7);
	showChat(show8, 8);
	showChat(show9, 9);

	Size size = Director::sharedDirector()->getVisibleSize();
	rootNode->setPosition(Vec2(835 * size.width / 960, 183 * size.height / 540));
}

bool ChatView::clickImage1(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11301);
	}
	return true;
}

bool ChatView::clickImage2(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11302);
	}
	return true;
}
bool ChatView::clickImage3(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11303);
	}
	return true;
}

bool ChatView::clickImage4(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11304);
	}
	return true;
}

bool ChatView::clickImage5(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11305);
	}
	return true;
}

bool ChatView::clickImage6(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11306);
	}
	return true;
}

bool ChatView::clickImage7(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11307);
	}
	return true;
}

bool ChatView::clickImage8(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11308);
	}
	return true;
}

bool ChatView::clickImage9(Touch *touch, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		blueSkyDispatchEvent(11309);
	}
	return true;
}

void ChatView::showChat(Node* show,int index)
{
	ImageView* chat1 = dynamic_cast<ImageView*>(show->getChildByName("chat1"));
	ImageView* chat2 = dynamic_cast<ImageView*>(show->getChildByName("chat2"));
	ImageView* chat3 = dynamic_cast<ImageView*>(show->getChildByName("chat3"));
	ImageView* chat4 = dynamic_cast<ImageView*>(show->getChildByName("chat4"));
	ImageView* chat5 = dynamic_cast<ImageView*>(show->getChildByName("chat5"));
	ImageView* chat6 = dynamic_cast<ImageView*>(show->getChildByName("chat6"));
	ImageView* chat7 = dynamic_cast<ImageView*>(show->getChildByName("chat7"));
	ImageView* chat8 = dynamic_cast<ImageView*>(show->getChildByName("chat8"));
	ImageView* chat9 = dynamic_cast<ImageView*>(show->getChildByName("chat9"));

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
}