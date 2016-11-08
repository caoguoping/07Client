#ifndef  _EntertainmentView_
#define  _EntertainmentView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  EntertainmentView : public BlueSkyView
{
public:
	EntertainmentView();
	~EntertainmentView();

	void initView();
	void updateEntertainment(void* data);
	void clickPlay(Ref*  pSender);


public:

	BTN_TOUCH_HANDLE(Button, closeBtn, 12700);
	BTN_TOUCH_HANDLE(ImageView, imgBg, 12700);
	ImageView*  imgFrame;

	Button*  btn1;
	Button*  btn2;
	Button*  btn3;
	Text* txtDiamond;  //��ʯ
	Text* txtGold;     //���

};

#endif