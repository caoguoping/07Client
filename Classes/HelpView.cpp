#include "HelpView.h"

HelpView::HelpView()
{
	rootNode = CSLoader::createNode("help.csb");
	addChild(rootNode);
	//rootNode->setScale(0.1, 0.1);
	//rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.1), ScaleTo::create(0.1f, 1.0f), nullptr));

	BTN_ADD_TOUCH_EVENTLISTENER(Button,HelpView, closeBtn, 13001, "closeBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, HelpView, Image_38, 99999, "Image_38", NULL)
}

HelpView::~HelpView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(HelpView, closeBtn, 13001);
	BTN_REMOVE_TOUCH_EVENTLISTENER(HelpView, Image_38, 99999);

	delete rootNode;
	rootNode = NULL;
}

void HelpView::initView()
{
	ScrollView_1 = dynamic_cast<ScrollView*>(rootNode->getChildByName("ScrollView_1"));
	ScrollView_1->setScrollBarEnabled(false);
}