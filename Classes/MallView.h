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

	Button  * closeBtn   ;
	CheckBox* activityBtn;
	CheckBox* zuanShiBtn ;

	Node* saveNode;
	Node* mallItem[E_mallMax];

	//��������
	ScrollView* activityView;

	bool isClicked = true;

	//��ǰ������ǵڼ�����Ʒ
	int nowIndex = -1;
};

#endif