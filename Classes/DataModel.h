
#ifndef  _DATA_MODEL_
#define  _DATA_MODEL_

#include "cocos2d.h"
#include "SGTools.h"
#pragma pack(1)


//����״̬
#define GAME_STATE_END						0x00								//û��״̬ ,��������
#define GAME_STATE_SIGNUP					0x01								//����״̬
#define GAME_STATE_MATCHING					0x02								//����״̬
#define GAME_STATE_OUT						0x03								//��̭״̬
#define GAME_STATE_QUIT						0x04							    //����


struct CMD_GP_UserYbToGold
{
	DWORD	dwUserID;
	DWORD	yb;
};
struct CMD_GP_UserInsureSuccess
{
	DWORD						dwUserID;							//�û� I D
	long long							lUserScore;							//�û����
	long long							lUserInsure;						//���н��
	char								szDescribeString[256];				//������Ϣ
};

struct MyBaseData
{
	//��������
	WORD							wFaceID;							//ͷ���ʶ
	DWORD							dwUserID;							//�û� I D  ��������
	DWORD							dwGameID;							//��Ϸ I D
	DWORD							dwGroupID;							//���ű�ʶ
	DWORD							dwCustomID;							//�Զ���ʶ
	DWORD							dwUserMedal;						//�û�����
	DWORD							dwExperience;						//������ֵ
	DWORD							dwLoveLiness;						//�û�����
	//�û��ɼ�
	SCORE								lUserScore;							//�û����
	SCORE								lUserInsure;						//�û�����
	//�û���Ϣ
	BYTE							cbGender;							//�û��Ա�
	BYTE							cbMoorMachine;						//��������
	string									szAccounts;							//��¼�ʺ�
	string									szNickName;							//�û��ǳ�
	string									szGroupName;						//��������
	//������Ϣ
	BYTE                           cbShowServerStatus;                //��ʾ������״̬
	DWORD										isFirstLogin;						//�Ƿ��ǽ����һ�ε�¼
	DWORD							rmb;								//��ʯ
	WORD							wBeiZaNum[4]; //���Ҽ���,ը�������ģ��ʻ�����Ŀ��

};

//ϵͳ��Ϣ���ݰ�
struct CMD_S_MESSAGE
{
	WORD							wChairID;							//�����û�
	TCHAR							szBuffer[128];						//ϵͳ��Ϣ
};
//200  110

//ϵͳ��Ϣ
struct CMD_CM_SystemMessage
{
	WORD							wType;								//��Ϣ����
	WORD							wLength;							//��Ϣ����
	TCHAR							szString[1024];						//��Ϣ����
};
//1000 1
//100  200



//7 ,   409  //������Ϣ
struct CMD_GR_MatchStatus
{
	WORD       dwRoundID;     //��ǰ����
	WORD       dwGameID;	//��ǰ����
	WORD      RoundCount;		//������
	WORD     GameCount;		//�ܳ���
	WORD     PlayerCount;   //������
	WORD     NextPlayerCount;		//��һ������   ���һ��Ϊ0 
};


//����������Ϣ
struct CMD_GR_MatchJinJi
{
	DWORD     dwUserID;
	BYTE            isJinJi;				//�Ƿ����    1  -- ����  0 -- ��̭
	WORD		cdRank;				//����
};
//7   410




//����
//6	2 ���������Ϣ
//DWORD    dwUserID;

//6	3 ���غ�����Ϣ
/*
struct tagFriendShipParameter
{
	DWORD							dwUserID;						//�û�ID
	WORD								wfriendsNum;					//��������
	tagFriendParameter			wfriendInfos[20];		//������Ϣ
};
*/


//���Ѳ���
struct tagFriendParameter
{
	DWORD							    dwUserID    ;						//�û�ID
	std::string 						szNickName  ;			//�û��ǳ�
	DWORD								dwRmb       ;								//��ʯ
	WORD								FaceID      ;
	WORD								wServerID   ;						//����ID
	WORD								wKindID     ;							//��ϷID
	DWORD							    dwLoveLiness;			//����
	WORD								WinRate     ;							//ʤ��
	BYTE                                bStates;                //0�����ߣ�1����
};

