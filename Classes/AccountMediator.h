#ifndef  _AccountMediator_
#define  _AccountMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"

#include "PlayPokerView.h"
#include "PlayPokerMediator.h"
#include "AccountView.h"


class AccountMediator : public BlueSkyMediator
{
public:
	AccountMediator(CMD_S_GameEnd data);
	AccountMediator();
	~AccountMediator();
	/**
	��ʼִ�к���
	*/
	void OnRegister();
	/**
	��������ִ�к���
	*/
	void onRemove();
	/*
	�¼���Ӧ����
	*/
	void onEvent(int i, void* data);
	Layer* getLayer();

private:
	//
	AccountView* accountView;

	//�ҵ���Ϸ������Ϣ
	Text* myName;
	Text* myGold;
	Node* myHead;
	Node* grade;
	string myNickName;
	int myFaceID;
	string myGoldChange;
	int myGrade; //(0 ~3)
	Sprite* successImage1;
	Sprite* successImage2;
	Sprite* failImage1;
	Sprite* failImage2;
	bool isSuccess;

	//���1�Ľ�����Ϣ
	Text* player1Name;
	Text* player1Gold;
	Node* player1Head;
	string playerNick1Name;
	int player1FaceID;
	string player1GoldChange;
	int player1Grade;

	//���2�Ľ�����Ϣ
	Text* player2Name;
	Text* player2Gold;
	Node* player2Head;
	string playerNick2Name;
	int player2FaceID;
	string player2GoldChange;
	int player2Grade;

	//���3�Ľ�����Ϣ
	Text* player3Name;
	Text* player3Gold;
	Node* player3Head;
	string playerNick3Name;
	int player3FaceID;
	string player3GoldChange;
	int player3Grade;


	//������ذ�ť
	void clickFanHuiBtnHander();

	//���������ť
	void clickContinueBtnHander();

	//������һ��
	void clickNextMatch();

	//��ʾ���ͷ��
	void showHead(Node* head, int faceID);

	//��ʾ�������
	void showGrade(int rank);

	//���Ž�����Ч
	void playAccountMusic(bool isSuccess);


};

#endif