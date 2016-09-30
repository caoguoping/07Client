#include "MusicService.h"

const string MusicService::NAME("MusicService");
bool MusicService::canPlayEffect = true;
bool MusicService::canVibrate = true;
bool MusicService::canPlayBackgroundMusic = true;
bool MusicService::isInDesk = false;

//���ú궨���ļ����������Ժ�ͳһ�޸�
#define	BG_MUSIC				"sounds/bgmusic.mp3"				//����
/*
	���������Ч
*/
#define YA_PAI_NAN				"sounds/am_dani.mp3"				//ѹ�ƣ��У�20001
#define YA_PAI_NV				"sounds/mm_dani.mp3"				//ѹ�ƣ�Ů��20002
#define BU_CHU_NAN				"sounds/am_buchu.mp3"				//�������У�20003
#define BU_CHU_NV				"sounds/mm_buchu.mp3"				//������Ů��20004
#define BOOM_NAN				"sounds/am_zha.mp3"					//ը�����У�20005
#define BOOM_NV					"sounds/mm_zha.mp3"					//ը����Ů��20006
#define TONG_HUA_SHUN_NAN		"sounds/am_tonghuashun.mp3"			//ͬ��˳���У�20007
#define TONG_HUA_SHUN_NV		"sounds/mm_tonghuashun.mp3"			//ͬ��˳��Ů��20008
#define HUO_JIAN_NAN			"sounds/am_tianwangzha.mp3"			//������У�20009
#define HUO_JIAN_NV				"sounds/mm_tianwangzha.mp3"			//�����Ů��20010
#define DAN_ZHANG_NAN			"sounds/am_danzhang.mp3"			//���ţ��У�20011
#define DAN_ZHANG_NV			"sounds/mm_danzhang.mp3"			//���ţ�Ů��20012
#define DUI_ZI_NAN				"sounds/am_dui.mp3"					//���ӣ��У�20013
#define DUI_ZI_NV				"sounds/mm_dui.mp3"					//���ӣ�Ů��20014
#define LIAN_DUI_NAN			"sounds/am_sanliandui.mp3"			//����		20015
#define LIAN_DUI_NV				"sounds/mm_sanliandui.mp3"			//			20016
#define SAN_DAI_ER_NAN			"sounds/am_sandaier.mp3"			//��������	20017
#define SAN_DAI_ER_NV			"sounds/mm_sandaier.mp3"			//			20018
#define SAN_ZHANG_NAN			"sounds/am_sanzhang.mp3"			//����		20019
#define SAN_ZHANG_NV			"sounds/mm_sanzhang.mp3"			//			20020
#define FEI_JI_NAN				"sounds/am_gangban.mp3"				//�ɻ�		20021
#define FEI_JI_NV				"sounds/mm_gangban.mp3"				//			20022

/*
	������Ч
*/
#define KANG_GONG_NAN			"sounds/nan_kanggong.mp3"			//����		20023
#define KANG_GONG_NV			"sounds/nv_kanggong.mp3"	
#define JING_GONG_NAN			"sounds/nan_jingong.mp3"			//����		20025
#define JING_GONG_NV			"sounds/nv_jingong.mp3"
#define HUANG_GONG_NAN			"sounds/nan_huangong.mp3"			//����		20027
#define HUANG_GONG_NV			"sounds/nv_huangong.mp3"

/*
	������Ч
*/
#define HURRY_NAN				"sounds/am_001.mp3"				//���ɣ��ȵĻ���л��20029
#define HURRY_NV				"sounds/mm_001.mp3"
#define PERFORM_NAN				"sounds/am_002.mp3"				//����ƴ��̫����	20031
#define PERFORM_NV				"sounds/mm_002.mp3"
#define FRIEND_NAN				"sounds/am_003.mp3"				//�������Ѱɣ��ܸ�������ϵ��ʽ��  20033
#define FRIEND_NV				"sounds/mm_003.mp3"
#define LEAVE_NAN				"sounds/am_004.mp3"				//������˼������Ҫ������  20035
#define LEAVE_NV				"sounds/mm_004.mp3"
#define BOOM_HOOM_NAN			"sounds/am_005.mp3"				//ը�����Ŵ��ؼҰ�	20037
#define BOOM_HOOM_NV			"sounds/mm_005.mp3"
#define COOPERATE_NAN			"sounds/am_006.mp3"				//�����������̫����� 20039
#define COOPERATE_NV			"sounds/mm_006.mp3"
#define HELLO_NAN				"sounds/am_007.mp3"				//��Һã��ܸ��˼�����λ  20041
#define HELLO_NV				"sounds/mm_007.mp3"
#define COMBINE_NAN				"sounds/am_008.mp3"				//��ô�ֶ�����������ô��ô��  20043
#define COMBINE_NV				"sounds/mm_008.mp3"
#define APOLOGY_NAN				"sounds/am_009.mp3"				//ˮƽ���ߣ�������   20045
#define APOLOGY_NV				"sounds/mm_009.mp3"	

