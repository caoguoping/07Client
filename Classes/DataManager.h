
#ifndef  _DATA_MANAGER_
#define  _DATA_MANAGER_

#include "cocos2d.h"
#include "PokerGameModel.h"
#include "SGTools.h"
#include "GameDataModel.h"
#include "PlayerInDeskModel.h"

#pragma pack(1)


//比赛状态
#define GAME_STATE_END						0x00								//没有状态 ,比赛结束
#define GAME_STATE_SIGNUP					0x01								//报名状态
#define GAME_STATE_MATCHING					0x02								//比赛状态
#define GAME_STATE_OUT						0x03								//淘汰状态
#define GAME_STATE_QUIT						0x04							    //退赛


struct CMD_GP_UserYbToGold
{
	DWORD	dwUserID;
	DWORD	yb;
};
struct CMD_GP_UserInsureSuccess
{
	DWORD						dwUserID;							//用户 I D
	long long							lUserScore;							//用户金币
	long long							lUserInsure;						//银行金币
	char								szDescribeString[256];				//描述消息
};

struct MyBaseData
{
	//属性资料
	WORD							wFaceID;							//头像标识
	DWORD							dwUserID;							//用户 I D  服务器用
	DWORD							dwGameID;							//游戏 I D
	DWORD							dwGroupID;							//社团标识
	DWORD							dwCustomID;							//自定标识
	DWORD							dwUserMedal;						//用户奖牌
	DWORD							dwExperience;						//经验数值
	DWORD							dwLoveLiness;						//用户魅力
	//用户成绩
	SCORE								lUserScore;							//用户金币
	SCORE								lUserInsure;						//用户银行
	//用户信息
	BYTE							cbGender;							//用户性别
	BYTE							cbMoorMachine;						//锁定机器
	string									szAccounts;							//登录帐号
	string									szNickName;							//用户昵称
	string									szGroupName;						//社团名字
	//配置信息
	BYTE                           cbShowServerStatus;                //显示服务器状态
	DWORD										isFirstLogin;						//是否是今天第一次登录
	DWORD							rmb;								//钻石
	WORD							wBeiZaNum[4]; //被砸鸡蛋,炸弹，爱心，鲜花的数目，

};

//系统消息数据包
struct CMD_S_MESSAGE
{
	WORD							wChairID;							//来自用户
	TCHAR							szBuffer[128];						//系统消息
};
//200  110

//系统消息
struct CMD_CM_SystemMessage
{
	WORD							wType;								//消息类型
	WORD							wLength;							//消息长度
	TCHAR							szString[1024];						//消息内容
};
//1000 1
//100  200



//7 ,   409  //场次信息
struct CMD_GR_MatchStatus
{
	WORD       dwRoundID;     //当前轮数
	WORD       dwGameID;	//当前场数
	WORD      RoundCount;		//总轮数
	WORD     GameCount;		//总场数
	WORD     PlayerCount;   //总人数
	WORD     NextPlayerCount;		//下一轮人数   最后一轮为0 
};


//比赛晋级消息
struct CMD_GR_MatchJinJi
{
	DWORD     dwUserID;
	BYTE            isJinJi;				//是否晋级    1  -- 晋级  0 -- 淘汰
	WORD		cdRank;				//名次
};
//7   410




//好友
//6	2 请求好友消息
//DWORD    dwUserID;

//6	3 返回好友消息
/*
struct tagFriendShipParameter
{
	DWORD							dwUserID;						//用户ID
	WORD								wfriendsNum;					//好友数量
	tagFriendParameter			wfriendInfos[20];		//好友信息
};
*/


//好友参数
struct tagFriendParameter
{
	DWORD							    dwUserID    ;						//用户ID
	std::string 						szNickName  ;			//用户昵称
	DWORD								dwRmb       ;								//钻石
	WORD								FaceID      ;
	WORD								wServerID   ;						//房间ID
	WORD								wKindID     ;							//游戏ID
	DWORD							    dwLoveLiness;			//魅力
	WORD								WinRate     ;							//胜率
	BYTE                                bStates;                //0不在线，1在线
};

//6	4  好友操作   包括 邀请好友 s = 0  同意邀请 s = 1   删除好友 s = 2
struct CMD_GP_Snd_ADD_Friend
{
	DWORD				dwUserID;
	DWORD				dwTargretUserID;
	WORD					wStatue;     // 0 - 邀请 1- 同意  2 --删除  3 -拒绝
};

