#ifndef  _MyInfoView_
#define  _MyInfoView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  MyInfoView : public BlueSkyView
{
public:
	MyInfoView();
	~MyInfoView();

	void initView();
	void showGold(int num);
	void showZhuanShi(int num);
	void showFace(int faceID = -1);
	void showDuanWei(int num);
	void showName(string name);

	public:
	BTN_TOUCH_HANDLE(Button, closeBtn, 11701);
	BTN_TOUCH_HANDLE(ImageView, Image_1, 11701);
// 	BTN_TOUCH_HANDLE(Button, addGoldBtn, 10702);
// 	BTN_TOUCH_HANDLE(Button, addZhuanBtn, 10703);

	//Ãû×Ö
	Text* txtName;
	Text* txtId;
	Text* txtGold;
	Text* txtDiamond;


	void showGoldNum(Node* goldNode, int num);
};

#endif