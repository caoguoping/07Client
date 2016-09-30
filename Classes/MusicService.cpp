#include "MusicService.h"

const string MusicService::NAME("MusicService");
bool MusicService::canPlayEffect = true;
bool MusicService::canVibrate = true;
bool MusicService::canPlayBackgroundMusic = true;
bool MusicService::isInDesk = false;

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
#define HUO_JIAN_NAN			"sounds/am_tianwangzha.mp3"			//火箭（男）20009
#define HUO_JIAN_NV				"sounds/mm_tianwangzha.mp3"			//火箭（女）20010
#define DAN_ZHANG_NAN			"sounds/am_danzhang.mp3"			//单张（男）20011
#define DAN_ZHANG_NV			"sounds/mm_danzhang.mp3"			//单张（女）20012
#define DUI_ZI_NAN				"sounds/am_dui.mp3"					//对子（男）20013
#define DUI_ZI_NV				"sounds/mm_dui.mp3"					//对子（女）20014
#define LIAN_DUI_NAN			"sounds/am_sanliandui.mp3"			//连对		20015
#define LIAN_DUI_NV				"sounds/mm_sanliandui.mp3"			//			20016
#define SAN_DAI_ER_NAN			"sounds/am_sandaier.mp3"			//三带二、	20017
#define SAN_DAI_ER_NV			"sounds/mm_sandaier.mp3"			//			20018
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
#define HURRY_NV				"sounds/mm_001.mp3"
#define PERFORM_NAN				"sounds/am_002.mp3"				//你的牌打的太好了	20031
#define PERFORM_NV				"sounds/mm_002.mp3"
#define FRIEND_NAN				"sounds/am_003.mp3"				//交个朋友吧，能告诉我联系方式吗  20033
#define FRIEND_NV				"sounds/mm_003.mp3"
#define LEAVE_NAN				"sounds/am_004.mp3"				//不好意思，有事要先走了  20035
#define LEAVE_NV				"sounds/mm_004.mp3"
#define BOOM_HOOM_NAN			"sounds/am_005.mp3"				//炸弹留着带回家啊	20037
#define BOOM_HOOM_NV			"sounds/mm_005.mp3"
#define COOPERATE_NAN			"sounds/am_006.mp3"				//和你合作真是太愉快了 20039
#define COOPERATE_NV			"sounds/mm_006.mp3"
#define HELLO_NAN				"sounds/am_007.mp3"				//大家好，很高兴见到各位  20041
#define HELLO_NV				"sounds/mm_007.mp3"
#define COMBINE_NAN				"sounds/am_008.mp3"				//怎么又断网，网络怎么这么差  20043
#define COMBINE_NV				"sounds/mm_008.mp3"
#define APOLOGY_NAN				"sounds/am_009.mp3"				//水平不高，请多包涵   20045
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



MusicService::MusicService()
{
	init();
}

void MusicService::init()
{

	//预加载音乐和音效文件
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BG_MUSIC);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(BG_MUSIC,true);

	//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	//SimpleAudioEngine::getInstance()->playEffect(BU_CHU_NV, true);
}

void MusicService::preloadAndPlayEffect(const char* s)
{
	if (isLoadMusic[s] != true)
	{
		SimpleAudioEngine::getInstance()->preloadEffect(s);
		isLoadMusic[s] = true;
	}
	if (canPlayEffect)
	{
		SimpleAudioEngine::getInstance()->playEffect(s, false);

		//SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
	}
}

