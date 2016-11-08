#ifndef  _PokerGameModel_
#define  _PokerGameModel_

#include "cocos2d.h"
#include "BlueSky.h"
#include "SGTools.h"
#pragma pack(1)


//物品获取提示
struct MessageVO
{
	int type = -1;														//1：获得钻石，2：获得金币，3：获得道具
	string name;														//钻石金币的数量，道具的名称
};

struct CMD_S_GameStart
{
	unsigned short					wBankerUser;						//庄家用户
	unsigned short				 	wCurrentUser;						//当前玩家
	unsigned int					cbCardData[27];						//扑克列表
	unsigned int					bOurSeries;                         //我方级数
	unsigned int                    bOtherSeries;                       //对方级数
	unsigned int                    bCurrentSeries;                     //本局级数
	int								m_iGameResult[4];                   //胜负情况
	unsigned int					RoomType;							//房间类型
	unsigned short                  wServerType;						//服务器类型
	bool							bLiangPai;							//是否亮牌
	unsigned int					bLiangCard;							//亮牌
};
//出牌数据包
struct CMD_C_OutCard
{
	unsigned char					bCardCount;							//出牌数目
	unsigned char					bCardData[27];						//扑克列表
};
//用户出牌
struct CMD_S_OutCard
{
	unsigned char					bCardCount;							//扑克数目
	unsigned short					wCurrentUser;						//当前玩家(接下来出牌的玩家)
	unsigned short					wOutCardUser;						//出牌玩家（哪个玩家出的牌）
	unsigned char					bCardData[27];						//扑克列表
};
//放弃出牌
struct CMD_S_PassCard
{
	unsigned char					bNewTurn;							//一轮开始
	unsigned short				 	wPassUser;							//放弃玩家
	unsigned short				 	wCurrentUser;						//当前玩家
};
//用户进贡
struct CMD_C_PayTribute
{
	unsigned int                     bPayType;							//进贡类型  1进贡 2回贡 
	unsigned short                   wUser;                              //进贡用户
	unsigned short                   wToUser;							//受进贡者（进贡发0，回贡需要发受回贡者椅子ID）
	unsigned char                    bCard;                              //进贡扑克
};
//用户进贡
struct CMD_S_PayTribute
{
	//只有前两个有用~
	unsigned char                    bPayType[4];						//进贡类型（2进贡 1受贡 0无）
	unsigned int					 bPayStatus;						//进贡阶段 0无 1进贡 2回贡 3获取回贡 4抗贡
	unsigned short                   wFromUser;                          //进贡用户
	unsigned short                   wToUser;                            //被进贡用户（）
	unsigned short                   wCurrentUser;                       //当前玩家（谁第一个出牌）
	unsigned char                    bCard;                              //进贡扑克
};
//游戏结束
struct CMD_S_GameEnd
{
	DWORD							lGameTax;							//游戏税收
	DWORD							lGameScore[4];						//游戏积分
	BYTE					bCardCount[4];						//扑克数目
	BYTE					bCardData[108];						//扑克列表
	BYTE                   bOurSeries;                         //我方级数
	BYTE                   bOtherSeries;                       //对方级数
	BYTE                   bCurrentSeries;                     //本局级数
	int                             m_iGameResult[4];                   //胜负情况
	int								Rank[4];	//值为服务器座位号， 下标为排名						//排名情况
	BYTE              bIsBlood;    //0：正常结束，   1：血战场结束

};

//用户表情
struct CMD_GR_C_UserExpression
{
	unsigned short					wItemIndex;							//表情索引
	long							dwTargetUserID;						//目标用户
};

//用户表情
struct CMD_GR_S_UserExpression
{
	unsigned short					wItemIndex;							//表情索引
	long							dwSendUserID;						//发送用户
	long							dwTargetUserID;						//目标用户
};

//道具动作
struct DAO_JU_ACTION
{
	int								index = -1;							//道具索引
	int								toDesk = -1;						//目标玩家椅子ID
	int								id = -1;
};

