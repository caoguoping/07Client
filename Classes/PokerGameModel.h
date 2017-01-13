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
	WORD					wBankerUser;						//庄家用户
	WORD				 	wCurrentUser;						//当前玩家
	DWORD					cbCardData[27];						//扑克列表
	DWORD					bOurSeries;                         //我方级数
	DWORD                    bOtherSeries;                       //对方级数
	DWORD                    bCurrentSeries;                     //本局级数
	int								m_iGameResult[4];                   //胜负情况
	DWORD					RoomType;							//房间类型
	WORD                  wServerType;						//服务器类型
	bool							bLiangPai;							//是否亮牌
	DWORD					bLiangCard;							//亮牌
};
//出牌数据包
struct CMD_C_OutCard
{
	BYTE					bCardCount;							//出牌数目
	BYTE					bCardData[27];						//扑克列表
};
//用户出牌
struct CMD_S_OutCard
{
	BYTE					bCardCount;							//扑克数目
	WORD					wCurrentUser;						//当前玩家(接下来出牌的玩家)
	WORD					wOutCardUser;						//出牌玩家（哪个玩家出的牌）
	BYTE					bCardData[27];						//扑克列表
};
//放弃出牌
struct CMD_S_PassCard
{
	BYTE					bNewTurn;							//一轮开始
	WORD				 	wPassUser;							//放弃玩家
	WORD				 	wCurrentUser;						//当前玩家
//	WORD					wJieFeng;                           //1接风，  0不是接风
};
//用户进贡
struct CMD_C_PayTribute
{
	DWORD                     bPayType;							//进贡类型  1进贡 2回贡 
	WORD                   wUser;                              //进贡用户
	WORD                   wToUser;							//受进贡者（进贡发0，回贡需要发受回贡者椅子ID）
	BYTE                    bCard;                              //进贡扑克
};
//用户进贡
struct CMD_S_PayTribute
{
	//只有前两个有用~
	BYTE                    bPayType[4];						//进贡类型（2进贡 1受贡 0无）
	DWORD					 bPayStatus;						//进贡阶段 0无 1进贡 2回贡 3获取回贡 4抗贡
	WORD                   wFromUser;                          //进贡用户
	WORD                   wToUser;                            //被进贡用户（）
	WORD                   wCurrentUser;                       //当前玩家（谁第一个出牌）
	BYTE                    bCard;                              //进贡扑克
};
//游戏结束
struct CMD_S_GameEnd
{
	int							lGameTax;							//游戏税收
	int							lGameScore[4];						//游戏积分
	BYTE					bCardCount[4];						//扑克数目
	BYTE					bCardData[108];						//扑克列表
	BYTE                   bOurSeries;                         //我方级数
	BYTE                   bOtherSeries;                       //对方级数
	BYTE                   bCurrentSeries;                     //本局级数
    BYTE              bIsBlood;    //0：正常结束，   1：血战场结束
    
    int                             m_iGameResult[4];                   //胜负情况
	int								Rank[4];	//值为服务器座位号， 下标为排名						//排名情况


};

//用户表情
struct CMD_GR_C_UserExpression
{
	WORD					wItemIndex;							//表情索引
	DWORD							dwTargetUserID;						//目标用户
};

//用户表情
struct CMD_GR_S_UserExpression
{
	WORD					wItemIndex;							//表情索引
	DWORD							dwSendUserID;						//发送用户
	DWORD							dwTargetUserID;						//目标用户
};

//道具动作
struct DAO_JU_ACTION
{
	WORD								index ;							//道具索引
	WORD                                fromDesk;       //谁扔的
	WORD								toDesk;						//目标玩家椅子ID
	WORD								id;         //actionId
	
};



//商城商品
struct SHOP_GOOD
{
	//道具信息
	WORD					wIndex;								//道具标识
	//string							szPropertyName = "1";				//道具名字
	WORD					wDiscount;							//会员折扣
	WORD					wIssueArea;							//发布范围

	//销售价格
	SCORE						lPropertyGold;						//道具金币
	double							dPropertyCash;						//道具价格

	//赠送魅力
	SCORE						lSendLoveLiness;					//赠送魅力
	SCORE						lRecvLoveLiness;					//接受魅力
};

//用户任务
struct DBR_GR_WriteUserMissionRes
{
	WORD							wKindId;							//房间ID
	DWORD							dwUserID;							//用户标识
	WORD							wMissionId;							//任务ID
	DWORD							dwValue;							//完成次数
	//SYSTEMTIME							Time;								//完成时间
	WORD							Complete;							//任务完成
};

