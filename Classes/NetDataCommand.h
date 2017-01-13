#ifndef  _NetDataCommand_
#define  _NetDataCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "head.h"
#include "RoomListModel.h"
#include "EventType.h"
#include "DataManager.h"
#include "PlayerInDeskModel.h"
#include "PokerGameModel.h"
#include "GameDataModel.h"

#include "command.h"




class  NetDataCommand : public BlueSkyCommand
{
public:
	NetDataCommand();
	~NetDataCommand(){};
	Text* txtLogin;
	Text* txtGame;
	Text* txtGame2;
	Text* txtFail;

	/**
	�¼�ִ֪ͨ�к���
	*/

	void execute(void* data);
private:
	void executeLogin(NetData netData);
	void executeGame(NetData netData);
	void loginComplete(NetData netData);//��¼�ɹ�
	void firstLogin(NetData netData);   //�״ε�½


	void getGameFail(NetData netData);


	void getRoomList(NetData netData);//��ȡ�����б�
	void getDeskInfo(NetData netData);	//��ȡ������Ϣ
	void getInDeskPlayerInfo(NetData netData);	//��ȡ���뷿��������Ϣ

	void getMatchJiesuanInfo(NetData netData);	//��ȡ����������Ϣ

	void getSendPokerInfo(NetData netData);	//��ȡ��������
	void getPlayerOutPoker(NetData netData);//�û�����
	void getPlayerOutPokerError(NetData netData);//�û����ƴ���
	void notOutPoker(NetData netData);//����
	void getPayTribute(NetData netData);//����
	void gameOver(NetData netData);//��Ϸ����
	void getChat(NetData netData);//����
	void getSignInformation(NetData netData);//ǩ����ѯ
	void getMisInfo(NetData netData);//������Ϣ
	void getMallInfo(NetData netData);//�̳���Ϣ
	void getSysMsg(NetData netData);//ϵͳ��Ϣ
	void getMisReward(NetData netData);//������
	void getLoginMisInfo(NetData netData);//������Ϣ
	void insureSuccess(NetData netData);//��ʯ��Ǯ
	void getGamblingInfo(NetData netData);//�齱��Ϣ
	void getItemsInfo(NetData netData);//��������
	void getBuyItemsInfo(NetData netData);//�����̳���Ʒ
	void getBeiZaInfo(NetData netData);   //���ҵ���Ŀ
	void getZuanShiInfo(NetData netData);//��ʯ�䶯
	void useItem(NetData netData);//ʹ�õ���
	void useJiPaiQi(NetData netData);//ʹ�ü�����
	void getRankInfo(NetData NetData); //��ȡ���а���Ϣ
	void getCupAwardInfo(NetData netData); //��ȡcup������Ϣ
	void getMatchNumInfo(NetData netData);	//��ȡ��ǰ��������
	void getMatchStates(NetData netData);    //7, 406  ������������������������
	void getBestRank(NetData netData);     //7, 411, ��ʷ�������
	void getJipaiqiData(NetData netData);
	//3, 104 �û�����
	void getMatchUserScore(NetData netData);

	//3   105  ʣ��������Ŀ
	void getMatchLeftDesk(NetData netData);

	//3  106  ���а�
	void getMatchRank(NetData netData);

	//7. 409 ���������ִ�
	void getMatchChangLun(NetData netData);

	//7. 410  �������Ƿ���̭
	void getMatchPass(NetData netData);

	//6	3 ���غ�����Ϣ
	void getFriendsInfo(NetData netData);

	//6	5	���غ��������Ϣ	s = -1 ����ʧ��	s = 0 �ɹ����� 	s = 1  �ɹ���Ϊ����
	void getFriedsAddInfoMe(NetData netData);

	//6, 6  
	void getFriedsAddInfoHim(NetData netData);

	//6	9	���������б�
	void getFriendsShuRen(NetData netData);

	//6, 11, ��������������Ϣ
	void getFriendSearch(NetData netData);

	//6. 13�� ��������
	void getFriendPush(NetData netData);

	//6. 16 ,�յ����ѳ�����
	void getFriendFieldInvite(NetData netData);

	//200, 113, ��Ϸ���������㲥�Ҽ���
	void getBroadCastDaoju(NetData netData);

	//4, 101
	void getTableInfo(NetData netData); //4�˳�����������

};

#endif