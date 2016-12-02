#ifndef  _InviteView_
#define  _InviteView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  InviteView : public BlueSkyView
{
public:
	InviteView(int i);
	~InviteView();

	void initView();
	void showFriends();
	void clickInvite(Ref*  pSender);
	int iChairId;
public:
	ListView*  lstInvite;
	Button *closeBtn;
};

#endif