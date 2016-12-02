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

	Button   * closeBtn;
	ImageView* imgBg   ;
	ImageView*  imgFrame;
	Button*  btn0;
	Button*  btn1;
	Button*  btn2;

	Text* txtDiamond;  //×êÊ¯
	Text* txtGold;     //½ð±Ò

};

#endif