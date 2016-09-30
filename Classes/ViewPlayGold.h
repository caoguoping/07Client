#ifndef  _VIEW_PlayGold_H_
#define  _VIEW_PlayGold_H_

#include "cocos2d.h"
#include "UTF8.h"
#include "SGTools.h"

USING_NS_CC;

class  ViewPlayGold : public Node
{
public:
	~ViewPlayGold();
	static ViewPlayGold * create();
	void initView();
	void updatePlayGold(void* data);
	void clickPlay(Ref*  pSender);
	void clickback(Ref*  pSender);
	void blueSkyDispatchEvent(int type, void* data = NULL);
	void* getModel(string name);


public:
	Node*  rootNode;
	Button*  btn1; 
	Button*  btn2;
	Button*  btn3;  
	Text* txtDiamond;  //×êÊ¯
	Text* txtGold;     //½ð±Ò
};

#endif