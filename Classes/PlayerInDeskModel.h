#ifndef  _PlayerInDeskModel_
#define  _PlayerInDeskModel_

#include "cocos2d.h"
#include "BlueSky.h"
#pragma pack(1)


struct OnDesk
{
	unsigned int dwUserID;
	unsigned short wTableID;
	unsigned short wChairID;
	unsigned char cbUserStatus;
};

struct OnDeskPlayerInfo
{
	unsigned int dwGameID;//��Ϸ I D
	unsigned long dwUserID;//�û� I D

	unsigned int dwGroupID;//���� I D

	unsigned int wFaceID;//ͷ������
	unsigned int dwCustomID;//�Զ���ʶ
	unsigned int cbGender;//�û��Ա�
	unsigned int cbMemberOrder;//��Ա�ȼ�

	unsigned int cbMasterOrder;//����ȼ�

	unsigned int wTableID;//��������
	unsigned int wChairID;//��������
	unsigned int cbUserStatus;//�û�״̬

	long long lScore;//�û�����
	long long lGrade;//�û��ɼ�
	long long lInsure;//�û�����

	unsigned int dwWinCount;//����
	unsigned int dwLostCount;//ʧ������
	unsigned int dwDrawCount;//�;�����
	unsigned int dwFleeCount;//��������

	unsigned int dwUserMedal;//�û�����

	unsigned int dwExperience;//�û�����
	unsigned int lLoveLiness;//�û�����

	string szNickName;//10--
	string szGroupName;//11--
	string szUnderWrite;//12--

	unsigned int nick1;
	unsigned int nick2;

	bool isClear = true;   //false ��Ҫ��ʾ true ����ʾ
};

class PlayerInDeskModel : public BlueSkyModel
{
public:
	PlayerInDeskModel(){};
	~PlayerInDeskModel(){};
	static const string NAME;

	//�����������Ϣ
	OnDeskPlayerInfo DeskPlayerInfo[4];



	OnDeskPlayerInfo FruitPlayer;
	int chair[4];   //����������ID
	//���������Ϣ
	void clean();
	
	//������ҵĿͻ�������ID��ȡ��ҵķ���������ID
	int getServiceChairID(int clientID);


	//�������� SessionSelectMediator�в���ʹ�� ֮������ݷ�����������ֵ��ֵ
	int ccNun;
	int wKindID;
};

#endif