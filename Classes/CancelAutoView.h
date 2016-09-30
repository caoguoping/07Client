#ifndef  _CancelAutoView_
#define  _CancelAutoView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  CancelAutoView : public BlueSkyView
{
public:
	CancelAutoView();
	~CancelAutoView();
	void initView();

private:
	BTN_TOUCH_HANDLE(Button, cancelAutoBtn, 11101);
	BTN_TOUCH_HANDLE(ImageView, autoImage, 11101);
	BTN_TOUCH_HANDLE(ImageView, Image_1, 11101);
};

#endif