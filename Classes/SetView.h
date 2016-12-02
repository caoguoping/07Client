#ifndef  _SetView_
#define  _SetView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  SetView : public BlueSkyView
{
public:
	SetView();
	~SetView();

	void initView();

	bool isMusicOpen;
	bool isEffectOpen;

	CheckBox*  chkMusic;
	CheckBox*  chkEffect;

	void clickChkMusic(Ref*  pSender);
	void clickChkEffect(Ref*  pSender);

};

#endif