//6	4  ���Ѳ���   ���� ������� s = 0  ͬ������ s = 1   ɾ������ s = 2
struct CMD_GP_Snd_ADD_Friend
{
	DWORD				dwUserID;
	DWORD				dwTargretUserID;
	WORD					wStatue;     // 0 - ���� 1- ͬ��  2 --ɾ��  3 -�ܾ�
};

//6	5	���غ��������Ϣ	s = -1 ����ʧ��	s = 0 �ɹ����� 	s = 1  �ɹ���Ϊ����
struct CMD_GP_C_ADD_Friend
{
	DWORD				dwUserID;
	DWORD				dwTargretUserID;
	WORD					wStatue;     // 0 - ���� 1- ͬ��  2 --ɾ��  3 -�ܾ�
	std::string								szNickName;			//�û��ǳ�
	DWORD								dwRmb;								//��ʯ
	WORD								FaceID;
	WORD								wServerID;						//����ID
	WORD								wKindID;							//��ϷID
	DWORD							dwLoveLiness;			//����
	WORD								WinRate;							//ʤ��
	WORD        					    wRcStates;    //���յ���״̬
};


//6	9	���������б�
/*
struct DBO_GP_Contact
{
	WORD									wNum;
	tagContactInfo					Infos[20];
};
*/

struct tagContactInfo
{
	DWORD						dwUserID;
	std::string							szNickName;
	WORD							wFaceID;
};


// 6, 10 ����
// struct  CMD_GP_C_SEARCH_USER
// {
// 	TCHAR								szSearchINfo[LEN_NICKNAME];
// };
// 

//6�� 11�� 
struct  CMD_GP_S_SEARCH_USER
{
	DWORD							dwUserID;
	std::string							szNickName;
	WORD								wFaceID;
};

//����������Ϣ
struct tagInviteInfo
{
	DWORD							dwUserID;
	std::string							szNickName;
	WORD								wFaceID;
};

//6, 13 ��������
struct CMD_GP_S_RESULT_INVITE
{
	DWORD								dwUserID;
	WORD									wNum;
	tagInviteInfo						info[20];
};

//6, 15 �������뷢��
struct CMD_SUB_S_INVITE_ENTER_GAME
{
	DWORD							dwUserID;  //�Լ�ID
	DWORD							dwTargetID;      //����Ŀ�����
	WORD								wGameID;		//��ϷID
	WORD								wTableID;
	WORD								wChairID;
	WORD                                wIsFriend;   //1 : friend,  0:  team.
	char                     strName[64];
};

//6, 16 �յ���������
struct CMD_SUB_C_INVITE_ENTER_GAME
{
	DWORD							dwUserID;  //�Լ�ID
	DWORD							dwTargetID;      //����Ŀ�����
	WORD								wGameID;		//��ϷID
	WORD								wTableID;
	WORD								wChairID;
	WORD                                wIsFriend;   //1 : friend,  0:  team.
	std::string                     strName;
};

//200, 13 game ������������  ���չ㲥200, 113
struct	CMD_C_USE_PROPERTY
{
	WORD						wIndex;						//����ID 1, 2, 3, 4
	WORD						wChairID;					//�Լ�����λID
	WORD						wTargetID;				//Ŀ��ID 
};

//3, 510 ���Ҽ����ȼ��� ��¼������
struct CMD_GP_S_RESULT_INFO
{
	DWORD							dwUserID;
	WORD								wNum1;
	WORD								wNum2;
	WORD								wNum3;
	WORD								wNum4;
};

//4, 101.
//����״̬

struct CMD_GR_TableStatus
{
	WORD							wTableID;							//���Ӻ���
	//tagTableStatus					TableStatus;						//����״̬
	BYTE							cbTableLock;						//������־
	BYTE							cbPlayStatus;						//��Ϸ��־   //0, ���Ӳ��ڡ�
};


struct stSystemMsg
{
	WORD							wType;								//��Ϣ����
	WORD							wLength;							//��Ϣ����
	std::string						strContent;						//��Ϣ����
};

USING_NS_CC;

//ǩ����ѯ
struct DBO_GP_Seven_Logon
{
	DWORD					dwUserID;							//�û���ʶ
	WORD					LogonCnt;							//ǩ������
};

#endif

