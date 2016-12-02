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
		E_activity = 0,   //ת��
		E_zuanshi,        //��ֵ����
		E_myCup,          //myCup
		E_mallMax,

	}T_enumMall;


	Text* txtDiamond;  //��ʯ
	Text* txtGold;     //���
	TextBMFont* textZuanshi;  //�齱��Ҫ����ʯ
	int  needZuanshi;

	int currentTitle;
	

	ActivityView(int actIndex = 0);
	~ActivityView();


	//void showGrowth(CMD_GP_CupInfo* cupInfo);
	//void saveRankData(CMD_GP_CupInfo*  cupInfo);


	void initView();
	void showMyZuanShi(int num = -1);
	void showMyGold(int num = -1);


	void showRechargeGift();
	Sprite*  spineIner;  //ת��
	unsigned short lotteryIndex = 0;  //����
	unsigned short lotteryTimes;    //�齱����  
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
	void showActivityNode(int iWhich);
	void getSpin(Ref*);
	void getSpinReward();



	//���гɳ�
	void clickGrowth(Ref* psender);
	void clickRank(Ref* psender);

	Text*  txtCannot[5];
	Button*   btnGetGrowth[5];
	ImageView* imgGetAlready[5];
	void clickGetGrowth(Ref* psender);
	Text*  txtMyLevel;      //�ҵĵȼ�
	Text*  txtMyExp;        //��ǰ����
	Text*  txtLevelUpExp;   //�������辭��
	LoadingBar*  loadingExp;

	Text  *timesDay, *timesHour, *timesMin, *timesSec;
	void setTimes(float dt);


public:

	Node* mallItem[E_mallMax];


	//�齱
	Node* lottery1;
	Node* lottery2;
	Node* lottery3;
	Node* lottery4;
	Node* lottery5;
	Node* lottery6;
	Node* lottery7;
	Node* lottery8;

	//�ɳ�
	ScrollView* growthScroll;
	//���а�
	ListView*   rankList;
	CheckBox*   growthCheckBox;
	CheckBox*   rankCheckBox;

	

	//��ֵ
	vector<Node*> rechargeShowNode;
	vector<Button*> getBtnArr;
	vector<bool> canGetAward;
	//
	void clickGetBtn(Ref *pSender, int i);
	bool isClicked = true;

	int times = 0;

	void updateInfo();

	void buyItem(float dt);

	Button    *closeBtn;
	CheckBox  *lotteryBtn;
	CheckBox  *rechargeBtn;
	CheckBox  *myCupBtn;
};

#endif