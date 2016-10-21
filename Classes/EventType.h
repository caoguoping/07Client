#ifndef __EventType__
#define __EventType__
#include<string>
using namespace std;
enum EventType
{
	GAME_START,
	SOCKET_INIT,
	SOCKET_REC_DATA,
	REGIST_CHARACTER,
	LOGIN_COMPLETE,
	ERROR_MSG,
	ROOM_LIST_GET,
	CONNECT_GAME_SERVICE,
	GAMESERVER_LOGIN_SUCSS,
	ON_DESK,
	PLAYER_ON_DESK,
	OTHER_PLAYER_ON_DESK,
	SHOW_PLAYER_ON_DESK,
	REMOVE_TEST_UI,
	SEND_POKER,                //发牌
	PAY_TRIBUTE,
	GAME_OVER,
	REV_PLAYER_OUT_POKER,      //用户出牌
	NOT_OUT_POKER,
	SHOW_GAME_DATA,				//本局游戏数据显示（级数）
	CHANGE_POKER_STATE,			//改变牌的选中状态
	SELECT_POKER_MOVE,          //滑动选牌，只增不减。
	REMOVE_POKER,				//在手牌中移除出掉的牌
	CHANGE_POKER_POSITION,		//改变牌的位置
	REMOVE_OUT_POKER,			//清除出的牌的显示
	REMOVE_POKER_VIEW,			//移除牌的显示
	SET_POKER_OPACITY,			//调整手牌的透明度
	BACK_TO_HALL,				//返回大厅
	GET_JING_GONG,				//获取别人给自己进贡的牌
	RE_SHOW_POKER,
	TONG_HUA_SHUN,
	HUO_JIAN,
	FEI_JI,
	BOOM,
	KANG_GONG,
	RE_SORT_POKER,
	ALERT,
	RE_LOGIN,
	CHAT,
	INSURESUCCESS,
	POKER_GONG_PAI_STATE,		//牌加上贡牌标记
	SHOW_DAO_JU_ACTION,
	SEVEN_LOGIN_INFO,			//七日登录信息
	DAILY_MISSION_INFO,			//日常任务信息
	MALL_INFO,					//商城信息
	GET_MIS_REWARD,				//获取任务奖励
	GET_GAMBLING_REWARD,		//获取抽奖奖励
	GET_BUY_ITEMS,			//获取购买商城道具
	BACK_TO_LOBBY,
	USE_JI_PAI_QI,				//使用记牌器
	PUSH_JIPAIQI,                      //推送记牌器数据
	TASK_REWORD,                        //任务3000金币
	MATCH_NUM,					//参赛人数
	MATCH_STATES,                  //比赛结束
	FRIEND_LIST,       //好友列表
	FRIEND_SHUREN,    //好友熟人
	FRIEND_OPT_ME,     //好友操作,自己的操作，回给自己的
	FRIEND_OPT_HIM,     //好友操作,对方给自己的操作
	FRIEND_SEARCH,  //好友搜索
	FRIEND_PLAY,    //进入好友场

	
};
//10001 --  10100  :LoginView
//10101 --  10200  :HallView
//10201 --  10300  :SessionSelectView
//10301 --  10400  :HeadPortraitView
//10401 --  10500  :OptionView
//10501 --  10600  :AccountView
//10601 --  10700  :PlayPokerView
//10701 --  10800  :PlayerInfoView
//10801 --  10900  :ShopView
//10901 --  11000  :SevenDayGiftView
//11001 --  11100  :DailyMissionView
//11101 --  11200  :CancelAutoView
//11201 --  11300  :MallView
//11301 --  11400  :ChatView
//11401 --  11500  :WarningView
//11501 --  11600  :ShowChatView
//11601 --  11700  :GongPaiActionView
//11701 --	11800  :MyInfoView
//11801 --  11900  :DaoJuActionView
//11901 --  12000  :MessageShowView
//12001 --  12100  :PackageView
//12101 --  12200  :LobbyView
//12120 --          NewLobbyView
//12201 --  12300  :JiPaiView
//12301 -- 12399    :FriendView
//12400 --  12500  :caoguoping
//12600 --  12700  :playGoldView
//12700 -- 12800   :entertainment
//12800 -- 12900   :blood


//15001-15030   :activity
//16000 16010:  match
//17000 -- 17100   :invite



//99999用于屏蔽触摸事件
//20000开始处理音效
//30000退出游戏
//30001金币不足
//30002钻石不足


#endif