#ifndef  _PlayPokerMediator_
#define  _PlayPokerMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "OutPokerLogicRule.h"
#include "PokerLogic.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "GameDataModel.h"
#include "PlayerInDeskModel.h"
#include "DataManager.h"
#include "PokerMediator.h"
#include "PokerGameModel.h"

#include "UTF8.h"
#include "PokerView.h"
#include "PokerMediator.h"
#include "PlayerInfoView.h"
#include "PlayerInfoMediator.h"
#include "CancelAutoView.h"
#include "CancelAutoMediator.h"
#include "DailyMissionView.h"
#include "DailyMissionMediator.h"
#include "ChatView.h"
#include "ChatMediator.h"
#include "GongPaiActionView.h"
#include "GongPaiActionMediator.h"
#include "ShopView.h"
#include "ShopMediator.h"
#include "RoomListModel.h"

#include "SGTools.h"
#include "ViewMatchRanking.h"
#include "PlayPokerView.h"

using namespace std;
USING_NS_CC;

class  PlayPokerMediator : public BlueSkyMediator
{
public:
	PlayPokerView*  playPokerView;

	UIFrameDef(bloodStart)
	UIFrameDef(zhupai)	
		ImageView*  imgZhupai;
	ImageView*  imgZhupaiDi;
	UIFrameDef(matchEndLoading)
		UIFrameDef(matchEndLoading2)



	Text*   txtLeftDesks = NULL;
	//积分排名
	ViewMatchRanking*  mpViewMatchRanking;
	ImageView*  imgMatchScore;
	Text*  txtScore;        //积分
	Text*  txtNowRank;		//排名
	Text*  txtAllLeftPeople; //本轮总人数	
	DWORD jipaiqiNum;
	Button* addWealthBtn;
	Button* fanHuiBtn;
	Button* chatBtn;
	Button* chuPaiBtn;
	Button* tiShiBtn;
	Button* buChuBtn;
	Button* jingongBtn;
	Button* huangongBtn;
	Button* tongHuaShunBtn;
	Button* liChengYiPaiBtn;
	Button* chongLiBtn;
	Button* startBtn;  //开始游戏按钮
	Button* markBtn; 	//记牌器按钮
	bool   isJipaiQiShow; //记牌器是否显示
	bool   isJiapaiQiRequested;   //是否已发送过请求。
	Button* autoBtn; //托管按钮
	Button* taskBtn; //任务按钮
	ImageView* imgJPTip;
	Text*  txtJPTips;
	Button* lookTableBtn; 	//看桌面按钮
	Node* actionNode;
	//本轮级数
	ImageView* myJiShu1;
	ImageView* otherJiShu1;
	Text*  myLv;
	Text*  otherLv;
	//不出
	ImageView* buchu1;
	ImageView* buchu2;
	ImageView* buchu3;
	ImageView* buchu4;
	//准备
	ImageView* zhunbei1;
	ImageView* zhunbei2;
	ImageView* zhunbei3;
	ImageView* zhunbei4;
	//托管
	ImageView* meAutoImage;
	ImageView* leftAutoImage;
	ImageView* topAutoImage;
	ImageView* rightAutoImage;

	Node* paiFenNode;
	Vec2 touchBeginPos;
	int nowBeiLv ;  //本局倍率
	int huiGongID ;   //回贡对象的服务器椅子ID
	bool hasPlayJinGongAction ;
	bool hasPlayHuanGongAction ;
	bool hasGetJinGong ;
	bool hasGetHuanGong ;
	bool isFirstOutPoker ;  //是否是第一次发牌
	bool isMeFirstOutPoker ;

	int mPlayCount;    //进行了几次打牌，发完牌算第一次，
	bool isAutoState;
	int clickTiShiTimes; //记录本轮提示被点击的次数
	int clickTongHuaShunTimes; //记录本轮同花顺按钮被点击的次数
	bool isChatOpened; 	//聊天面板是否被打开
	int wCurrentUser;
public:
	PlayPokerMediator();
	~PlayPokerMediator();
	void callRemoveZhupaiDi();
	void callRemoveZhupaiNode();
	void OnRegister();
	void readyPlay();
	void showFriendButtons(bool isShow);

	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();
	void clickfanHuiBtnHander();
	void handleFanhui();
	void clickChatBtnHander(Ref* psender);
	void clickJinGongBtnHander(Ref* psender);
	void clickHuanGongBtnHander(Ref* psender);
	void clickTiShiBtnHander(Ref* psender);
	void clickBuChuBtnHander(Ref* psender);
	void clickChuPaiBtnHander(Ref* psender);
	void clickTongHuaShunBtnHander(Ref* psender);
	void clickLiChengYiPaiBtnHander(Ref* psender);
	void clickChongLiBtnHander(Ref* psender);
	void clickMarkBtnHander(Ref* psender);
	void clickAutoBtnHander(Ref* psender);
	void clickTaskBtnHander(Ref* psender);
	bool clicklookTableBtn(Touch *touch, Widget::TouchEventType type);
	void handleTiShi();
	void handleBuChu();
	void handleChuPai();

public:
	void handleFriendPlay();
	void showPlayerOnDeskHandle(void* data);
	void showPlayerOnDeskHandle();
	void OnDeskHandle(void* data);
	void delaySendPokerHandle();
	void delayShowZhupai();
	void sendPokerkHandle();
	void notOutPokerHandle(void* data);
	void reveivePlayerOutPokerHandle(void* data);
	void payTributeHandle(void* data);
	void showMatchEndLoading();
	void hideEndLoading();
	void showMatchRanking();
	void hideMatchRanking();
	void onMatchEnd(BYTE bState);
	void updateMatchScore();  //更新
	void onTouchesHuapai(Ref*  pSender, Widget::TouchEventType type);
	//是否显示出牌按钮
	void isMyTurn(bool value);
	//是否显示不出文字
	void showBuchu(int deskID, bool show, bool isClearData);
	//显示上座的玩家
	void showPlayerOnDesk();
	void sendReadyMsg();
	void setBuChuBtnState(bool state);
	void showZhunBei(int deskID, bool show);
	void setJinGongBtnState(bool show);
	void setHuanGongBtnState(bool show);
	//获取别人给自己进贡的牌
	void getJingGong(int pokerID);
	//自己的出牌时间已到
	void meTimeUp();
	//进贡时间到
	void jinGongTimeUp();
	//还贡时间到
	void huanGongTimeUp();
	//显示托管图标
	void showAutoImage(int deskID,bool show);
	//播放出牌音效
	void playChuPaiMusic(int pokerType,int faceID, int value = 0, int desk = 0);
	//取消托管
	void clickCancelAutoBtnHander();
	//是否将出牌按钮置灰
	void setChuPaiBtnState(bool isZhiHui);
	//显示本轮打几
	void showNowJiShu(bool isMyJiShu);


};

#endif