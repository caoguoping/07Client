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
	事件通知执行函数
	*/

	void execute(void* data);
private:
	void executeLogin(NetData netData);
	void executeGame(NetData netData);
	void loginComplete(NetData netData);//登录成功
	void firstLogin(NetData netData);   //首次登陆


	void getGameFail(NetData netData);


	void getRoomList(NetData netData);//获取房间列表
	void getDeskInfo(NetData netData);	//获取房间信息
	void getInDeskPlayerInfo(NetData netData);	//获取进入房间的玩家信息

	void getMatchJiesuanInfo(NetData netData);	//获取比赛结算信息

	void getSendPokerInfo(NetData netData);	//获取发牌数据
	void getPlayerOutPoker(NetData netData);//用户出牌
	void getPlayerOutPokerError(NetData netData);//用户出牌错误
	void notOutPoker(NetData netData);//不出
	void getPayTribute(NetData netData);//进贡
	void gameOver(NetData netData);//游戏结束
	void getChat(NetData netData);//聊天
	void getSignInformation(NetData netData);//签到查询
	void getMisInfo(NetData netData);//任务信息
	void getMallInfo(NetData netData);//商城信息
	void getSysMsg(NetData netData);//系统信息
	void getMisReward(NetData netData);//任务奖励
	void getLoginMisInfo(NetData netData);//任务信息
	void insureSuccess(NetData netData);//钻石换钱
	void getGamblingInfo(NetData netData);//抽奖信息
	void getItemsInfo(NetData netData);//背包道具
	void getBuyItemsInfo(NetData netData);//购买商城物品
	void getBeiZaInfo(NetData netData);   //被砸的数目
	void getZuanShiInfo(NetData netData);//钻石变动
	void useItem(NetData netData);//使用道具
	void useJiPaiQi(NetData netData);//使用记牌器
	void getRankInfo(NetData NetData); //获取排行榜信息
	void getCupAwardInfo(NetData netData); //获取cup奖励信息
	void getMatchNumInfo(NetData netData);	//获取当前参赛人数
	void getMatchStates(NetData netData);    //7, 406  比赛结束，包括非正常结束
	void getBestRank(NetData netData);     //7, 411, 历史最佳排名
	void getJipaiqiData(NetData netData);
	//3, 104 用户分数
	void getMatchUserScore(NetData netData);

	//3   105  剩余桌子数目
	void getMatchLeftDesk(NetData netData);

	//3  106  排行榜
	void getMatchRank(NetData netData);

	//7. 409 比赛场次轮次
	void getMatchChangLun(NetData netData);

	//7. 410  比赛场是否淘汰
	void getMatchPass(NetData netData);

	//6	3 返回好友消息
	void getFriendsInfo(NetData netData);

	//6	5	返回好友添加信息	s = -1 邀请失败	s = 0 成功邀请 	s = 1  成功加为好友
	void getFriedsAddInfoMe(NetData netData);

	//6, 6  
	void getFriedsAddInfoHim(NetData netData);

	//6	9	返回熟人列表
	void getFriendsShuRen(NetData netData);

	//6, 11, 返回搜索好友信息
	void getFriendSearch(NetData netData);

	//6. 13， 好友推送
	void getFriendPush(NetData netData);

	//6. 16 ,收到好友场请求
	void getFriendFieldInvite(NetData netData);

	//200, 113, 游戏服务器，广播砸鸡蛋
	void getBroadCastDaoju(NetData netData);

	//4, 101
	void getTableInfo(NetData netData); //4人场主建人跑了

};

#endif