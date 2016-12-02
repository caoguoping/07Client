#ifndef  _MATCHView_
#define  _MATCHView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  MatchView : public BlueSkyView
{
public:
	MatchView();
	~MatchView();
	void initView();

	Button   * closeBtn;
	ImageView* imgBg;
	void gotoMatch(Ref*  psender);
	void createFastMatch();

	void initFastView();  //���˿���
	void initNewView();
	void initFeeView();

	void updateFastView(); //���˿���


public:

	ImageView*  imgFrame;
	Button*  btnGoto[3];

	//fastview
	Node* matchFastNode;
	Button*  btnCansai;
	Button*  btnTuisai;
	ProgressTimer*  timerPeople;
	Text*   txtNowPeople;
	Text*   txtNeedPeople;	
	
	Node*   nodeGoldInfo;
	Text* txtDiamond;  //��ʯ
	Text* txtGold;     //���

	void clickCansai(Ref*  psender);
	void clickTuisai(Ref*  psender);
	void clickBtnCloseFast(Ref* pSender);

};

#endif
