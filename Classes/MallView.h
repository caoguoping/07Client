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
	Text* txtDiamond;  //��ʯ
	Text* txtGold;     //���
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

	BTN_TOUCH_HANDLE(Button, closeBtn, 11201);
	BTN_TOUCH_HANDLE(CheckBox, activityBtn, 11202);
	BTN_TOUCH_HANDLE(CheckBox, zuanShiBtn, 11203);

	Node* saveNode;
	Node* mallItem[E_mallMax];

	//��������
	ScrollView* activityView;

	bool isClicked = true;

	//��ǰ������ǵڼ�����Ʒ
	int nowIndex = -1;
};

#endif