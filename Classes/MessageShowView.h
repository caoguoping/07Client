#ifndef  _MessageShowView_
#define  _MessageShowView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "UTF8.h"

class  MessageShowView : public BlueSkyView
{
public:
	MessageShowView();
	~MessageShowView();

	void initView();

	//type:类型（1：获得钻石，2：获得金币，3：获得道具）
	void showMessage(int type,string name);


	void hideMessage();

private:
	BTN_TOUCH_HANDLE(ImageView, Image_38, 11902);
	BTN_TOUCH_HANDLE(Button, getBtn, 11903);
	BTN_TOUCH_HANDLE(Button, closeBtn, 11904);
	//
	Text* txtGold;
	Text* txtDiamond;
	Text* txtProp;   //道具消息


};

#endif