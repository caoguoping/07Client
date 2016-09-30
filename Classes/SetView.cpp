#include "SetView.h"

SetView::SetView()
{
	rootNode = CSLoader::createNode("set.csb");
	addChild(rootNode);
	//rootNode->setScale(0.1, 0.1);
	//rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.1), ScaleTo::create(0.1f, 1.0f), nullptr));

	BTN_ADD_TOUCH_EVENTLISTENER(Button,SetView, closeBtn, 14001, "closeBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, SetView, musicBtn, 14002, "musicBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, SetView, effectBtn, 14003, "effectBtn", NULL)
	//BTN_ADD_TOUCH_EVENTLISTENER(CheckBox, SetView, shockBtn, 14004, "shockBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, SetView, reLoginBtn, 14005, "reLoginBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, SetView, helpBtn, 14006, "helpBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, SetView, Image_38, 14001, "Image_38", NULL)
}

SetView::~SetView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, closeBtn, 14001);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, musicBtn, 14002);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, effectBtn, 14003);
	//BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, shockBtn, 14004);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, reLoginBtn, 14005);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, helpBtn, 14006);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, Image_38, 14001);


	delete rootNode;
	rootNode = NULL;
}

void SetView::initView()
{
	_musicBtn->setSelected(!isMusicOpen);
	_effectBtn->setSelected(!isEffectOpen);
	//_shockBtn->setSelected(!isShockOpen);
}