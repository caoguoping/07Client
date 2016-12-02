#include "WarningView.h"
#include "SGTools.h"

WarningView::WarningView(AlertVO *alertVO)
{
	rootNode = CSLoader::createNode("warning.csb");
	addChild(rootNode);
	rootNode->setScale(0.8, 0.8);
	rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.03), ScaleTo::create(0.15f, 1.0f), nullptr));
	enterEventId = alertVO->enterEventId;
	cancleEventId = alertVO->cancleEventId;
	Text_1 = dynamic_cast<Text*>(rootNode->getChildByName("Text_1"));

		UIGet_Button("getBtn_0", rootNode, getBtn_0)
		UIGet_Button("cancleBtn", rootNode, cancleBtn)
		UIGet_Button("getBtn", rootNode, getBtn)
		UIGet_Button("closeBtn", rootNode, closeBtn)
		UIGet_ImageView("Image_38", rootNode, Image_38)

		BTN_EVENT(getBtn_0, 11401)
		BTN_EVENT(cancleBtn, 11402)
		BTN_EVENT(getBtn, 11403)
		BTN_EVENT(closeBtn, 11404)
		BTN_EVENT(Image_38, 11404)


	if (alertVO->type == 0)
	{
		cancleBtn->setVisible(false);
		getBtn->setVisible(false);
	}
	else
	{
		getBtn_0->setVisible(false);
	}
	string s = UTF8::getInstance()->getString(alertVO->msgParentName, alertVO->msgName);
	Text_1->setString(s);
	delete alertVO;
	alertVO = NULL;
}

WarningView::~WarningView()
{
	delete rootNode;
	rootNode = NULL;
}

