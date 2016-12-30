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
	//��������
	ViewMatchRanking*  mpViewMatchRanking;
	ImageView*  imgMatchScore;
	Text*  txtScore;        //����
	Text*  txtNowRank;		//����
	Text*  txtAllLeftPeople; //����������	
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
	Button* startBtn;  //��ʼ��Ϸ��ť
	Button* markBtn; 	//��������ť
	bool   isJipaiQiShow; //�������Ƿ���ʾ
	bool   isJiapaiQiRequested;   //�Ƿ��ѷ��͹�����
	Button* autoBtn; //�йܰ�ť
	Button* taskBtn; //����ť
	ImageView* imgJPTip;
	Text*  txtJPTips;
	Button* lookTableBtn; 	//�����水ť
	Node* actionNode;
	//���ּ���
	ImageView* myJiShu1;
	ImageView* otherJiShu1;
	Text*  myLv;
	Text*  otherLv;
	//����
	ImageView* buchu1;
	ImageView* buchu2;
	ImageView* buchu3;
	ImageView* buchu4;
	//׼��
	ImageView* zhunbei1;
	ImageView* zhunbei2;
	ImageView* zhunbei3;
	ImageView* zhunbei4;
	//�й�
	ImageView* meAutoImage;
	ImageView* leftAutoImage;
	ImageView* topAutoImage;
	ImageView* rightAutoImage;

	Node* paiFenNode;
	Vec2 touchBeginPos;
	int nowBeiLv ;  //���ֱ���
	int huiGongID ;   //�ع�����ķ���������ID
	bool hasPlayJinGongAction ;
	bool hasPlayHuanGongAction ;
	bool hasGetJinGong ;
	bool hasGetHuanGong ;
	bool isFirstOutPoker ;  //�Ƿ��ǵ�һ�η���
	bool isMeFirstOutPoker ;

	int mPlayCount;    //�����˼��δ��ƣ����������һ�Σ�
	bool isAutoState;
	int clickTiShiTimes; //��¼������ʾ������Ĵ���
	int clickTongHuaShunTimes; //��¼����ͬ��˳��ť������Ĵ���
	bool isChatOpened; 	//��������Ƿ񱻴�
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
	void updateMatchScore();  //����
	void onTouchesHuapai(Ref*  pSender, Widget::TouchEventType type);
	//�Ƿ���ʾ���ư�ť
	void isMyTurn(bool value);
	//�Ƿ���ʾ��������
	void showBuchu(int deskID, bool show, bool isClearData);
	//��ʾ���������
	void showPlayerOnDesk();
	void sendReadyMsg();
	void setBuChuBtnState(bool state);
	void showZhunBei(int deskID, bool show);
	void setJinGongBtnState(bool show);
	void setHuanGongBtnState(bool show);
	//��ȡ���˸��Լ���������
	void getJingGong(int pokerID);
	//�Լ��ĳ���ʱ���ѵ�
	void meTimeUp();
	//����ʱ�䵽
	void jinGongTimeUp();
	//����ʱ�䵽
	void huanGongTimeUp();
	//��ʾ�й�ͼ��
	void showAutoImage(int deskID,bool show);
	//���ų�����Ч
	void playChuPaiMusic(int pokerType,int faceID, int value = 0, int desk = 0);
	//ȡ���й�
	void clickCancelAutoBtnHander();
	//�Ƿ񽫳��ư�ť�û�
	void setChuPaiBtnState(bool isZhiHui);
	//��ʾ���ִ�
	void showNowJiShu(bool isMyJiShu);


};

#endif