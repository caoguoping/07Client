#ifndef  _DailyMissionView_
#define  _DailyMissionView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "PokerGameModel.h"

class  DailyMissionView : public BlueSkyView
{
public:
	DailyMissionView(bool showGetBtn = true);
	~DailyMissionView();

	void initView();
	void showAllMission();
	void showMission();
	void showMissionState(Node* show, unsigned short isCompleted, unsigned short canGetMisAward, int index);
	void showMisCondition(Node* show, int index);

	//储存任务信息
	vector<DBR_GR_UserLogonMissionRes> dailyMisInfo;

public:
	BTN_TOUCH_HANDLE(Button, closeBtn, 11007);
	BTN_TOUCH_HANDLE(ImageView, Image_38, 11007);

	//滚动容器
	ScrollView* activityView;
	Node*   taskNodes[6];
	Text*   txtDescrip[6];
	Text*   txtReward[6];
	Text*   txtNowNum[6];
	Text*	txtNowNum0[6];
	Text*   txtNeetNum[6];
	Button*  btnGet[6];
	Button*  btnGoto[6];
	ImageView*  imgReceive[6];
	ImageView*  imgNormal[6];
	ImageView*  imgBlack[6];


	//
	vector<Node*> mallShowNode;
	vector<Button*> getBtnArr;

	//
	vector<unsigned short> isComplete;
	vector<unsigned short> hasGetAward;

	//
	void clickGetBtn(Ref *pSender);    //获得
	void clickGotoBtn(Ref *pSender);   //前往
	bool isClicked = true;

	//
	bool canShowGetBtn;

	//
	void buyItem(float dt);
};

#endif