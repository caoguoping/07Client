#ifndef  _PlayerInDeskModel_
#define  _PlayerInDeskModel_

#include "cocos2d.h"
#include "BlueSky.h"
#include "SGTools.h"
#pragma pack(1)


struct OnDesk
{
	DWORD dwUserID;
	WORD  wTableID;
	WORD  wChairID;
	BYTE cbUserStatus;
};

struct OnDeskPlayerInfo
{
	DWORD dwGameID;//��Ϸ I D
	DWORD dwUserID;//�û� I D
	DWORD dwGroupID;//���� I D
	WORD wFaceID;//ͷ������
	DWORD dwCustomID;//�Զ���ʶ
	BYTE cbGender;//�û��Ա�
	BYTE cbMemberOrder;//��Ա�ȼ�
	BYTE cbMasterOrder;//����ȼ�
	WORD wTableID;//��������
	WORD wChairID;//��������
	BYTE cbUserStatus;//�û�״̬
	SCORE lScore;//�û�����
	SCORE lGrade;//�û��ɼ�
	SCORE lInsure;//�û�����

	DWORD dwWinCount;//����
	DWORD dwLostCount;//ʧ������
	DWORD dwDrawCount;//�;�����
	DWORD dwFleeCount;//��������
	DWORD dwUserMedal;//�û�����
	DWORD dwExperience;//�û�����
	DWORD lLoveLiness;//�û�����
	WORD nick1;
	WORD nick2;

	string szNickName;//10--
	string szGroupName;//11--
	string szUnderWrite;//12--
	bool isClear = true;   //false ��Ҫ��ʾ true ����ʾ
};

class PlayerInDeskModel : public BlueSkyModel
{
public:
	PlayerInDeskModel(){};
	~PlayerInDeskModel(){};
	static const string NAME;

	//�����������Ϣ
	OnDeskPlayerInfo DeskPlayerInfo[4]; //�±�Ϊ������ID



	OnDeskPlayerInfo FruitPlayer;
	int chair[4];   //����������ID    �±�Ϊ������Id, ֵΪ�ͻ���ID
	//���������Ϣ
	void clean();
	
	//������ҵĿͻ�������ID��ȡ��ҵķ���������ID
	int getServiceChairID(int clientID);


	//�������� SessionSelectMediator�в���ʹ�� ֮������ݷ�����������ֵ��ֵ
	int ccNun;
	int wKindID;
};

#endif