void MusicService::onEvent(int i, void* data)
{
	switch (i)
	{
	case 20000:
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		canPlayBackgroundMusic = false;
		break;
	case EventType::ON_DESK:
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		isInDesk = true;
		break;
	case 20055:
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		canPlayBackgroundMusic = true;
		break;
	case EventType::BACK_TO_HALL:
		if (canPlayBackgroundMusic)
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		isInDesk = false;
		break;
	case 20060:
		if (canPlayBackgroundMusic && !isInDesk)
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		break;
	case 20056:
		canPlayEffect = false;
		break;
	case 20057:
		canPlayEffect = true;
		break;
	case 20058:
		canVibrate = false;
		break;
	case 20059:
		canVibrate = true;
		break;
		//压牌（男）
	case 20001:
		preloadAndPlayEffect(YA_PAI_NAN);
		break;
		//压牌（女）
	case 20002:
		preloadAndPlayEffect(YA_PAI_NV);
		break;
		//不出（男）
	case 20003:
		preloadAndPlayEffect(BU_CHU_NAN);
		break;
		//不出（女）
	case 20004:
		preloadAndPlayEffect(BU_CHU_NV);
		break;
		//炸弹（男）
	case 20005:
		preloadAndPlayEffect(BOOM_NAN);
		break;
		//炸弹（女）
	case 20006:
		preloadAndPlayEffect(BOOM_NV);
		break;
		//同花顺（男）
	case 20007:
		preloadAndPlayEffect(TONG_HUA_SHUN_NAN);
		break;
		//同花顺（女）
	case 20008:
		preloadAndPlayEffect(TONG_HUA_SHUN_NV);
		break;
		//火箭（男）
	case 20009:
		preloadAndPlayEffect(HUO_JIAN_NAN);
		break;
		//火箭（女）
	case 20010:
		preloadAndPlayEffect(HUO_JIAN_NV);
		break;
		//单张（男）
	case 20011:
		preloadAndPlayEffect(DAN_ZHANG_NAN);
		break;
		//单张（女）
	case 20012:
		preloadAndPlayEffect(DAN_ZHANG_NV);
		break;
		//对子（男）
	case 20013:
		preloadAndPlayEffect(DUI_ZI_NAN);
		break;
		//对子（女）
	case 20014:
		preloadAndPlayEffect(DUI_ZI_NV);
		break;
		//连对（男）
	case 20015:
		preloadAndPlayEffect(LIAN_DUI_NAN);
		break;
		//连对（女）
	case 20016:
		preloadAndPlayEffect(LIAN_DUI_NV);
		break;
		//三带二（男）
	case 20017:
		preloadAndPlayEffect(SAN_DAI_ER_NAN);
		break;
		//三带二（女）
	case 20018:
		preloadAndPlayEffect(SAN_DAI_ER_NV);
		break;
		//三张（男）
	case 20019:
		preloadAndPlayEffect(SAN_ZHANG_NAN);
		break;
		//三张（女）
	case 20020:
		preloadAndPlayEffect(SAN_ZHANG_NV);
		break;
		//飞机（男）
	case 20021:
		preloadAndPlayEffect(FEI_JI_NAN);
		break;
		//飞机（女）
	case 20022:
		preloadAndPlayEffect(FEI_JI_NV);
		break;
		//抗贡（男）
	case 20023:
		preloadAndPlayEffect(KANG_GONG_NAN);
		break;
		//抗贡（女）
	case EventType::KANG_GONG:
		preloadAndPlayEffect(KANG_GONG_NV);
		break;
		//进贡（男）
	case 20025:
		preloadAndPlayEffect(JING_GONG_NAN);
		break;
		//进贡（女）
	case 20026:
		preloadAndPlayEffect(JING_GONG_NV);
		break;
		//还贡（男）
	case 20027:
		preloadAndPlayEffect(HUANG_GONG_NAN);
		break;
		//还贡（女）
	case 20028:
		preloadAndPlayEffect(HUANG_GONG_NV);
		break;
		//快点吧，等的花都谢了（男）
	case 20029:
		preloadAndPlayEffect(HURRY_NAN);
		break;
		//快点吧，等的花都谢了（女）
	case 20030:
		preloadAndPlayEffect(HURRY_NV);
		break;
		//你的牌打的太好了（男）
	case 20031:
		preloadAndPlayEffect(PERFORM_NAN);
		break;
		//你的牌打的太好了（女）
	case 20032:
		preloadAndPlayEffect(PERFORM_NV);
		break;
		//交个朋友吧，能告诉我联系方式吗（男）
	case 20033:
		preloadAndPlayEffect(FRIEND_NAN);
		break;
		//交个朋友吧，能告诉我联系方式吗（女）
	case 20034:
		preloadAndPlayEffect(FRIEND_NV);
		break;
		//不好意思，有事要先走了（男）
	case 20035:
		preloadAndPlayEffect(LEAVE_NAN);
		break;
		//不好意思，有事要先走了（女）
	case 20036:
		preloadAndPlayEffect(LEAVE_NV);
		break;
		//炸弹留着带回家啊（男）
	case 20037:
		preloadAndPlayEffect(BOOM_HOOM_NAN);
		break;
		//炸弹留着带回家啊（女）
	case 20038:
		preloadAndPlayEffect(BOOM_HOOM_NV);
		break;
		//和你合作真是太愉快了（男）
	case 20039:
		preloadAndPlayEffect(COOPERATE_NAN);
		break;
		//和你合作真是太愉快了（女）
	case 20040:
		preloadAndPlayEffect(COOPERATE_NV);
		break;
		//大家好，很高兴见到各位（男）
	case 20041:
		preloadAndPlayEffect(HELLO_NAN);
		break;
		//大家好，很高兴见到各位（女）
	case 20042:
		preloadAndPlayEffect(HELLO_NV);
		break;
		//怎么又断网，网络怎么这么差（男）
	case 20043:
		preloadAndPlayEffect(COMBINE_NAN);
		break;
		//怎么又断网，网络怎么这么差（女）
	case 20044:
		preloadAndPlayEffect(COMBINE_NV);
		break;
		//水平不高，请多包涵（男）
	case 20045:
		preloadAndPlayEffect(APOLOGY_NAN);
		break;
		//水平不高，请多包涵（女）
	case 20046:
		preloadAndPlayEffect(APOLOGY_NV);
		break;
		//出牌音效
	case 20047:
		preloadAndPlayEffect(SEND_CARD);
		break;
		//胜利音效
	case 20048:
		preloadAndPlayEffect(GAME_WIN);
		break;
		//失败音效
	case 20049:
		preloadAndPlayEffect(GAME_FAIL);
		break;
		//点击按钮音效
	case 20050:
		preloadAndPlayEffect(BUTTON_CLICK);
		break;
		//撒豆
	case 20051:
		preloadAndPlayEffect(GOLD_FALL);
		break;
		//领奖音效
	case 20052:
		preloadAndPlayEffect(GET_AWARD);
		break;
		//计时器
	case 20053:
		preloadAndPlayEffect(JI_SHI_QI);
		break;
		//抽奖音效
	case 20054:
		preloadAndPlayEffect(CHOU_JIANG);
		break;
		//飞机
	case EventType::FEI_JI:
		preloadAndPlayEffect(ACTION_FEI_JI);
		break;
		//炸弹
	case EventType::BOOM:
		preloadAndPlayEffect(ACTION_BOOM);
		if (canVibrate)
			//SimpleAudioEngine::getInstance()->vibrate(1);
		break;
		//同花顺
	case EventType::TONG_HUA_SHUN:
		preloadAndPlayEffect(ACTION_TONG_HUA_SHUN);
		if (canVibrate)
			//SimpleAudioEngine::getInstance()->vibrate(1);
		break;
		//火箭
	case EventType::HUO_JIAN:
		preloadAndPlayEffect(ACTION_HUO_JIAN);
		if (canVibrate)
			//SimpleAudioEngine::getInstance()->vibrate(1);
		break;
	}
}

bool MusicService::getBackGroundMusicState()
{
	return (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying());
}

bool MusicService::getEffectMusicState()
{
	return canPlayEffect;
}

bool MusicService::getCanBackgroundMusic()
{
	return canPlayBackgroundMusic;
}