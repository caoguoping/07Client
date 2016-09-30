#ifndef  _ShowChatView_
#define  _ShowChatView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  ShowChatView : public BlueSkyView
{
public:
	ShowChatView();
	~ShowChatView();
	void initView(int desk,int index,int chat);

private:
	void showChat(int index);
	void hideChat();

	int deskID = -1;
	int chatID = -1;
	Node* showNode;
	ImageView* leftImage;
	ImageView* rightImage;
};

#endif