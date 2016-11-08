#include "SevenDayGiftView.h"
#include "SGTools.h"

SevenDayGiftView::SevenDayGiftView()
{
	rootNode = CSLoader::createNode("sevenDayGift.csb");
	addChild(rootNode);

	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("sevenDayGift.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);

	BTN_ADD_TOUCH_EVENTLISTENER(Button, SevenDayGiftView, getGiftBtn, 10901, "getGiftBtn", "Image_frame")
		BTN_ADD_TOUCH_EVENTLISTENER(Button, SevenDayGiftView, closeBtn, 10902, "closeBtn", "Image_frame")
		BTN_ADD_TOUCH_EVENTLISTENER(ImageView, SevenDayGiftView, Image_38, 10902, "Image_bg", NULL)
}

SevenDayGiftView::~SevenDayGiftView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(SevenDayGiftView, getGiftBtn, 10901);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SevenDayGiftView, closeBtn, 10902);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SevenDayGiftView, Image_38, 10902);

	rootNode->stopAllActions();
	delete rootNode;
	rootNode = NULL;
}

void SevenDayGiftView::initView(bool isShowCloseBtn)
{
	UIGet_ImageView("Image_frame", rootNode, imgFrame)
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

