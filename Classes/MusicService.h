#ifndef  _MusicService_
#define  _MusicService_

#include "SimpleAudioEngine.h"
#include "cocos2d.h"
using namespace CocosDenshion;


//采用宏定义文件名，便于以后统一修改
#define	BG_MUSIC				"sounds/bgmusic.mp3"				//背景
/*
人物、牌型音效
*/
#define YA_PAI_NAN				"sounds/am_dani.mp3"				//压牌（男）20001
#define YA_PAI_NV				"sounds/mm_dani.mp3"				//压牌（女）20002
#define BU_CHU_NAN				"sounds/am_buchu.mp3"				//不出（男）20003
#define BU_CHU_NV				"sounds/mm_buchu.mp3"				//不出（女）20004
#define BOOM_NAN				"sounds/am_zha.mp3"					//炸弹（男）20005
#define BOOM_NV					"sounds/mm_zha.mp3"					//炸弹（女）20006
#define TONG_HUA_SHUN_NAN		"sounds/am_tonghuashun.mp3"			//同花顺（男）20007
#define TONG_HUA_SHUN_NV		"sounds/mm_tonghuashun.mp3"			//同花顺（女）20008
#define SHUN_NAN		        "sounds/nan_zashun.mp3"			//顺（男）20007
#define SHUN_NV		            "sounds/mm_zashun.mp3"			    //顺（女）20008
#define HUO_JIAN_NAN			"sounds/am_tianwangzha.mp3"			//火箭（男）20009
#define HUO_JIAN_NV				"sounds/mm_tianwangzha.mp3"			//火箭（女）20010
#define DAN_ZHANG_NAN			"sounds/am_danzhang.mp3"			//单张（男）20011
#define DAN_ZHANG_NV			"sounds/mm_danzhang.mp3"			//单张（女）20012
#define DUI_ZI_NAN				"sounds/am_dui.mp3"					//对子（男）20013
#define DUI_ZI_NV				"sounds/mm_dui.mp3"					//对子（女）20014
#define LIAN_DUI_NAN			"sounds/am_sanliandui.mp3"			//连对		20015
#define LIAN_DUI_NV				"sounds/mm_sanliandui.mp3"			//			20016
#define SAN_DAI_ER_NAN			"sounds/am_sandaier.mp3"			//三带二、	20017
#define SAN_DAI_ER_NV			"sounds/nv_sandaier.mp3"			//			20018
#define SAN_ZHANG_NAN			"sounds/am_sanzhang.mp3"			//三张		20019
#define SAN_ZHANG_NV			"sounds/mm_sanzhang.mp3"			//			20020
#define FEI_JI_NAN				"sounds/am_gangban.mp3"				//飞机		20021
#define FEI_JI_NV				"sounds/mm_gangban.mp3"				//			20022

/*
贡牌音效
*/
#define KANG_GONG_NAN			"sounds/nan_kanggong.mp3"			//抗贡		20023
#define KANG_GONG_NV			"sounds/nv_kanggong.mp3"	
#define JING_GONG_NAN			"sounds/nan_jingong.mp3"			//进贡		20025
#define JING_GONG_NV			"sounds/nv_jingong.mp3"
#define HUANG_GONG_NAN			"sounds/nan_huangong.mp3"			//还贡		20027
#define HUANG_GONG_NV			"sounds/nv_huangong.mp3"

/*
聊天音效
*/
#define HURRY_NAN				"sounds/am_001.mp3"				//快点吧，等的花都谢了20029
#define PERFORM_NAN				"sounds/am_002.mp3"				//你的牌打的太好了	20031
#define FRIEND_NAN				"sounds/am_003.mp3"				//交个朋友吧，能告诉我联系方式吗  20033
#define LEAVE_NAN				"sounds/am_004.mp3"				//不好意思，有事要先走了  20035
#define BOOM_HOOM_NAN			"sounds/am_005.mp3"				//炸弹留着带回家啊	20037
#define COOPERATE_NAN			"sounds/am_006.mp3"				//和你合作真是太愉快了 20039
#define HELLO_NAN				"sounds/am_007.mp3"				//大家好，很高兴见到各位  20041
#define COMBINE_NAN				"sounds/am_008.mp3"				//怎么又断网，网络怎么这么差  20043
#define APOLOGY_NAN				"sounds/am_009.mp3"				//水平不高，请多包涵   20045

#define HURRY_NV				"sounds/mm_001.mp3"
#define PERFORM_NV				"sounds/mm_002.mp3"
#define FRIEND_NV				"sounds/mm_003.mp3"
#define LEAVE_NV				"sounds/mm_004.mp3"
#define BOOM_HOOM_NV			"sounds/mm_005.mp3"
#define COOPERATE_NV			"sounds/mm_006.mp3"
#define HELLO_NV				"sounds/mm_007.mp3"
#define COMBINE_NV				"sounds/mm_008.mp3"
#define APOLOGY_NV				"sounds/mm_009.mp3"	



/*
其他音效
*/
#define SEND_CARD				"sounds/game_send_card.mp3"			//出牌音效 20047
#define GAME_WIN				"sounds/game_win.mp3"				//胜利音效 20048
#define GAME_FAIL				"sounds/game_lose.mp3"				//失败音效 20049
#define BUTTON_CLICK			"sounds/game_button_click.mp3"		//点击按钮音效 20050
#define GOLD_FALL				"sounds/Goldfall2.mp3"				//撒豆 20051
#define GET_AWARD				"sounds/Special_star.mp3"			//领奖音效 20052
#define JI_SHI_QI				"sounds/jishiqi.mp3"				//计时器 20053
#define CHOU_JIANG				"sounds/expression-7.mp3"			//抽奖音效 20054


/*
出牌特效音效
*/
#define ACTION_FEI_JI			"sounds/game_gangbaneffect.mp3"	//飞机  FEI_JI
#define ACTION_BOOM				"sounds/zhadan.mp3"				//炸弹  BOOM
#define ACTION_TONG_HUA_SHUN	"sounds/TongHuaShunAct.mp3"		//同花顺 TONG_HUA_SHUN
#define ACTION_HUO_JIAN			"sounds/game_effect_wanzha.mp3"	//火箭  HUO_JIAN

#define EFFECT_BTN  "sounds/game_button_click.mp3"  //点击按钮音效 20050

class MusicService
{
public:
	static MusicService*  getInstance();
	void init();
	void playEffect(const char*  fileName);
	void playMusic(const char*  fileName);
public:
	bool isEffectOn;
	bool isMusicOn;
};

#define PLayEffect(name)    MusicService::getInstance()->playEffect(name);
#define PLayMUSIC(name)    MusicService::getInstance()->playMusic(name);

#endif