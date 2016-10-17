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
	int pintNum = 0;
	PlayPokerView*  playPokerView;
	cocostudio::timeline::ActionTimeline* matchEndLoading;
	cocostudio::timeline::ActionTimeline* matchEndLoading2;
	bool isShowMatchEndLoading;
	Node*   matchEndLoadingNode;
	Node*   matchEndLoadingNode2;
	Text*   txtLeftDesks = NULL;
	//积分排名
	ViewMatchRanking*  mpViewMatchRanking;
	ImageView*  imgMatchScore;
	Text*  txtScore;        //积分
	Text*  txtNowRank;		//排名
	Text*  txtAllLeftPeople; //本轮总人数	


	//本局是否买过记牌器
	bool hasBuyJiPaiQi = false;
	//记录本轮提示被点击的次数
	int clickTiShiTimes = 0;
	//记录本轮同花顺按钮被点击的次数
	int clickTongHuaShunTimes = 0;
	//聊天面板是否被打开
	bool isChatOpened = false;
	int mJoinInPlayer = 0;  //进入桌子的玩家数目
	DWORD jipaiqiNum;
	//
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
	//记牌器按钮
	Button* markBtn;
	//托管按钮
	Button* autoBtn;
	//清零按钮
	Button* clearBtn;
	ImageView* imgJPTip;
	Text*  txtJPTips;
	//看桌面按钮
	Button* lookTableBtn;
	//欢乐豆显示
	Text* wealthText;
	//	Text* Text_1;
	Node* actionNode;
	//本轮级数
	ImageView* myJiShu1;
	ImageView* myJiShu2;
	ImageView* otherJiShu1;
	ImageView* otherJiShu2;
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
	Vec2 touchBeginPos = Vec2(0, 0);
	//本局倍率
	int nowBeiLv = 1;
	//回贡对象的服务器椅子ID
	int huiGongID = -1;
	bool hasPlayJinGongAction = false;
	bool hasPlayHuanGongAction = false;
	bool hasGetJinGong = false;
	bool hasGetHuanGong = false;

	//是否是第一次发牌
	bool isFirstOutPoker = true;
	bool isMeFirstOutPoker = false;

	//
	int wCurrentUser;

	//
	bool isAutoState = false;
public:
	PlayPokerMediator(){};
	~PlayPokerMediator();
	void OnRegister();
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();
	void clickfanHuiBtnHander();
	void clickChatBtnHander();
	void clickChuPaiBtnHander();
	void clickJinGongBtnHander();
	void clickHuanGongBtnHander();
	void clickTiShiBtnHander();
	void clickBuChuBtnHander(Ref* psender);
	void clickTongHuaShunBtnHander();
	void clickLiChengYiPaiBtnHander();
	void clickChongLiBtnHander();
	void clickMarkBtnHander();
	void clickAutoBtnHander();
	void clickClearBtnHander();
	//看桌面10042
	bool clicklookTableBtn(Touch *touch, Widget::TouchEventType type);

public:
	void showPlayerOnDeskHandle(void* data);
	void OnDeskHandle(void* data);
	void sendPokerkHandle(void* data);
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
	void isOrNotMyTurn(bool value);
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
	void playChuPaiMusic(int pokerType,int faceID);
	//取消托管
	void clickCancelAutoBtnHander();
	//是否将出牌按钮置灰
	void setChuPaiBtnState(bool isZhiHui);
	//显示本轮打几
	void showNowJiShu(bool isMyJiShu);


};

#endif