//用户任务
struct DBR_GR_UserLogonMissionRes
{
	WORD							wKindId;							//房间ID
	DWORD							dwUserID;							//用户标识
	WORD							wMissionId;							//任务ID
	DWORD							dwValue;							//完成次数
	//SYSTEMTIME						    Time;								//完成时间
	WORD							Complete;							//任务完成	0- 已经完成  1-  未完成
	WORD							Receive;							//完成标志  1 - 已经领取 0 -未领取
};


//任务奖励领取
struct CMD_GR_UerMissionRec
{
	DWORD							dwUserID;							//用户 I D
	WORD							wMissionId;							//任务ID
	WORD							wKindID;							//房间ID
};
//任务奖励
struct CMD_GR_GetMissionRewardRec
{
	WORD							flag;								//1-- 成功 2 -- 失败
	WORD							wMissionId;							//任务ID
	WORD							Score;								//奖励金币
	WORD							KindID;								//道具ID(配置ID)
	WORD							PropCnt;							//道具个数
};
//金币操作
struct CMD_GP_UserAddandSubScore
{
	DWORD							dwUserID;							//用户 I D
	DWORD							lSaveScore;							//存入金币
	WORD							time;								//抽奖次数
};
// 抽奖操作
// struct CMD_GP_User_Gambling
// {
// 	DWORD							dwUserID;							//用户 I D
// 	DWORD							Gambling;							//奖项	I D
// 	DWORD							Currency;							//用户钻石
// 	DWORD							GamblingCnt;						//抽奖次数
// };

//抽奖操作
struct CMD_GP_User_Gambling
{
	DWORD							dwUserID;							//用户 I D
	WORD							Gambling;							//奖项	I D
	WORD							GamblingCnt;						//抽奖次数
	WORD                          diamondNum;                         //钻石
};
//背包道具
struct Package_Item
{
	DWORD							dwPropID;							//道具系统ID,标示物品
	WORD							wPropCount;							//道具个数
	WORD							wKindID;							//配置ID
};
//购买商城道具
struct Buy_Mall_Item
{
	DWORD							dwUserID;							//用户ID
	WORD							wPropCount;							//购买个数
	WORD							wKindID;							//配置ID
};
//道具使用
struct DBR_GR_UseProperty
{
	DWORD							dwUserID;							//用户 I D
	WORD							wPropertyIndex;						//道具索引
	WORD							wItemCount;							//使用数目
	DWORD							dwTargetUserID;						//使用对象
	BYTE							cbRequestArea;			            //使用范围 
};
//道具成功
struct CMD_GR_S_PropertySuccess
{
	BYTE                           cbRequestArea;						//使用环境
	WORD							wItemCount;							//购买数目
	WORD							wPropertyIndex;						//道具索引
	DWORD							dwSourceUserID;						//目标对象
	DWORD							dwTargetUserID;						//使用对象
};

//道具消费
struct DBR_GR_PropertyConsume
{
	WORD							wPropertyIndex;						//道具索引
	WORD							wKindID;							//房间ID
	DWORD							dwUserID;							//用户 I D
	SCORE								lScore;								//消费积分
	WORD							resultID;							//结果ID
};

//3, 1006请求
//3, 1007响应

//奖杯排行榜
struct tagCupRanking
{

	DWORD							dwUserID;						//用户ID
	std::string						szNickName;			//用户昵称
	WORD								cLevel;								//用户等级
	WORD								cExp;									//用户经验值
	WORD                               faceId;
};

struct tagCupRankingInfos
{
	WORD						dwNum;					//总数目
	tagCupRanking			dwRankingInfos[30];			//30个
};

//奖杯
struct CMD_GP_CupInfo
{
	DWORD                           openTime;      //开服时间
	DWORD							dwUserID;
	WORD								cLevel;
	WORD								cExp;
	WORD								awards;
	tagCupRankingInfos						rankingInfo;

};

//奖杯奖励
struct CMD_GP_CupAwards
{
	DWORD						dwUserID;
	WORD						flag;   // 标记是否成功领取 1 -- 成功  2 -- 失败
	WORD						dwIndex;	
	WORD						dwAwards;
};

struct CMD_GROWTH_INFO
{
	DWORD dwUserID;
	WORD  wIndex;
};




//比赛人数
struct CMD_GR_Match_Num
{
	DWORD							dwWaitting;							//等待人数
	DWORD							dwTotal;							//开赛人数
	DWORD							dwMatchTotal;						//总人数
};

//比赛报名  坐下请求
struct CMD_GR_UserSitDown
{
	WORD							wTableID;							//桌子位置
	WORD							wChairID;							//椅子位置
	WORD							szPassword[33];			//桌子密码
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
