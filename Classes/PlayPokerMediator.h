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
	//��������
	ViewMatchRanking*  mpViewMatchRanking;
	ImageView*  imgMatchScore;
	Text*  txtScore;        //����
	Text*  txtNowRank;		//����
	Text*  txtAllLeftPeople; //����������	


	//�����Ƿ����������
	bool hasBuyJiPaiQi = false;
	//��¼������ʾ������Ĵ���
	int clickTiShiTimes = 0;
	//��¼����ͬ��˳��ť������Ĵ���
	int clickTongHuaShunTimes = 0;
	//��������Ƿ񱻴�
	bool isChatOpened = false;
	int mJoinInPlayer = 0;  //�������ӵ������Ŀ
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

	Button* startBtn;  //��ʼ��Ϸ��ť
	//��������ť
	Button* markBtn;
	//�йܰ�ť
	Button* autoBtn;
	//���㰴ť
	Button* clearBtn;
	ImageView* imgJPTip;
	Text*  txtJPTips;
	//�����水ť
	Button* lookTableBtn;
	//���ֶ���ʾ
	Text* wealthText;
	//	Text* Text_1;
	Node* actionNode;
	//���ּ���
	ImageView* myJiShu1;
	ImageView* myJiShu2;
	ImageView* otherJiShu1;
	ImageView* otherJiShu2;
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
	Vec2 touchBeginPos = Vec2(0, 0);
	//���ֱ���
	int nowBeiLv = 1;
	//�ع�����ķ���������ID
	int huiGongID = -1;
	bool hasPlayJinGongAction = false;
	bool hasPlayHuanGongAction = false;
	bool hasGetJinGong = false;
	bool hasGetHuanGong = false;

	//�Ƿ��ǵ�һ�η���
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
	//������10042
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
	void updateMatchScore();  //����
	void onTouchesHuapai(Ref*  pSender, Widget::TouchEventType type);

	//�Ƿ���ʾ���ư�ť
	void isOrNotMyTurn(bool value);
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
	void playChuPaiMusic(int pokerType,int faceID);
	//ȡ���й�
	void clickCancelAutoBtnHander();
	//�Ƿ񽫳��ư�ť�û�
	void setChuPaiBtnState(bool isZhiHui);
	//��ʾ���ִ�
	void showNowJiShu(bool isMyJiShu);


};

#endif