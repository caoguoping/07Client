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

	bool isMusicOpen;
	bool isEffectOpen;

	CheckBox*  chkMusic;
	CheckBox*  chkEffect;

	void clickChkMusic(Ref*  pSender);
	void clickChkEffect(Ref*  pSender);

private:
	BTN_TOUCH_HANDLE(Button,closeBtn, 14001);
	BTN_TOUCH_HANDLE(Button, reLoginBtn, 14005);
	BTN_TOUCH_HANDLE(Button, helpBtn, 14006);
	BTN_TOUCH_HANDLE(ImageView, Image_38, 14001);
};

#endif