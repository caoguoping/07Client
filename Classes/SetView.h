#ifndef  _SetView_
#define  _SetView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  SetView : public BlueSkyView
{
public:
	SetView();
	~SetView();

	void initView();

	bool isMusicOpen = true;
	bool isEffectOpen = true;
	bool isShockOpen = true;

private:
	BTN_TOUCH_HANDLE(Button,closeBtn, 14001);
	BTN_TOUCH_HANDLE(CheckBox, musicBtn, 14002);
	BTN_TOUCH_HANDLE(CheckBox, effectBtn, 14003);
	BTN_TOUCH_HANDLE(Button, reLoginBtn, 14005);
	BTN_TOUCH_HANDLE(Button, helpBtn, 14006);
	BTN_TOUCH_HANDLE(ImageView, Image_38, 14001);
};

#endif