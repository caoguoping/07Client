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
public:
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
	int nowIndex;
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
	BTN_TOUCH_HANDLE(Button, fanhui_btn, 10601);
	BTN_TOUCH_HANDLE(Button, liaotian_Btn, 10602);
	BTN_TOUCH_HANDLE(Button, chupai_Btn, 10603);//
	BTN_TOUCH_HANDLE(Button, tishi_Btn, 10604);//
	BTN_TOUCH_HANDLE(Button, buchu_Btn, 10605);//
	BTN_TOUCH_HANDLE(Button, jingongBtn, 10606);
	BTN_TOUCH_HANDLE(Button, huangongBtn, 10607);
	BTN_TOUCH_HANDLE(Button, lookTableBtn, 10608);
	BTN_TOUCH_HANDLE(Button, tonghuashun_Btn, 10609);//
	BTN_TOUCH_HANDLE(Button, lichengyipai_Btn, 10610);//
	BTN_TOUCH_HANDLE(Button, chongxinglipai_Btn, 10611);//
	BTN_TOUCH_HANDLE(Button, jipaiqi_Btn, 10612);//
	BTN_TOUCH_HANDLE(Button, tuoguan_Btn, 10613);//
	BTN_TOUCH_HANDLE(Button, clear_btn, 10614);//
	BTN_TOUCH_HANDLE(Button, clickMeBtn, 10618);
	BTN_TOUCH_HANDLE(Button, clickLeftBtn, 10619);
	BTN_TOUCH_HANDLE(Button, clickTopBtn, 10620);
	BTN_TOUCH_HANDLE(Button, clickRightBtn, 10621);
	BTN_TOUCH_HANDLE(Button, getGoldBtn, 10615);

};





#endif