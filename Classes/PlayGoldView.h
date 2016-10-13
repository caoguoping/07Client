#ifndef  _PlayGoldView_
#define  _PlayGoldView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  PlayGoldView : public BlueSkyView
{
public:
	PlayGoldView();
	~PlayGoldView();

	void initView();
	void updatePlayGold(void* data);
	void clickPlay(Ref*  pSender);


public:
	BTN_TOUCH_HANDLE(Button, closeBtn, 12600);
	Button*  btn1;
	Button*  btn2;
	Button*  btn3;
	Text* txtDiamond;  //��ʯ
	Text* txtGold;     //���

};

#endif