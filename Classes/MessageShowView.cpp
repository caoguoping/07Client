#include "MessageShowView.h"
#include "SGTools.h"

MessageShowView::MessageShowView()
{
	rootNode = CSLoader::createNode("messageShow.csb");
	addChild(rootNode);
	rootNode->setScale(0.8, 0.8);
	rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.03), ScaleTo::create(0.15f, 1.0f), nullptr));	ImageView* imgTmp;
	Button*  btnTmp;

	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, MessageShowView, Image_38, 11902, "Image_38", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(Button, MessageShowView, getBtn, 11903, "getBtn", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(Button, MessageShowView, closeBtn, 11904, "closeBtn", NULL);
}

MessageShowView::~MessageShowView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(MessageShowView, Image_38, 11902);
	BTN_REMOVE_TOUCH_EVENTLISTENER(MessageShowView, getBtn, 11903);
	BTN_REMOVE_TOUCH_EVENTLISTENER(MessageShowView, closeBtn, 11904);

	delete rootNode;
	rootNode = NULL;
}

void MessageShowView::initView()
{
	UIGet_Text("Text_Diamond", rootNode, txtDiamond)
		UIGet_Text("Text_gold", rootNode, txtGold)
		UIGet_Text("Text_prop", rootNode, txtProp)
	rootNode->setVisible(false);
}

//type:类型（1：获得钻石，2：获得金币，3：获得道具）
void MessageShowView::showMessage(int type, string name)
{
	rootNode->stopAllActions();
	rootNode->setVisible(true);
	string show;
	switch (type)
	{
	case 1:
		show = UTF8::getInstance()->getString("message", "diamond") + name;
		txtDiamond->setString(show);
		break;
	case 2:
		show = UTF8::getInstance()->getString("message", "gold") + name;
		txtGold->setString(show);
		break;
	case 3:
		show = UTF8::getInstance()->getString("message", "item") + name;
		txtProp->setString(show);
		break;
	}
}

//
void MessageShowView::hideMessage()
{
	txtDiamond->setString("");
	txtGold->setString("");
	txtProp->setString("");
	rootNode->setVisible(false);
}