//签到查询
struct DBO_GP_Seven_Logon
{
	unsigned long					dwUserID;							//用户标识
	unsigned short					LogonCnt;							//签到天数
};

//商城商品
struct SHOP_GOOD
{
	//道具信息
	unsigned short					wIndex;								//道具标识
	//string							szPropertyName = "1";				//道具名字
	unsigned short					wDiscount;							//会员折扣
	unsigned short					wIssueArea;							//发布范围

	//销售价格
	long long						lPropertyGold;						//道具金币
	double							dPropertyCash;						//道具价格

	//赠送魅力
	long long						lSendLoveLiness;					//赠送魅力
	long long						lRecvLoveLiness;					//接受魅力
};

//用户任务
struct DBR_GR_WriteUserMissionRes
{
	unsigned short							wKindId;							//房间ID
	unsigned long							dwUserID;							//用户标识
	unsigned short							wMissionId;							//任务ID
	unsigned long							dwValue;							//完成次数
	//SYSTEMTIME							Time;								//完成时间
	unsigned short							Complete;							//任务完成
};

//用户任务
struct DBR_GR_UserLogonMissionRes
{
	unsigned short							wKindId;							//房间ID
	unsigned long							dwUserID;							//用户标识
	unsigned short							wMissionId;							//任务ID
	unsigned long							dwValue;							//完成次数
	//SYSTEMTIME						    Time;								//完成时间
	unsigned short							Complete;							//任务完成	0- 已经完成  1-  未完成
	unsigned short							Receive;							//完成标志  1 - 已经领取 0 -未领取
};


//任务奖励领取
struct CMD_GR_UerMissionRec
{
	unsigned long							dwUserID;							//用户 I D
	unsigned short							wMissionId;							//任务ID
	unsigned short							wKindID;							//房间ID
};
//任务奖励
struct CMD_GR_GetMissionRewardRec
{
	unsigned short							flag;								//1-- 成功 2 -- 失败
	unsigned short							wMissionId;							//任务ID
	unsigned short							Score;								//奖励金币
	unsigned short							KindID;								//道具ID(配置ID)
	unsigned short							PropCnt;							//道具个数
};
//金币操作
struct CMD_GP_UserAddandSubScore
{
	unsigned long							dwUserID;							//用户 I D
	unsigned long							lSaveScore;							//存入金币
	unsigned short							time;								//抽奖次数
};
// 抽奖操作
// struct CMD_GP_User_Gambling
// {
// 	unsigned long							dwUserID;							//用户 I D
// 	unsigned long							Gambling;							//奖项	I D
// 	unsigned long							Currency;							//用户钻石
// 	unsigned long							GamblingCnt;						//抽奖次数
// };

//抽奖操作
struct CMD_GP_User_Gambling
{
	unsigned int							dwUserID;							//用户 I D
	unsigned short							Gambling;							//奖项	I D
	unsigned short							GamblingCnt;						//抽奖次数
	unsigned short                          diamondNum;                         //钻石
};
//背包道具
struct Package_Item
{
	unsigned long							dwPropID;							//道具系统ID,标示物品
	unsigned short							wPropCount;							//道具个数
	unsigned short							wKindID;							//配置ID
};
//购买商城道具
struct Buy_Mall_Item
{
	unsigned long							dwUserID;							//用户ID
	unsigned short							wPropCount;							//购买个数
	unsigned short							wKindID;							//配置ID
};
//道具使用
struct DBR_GR_UseProperty
{
	unsigned long							dwUserID;							//用户 I D
	unsigned short							wPropertyIndex;						//道具索引
	unsigned short							wItemCount;							//使用数目
	unsigned long							dwTargetUserID;						//使用对象
	unsigned char							cbRequestArea;			            //使用范围 
};
//道具成功
struct CMD_GR_S_PropertySuccess
{
	unsigned char                           cbRequestArea;						//使用环境
	unsigned short							wItemCount;							//购买数目
	unsigned short							wPropertyIndex;						//道具索引
	unsigned long							dwSourceUserID;						//目标对象
	unsigned long							dwTargetUserID;						//使用对象
};

