#ifndef  _DailyMissionView_
#define  _DailyMissionView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "PokerGameModel.h"

class  DailyMissionView : public BlueSkyView
{
public:
	DailyMissionView(bool showGetBtn = true);
	~DailyMissionView();

	void initView();
	void showAllMission();

	//����������Ϣ
	vector<DBR_GR_UserLogonMissionRes> dailyMisInfo;

public:
	Button   * closeBtn;
	ImageView* Image_38;
	Sprite*  imgFrame;

	//��������
	ScrollView* scrImg;
	Text*   txtNowNum[6];
	Text*   txtNeetNum[6];
	Text*   txtNumLian[6];
	Button*  btnGet[6];
	Button*  btnGoto[6];
	ImageView*  imgNormal[6];
	ImageView*  imgBlack[6];

	vector<Node*> mallShowNode;
	vector<Button*> getBtnArr;
	vector<WORD> isComplete;
	vector<WORD> hasGetAward;
	void clickGetBtn(Ref *pSender);    //���
	void clickGotoBtn(Ref *pSender);   //ǰ��
	bool isClicked = true;
	bool canShowGetBtn;
};

#endif