/*
	������Ч
*/
#define SEND_CARD				"sounds/game_send_card.mp3"			//������Ч 20047
#define GAME_WIN				"sounds/game_win.mp3"				//ʤ����Ч 20048
#define GAME_FAIL				"sounds/game_lose.mp3"				//ʧ����Ч 20049
#define BUTTON_CLICK			"sounds/game_button_click.mp3"		//�����ť��Ч 20050
#define GOLD_FALL				"sounds/Goldfall2.mp3"				//���� 20051
#define GET_AWARD				"sounds/Special_star.mp3"			//�콱��Ч 20052
#define JI_SHI_QI				"sounds/jishiqi.mp3"				//��ʱ�� 20053
#define CHOU_JIANG				"sounds/expression-7.mp3"			//�齱��Ч 20054


/*
	������Ч��Ч
*/
#define ACTION_FEI_JI			"sounds/game_gangbaneffect.mp3"	//�ɻ�  FEI_JI
#define ACTION_BOOM				"sounds/zhadan.mp3"				//ը��  BOOM
#define ACTION_TONG_HUA_SHUN	"sounds/TongHuaShunAct.mp3"		//ͬ��˳ TONG_HUA_SHUN
#define ACTION_HUO_JIAN			"sounds/game_effect_wanzha.mp3"	//���  HUO_JIAN



MusicService::MusicService()
{
	init();
}

