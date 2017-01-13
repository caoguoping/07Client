
#ifndef  _DATA_MANAGER_
#define  _DATA_MANAGER_
#pragma pack(1)

#include "DataModel.h"
#include "cocos2d.h"
#include "PokerGameModel.h"
#include "SGTools.h"
#include "GameDataModel.h"
#include "PlayerInDeskModel.h"
#include "LobbyView.h"
#include "PlayPokerView.h"
//#include "PlayPokerMediator.h"

class PlayPokerMediator;
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
		E_GameFriend,  //����
		E_GameFriendPassive,  //���˱���
		E_GameTeam, 
		E_GameTeamPassive,  //��ӱ���
		E_GameRandZhupai,  
		E_GameBlood,
	}E_GameCate;

	BYTE bGameCate;    //��һ����Ϸ 0��normal,  1,  ������..., 7, Ѫս   // ���� E_GameCate
	BYTE bGameCateSub;    //ͬ����Ϸ�ĵڼ�����ť  0��1��2��˳��

	BYTE jipai[18];     //����������
	WORD chouJiangTime;   //�齱����
	WORD diamondNum;     //��һ����Ҫ����ʯ

	CMD_GP_CupInfo  myRankInfo;    //���а���Ϣ
	DBO_GP_Seven_Logon  sevenLogin;


	DWORD dwGameBtnId;   //��������ĸ���Ϸ��ť  

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
	WORD wFriendFieldTableId;    //���ѳ�������
	WORD wFriendFieldChairId;
	WORD wFriendPassiveTableId;    //���ѳ���������
	WORD wFriendPassiveChairId;
	std::vector<tagFriendParameter> vFriends;   //�����б�
	std::vector<tagFriendParameter> vFriendLine;   //���ߺ����б�


	std::vector<tagContactInfo> vFriendsShuRen;  //

	std::vector<tagInviteInfo> vFriendPush;   //friends add me push
	MyBaseData myBaseData;
	string md5Passwd;

	//��������˺Ų���
	DWORD dwRoleCreate;
	void *sendPokerData;
	DWORD dwGameState;   //0:δ������Ϸ����  , 1:ƥ��׶�  , 2:����֮��
	int mJoinInPlayer;  //�������ӵ������Ŀ

	vector<string>		m_vecScreenCharLib;  //�����ֿ�
	BYTE pokers[30];   //��¼�յ��ĳ���
	BYTE pokerSize;    //��¼�յ��ĳ�����Ŀ

	//��ɾ���Ľ���
public:
	LobbyView*  lobbyview;
	PlayPokerView*   playPokerView;
	PlayPokerMediator*  playPokerMediator;
public:
	static DataManager * getInstance();
	void saveRankData(CMD_GP_CupInfo* cupInfo);
	void initData();
	static void split(vector<string> &vecResult, const string &str, const string &pattern = ",");
	bool readScreenLibConfig();
	//��������ַ��Ƿ����(true: ����������)
	bool onCheckScreenChar(const string& _strCheck);

};

//��������
#define DATA DataManager::getInstance()
#define DATAPokerGame ((PokerGameModel*)getModel(PokerGameModel::NAME))
#define DATAGameData ((GameDataModel*)getModel(GameDataModel::NAME))
#define DATAPlayerIndesk ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME))




#endif

