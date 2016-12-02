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

	int enterEventId;//点击确定抛出事件id <0不抛出事件
	int cancleEventId;//点击取消抛出事件id <0不抛出事件
	
	Button  *  getBtn_0 ;
	Button  *  cancleBtn;
	Button  *  getBtn   ;
	Button  *  closeBtn ;
	ImageView* Image_38 ;

	Text *Text_1;
};

#endif