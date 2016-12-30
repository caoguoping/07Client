#ifndef  _ShopView_
#define  _ShopView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "PokerGameModel.h"



class  ShopView : public BlueSkyView
{
public:
	typedef enum shop
	{

		E_zuanshi = 0,
		E_gold,
		E_shopMax,

	}T_enumShop;


	Node* shopItem[E_shopMax];
	int currentTitle;
	Text* txtDiamond;  //×êÊ¯
	Text* txtGold;     //½ð±Ò
	int shopID;
public:
	ShopView(int shopID);
	~ShopView();

	void showMyZuanShi(int num);
	void showMyGold(SCORE num);
	void showZuanShiView();
	void showGoldView();
	void clickBtnZuanShi(Ref*  pSender, CheckBox::EventType type);
	void clickBtnGold(Ref*  pSender, CheckBox::EventType type);
	void initView();
	void clickChargeBtn(Ref*  pSender);
	CheckBox* zhuanShiBtn;
	CheckBox* goldBtn    ;
	Button  * closeBtn   ;


};

#endif
