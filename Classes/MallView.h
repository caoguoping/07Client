#ifndef  _MallView_
#define  _MallView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "PokerGameModel.h"


class  MallView : public BlueSkyView
{
public:

	typedef enum mall
	{
		E_activity = 0,
		E_zuanshi,
		// 	E_gold,
		// 	E_changeReward,
		E_mallMax,

	}T_enumMall;

	int currentTitle; 

	ImageView*  imgHuodong[2];
	ImageView*  imgZuanshi[5];
	Button*     btnHuodong[2];
	Button*     btnZuanshi[5];
	Text* txtDiamond;  //钻石
	Text* txtGold;     //金币
public:
	MallView();
	~MallView();
	void initView();
	void showActivityView();
	void showZuanShiView();
	void showGoldView();
	void showRewardView();
	void showMall(int mallType = -1);
	void showMyZuanShi(int num = -1);
	void showMyGold(int num = -1);


public:

	Button  * closeBtn   ;
	CheckBox* activityBtn;
	CheckBox* zuanShiBtn ;

	Node* saveNode;
	Node* mallItem[E_mallMax];

	//滚动容器
	ScrollView* activityView;

	bool isClicked = true;

	//当前点击的是第几个商品
	int nowIndex = -1;
};

#endif