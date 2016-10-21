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
	SEND_POKER,                //����
	PAY_TRIBUTE,
	GAME_OVER,
	REV_PLAYER_OUT_POKER,      //�û�����
	NOT_OUT_POKER,
	SHOW_GAME_DATA,				//������Ϸ������ʾ��������
	CHANGE_POKER_STATE,			//�ı��Ƶ�ѡ��״̬
	SELECT_POKER_MOVE,          //����ѡ�ƣ�ֻ��������
	REMOVE_POKER,				//���������Ƴ���������
	CHANGE_POKER_POSITION,		//�ı��Ƶ�λ��
	REMOVE_OUT_POKER,			//��������Ƶ���ʾ
	REMOVE_POKER_VIEW,			//�Ƴ��Ƶ���ʾ
	SET_POKER_OPACITY,			//�������Ƶ�͸����
	BACK_TO_HALL,				//���ش���
	GET_JING_GONG,				//��ȡ���˸��Լ���������
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
	POKER_GONG_PAI_STATE,		//�Ƽ��Ϲ��Ʊ��
	SHOW_DAO_JU_ACTION,
	SEVEN_LOGIN_INFO,			//���յ�¼��Ϣ
	DAILY_MISSION_INFO,			//�ճ�������Ϣ
	MALL_INFO,					//�̳���Ϣ
	GET_MIS_REWARD,				//��ȡ������
	GET_GAMBLING_REWARD,		//��ȡ�齱����
	GET_BUY_ITEMS,			//��ȡ�����̳ǵ���
	BACK_TO_LOBBY,
	USE_JI_PAI_QI,				//ʹ�ü�����
	PUSH_JIPAIQI,                      //���ͼ���������
	TASK_REWORD,                        //����3000���
	MATCH_NUM,					//��������
	MATCH_STATES,                  //��������
	FRIEND_LIST,       //�����б�
	FRIEND_SHUREN,    //��������
	FRIEND_OPT_ME,     //���Ѳ���,�Լ��Ĳ������ظ��Լ���
	FRIEND_OPT_HIM,     //���Ѳ���,�Է����Լ��Ĳ���
	FRIEND_SEARCH,  //��������
	FRIEND_PLAY,    //������ѳ�

	
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



//99999�������δ����¼�
//20000��ʼ������Ч
//30000�˳���Ϸ
//30001��Ҳ���
//30002��ʯ����


#endif