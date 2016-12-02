#ifndef  _CancelAutoView_
#define  _CancelAutoView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  CancelAutoView : public BlueSkyView
{
public:
	CancelAutoView();
	~CancelAutoView();
	void initView();


	Button *   cancelAutoBtn;
	ImageView* autoImage    ;
	ImageView* Image_1      ;
};

#endif