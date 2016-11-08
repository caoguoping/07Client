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
	void OnRegister();
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();

public:
	AccountView* accountView;
	int svrChairId[4];
	int faceId[4]; 
	std::string strNickName[4];
	int iGrade[4];
	DWORD  dwGold[4];
	Text*  txtName[4];
	Text*  txtGold[4];
	Node*  ndHead[4];
	//我的游戏结算信息
	Node* grade;
	Sprite* successImage1; //girls
	Sprite* successImage2;
	Sprite* SpBloodSeccess;
	Sprite* SpBloodNumSec;

	Sprite* failImage1;  //girls
	Sprite* failImage2;
	Sprite* SPBloodFail;
	Sprite* SPBloodNumFail;
	bool isSuccess;

	//显示玩家头像
	void showHead(Node* head, int faceID);

	//显示玩家名次
	void showGrade(int rank);

	//播放结算音效
	void playAccountMusic(bool isSuccess);


};

#endif