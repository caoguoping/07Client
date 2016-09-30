#ifndef  _ShopView_
#define  _ShopView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "PokerGameModel.h"



class  ShopView : public BlueSkyView
{
public:
	typedef enum mall
	{

		E_zuanshi = 0,
		E_gold,
		E_shopMax,

	}T_enumShop;


	Node* mallItem[E_shopMax];
	int currentTitle;
	Text* txtDiamond;  //×êÊ¯
	Text* txtGold;     //½ð±Ò
	int shopID;



public:
	ShopView(int shopID);
	~ShopView();

	void showMyZuanShi(int num);
	void showMyGold(int num);


	void showZuanShiView();
	void showGoldView();



	void initView();



private:
	BTN_TOUCH_HANDLE(CheckBox, zhuanShiBtn, 10801);
	BTN_TOUCH_HANDLE(CheckBox, goldBtn, 10802);
	BTN_TOUCH_HANDLE(Button, closeBtn, 10803);


};

#endif