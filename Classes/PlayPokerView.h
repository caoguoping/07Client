#ifndef  _PlayPokerView_
#define  _PlayPokerView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "SGTools.h"
using namespace ui;
USING_NS_CC;
class  PlayPokerView : public BlueSkyView
{
public:
	PlayPokerView();
	~PlayPokerView();
	void showFriendInvites();
	void hideFriendInvite(DWORD  dwWhich);
	void clickBtnInvite(Ref*   pSender);
	void showPiPei(bool show);
	void clockShow(float dt);
	void hideAllPokerNum();
	void showPokerNum(int desk, int pokerNum);
	void hideAllFace();
	void hideAllName();
	void showCharacterName(int pos, string name);
	void showDaiJiFace(int pos, int faceID);
	void showChuPaiFace(int pos, int faceID);
	void showSuccessFace(int pos, int faceID);
	void showDaiJiFaceHander(float dt);
	void showPokerAllOutFaceHander(float dt);
	void showPokerAllOutFace(int pos, int faceID);
	void hideClock(int pos = -1);
	void stopClock();
	void showBeiLv(int index);
	void showLunChang();
	void showTouyou(int);
	void startClock(int deskID, int index = 1);  //deskId : client chairId.
	void viewInit();
	void refresh();   //界面不清，每次重置。
	void hideLayer();  //掩藏界面，去除点击等
public:

	Sprite*   spDesk[4];
	Sprite*    spBg[4];

	//划牌触摸层
	ImageView*  imgHuaPai;



	//好友场
	ImageView*  imgInvitebg[3];   //0, 1, 2, 分别为 左 ，上， 下
	Button*     btnInvite[3];
	ImageView*  imgInviteBg;

	//时间钟
	Node* myClock;
	Node* leftClock;
	Node* topClock;
	Node* rightClock;

	TextBMFont * myClockText;
	TextBMFont* leftClockText;
	TextBMFont* topClockText;
	TextBMFont* rightClockText;
	ProgressTimer*  myTimer;
	ProgressTimer*  leftTimer;
	ProgressTimer*  topTimer;
	ProgressTimer*  rightTimer;

	//轮场次与倍率
	ImageView*  imgBeilv;
	ImageView*  imgLunChang;
	Text*    txtBeilv;
	Text*    txtLun;
	Text*    txtChang;

	int time;   //timer
	int nowIndex;    //1 出牌时间到，  2 进贡时间到   3 还贡时间到
	int sucessesPlayer ;   //已出完牌的玩家个数
	int desk;
	int face;
	ImageView*  imgTouyou[3];
	//玩家骨骼动画
	//
	Node* meCharacterNode;
	Node* leftCharacterNode;
	Node* topCharacterNode;
	Node* rightCharacterNode;
	cocostudio::Armature* Action1;
	cocostudio::Armature* Action2;
	cocostudio::Armature* Action3;
	cocostudio::Armature* Action4;

	//头游
	UIFrameDef(touyou)
//		UIFrameDef(jiefeng)
    void gameOverHandle();

	//正在匹配
	cocostudio::Armature* pipeiAction;

	//玩家名称
	Text* leftName;
	Text* topName;
	Text* rightName;

	//剩余牌数
	Node* leftPokerNum;
	Node* topPokerNum;
	Node* rightPokerNum;


	public:
	Button* fanhui_btn   ;
	Button* clickMeBtn   ;
	Button* clickLeftBtn ;
	Button* clickTopBtn  ;
	Button* clickRightBtn;
	Button* getGoldBtn   ;

};





#endif
