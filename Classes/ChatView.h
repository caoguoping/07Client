#ifndef  _ChatView_
#define  _ChatView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  ChatView : public BlueSkyView
{
public:
	ChatView();
	~ChatView();
	void initView();

private:
	//¹ö¶¯ÈÝÆ÷
	ScrollView* layout;
	ImageView* imgBgs[9];
	Text*      txtChats[9];
	void clickChatImgBg(Ref*  pSender);
};

#endif