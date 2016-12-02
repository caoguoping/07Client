#ifndef  _BloodView_
#define  _BloodView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  BloodView : public BlueSkyView
{
public:
	BloodView();
	~BloodView();

	void initView();
	void updateBlood(void* data);
	void clickPlay(Ref*  pSender);


public:

	ImageView*  imgFrame;
	Button*  btn1;
	Button*  btn2;
	Button*  btn3;
	Text* txtDiamond;  //×êÊ¯
	Text* txtGold;     //½ð±Ò

};

#endif