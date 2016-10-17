
#ifndef  _DATA_MANAGER_
#define  _DATA_MANAGER_

#include "cocos2d.h"
#include "PokerGameModel.h"
#include "SGTools.h"
#include "GameDataModel.h"
#include "PlayerInDeskModel.h"

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
	unsigned short							wFaceID;							//ͷ���ʶ
	DWORD							dwUserID;							//�û� I D  ��������
	DWORD							dwGameID;							//��Ϸ I D
	DWORD							dwGroupID;							//���ű�ʶ
	DWORD							dwCustomID;							//�Զ���ʶ
	DWORD							dwUserMedal;						//�û�����
	DWORD							dwExperience;						//������ֵ
	DWORD							dwLoveLiness;						//�û�����

	//�û��ɼ�
	long long								lUserScore;							//�û����
	long long								lUserInsure;						//�û�����

	//�û���Ϣ
	unsigned char							cbGender;							//�û��Ա�
	unsigned char							cbMoorMachine;						//��������
	string									szAccounts;							//��¼�ʺ�

	string									szNickName;							//�û��ǳ�
	string									szGroupName;						//��������


	//������Ϣ
	unsigned char                           cbShowServerStatus;                //��ʾ������״̬

	int										isFirstLogin;						//�Ƿ��ǽ����һ�ε�¼

	DWORD							rmb;								//��ʯ

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


//200, 13 game ������������  ���չ㲥200, 113
struct	CMD_C_USE_PROPERTY
{
	WORD						wIndex;						//����ID
	WORD						wChairID;					//�Լ�����λID
	WORD						wTargetID;				//Ŀ��ID 
};





USING_NS_CC;

class DataManager 
{
public:

	typedef enum DeskBg
	{
		E_DeskBg_Match = 10,
	}E_DeskBg;


	typedef enum GameCate
	{
		E_GameCateNormal = 0,
		E_GameCateMatch,    //����
	}E_GameCate;

	BYTE jipai[18];     //����������
	WORD chouJiangTime;   //�齱����
	WORD diamondNum;     //��һ����Ҫ����ʯ

	CMD_GP_CupInfo  myRankInfo;    //���а���Ϣ

	DWORD dwGameBtnId;   //��������ĸ���Ϸ��ť  
	BYTE bGameCate;    //��һ����Ϸ 0�� ������   1�� ����
	WORD wMatchAllChangci;   //�����ܳ���    3��  2��
	WORD wMatchAllLunci;     //��ǰ���ε����ִΣ����֣�
	WORD wMatchNowChangci;   //��ǰ��������    1�� 2�� 3
	WORD wMatchNowLuanci;    //��ǰ�����ִ� 
	WORD wMatchPlayer;       //��ǰ��������
	WORD wMatchNextPlayerCount;   //��һ������   ���һ��Ϊ0 
	BYTE bLastMatch;   //0, ��̭��  1�����ܾ����� 2:���Ǳ���
	BYTE bIsJinji;     //1, ������  0:  ��̭
	BYTE bMatchOver;   //1������������ 0��û�н���
	WORD	wCdRank;				//����
	WORD    wMatchScore;     //����
	WORD    wBestRank;      //��ʷ�������
	CMD_S_GameEnd   GameEndData;

	BYTE  bMatchItem = 0;    //�����ĵڼ�����ť  0��1��2

	std::vector<tagFriendParameter> vFriends;   //

	std::vector<tagContactInfo> vFriendsShuRen;  //

	std::vector<tagInviteInfo> vFriendPush;   //friends add me push

	//CMD_GP_C_ADD_Friend stFriendOpt;

	MyBaseData myBaseData;
	string md5Passwd;

public:
	static DataManager * getInstance();
	void saveRankData(CMD_GP_CupInfo* cupInfo);
	void initData();
};

//��������
#define DATA DataManager::getInstance()
#define DATAPokerGame ((PokerGameModel*)getModel(PokerGameModel::NAME))
#define DATAGameData ((GameDataModel*)getModel(GameDataModel::NAME))
#define DATAPlayerIndesk ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME))




#endif

