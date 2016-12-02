#include "SevenDayGiftView.h"
#include "SGTools.h"

SevenDayGiftView::SevenDayGiftView()
{
	rootNode = CSLoader::createNode("sevenDayGift.csb");
	addChild(rootNode);

	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("sevenDayGift.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);


}

SevenDayGiftView::~SevenDayGiftView()
{
	rootNode->stopAllActions();
	delete rootNode;
	rootNode = NULL;
}

void SevenDayGiftView::initView(bool isShowCloseBtn)
{

	UIGet_ImageView("Image_frame", rootNode, imgFrame)
	UIGet_Button("getGiftBtn", imgFrame, getGiftBtn)
	UIGet_Button("closeBtn", imgFrame, closeBtn)
	UIGet_ImageView("Image_bg", rootNode,  Image_38)
	BTN_EVENT(getGiftBtn, 10901	)
	BTN_EVENT(closeBtn, 10902	)
	BTN_EVENT(Image_38, 10902	)
		
	char temp[64];
	for (int i = 0; i < 7; i++)
	{
		sprintf(temp, "Image_%d", i);
		UIGet_ImageView(temp, imgFrame, imgGift[i])
			UIGet_ImageView("Image_mask", imgGift[i], imgMask[i])
			imgMask[i]->setVisible(false);
	}

	showGift();
}

//显示奖励领取情况
void SevenDayGiftView::showGift()
{
	int maskSize = (nowDay % 7);
	for (int i = 0; i < maskSize; i ++)
	{
		imgMask[i]->setVisible(true);
	}

}

