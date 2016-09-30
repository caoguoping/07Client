#ifndef  _ActivityMediator_
#define  _ActivityMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"
#include "GameDataModel.h"
#include "PokerLogic.h"
#include "ActivityView.h"
#include "DataManager.h"

class ActivityMediator : public BlueSkyMediator
{
public:
	ActivityMediator();
	~ActivityMediator();
	void OnRegister();
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();


public:
	ActivityView* activityView;

	void clickCloseBtnHander();
	
	//������ǩҳ
	void clickLotteryBtnHander();
	void clickRechargeBtnHander();
	void clickMyCupBtnHander();



	void clickGetLotteryBtnHander(); //����齱��ť
	void getLotteryAwardHander();
	void getRechargeAwardHander(int index);


	void updateInfo();   //���½�Һ���ʯ
	void updateCupAward(CMD_GP_CupAwards info);
};

#endif