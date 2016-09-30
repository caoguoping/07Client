#ifndef  _ActivityView_
#define  _ActivityView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PokerGameModel.h"

#define AWARDS_NUM	5

class  ActivityView : public BlueSkyView
{
public:


	typedef enum mall
	{
		E_activity = 0,   //转盘
		E_zuanshi,        //充值返利
		E_myCup,          //myCup
		E_mallMax,

	}T_enumMall;


	TextBMFont* myZuanshi;  //钻石
	TextBMFont* myGold;     //金币
	TextBMFont* textZuanshi;  //抽奖需要的钻石
	int  needZuanshi;

	PageView* actScrow;
	int currentTitle;
	

	ActivityView(int actIndex = 0);
	~ActivityView();


	//void showGrowth(CMD_GP_CupInfo* cupInfo);
	//void saveRankData(CMD_GP_CupInfo*  cupInfo);


	void initView();
	void showMyZuanShi(int num = -1);
	void showMyGold(int num = -1);


	void showRechargeGift();
	Sprite*  spineIner;  //转盘
	unsigned short lotteryIndex = 0;  //奖项
	unsigned short lotteryTimes;    //抽奖次数  
	unsigned short wpIndex;

	void showRechargeGiftState(Node* show,bool canGet,int index);
	void showLotteryGift(int index);
	void showLotteryNum(int index);

	//
	void startLottery();
	int setLevelAndPercent(int totalExp);
	void setCupAwardsInfo(unsigned short awardsinfo, int cuplvl);

	int index = 1;

	void showLottery();
	void showRecharge();
	void showMyCup();
	void updateTitle(float dt);
	void getSpin(Ref*);
	void getSpinReward();



	//排行成长
	void clickGrowth(Ref* psender);
	void clickRank(Ref* psender);

	Text*  txtCannot[5];
	Button*   btnGetGrowth[5];
	void clickGetGrowth(Ref* psender);
	Text*  txtMyLevel;      //我的等级
	Text*  txtMyExp;        //当前经验
	Text*  txtLevelUpExp;   //升级所需经验
	LoadingBar*  loadingExp;

	Text  *timesDay, *timesHour, *timesMin, *timesSec;
	void setTimes(float dt);



private:
	BTN_TOUCH_HANDLE(Button,closeBtn, 15001);
	BTN_TOUCH_HANDLE(CheckBox, lotteryBtn, 15002);
	BTN_TOUCH_HANDLE(CheckBox, rechargeBtn, 15003);
	BTN_TOUCH_HANDLE(CheckBox, myCupBtn, 15010);
	//BTN_TOUCH_HANDLE(Button, spinBtn, 15011);


	BTN_TOUCH_HANDLE(Button, getLotteryBtn, 15004);

	BTN_TOUCH_HANDLE(ImageView, Button_1, 99999);

	Node* mallItem[E_mallMax];


	//抽奖
	Node* lottery1;
	Node* lottery2;
	Node* lottery3;
	Node* lottery4;
	Node* lottery5;
	Node* lottery6;
	Node* lottery7;
	Node* lottery8;

	//成长
	ScrollView* growthScroll;
	//排行榜
	ListView*   rankList;
	CheckBox*   growthCheckBox;
	CheckBox*   rankCheckBox;

	

	//充值
	vector<Node*> rechargeShowNode;
	vector<Button*> getBtnArr;
	vector<bool> canGetAward;
	//
	void clickGetBtn(Ref *pSender, int i);
	bool isClicked = true;

	int times = 0;

	void updateInfo();

	void buyItem(float dt);

};

#endif