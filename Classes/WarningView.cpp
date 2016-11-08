#include "WarningView.h"

WarningView::WarningView(AlertVO *alertVO)
{
	rootNode = CSLoader::createNode("warning.csb");
	addChild(rootNode);
	rootNode->setScale(0.8, 0.8);
	rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.03), ScaleTo::create(0.15f, 1.0f), nullptr));
	enterEventId = alertVO->enterEventId;
	cancleEventId = alertVO->cancleEventId;
	Text_1 = dynamic_cast<Text*>(rootNode->getChildByName("Text_1"));
	BTN_ADD_TOUCH_EVENTLISTENER(Button, WarningView, getBtn_0, 11401, "getBtn_0", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(Button, WarningView, cancleBtn, 11402, "cancleBtn", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(Button, WarningView, getBtn, 11403, "getBtn", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(Button, WarningView, closeBtn, 11404, "closeBtn", NULL);
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, WarningView, Image_38, 11404, "Image_38", NULL);
	if (alertVO->type == 0)
	{
		_cancleBtn->setVisible(false);
		_getBtn->setVisible(false);
	}
	else
	{
		_getBtn_0->setVisible(false);
	}
	string s = UTF8::getInstance()->getString(alertVO->msgParentName, alertVO->msgName);
	Text_1->setString(s);
	delete alertVO;
	alertVO = NULL;
}

WarningView::~WarningView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(WarningView, getBtn_0, enterEventId);
	BTN_REMOVE_TOUCH_EVENTLISTENER(WarningView, cancleBtn, cancleEventId);
	BTN_REMOVE_TOUCH_EVENTLISTENER(WarningView, getBtn, enterEventId);
	BTN_REMOVE_TOUCH_EVENTLISTENER(WarningView, closeBtn, cancleEventId);

	BTN_REMOVE_TOUCH_EVENTLISTENER(WarningView, Image_38, 11404);
	delete rootNode;
	rootNode = NULL;
}

