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
	Button  *closeBtn, *eggBtn, *boomBtn, *heartBtn, *flowerBtn, *addFriendBtn, *btnAddGold;
	Text* txtName;
	Text* txtId;
	Text* txtGold;
	Button*  btnAddFriend;
};

#endif
