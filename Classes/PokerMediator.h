#ifndef  _PokerMediator_
#define  _PokerMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "PokerLogic.h"
#include "GameDataModel.h"
#include "PlayPokerMediator.h"
#include "PokerView.h"




USING_NS_CC;
using namespace ui;

struct pokeridData
{
	int pokerID;
	int pokerID2;
	int deskID;
};

class  PokerMediator : public BlueSkyMediator
{
public:
	PokerMediator(int id = -1, bool isOutPoker = false, int desk = -1, int DuiNum = -1, int ZhangNum = -1, int DuiAllNum = -1, int ZhangAllNum = -1, int isChangePos = -1,bool isGongP = false);
	~PokerMediator();
	/**
	开始执行函数
	*/
	void OnRegister();
	/**
	结束回收执行函数
	*/
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();

	//触摸开始
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnd(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);

	public:
	//
	EventListenerTouchOneByOne* touchListener;				//触摸事件监听器

	//如果选择了牌就露出头
	void SelectPkLuTou();

	//如果选择了牌就缩头
	void SelectPkSuoTou();

	//调整牌的位置
	void changePokerPosition();

	PokerVO poker;

	//是否是出的牌
	bool isPlayerOutPoker;

	//这张牌在第几堆
	int Dui;

	//这张牌在这堆中的第几张（第一张在最下面）?被压在最下面，实际位置在最上面
	int Zhang;

	//一共有多少堆
	int DuiAll;

	//这堆一共有多少张
	int ZhangAll;

	//手牌中牌与牌之间的间距
	int pkJianJu;				

	//玩家的座位号
	//      2       
	//   1	   3
	//      0
	int deskPos = -1;

	//
	PokerView* pokerView;
};

#endif