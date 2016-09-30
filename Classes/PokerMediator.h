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
	��ʼִ�к���
	*/
	void OnRegister();
	/**
	��������ִ�к���
	*/
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();

	//������ʼ
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnd(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);

	public:
	//
	EventListenerTouchOneByOne* touchListener;				//�����¼�������

	//���ѡ�����ƾ�¶��ͷ
	void SelectPkLuTou();

	//���ѡ�����ƾ���ͷ
	void SelectPkSuoTou();

	//�����Ƶ�λ��
	void changePokerPosition();

	PokerVO poker;

	//�Ƿ��ǳ�����
	bool isPlayerOutPoker;

	//�������ڵڼ���
	int Dui;

	//������������еĵڼ��ţ���һ���������棩?��ѹ�������棬ʵ��λ����������
	int Zhang;

	//һ���ж��ٶ�
	int DuiAll;

	//���һ���ж�����
	int ZhangAll;

	//������������֮��ļ��
	int pkJianJu;				

	//��ҵ���λ��
	//      2       
	//   1	   3
	//      0
	int deskPos = -1;

	//
	PokerView* pokerView;
};

#endif