//6	5	返回好友添加信息	s = -1 邀请失败	s = 0 成功邀请 	s = 1  成功加为好友
struct CMD_GP_C_ADD_Friend
{
	DWORD				dwUserID;
	DWORD				dwTargretUserID;
	WORD					wStatue;     // 0 - 邀请 1- 同意  2 --删除  3 -拒绝
	std::string								szNickName;			//用户昵称
	DWORD								dwRmb;								//钻石
	WORD								FaceID;
	WORD								wServerID;						//房间ID
	WORD								wKindID;							//游戏ID
	DWORD							dwLoveLiness;			//魅力
	WORD								WinRate;							//胜率
	WORD        					    wRcStates;    //接收到的状态
};


//6	9	返回熟人列表
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


// 6, 10 请求
// struct  CMD_GP_C_SEARCH_USER
// {
// 	TCHAR								szSearchINfo[LEN_NICKNAME];
// };
// 

//6， 11， 
struct  CMD_GP_S_SEARCH_USER
{
	DWORD							dwUserID;
	std::string							szNickName;
	WORD								wFaceID;
};

//好友邀请信息
struct tagInviteInfo
{
	DWORD							dwUserID;
	std::string							szNickName;
	WORD								wFaceID;
};

//6, 13 好友推送
struct CMD_GP_S_RESULT_INVITE
{
	DWORD								dwUserID;
	WORD									wNum;
	tagInviteInfo						info[20];
};

//6, 15 好友邀请发送
struct CMD_SUB_S_INVITE_ENTER_GAME
{
	DWORD							dwUserID;  //自己ID
	DWORD							dwTargetID;      //邀请目标玩家
	WORD								wGameID;		//游戏ID
	WORD								wTableID;
	WORD								wChairID;
	WORD                                wIsFriend;   //1 : friend,  0:  team.
	char                     strName[64];
};

//6, 16 收到好友邀请
struct CMD_SUB_C_INVITE_ENTER_GAME
{
	DWORD							dwUserID;  //自己ID
	DWORD							dwTargetID;      //邀请目标玩家
	WORD								wGameID;		//游戏ID
	WORD								wTableID;
	WORD								wChairID;
	WORD                                wIsFriend;   //1 : friend,  0:  team.
	std::string                     strName;
};

//200, 13 game 发给服务器，  接收广播200, 113
struct	CMD_C_USE_PROPERTY
{
	WORD						wIndex;						//道具ID 1, 2, 3, 4
	WORD						wChairID;					//自己的座位ID
	WORD						wTargetID;				//目标ID 
};

//3, 510 被砸鸡蛋等计数 登录服务器
struct CMD_GP_S_RESULT_INFO
{
	DWORD							dwUserID;
	WORD								wNum1;
	WORD								wNum2;
	WORD								wNum3;
	WORD								wNum4;
};

//4, 101.
//桌子状态

// struct tagTableStatus
// {
// 	BYTE							cbTableLock;						//锁定标志
// 	BYTE							cbPlayStatus;						//游戏标志
// };
struct CMD_GR_TableStatus
{
	WORD							wTableID;							//桌子号码
	//tagTableStatus					TableStatus;						//桌子状态
	BYTE							cbTableLock;						//锁定标志
	BYTE							cbPlayStatus;						//游戏标志   //0, 桌子不在。
};


struct stSystemMsg
{
	WORD							wType;								//消息类型
	WORD							wLength;							//消息长度
	std::string						strContent;						//消息内容
};

USING_NS_CC;

//签到查询
struct DBO_GP_Seven_Logon
{
	DWORD					dwUserID;							//用户标识
	WORD					LogonCnt;							//签到天数
};


//class LobbyView;
#include "LobbyView.h"

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

	//不删除的界面
public:
	LobbyView*  lobbyview;
public:
	static DataManager * getInstance();
	void saveRankData(CMD_GP_CupInfo* cupInfo);
	void initData();
};

//新增数据
#define DATA DataManager::getInstance()
#define DATAPokerGame ((PokerGameModel*)getModel(PokerGameModel::NAME))
#define DATAGameData ((GameDataModel*)getModel(GameDataModel::NAME))
#define DATAPlayerIndesk ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME))




#endif

