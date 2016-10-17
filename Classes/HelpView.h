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

public:
	BTN_TOUCH_HANDLE(Button,closeBtn, 13001);
	BTN_TOUCH_HANDLE(ImageView, Image_38, 13001);

	//
	//滚动容器
	ScrollView* mScrollView[5];  //牌型， 牌型大小，游戏名字，贡牌规则，游戏等级
	CheckBox*    mCheckBox[5];

	void clickCheckBox(Ref*  pSender);
	void handleWhich(int iwhich);
};

#endif