#ifndef  _HelpView_
#define  _HelpView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  HelpView : public BlueSkyView
{
public:
	HelpView();
	~HelpView();

	void initView();

private:
	BTN_TOUCH_HANDLE(Button,closeBtn, 13001);
	BTN_TOUCH_HANDLE(ImageView, Image_38, 99999);

	//
	//¹ö¶¯ÈÝÆ÷
	ScrollView* ScrollView_1;
};

#endif