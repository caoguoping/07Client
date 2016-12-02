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
	Button   * closeBtn;
	ImageView* imgBg   ;
	ImageView*  imgFrame;
	Button*  btn1;
	Button*  btn2;
	Button*  btn3;
	Text* txtDiamond;  //×êÊ¯
	Text* txtGold;     //½ð±Ò

};

#endif