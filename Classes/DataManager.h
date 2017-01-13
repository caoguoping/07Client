
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
		E_GameCateMatch,    //比赛
		E_GameFriend,  //四人
		E_GameFriendPassive,  //四人被动
		E_GameTeam, 
		E_GameTeamPassive,  //组队被动
		E_GameRandZhupai,  
		E_GameBlood,
	}E_GameCate;

	BYTE bGameCate;    //哪一类游戏 0，normal,  1,  比赛，..., 7, 血战   // 其他 E_GameCate
	BYTE bGameCateSub;    //同类游戏的第几个按钮  0，1，2按顺序

	BYTE jipai[18];     //记牌器数据
	WORD chouJiangTime;   //抽奖次数
	WORD diamondNum;     //抽一次需要的钻石

	CMD_GP_CupInfo  myRankInfo;    //排行榜信息
	DBO_GP_Seven_Logon  sevenLogin;


	DWORD dwGameBtnId;   //点击的是哪个游戏按钮  

	WORD wMatchAllChangci;   //比赛总场次    3轮  2场
	WORD wMatchAllLunci;     //当前场次的总轮次（两轮）
	WORD wMatchNowChangci;   //当前比赛场次    1， 2， 3
	WORD wMatchNowLuanci;    //当前比赛轮次 
	WORD wMatchPlayer;       //当前轮总人数
	WORD wMatchNextPlayerCount;   //下一轮人数   最后一轮为0 
	BYTE bLastMatch;   //0, 淘汰，  1：是总决赛， 2:不是比赛
	BYTE bIsJinji;     //1, 晋级，  0:  淘汰
	BYTE bMatchOver;   //1：比赛结束， 0，没有结束
	WORD	wCdRank;				//名次
	WORD    wMatchScore;     //积分
	WORD    wBestRank;      //历史最佳排名
	CMD_S_GameEnd   GameEndData;
	WORD wFriendFieldTableId;    //好友场创建者
	WORD wFriendFieldChairId;
	WORD wFriendPassiveTableId;    //好友场被邀请者
	WORD wFriendPassiveChairId;
	std::vector<tagFriendParameter> vFriends;   //好友列表
	std::vector<tagFriendParameter> vFriendLine;   //在线好友列表


	std::vector<tagContactInfo> vFriendsShuRen;  //

	std::vector<tagInviteInfo> vFriendPush;   //friends add me push
	MyBaseData myBaseData;
	string md5Passwd;

	//随机生成账号测试
	DWORD dwRoleCreate;
	void *sendPokerData;
	DWORD dwGameState;   //0:未进入游戏界面  , 1:匹配阶段  , 2:发牌之后
	int mJoinInPlayer;  //进入桌子的玩家数目

	vector<string>		m_vecScreenCharLib;  //屏蔽字库
	BYTE pokers[30];   //记录收到的出牌
	BYTE pokerSize;    //记录收到的出牌数目

	//不删除的界面
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
	//检测屏蔽字符是否存在(true: 存在屏蔽字)
	bool onCheckScreenChar(const string& _strCheck);

};

//新增数据
#define DATA DataManager::getInstance()
#define DATAPokerGame ((PokerGameModel*)getModel(PokerGameModel::NAME))
#define DATAGameData ((GameDataModel*)getModel(GameDataModel::NAME))
#define DATAPlayerIndesk ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME))




#endif

