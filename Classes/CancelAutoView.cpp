#include "CancelAutoView.h"
#include "SGTools.h"

CancelAutoView::CancelAutoView()
{
	rootNode = CSLoader::createNode("cancelAuto.csb");
	addChild(rootNode);

		UIGet_Button("cancelAutoBtn", rootNode, cancelAutoBtn)
		UIGet_ImageView("autoImage", rootNode, autoImage)
		UIGet_ImageView("Image_1", rootNode, Image_1)
		BTN_EVENT(cancelAutoBtn, 11101)
		BTN_EVENT(autoImage, 11101)
		BTN_EVENT(Image_1, 11101)


}

CancelAutoView::~CancelAutoView()
{

}

void CancelAutoView::initView()
{
	Size size = Director::sharedDirector()->getVisibleSize();
	rootNode->setPosition(Vec2(480 * size.width / 960,90 * size.height / 540));
}