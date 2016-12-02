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
	ImageView* Image_38;
	Button   * getBtn  ;
	Button   * closeBtn;
	//
	Text* txtGold;
	Text* txtDiamond;
	Text* txtProp;   //道具消息


};

#endif