void MusicService::init()
{

	//Ԥ�������ֺ���Ч�ļ�
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
		//ѹ�ƣ��У�
	case 20001:
		preloadAndPlayEffect(YA_PAI_NAN);
		break;
		//ѹ�ƣ�Ů��
	case 20002:
		preloadAndPlayEffect(YA_PAI_NV);
		break;
		//�������У�
	case 20003:
		preloadAndPlayEffect(BU_CHU_NAN);
		break;
		//������Ů��
	case 20004:
		preloadAndPlayEffect(BU_CHU_NV);
		break;
		//ը�����У�
	case 20005:
		preloadAndPlayEffect(BOOM_NAN);
		break;
		//ը����Ů��
	case 20006:
		preloadAndPlayEffect(BOOM_NV);
		break;
		//ͬ��˳���У�
	case 20007:
		preloadAndPlayEffect(TONG_HUA_SHUN_NAN);
		break;
		//ͬ��˳��Ů��
	case 20008:
		preloadAndPlayEffect(TONG_HUA_SHUN_NV);
		break;
		//������У�
	case 20009:
		preloadAndPlayEffect(HUO_JIAN_NAN);
		break;
		//�����Ů��
	case 20010:
		preloadAndPlayEffect(HUO_JIAN_NV);
		break;
		//���ţ��У�
	case 20011:
		preloadAndPlayEffect(DAN_ZHANG_NAN);
		break;
		//���ţ�Ů��
	case 20012:
		preloadAndPlayEffect(DAN_ZHANG_NV);
		break;
		//���ӣ��У�
	case 20013:
		preloadAndPlayEffect(DUI_ZI_NAN);
		break;
		//���ӣ�Ů��
	case 20014:
		preloadAndPlayEffect(DUI_ZI_NV);
		break;
		//���ԣ��У�
	case 20015:
		preloadAndPlayEffect(LIAN_DUI_NAN);
		break;
		//���ԣ�Ů��
	case 20016:
		preloadAndPlayEffect(LIAN_DUI_NV);
		break;
		//���������У�
	case 20017:
		preloadAndPlayEffect(SAN_DAI_ER_NAN);
		break;
		//��������Ů��
	case 20018:
		preloadAndPlayEffect(SAN_DAI_ER_NV);
		break;
		//���ţ��У�
	case 20019:
		preloadAndPlayEffect(SAN_ZHANG_NAN);
		break;
		//���ţ�Ů��
	case 20020:
		preloadAndPlayEffect(SAN_ZHANG_NV);
		break;
		//�ɻ����У�
	case 20021:
		preloadAndPlayEffect(FEI_JI_NAN);
		break;
		//�ɻ���Ů��
	case 20022:
		preloadAndPlayEffect(FEI_JI_NV);
		break;
		//�������У�
	case 20023:
		preloadAndPlayEffect(KANG_GONG_NAN);
		break;
		//������Ů��
	case EventType::KANG_GONG:
		preloadAndPlayEffect(KANG_GONG_NV);
		break;
		//�������У�
	case 20025:
		preloadAndPlayEffect(JING_GONG_NAN);
		break;
		//������Ů��
	case 20026:
		preloadAndPlayEffect(JING_GONG_NV);
		break;
		//�������У�
	case 20027:
		preloadAndPlayEffect(HUANG_GONG_NAN);
		break;
		//������Ů��
	case 20028:
		preloadAndPlayEffect(HUANG_GONG_NV);
		break;
		//���ɣ��ȵĻ���л�ˣ��У�
	case 20029:
		preloadAndPlayEffect(HURRY_NAN);
		break;
		//���ɣ��ȵĻ���л�ˣ�Ů��
	case 20030:
		preloadAndPlayEffect(HURRY_NV);
		break;
		//����ƴ��̫���ˣ��У�
	case 20031:
		preloadAndPlayEffect(PERFORM_NAN);
		break;
		//����ƴ��̫���ˣ�Ů��
	case 20032:
		preloadAndPlayEffect(PERFORM_NV);
		break;
		//�������Ѱɣ��ܸ�������ϵ��ʽ���У�
	case 20033:
		preloadAndPlayEffect(FRIEND_NAN);
		break;
		//�������Ѱɣ��ܸ�������ϵ��ʽ��Ů��
	case 20034:
		preloadAndPlayEffect(FRIEND_NV);
		break;
		//������˼������Ҫ�����ˣ��У�
	case 20035:
		preloadAndPlayEffect(LEAVE_NAN);
		break;
		//������˼������Ҫ�����ˣ�Ů��
	case 20036:
		preloadAndPlayEffect(LEAVE_NV);
		break;
		//ը�����Ŵ��ؼҰ����У�
	case 20037:
		preloadAndPlayEffect(BOOM_HOOM_NAN);
		break;
		//ը�����Ŵ��ؼҰ���Ů��
	case 20038:
		preloadAndPlayEffect(BOOM_HOOM_NV);
		break;
		//�����������̫����ˣ��У�
	case 20039:
		preloadAndPlayEffect(COOPERATE_NAN);
		break;
		//�����������̫����ˣ�Ů��
	case 20040:
		preloadAndPlayEffect(COOPERATE_NV);
		break;
		//��Һã��ܸ��˼�����λ���У�
	case 20041:
		preloadAndPlayEffect(HELLO_NAN);
		break;
		//��Һã��ܸ��˼�����λ��Ů��
	case 20042:
		preloadAndPlayEffect(HELLO_NV);
		break;
		//��ô�ֶ�����������ô��ô��У�
	case 20043:
		preloadAndPlayEffect(COMBINE_NAN);
		break;
		//��ô�ֶ�����������ô��ô�Ů��
	case 20044:
		preloadAndPlayEffect(COMBINE_NV);
		break;
		//ˮƽ���ߣ����������У�
	case 20045:
		preloadAndPlayEffect(APOLOGY_NAN);
		break;
		//ˮƽ���ߣ���������Ů��
	case 20046:
		preloadAndPlayEffect(APOLOGY_NV);
		break;
		//������Ч
	case 20047:
		preloadAndPlayEffect(SEND_CARD);
		break;
		//ʤ����Ч
	case 20048:
		preloadAndPlayEffect(GAME_WIN);
		break;
		//ʧ����Ч
	case 20049:
		preloadAndPlayEffect(GAME_FAIL);
		break;
		//�����ť��Ч
	case 20050:
		preloadAndPlayEffect(BUTTON_CLICK);
		break;
		//����
	case 20051:
		preloadAndPlayEffect(GOLD_FALL);
		break;
		//�콱��Ч
	case 20052:
		preloadAndPlayEffect(GET_AWARD);
		break;
		//��ʱ��
	case 20053:
		preloadAndPlayEffect(JI_SHI_QI);
		break;
		//�齱��Ч
	case 20054:
		preloadAndPlayEffect(CHOU_JIANG);
		break;
		//�ɻ�
	case EventType::FEI_JI:
		preloadAndPlayEffect(ACTION_FEI_JI);
		break;
		//ը��
	case EventType::BOOM:
		preloadAndPlayEffect(ACTION_BOOM);
		if (canVibrate)
			//SimpleAudioEngine::getInstance()->vibrate(1);
		break;
		//ͬ��˳
	case EventType::TONG_HUA_SHUN:
		preloadAndPlayEffect(ACTION_TONG_HUA_SHUN);
		if (canVibrate)
			//SimpleAudioEngine::getInstance()->vibrate(1);
		break;
		//���
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