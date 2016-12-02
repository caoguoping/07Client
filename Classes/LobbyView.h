#ifndef  _LobbyView_
#define  _LobbyView_

#include "cocos2d.h"
#include "BlueSky.h"
//#include "cocostudio/CocoStudio.h"
#include "SGTools.h"

class  LobbyView : public BlueSkyView
{
public:


	UIDefDelayClick(Button, Task)
		UIDefDelayClick(Button, Signature)
		UIDefDelayClick(Button, Setting)
		UIDefDelayClick(Button, PlayGold)
		UIDefDelayClick(Button, Entertainment)
		UIDefDelayClick(Button, Match)
		UIDefDelayClick(Button, Blood)

		UIDefDelayClick(Button, Fast)
		UIDefDelayClick(Button, Charge)
		UIDefDelayClick(Button, Shop)
		UIDefDelayClick(Button, Activity)
		UIDefDelayClick(Button, Package)
		UIDefDelayClick(Button, Head)
		UIDefDelayClick(Button, AddWealth)   //�ӽ��
		UIDefDelayClick(Button, AddDiamond)   //����ʯ
		UIDefDelayClick(Button, Friend)

		Sprite*  spFriendTip;

		ScrollView*   scrBtn;
		
		PageView* pgAd;
		ImageView* imgPageBg;

		Button   *btnFold, *btnUnfold;
		Text*  txtGold;
		Text*  txtDiamond;
		Text*        txtPlayerName;
		Text*  txtId;
		Node*  headNode;

public:
	typedef enum mall
	{
		E_choujiang = 0,   //ת��
		E_recharge,        //��ֵ����
		E_myCup,          //myCup
		E_adMax,
	}T_enumAd;


	int currentAd;
	Button* btnAd[E_adMax];
	Button* btnAdIndicator[E_adMax];
	int adSelect;
	void callAdselect(Ref* psender);
	void adUpdate(float dt);


	LobbyView();
	~LobbyView();
	void initView();
	void refreshView();
	void showHeadImage(int index);
	void showGold(int gold);
	///
	void touchEvent(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

	void clickBtnFold(Ref*  pSender);
	void clickBtnUnfold(Ref*  pSender);


private:

	ImageView* rightImage1;
	ImageView* rightImage2;
	ImageView* leftImage1;
	ImageView* leftImage2;

	//
	

	//��������
	ScrollView* ScrollView_1;

	void ScrollEvent(Ref* target,ScrollviewEventType type);

	cocostudio::timeline::ActionTimeline* fastBtnAction;
	cocostudio::timeline::ActionTimeline* guandanBtnAction;

	void runBtnAction(float dt);
	void stopBtnAction(float dt);
};

#endif