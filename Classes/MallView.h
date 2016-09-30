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


	PageView* actScrow;
	int currentTitle; 
	Text* txtDiamond;  //钻石
	Text* txtGold;     //金币
public:
	MallView();
	~MallView();
	void updateTitle(float dt);
	void initView();
	void showActivityView();
	void showZuanShiView();
	void showGoldView();
	void showRewardView();
	void showMall(int mallType = -1);
	void showMyZuanShi(int num = -1);
	void showMyGold(int num = -1);

	//
	vector<Node*> mallShowNode;
	vector<Button*> getBtnArr;
	vector<ImageView*> image1Arr;
	vector<ImageView*> image2Arr;
	vector<cocostudio::timeline::ActionTimeline*> guangQuanActionArr;
	vector<cocostudio::timeline::ActionTimeline*> teJiaActionArr;
	vector<cocostudio::timeline::ActionTimeline*> reXiaoActionArr;
	vector<cocostudio::timeline::ActionTimeline*> xianShiActionArr;

	//储存商城商品信息
	vector<SHOP_GOOD> mallGoodsInfo;

public:
	void  pageTurning(Ref* psender, cocos2d::ui::PageView::EventType etype);


	BTN_TOUCH_HANDLE(Button, closeBtn, 11201);
	BTN_TOUCH_HANDLE(ImageView, Image_99999, 99999);
	BTN_TOUCH_HANDLE(CheckBox, activityBtn, 11202);
	BTN_TOUCH_HANDLE(CheckBox, zuanShiBtn, 11203);
// 	BTN_TOUCH_HANDLE(CheckBox, goldBtn, 11204);
// 	BTN_TOUCH_HANDLE(CheckBox, rewardBtn, 11205);
	//BTN_TOUCH_HANDLE(Button, rechargeBtn, 11206);    //充值

	Node* goldNum_1;
	Node* goldNum_2;
	Node* goldNum_3;
	Node* goldNum_4;
	Node* goldNum_5;
	Node* goldNum_6;
	Node* goldNum_7;
	Node* goldNum_8;
	Node* goldNum_9;

	Node* zhuanShiNum_1;
	Node* zhuanShiNum_2;
	Node* zhuanShiNum_3;
	Node* zhuanShiNum_4;
	Node* zhuanShiNum_5;
	Node* zhuanShiNum_6;
	Node* zhuanShiNum_7;
	Node* zhuanShiNum_8;
	Node* zhuanShiNum_9;


	Node* saveNode;
	Node* mallItem[E_mallMax];

	//滚动容器
	ScrollView* activityView;

	//
	//Node* activityNode1;

	void showGoldNum(Node* goldNode, int num);

	//
	void clickGetBtn(Ref *pSender,int i);
	bool isClicked = true;

	//
	void actionShow(float dt);

	//
	void actionNodeShow(int index);

	//
	void costShow(int index, bool isCostRMB, int costNum);

	//
	void imageShow(int index, int goodsType, int wIndex);

	//
	void titleShow(int index, int wIndex);

	//
	void goldOrZuanShiImage(Node* show, int value);

	//
	void daoJuImage(Node* show, int value);

	//
	void buyItem(float dt);

	//当前点击的是第几个商品
	int nowIndex = -1;
};

#endif