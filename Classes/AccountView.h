#ifndef  _AccountView_
#define  _AccountView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  AccountView : public BlueSkyView
{
public:
	AccountView();
	~AccountView();

	void initView();
	void updateBackTimes(float dt);
	void playAccountAction(bool isSuccess);
	void clickBtnBack(Ref*  pSender);
	void btnBackHandle();
	
	void clickBtnContinune(Ref*  pSender);
	void clickBtnNextMatch(Ref*  pSender);
	void showSuccessAction(float dt);
public:

	int leftTime;    
	Node*   ndPubMsg;
	Layout*  winLayout;    //比赛胜利结算
	Layout*  loseLayout;   //比赛失败结算
	Text*    txtRanks;    //名次
	Text*    txtBestRanks;  //最佳名次
	Text*   txtPeoples;   //多少人场比赛

	Text*   txtRewards;   //奖励金币
	Text*   txtBackTime;   //返回剩余时间
	Button  *btnBack, *btnContinue, *btnNextMatch;
	//失败动画
	cocostudio::timeline::ActionTimeline* failAction;
	Node* failActionNode;

	//胜利粒子
	ParticleSystemQuad* winParticle;
	ParticleSystemQuad* glodParticle;


};

#endif