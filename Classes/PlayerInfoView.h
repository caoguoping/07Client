#ifndef  _PlayerInfoView_
#define  _PlayerInfoView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  PlayerInfoView : public BlueSkyView
{
public:
	PlayerInfoView();
	~PlayerInfoView();

public:
	Text* txtName;
	Text* txtId;
	Text* txtGold;

private:
	BTN_TOUCH_HANDLE(Button, closeBtn, 10701);
	BTN_TOUCH_HANDLE(Button, eggBtn, 10702);
	BTN_TOUCH_HANDLE(Button, boomBtn, 10703);
	BTN_TOUCH_HANDLE(Button, heartBtn, 10704);
	BTN_TOUCH_HANDLE(Button, flowerBtn, 10705);
	BTN_TOUCH_HANDLE(Button, addFriendBtn, 10706);
	BTN_TOUCH_HANDLE(ImageView, Image_1, 99999);
};

#endif