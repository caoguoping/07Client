#ifndef  _WarningView_
#define  _WarningView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "GameDataModel.h"
#include "UTF8.h"
class  WarningView : public BlueSkyView
{
public:
	WarningView(AlertVO *alertVO = nullptr);
	~WarningView();

	int enterEventId;//���ȷ���׳��¼�id <0���׳��¼�
	int cancleEventId;//���ȡ���׳��¼�id <0���׳��¼�
	
	BTN_TOUCH_HANDLE(Button, getBtn_0, 11401);
	BTN_TOUCH_HANDLE(Button, cancleBtn, 11402);
	BTN_TOUCH_HANDLE(Button, getBtn, 11403);
	BTN_TOUCH_HANDLE(Button, closeBtn, 11404);
	BTN_TOUCH_HANDLE(ImageView, Image_38, 11404);

	Text *Text_1;
};

#endif