//道具消费
struct DBR_GR_PropertyConsume
{
	unsigned short							wPropertyIndex;						//道具索引
	unsigned short							wKindID;							//房间ID
	unsigned long							dwUserID;							//用户 I D
	long long								lScore;								//消费积分
	unsigned short							resultID;							//结果ID
};

//3, 1006请求
//3, 1007响应

//奖杯排行榜
struct tagCupRanking
{

	unsigned int							dwUserID;						//用户ID
	std::string						szNickName;			//用户昵称
	unsigned short								cLevel;								//用户等级
	unsigned short								cExp;									//用户经验值
	unsigned short                               faceId;
};

struct tagCupRankingInfos
{
	unsigned short						dwNum;					//总数目
	tagCupRanking			dwRankingInfos[30];			//30个
};

//奖杯
struct CMD_GP_CupInfo
{
	unsigned int                           openTime;      //开服时间
	unsigned int							dwUserID;
	unsigned short								cLevel;
	unsigned short								cExp;
	unsigned short								awards;
	tagCupRankingInfos						rankingInfo;

};

//奖杯奖励
struct CMD_GP_CupAwards
{
	unsigned int						dwUserID;
	unsigned short						flag;   // 标记是否成功领取 1 -- 成功  2 -- 失败
	unsigned short						dwIndex;	
	unsigned short						dwAwards;
};

struct CMD_GROWTH_INFO
{
	unsigned int dwUserID;
	unsigned short  wIndex;
};




//比赛人数
struct CMD_GR_Match_Num
{
	unsigned int							dwWaitting;							//等待人数
	unsigned int							dwTotal;							//开赛人数
	unsigned int							dwMatchTotal;						//总人数
};

//比赛报名  坐下请求
struct CMD_GR_UserSitDown
{
	unsigned short							wTableID;							//桌子位置
	unsigned short							wChairID;							//椅子位置
	unsigned short							szPassword[33];			//桌子密码
};


//用户分数   3 , 104	
//用户积分
struct tagUserScore
{
	//积分信息
	SCORE							lScore;								//用户分数
	SCORE							lGrade;								//用户成绩
	SCORE							lInsure;							//用户银行

	//输赢信息
	DWORD							dwWinCount; 
	DWORD							dwLostCount;						//失败盘数
	DWORD							dwDrawCount;						//和局盘数
	DWORD							dwFleeCount;						//逃跑盘数

	//全局信息
	DWORD							dwUserMedal;						//用户奖牌
	DWORD							dwExperience;						//用户经验
	LONG							lLoveLiness;						//用户魅力
};

struct CMD_GR_UserScore
{
	DWORD							dwUserID;							//用户标识
	tagUserScore					UserScore;							//积分信息
	WORD								wMatchScore;					//比赛积分
};


//3   105  剩余桌子数目
//WORD

//3  106  排行榜

struct Match_Ranking_Item
{
	DWORD			dwUserID;    //玩家昵称 
	string        szSendNickName;
	WORD				wMatchScore;				//比赛积分
	WORD	            wRankingID;					//比赛名次
};

struct CMD_GR_MATCH_RANKING
{
	Match_Ranking_Item     rankingInfo[20];
};









class PokerGameModel : public BlueSkyModel
{
public:
	PokerGameModel();
	~PokerGameModel(){};
	CMD_S_OutCard playerOutCard;//上一轮玩家出牌信息
	

	//储存任务信息
	vector<DBR_GR_UserLogonMissionRes> dailyMisInfo;

	//储存商城商品信息
	vector<SHOP_GOOD> mallGoodsInfo;

	//储存背包道具信息
	vector<Package_Item> packageItem;
	int jipaiqiNum;    //记牌器数量

	CMD_GR_Match_Num  num_info;		//当前参赛人数

	static const string NAME;
};


#endif