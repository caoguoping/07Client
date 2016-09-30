#include "CancelAutoView.h"

CancelAutoView::CancelAutoView()
{
	rootNode = CSLoader::createNode("cancelAuto.csb");
	addChild(rootNode);
	BTN_ADD_TOUCH_EVENTLISTENER(Button, CancelAutoView, cancelAutoBtn, 11101, "cancelAutoBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, CancelAutoView, autoImage, 11101, "autoImage", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, CancelAutoView, Image_1, 11101, "Image_1", NULL)
}

CancelAutoView::~CancelAutoView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(CancelAutoView, cancelAutoBtn, 11101);
	BTN_REMOVE_TOUCH_EVENTLISTENER(CancelAutoView, autoImage, 11101);
	BTN_REMOVE_TOUCH_EVENTLISTENER(CancelAutoView, Image_1, 11101);
}

void CancelAutoView::initView()
{
	Size size = Director::sharedDirector()->getVisibleSize();
	rootNode->setPosition(Vec2(480 * size.width / 960,90 * size.height / 540));
}