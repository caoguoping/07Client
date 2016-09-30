#ifndef  _AccountMediator_
#define  _AccountMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"

#include "PlayPokerView.h"
#include "PlayPokerMediator.h"
#include "AccountView.h"


class AccountMediator : public BlueSkyMediator
{
public:
	AccountMediator(CMD_S_GameEnd data);
	AccountMediator();
	~AccountMediator();
	/**
	开始执行函数
	*/
	void OnRegister();
	/**
	结束回收执行函数
	*/
	void onRemove();
	/*
	事件响应函数
	*/
	void onEvent(int i, void* data);
	Layer* getLayer();

private:
	//
	AccountView* accountView;

	//我的游戏结算信息
	Text* myName;
	Text* myGold;
	Node* myHead;
	Node* grade;
	string myNickName;
	int myFaceID;
	string myGoldChange;
	int myGrade; //(0 ~3)
	Sprite* successImage1;
	Sprite* successImage2;
	Sprite* failImage1;
	Sprite* failImage2;
	bool isSuccess;

	//玩家1的结算信息
	Text* player1Name;
	Text* player1Gold;
	Node* player1Head;
	string playerNick1Name;
	int player1FaceID;
	string player1GoldChange;
	int player1Grade;

	//玩家2的结算信息
	Text* player2Name;
	Text* player2Gold;
	Node* player2Head;
	string playerNick2Name;
	int player2FaceID;
	string player2GoldChange;
	int player2Grade;

	//玩家3的结算信息
	Text* player3Name;
	Text* player3Gold;
	Node* player3Head;
	string playerNick3Name;
	int player3FaceID;
	string player3GoldChange;
	int player3Grade;


	//点击返回按钮
	void clickFanHuiBtnHander();

	//点击继续按钮
	void clickContinueBtnHander();

	//报名下一场
	void clickNextMatch();

	//显示玩家头像
	void showHead(Node* head, int faceID);

	//显示玩家名次
	void showGrade(int rank);

	//播放结算音效
	void playAccountMusic(bool isSuccess);


};

#endif