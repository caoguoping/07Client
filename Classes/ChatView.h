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
	ImageView* Image_1;
	ImageView* Image_2;
	ImageView* Image_3;
	ImageView* Image_4;
	ImageView* Image_5;
	ImageView* Image_6;
	ImageView* Image_7;
	ImageView* Image_8;
	ImageView* Image_9;
	Node* show1;
	Node* show2;
	Node* show3;
	Node* show4;
	Node* show5;
	Node* show6;
	Node* show7;
	Node* show8;
	Node* show9;


	//
	bool clickImage1(Touch *touch, Widget::TouchEventType type);
	bool clickImage2(Touch *touch, Widget::TouchEventType type);
	bool clickImage3(Touch *touch, Widget::TouchEventType type);
	bool clickImage4(Touch *touch, Widget::TouchEventType type);
	bool clickImage5(Touch *touch, Widget::TouchEventType type);
	bool clickImage6(Touch *touch, Widget::TouchEventType type);
	bool clickImage7(Touch *touch, Widget::TouchEventType type);
	bool clickImage8(Touch *touch, Widget::TouchEventType type);
	bool clickImage9(Touch *touch, Widget::TouchEventType type);

	//
	void showChat(Node* show, int index);
};

#endif