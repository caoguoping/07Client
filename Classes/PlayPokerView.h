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
	void refresh();   //���治�壬ÿ�����á�
	void hideLayer();  //�ڲؽ��棬ȥ�������
public:

	Sprite*   spDesk[4];
	Sprite*    spBg[4];

	//���ƴ�����
	ImageView*  imgHuaPai;



	//���ѳ�
	ImageView*  imgInvitebg[3];   //0, 1, 2, �ֱ�Ϊ �� ���ϣ� ��
	Button*     btnInvite[3];
	ImageView*  imgInviteBg;

	//ʱ����
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

	//�ֳ����뱶��
	ImageView*  imgBeilv;
	ImageView*  imgLunChang;
	Text*    txtBeilv;
	Text*    txtLun;
	Text*    txtChang;

	int time;   //timer
	int nowIndex;    //1 ����ʱ�䵽��  2 ����ʱ�䵽   3 ����ʱ�䵽
	int sucessesPlayer ;   //�ѳ����Ƶ���Ҹ���
	int desk;
	int face;
	ImageView*  imgTouyou[3];
	//��ҹ�������
	//
	Node* meCharacterNode;
	Node* leftCharacterNode;
	Node* topCharacterNode;
	Node* rightCharacterNode;
	cocostudio::Armature* Action1;
	cocostudio::Armature* Action2;
	cocostudio::Armature* Action3;
	cocostudio::Armature* Action4;

	//ͷ��
	UIFrameDef(touyou)
//		UIFrameDef(jiefeng)
    void gameOverHandle();

	//����ƥ��
	cocostudio::Armature* pipeiAction;

	//�������
	Text* leftName;
	Text* topName;
	Text* rightName;

	//ʣ������
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
