#ifndef PACKET_HEAD_FILE
#define PACKET_HEAD_FILE

#pragma pack(1)
using namespace std;
#include "SGTools.h"

/*************************************************
       ��Ϸ������������Ϣ��
************************************************/
#define GAME_MAIN_LOGIN         1
#define GAME_SUB_LOGIN_FAIL     101
#define GAME_SUB_LOGIN_SUCCESS  102

#define GAME_MAIN_DESK     3
#define GAME_SUB_OTHER_DESK 100
#define GAME_SUB_Match_JISUAN 101
#define GAME_SUB_ONDESK     102
#define GAME_SUB_DESKFAIL   103
#define GAME_SUB_USEITEM    301
#define GAME_SUB_USEJIPAIQI    307

#define GAME_MAIN_PLAY    200
#define GAME_SUB_GAMEOVER 105
#define GAME_SUB_FAPAI   101
#define GAME_SUB_SENDPOKER 102
#define GAME_SUB_NOTOUTPOKER 103
#define GAME_SUB_JINGONG   104
#define GAME_SUB_PUSHJIPAIQI  112

#define GAME_MAIN_TASK 5
#define GAME_SUB_TASK  104    //����


#define MDM_GR_MATCH				7									//��������

#define SUB_GR_MATCH_FEE			400									//��������
#define SUB_GR_MATCH_NUM			401									//�ȴ�����
#define SUB_GR_LEAVE_MATCH			402									//�˳�����
#define SUB_GR_MATCH_INFO			403									//������Ϣ
#define SUB_GR_MATCH_WAIT_TIP		404									//�ȴ���ʾ
#define SUB_GR_MATCH_RESULT			405									//�������
#define SUB_GR_MATCH_STATUS			406									//����״̬
#define SUB_GR_MATCH_USER_COUNT		407									//��������
#define SUB_GR_MATCH_DESC			408									//��������

#define GAME_MAIN_MATCH 7
#define GAME_SUB_MATCHPEAPLE  401    //��������






//////////////////////////////////////////////////////////////////////////////////
//��ֵ����

//ͷ���С
#define FACE_CX						48									//ͷ����
#define FACE_CY						48									//ͷ��߶�

//���ȶ���
#define LEN_LESS_ACCOUNTS			6									//����ʺ�
#define LEN_LESS_NICKNAME			6									//����ǳ�
#define LEN_LESS_PASSWORD			6									//�������

//��������
#define MAX_CHAIR					100									//�������
#define MAX_TABLE					512									//�������
#define MAX_COLUMN					32									//����б�
#define MAX_ANDROID					256									//������
#define MAX_PROPERTY				128									//������
#define MAX_WHISPER_USER			16									//���˽��


//�б���
#define MAX_KIND					128									//�������
#define MAX_SERVER					1024								//��󷿼�

//��������
#define INVALID_CHAIR				0xFFFF								//��Ч����
#define INVALID_TABLE				0xFFFF								//��Ч����

//˰�ն���
#define REVENUE_BENCHMARK			0L								    //˰�����
#define REVENUE_DENOMINATOR			1000L								//˰�շ�ĸ

//////////////////////////////////////////////////////////////////////////////////
//ϵͳ����

//��������
#define SCORE						long long							//��������
#define SCORE_STRING				TEXT("%I64d")						//��������

//��Ϸ״̬
#define GAME_STATUS_FREE			0									//����״̬
#define GAME_STATUS_PLAY			100									//��Ϸ״̬
#define GAME_STATUS_WAIT			200									//�ȴ�״̬

//ϵͳ����
#define LEN_USER_CHAT				128									//���쳤��
#define TIME_USER_CHAT				1L									//������
#define TRUMPET_MAX_CHAR            128									//���ȳ���

//////////////////////////////////////////////////////////////////////////////////
//��������

//�б�����
#define PRIME_TYPE					11L									//������Ŀ
#define PRIME_KIND					53L									//������Ŀ
#define PRIME_NODE					101L								//�ڵ���Ŀ
#define PRIME_PAGE					53L									//�Զ���Ŀ
#define PRIME_SERVER				1009L								//������Ŀ

//��������
#define PRIME_SERVER_USER			503L								//��������
#define PRIME_ANDROID_USER			503L								//��������
#define PRIME_PLATFORM_USER			100003L								//ƽ̨����

//////////////////////////////////////////////////////////////////////////////////
//���ݳ���

//��������
#define LEN_MD5						33									//��������
#define LEN_USERNOTE				32									//��ע����
#define LEN_ACCOUNTS				32									//�ʺų���
#define LEN_NICKNAME				32									//�ǳƳ���
#define LEN_PASSWORD				33									//���볤��
#define LEN_GROUP_NAME				32									//��������
#define LEN_UNDER_WRITE				32									//����ǩ��

//���ݳ���
#define LEN_QQ						16									//Q Q ����
#define LEN_EMAIL					33									//�����ʼ�
#define LEN_USER_NOTE				256									//�û���ע
#define LEN_SEAT_PHONE				33									//�̶��绰
#define LEN_MOBILE_PHONE			12									//�ƶ��绰
#define LEN_PASS_PORT_ID			19									//֤������
#define LEN_COMPELLATION			16									//��ʵ����
#define LEN_DWELLING_PLACE			128									//��ϵ��ַ

//������ʶ
#define LEN_NETWORK_ID				13									//��������
#define LEN_MACHINE_ID				33									//���г���

//�б�����
#define LEN_TYPE					32									//���೤��
#define LEN_KIND					32									//���ͳ���
#define LEN_NODE					32									//�ڵ㳤��
#define LEN_PAGE					32									//���Ƴ���
#define LEN_SERVER					32									//���䳤��
#define LEN_PROCESS					32									//���̳���

//////////////////////////////////////////////////////////////////////////////////

//�û���ϵ
#define	CP_NORMAL					0									//δ֪��ϵ
#define	CP_FRIEND					1									//���ѹ�ϵ
#define	CP_DETEST					2									//����ϵ
#define CP_SHIELD					3									//��������

//////////////////////////////////////////////////////////////////////////////////

//�Ա���
#define GENDER_FEMALE				0									//Ů���Ա�
#define GENDER_MANKIND				1									//�����Ա�

//////////////////////////////////////////////////////////////////////////////////

//��Ϸģʽ
#define GAME_GENRE_GOLD				0x0001								//�������
#define GAME_GENRE_SCORE			0x0002								//��ֵ����
#define GAME_GENRE_MATCH			0x0004								//��������
#define GAME_GENRE_EDUCATE			0x0008								//ѵ������

//����ģʽ
#define SCORE_GENRE_NORMAL			0x0100								//��ͨģʽ
#define SCORE_GENRE_POSITIVE		0x0200								//�Ǹ�ģʽ

//////////////////////////////////////////////////////////////////////////////////

//�û�״̬
#define US_NULL						0x00								//û��״̬
#define US_FREE						0x01								//վ��״̬
#define US_SIT						0x02								//����״̬
#define US_READY					0x03								//ͬ��״̬
#define US_LOOKON					0x04								//�Թ�״̬
#define US_PLAYING					0x05								//��Ϸ״̬
#define US_OFFLINE					0x06								//����״̬

//////////////////////////////////////////////////////////////////////////////////

//����״̬
#define MS_NULL						0x00								//û��״̬
#define MS_SIGNUP					0x01								//����״̬
#define MS_MATCHING					0x02								//����״̬
#define MS_OUT						0x03								//��̭״̬

//////////////////////////////////////////////////////////////////////////////////

//�������
#define SRL_LOOKON					0x00000001							//�Թ۱�־
#define SRL_OFFLINE					0x00000002							//���߱�־
#define SRL_SAME_IP					0x00000004							//ͬ����־

//�������
#define SRL_ROOM_CHAT				0x00000100							//�����־
#define SRL_GAME_CHAT				0x00000200							//�����־
#define SRL_WISPER_CHAT				0x00000400							//˽�ı�־
#define SRL_HIDE_USER_INFO			0x00000800							//���ر�־

//////////////////////////////////////////////////////////////////////////////////
//�б�����

//��Ч����
#define UD_NULL						0									//��Ч����
#define UD_IMAGE					100									//ͼ������
#define UD_CUSTOM					200									//�Զ�����

//��������
#define UD_GAME_ID					1									//��Ϸ��ʶ
#define UD_USER_ID					2									//�û���ʶ
#define	UD_NICKNAME					3									//�û��ǳ�

//��չ����
#define UD_GENDER					10									//�û��Ա�
#define UD_GROUP_NAME				11									//��������
#define UD_UNDER_WRITE				12									//����ǩ��

//״̬��Ϣ
#define UD_TABLE					20									//��Ϸ����
#define UD_CHAIR					21									//���Ӻ���

//������Ϣ
#define UD_SCORE					30									//�û�����
#define UD_GRADE					31									//�û��ɼ�
#define UD_USER_MEDAL				32									//�û�����
#define UD_EXPERIENCE				33									//�û�����
#define UD_LOVELINESS				34									//�û�����
#define UD_WIN_COUNT				35									//ʤ������
#define UD_LOST_COUNT				36									//�������
#define UD_DRAW_COUNT				37									//�;�����
#define UD_FLEE_COUNT				38									//�Ӿ�����
#define UD_PLAY_COUNT				39									//�ܾ�����

//���ֱ���
#define UD_WIN_RATE					40									//�û�ʤ��
#define UD_LOST_RATE				41									//�û�����
#define UD_DRAW_RATE				42									//�û�����
#define UD_FLEE_RATE				43									//�û�����
#define UD_GAME_LEVEL				44									//��Ϸ�ȼ�

//��չ��Ϣ
#define UD_NOTE_INFO				50									//�û���ע
#define UD_LOOKON_USER				51									//�Թ��û�

//ͼ���б�
#define UD_IMAGE_FLAG				(UD_IMAGE+1)						//�û���־
#define UD_IMAGE_GENDER				(UD_IMAGE+2)						//�û��Ա�
#define UD_IMAGE_STATUS				(UD_IMAGE+3)						//�û�״̬

//////////////////////////////////////////////////////////////////////////////////
//���ݿⶨ��

#define DB_ERROR 					-1  								//����ʧ��
#define DB_SUCCESS 					0  									//����ɹ�
#define DB_NEEDMB 					18 									//����ʧ��

//////////////////////////////////////////////////////////////////////////////////
//���߱�ʾ
#define PT_USE_MARK_DOUBLE_SCORE    0x0001								//˫������
#define PT_USE_MARK_FOURE_SCORE     0x0002								//�ı�����
#define PT_USE_MARK_GUARDKICK_CARD  0x0010								//���ߵ���
#define PT_USE_MARK_POSSESS         0x0020								//������� 

#define MAX_PT_MARK                 4                                   //��ʶ��Ŀ

//��Ч��Χ
#define VALID_TIME_DOUBLE_SCORE     3600                                //��Чʱ��
#define VALID_TIME_FOUR_SCORE       3600                                //��Чʱ��
#define VALID_TIME_GUARDKICK_CARD   3600                                //����ʱ��
#define VALID_TIME_POSSESS          3600                                //����ʱ��
#define VALID_TIME_KICK_BY_MANAGER  3600                                //��Ϸʱ�� 

//////////////////////////////////////////////////////////////////////////////////
//�豸����
#define DEVICE_TYPE_PC              0x00                                //PC
#define DEVICE_TYPE_ANDROID         0x10                                //Android
#define DEVICE_TYPE_ITOUCH          0x20                                //iTouch
#define DEVICE_TYPE_IPHONE          0x40                                //iPhone
#define DEVICE_TYPE_IPAD            0x80                                //iPad

/////////////////////////////////////////////////////////////////////////////////
//�ֻ�����

//��ͼģʽ
#define	VIEW_MODE_ALL				0x0001								//ȫ������
#define	VIEW_MODE_PART				0x0002								//���ֿ���

//��Ϣģʽ
#define VIEW_INFO_LEVEL_1			0x0010								//������Ϣ
#define VIEW_INFO_LEVEL_2			0x0020								//������Ϣ
#define VIEW_INFO_LEVEL_3			0x0040								//������Ϣ
#define VIEW_INFO_LEVEL_4			0x0080								//������Ϣ

//��������
#define RECVICE_GAME_CHAT			0x0100								//��������
#define RECVICE_ROOM_CHAT			0x0200								//��������
#define RECVICE_ROOM_WHISPER		0x0400								//����˽��

//��Ϊ��ʶ
#define BEHAVIOR_LOGON_NORMAL       0x0000                              //��ͨ��¼
#define BEHAVIOR_LOGON_IMMEDIATELY  0x1000                              //������¼

/////////////////////////////////////////////////////////////////////////////////
//������
#define RESULT_ERROR 					-1  								//�������
#define RESULT_SUCCESS 					0  									//����ɹ�
#define RESULT_FAIL 					1  									//����ʧ��

/////////////////////////////////////////////////////////////////////////////////
//�仯ԭ��
#define SCORE_REASON_WRITE              0                                   //д�ֱ仯
#define SCORE_REASON_INSURE             1                                   //���б仯
#define SCORE_REASON_PROPERTY           2                                   //���߱仯

/////////////////////////////////////////////////////////////////////////////////

//��¼����ʧ��ԭ��
#define LOGON_FAIL_SERVER_INVALIDATION  200                                 //����ʧЧ

////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//�б�����

#define MDM_GP_SERVER_LIST			2																							//�б���Ϣ

//��ȡ����
#define SUB_GP_GET_LIST				1																							//��ȡ�б�
#define SUB_GP_GET_SERVER			2																							//��ȡ����
#define SUB_GP_GET_ONLINE			3																							//��ȡ����
#define SUB_GP_GET_COLLECTION		4																							//��ȡ�ղ�

//�б���Ϣ
#define SUB_GP_LIST_TYPE			100																							//�����б�
#define SUB_GP_LIST_KIND			101																							//�����б�
#define SUB_GP_LIST_NODE			102																							//�ڵ��б�
#define SUB_GP_LIST_PAGE			103																							//�����б�
#define SUB_GP_LIST_SERVER			104																							//�����б�
#define SUB_GP_VIDEO_OPTION			105																							//��Ƶ����

//�����Ϣ
#define SUB_GP_LIST_FINISH			200																							//�������
#define SUB_GP_SERVER_FINISH		201																							//�������

//������Ϣ
#define SUB_GR_KINE_ONLINE			300																							//��������
#define SUB_GR_SERVER_ONLINE		301																							//��������

//////////////////////////////////////////////////////////////////////////////////

#define SOCKET_TCP_BUFFER					16384																				//���绺��
#define SOCKET_TCP_PACKET					(SOCKET_TCP_BUFFER-sizeof(TCP_Head))												//���绺��

//�ں�����
#define MDM_KN_COMMAND				0																							//�ں�����
#define SUB_KN_DETECT_SOCKET		1																							//�������
#define SUB_KN_VALIDATE_SOCKET		2																							//��֤����

//��¼��ʽ
#define LOGON_BY_GAME_ID			1																							//I D ��¼
#define LOGON_BY_ACCOUNTS			2																							//�ʺŵ�¼

#define SUB_GP_LOGON_GAMEID			1																							//I D ��¼
#define SUB_GP_LOGON_ACCOUNTS		2																							//�ʺŵ�¼

#define MDM_GP_LOGON				1																							//�㳡��¼
#define MB_VALIDATE_FLAGS           0x01																						//Ч���ܱ�
#define LOW_VER_VALIDATE_FLAGS      0x02																						//Ч��Ͱ汾


//////////////////////////////////////////////////////////////////////////////////
//��¼����

#define MDM_GP_LOGON				1									//�㳡��¼

//��¼ģʽ
#define SUB_GP_LOGON_GAMEID			1									//I D ��¼
#define SUB_GP_LOGON_ACCOUNTS		2									//�ʺŵ�¼
#define SUB_GP_REGISTER_ACCOUNTS	3									//ע���ʺ�

//��¼���
#define SUB_GP_LOGON_SUCCESS		100									//��¼�ɹ�
#define SUB_GP_LOGON_FAILURE		101									//��¼ʧ��
#define SUB_GP_LOGON_FINISH			102									//��¼���
#define SUB_GP_VALIDATE_MBCARD      103                                 //��¼ʧ��
#define SUB_GP_CREATE_ROLE          105                                 //֪ͨ������ɫ  1  , 105



//������ʾ
#define SUB_GP_UPDATE_NOTIFY		200									//������ʾ

//////////////////////////////////////////////////////////////////////////////////
//






#define MainLoginSuccess 1
#define SubLoginSuccess 100



//////////////////////////////////////////////////////////////////////////////////
//��¼����

#define MDM_GR_LOGON				1									//��¼��Ϣ

//��¼ģʽ
#define SUB_GR_LOGON_USERID			1									//I D ��¼
#define SUB_GR_LOGON_MOBILE			2									//�ֻ���¼
#define SUB_GR_LOGON_ACCOUNTS		3									//�ʻ���¼

//��¼���
#define SUB_GR_LOGON_SUCCESS		100									//��¼�ɹ�
#define SUB_GR_LOGON_FAILURE		101									//��¼ʧ��
#define SUB_GR_LOGON_FINISH			102									//��¼���
#define SUB_GP_VALIDATE_MBCARD      103                                 //��¼ʧ��
#define SUB_GP_CREATE_ROLE          105                                 //֪ͨ������ɫ  1  , 105

//������ʾ
#define SUB_GR_UPDATE_NOTIFY		200									//������ʾ





























//��������

#define MDM_GR_CONFIG				2									//������Ϣ

#define SUB_GR_CONFIG_COLUMN		100									//�б�����
#define SUB_GR_CONFIG_SERVER		101									//��������
#define SUB_GR_CONFIG_PROPERTY		102									//��������
#define SUB_GR_CONFIG_FINISH		103									//�������
#define SUB_GR_CONFIG_USER_RIGHT	104									//���Ȩ��



#define MDM_GR_USER					3									//�û���Ϣ

//�û�����
#define SUB_GR_USER_RULE			1									//�û�����
#define SUB_GR_USER_LOOKON			2									//�Թ�����
#define SUB_GR_USER_SITDOWN			3									//��������
#define SUB_GR_USER_STANDUP			4									//��������
#define SUB_GR_USER_INVITE			5									//�û�����
#define SUB_GR_USER_INVITE_REQ		6									//��������
#define SUB_GR_USER_REPULSE_SIT  	7									//�ܾ��������
#define SUB_GR_USER_KICK_USER       8                                   //�߳��û�
#define SUB_GR_USER_INFO_REQ        9                                   //�����û���Ϣ
#define SUB_GR_USER_CHAIR_REQ       10                                  //�������λ��
#define SUB_GR_USER_CHAIR_INFO_REQ  11                                  //���������û���Ϣ

//�û�״̬
#define SUB_GR_USER_ENTER			100									//�û�����
#define SUB_GR_USER_SCORE			101									//�û�����
#define SUB_GR_USER_STATUS			102									//�û�״̬
#define SUB_GR_REQUEST_FAILURE		103									//����ʧ��

//��������
#define SUB_GR_USER_CHAT			201									//������Ϣ
#define SUB_GR_USER_EXPRESSION		202									//������Ϣ
#define SUB_GR_WISPER_CHAT			203									//˽����Ϣ
#define SUB_GR_WISPER_EXPRESSION	204									//˽�ı���
#define SUB_GR_COLLOQUY_CHAT		205									//�Ự��Ϣ
#define SUB_GR_COLLOQUY_EXPRESSION	206									//�Ự����

//��������
#define SUB_GR_PROPERTY_BUY			300									//�������
#define SUB_GR_PROPERTY_SUCCESS		301									//���߳ɹ�
#define SUB_GR_PROPERTY_FAILURE		302									//����ʧ��
#define SUB_GR_PROPERTY_MESSAGE     303                                 //������Ϣ
#define SUB_GR_PROPERTY_EFFECT      304                                 //����ЧӦ
#define SUB_GR_PROPERTY_TRUMPET		305                                 //������Ϣ
#define SUB_GR_PROPERTY_Consume		306									//��������
#define SUB_GR_CONSUME_SUCCESS		307									//���ѷ���
#define SUB_GR_USE_NOTE_CARDS			308							//ʹ�ü�����	 ����Ϊ�� ʹ�õ���	


//״̬����

#define MDM_GR_STATUS				4									//״̬��Ϣ

#define SUB_GR_TABLE_INFO			100									//������Ϣ
#define SUB_GR_TABLE_STATUS			101									//����״̬



//��������

#define MDM_GR_INSURE				5									//�û���Ϣ

//��������
#define SUB_GR_QUERY_INSURE_INFO	1									//��ѯ����
#define SUB_GR_SAVE_SCORE_REQUEST	2									//������
#define SUB_GR_TAKE_SCORE_REQUEST	3									//ȡ�����
#define SUB_GR_TRANSFER_SCORE_REQUEST	4								//ȡ�����
#define SUB_GR_QUERY_USER_INFO_REQUEST	5								//��ѯ�û�

#define SUB_GR_USER_INSURE_INFO		100									//��������
#define SUB_GR_USER_INSURE_SUCCESS	101									//���гɹ�
#define SUB_GR_USER_INSURE_FAILURE	102									//����ʧ��
#define SUB_GR_USER_TRANSFER_USER_INFO	103								//�û�����
#define SUB_GR_USER_MISSION_INFO		104								//������Ϣ
//#define SUB_GR_USER_MISSION_REWARD		105								//������


//��������

#define MDM_GR_MANAGE				6									//��������

#define SUB_GR_SEND_WARNING			1									//���;���
#define SUB_GR_SEND_MESSAGE			2									//������Ϣ
#define SUB_GR_LOOK_USER_IP			3									//�鿴��ַ
#define SUB_GR_KILL_USER			4									//�߳��û�
#define SUB_GR_LIMIT_ACCOUNS		5									//�����ʻ�
#define SUB_GR_SET_USER_RIGHT		6									//Ȩ������

//��������
#define SUB_GR_QUERY_OPTION			7									//��ѯ����
#define SUB_GR_OPTION_SERVER		8									//��������
#define SUB_GR_OPTION_CURRENT		9									//��ǰ����

#define SUB_GR_LIMIT_USER_CHAT		10									//��������

#define SUB_GR_KICK_ALL_USER		11									//�߳��û�
#define SUB_GR_DISMISSGAME		    12									//��ɢ��Ϸ




//�������

#define MDM_GF_FRAME				100									//�������

//////////////////////////////////////////////////////////////////////////////////
//�������

//�û�����
#define SUB_GF_GAME_OPTION			1									//��Ϸ����
#define SUB_GF_USER_READY			2									//�û�׼��
#define SUB_GF_LOOKON_CONFIG		3									//�Թ�����

//��������
#define SUB_GF_USER_CHAT			10									//�û�����
#define SUB_GF_USER_EXPRESSION		11									//�û�����

//��Ϸ��Ϣ
#define SUB_GF_GAME_STATUS			100									//��Ϸ״̬
#define SUB_GF_GAME_SCENE			101									//��Ϸ����
#define SUB_GF_LOOKON_STATUS		102									//�Թ�״̬

//ϵͳ��Ϣ
#define SUB_GF_SYSTEM_MESSAGE		200									//ϵͳ��Ϣ
#define SUB_GF_ACTION_MESSAGE		201									//������Ϣ



//��Ϸ����

#define MDM_GF_GAME					200									//��Ϸ����

//////////////////////////////////////////////////////////////////////////////////
//Я����Ϣ

//������Ϣ
#define DTP_GR_TABLE_PASSWORD		1									//��������

//�û�����
#define DTP_GR_NICK_NAME			20									//�û��ǳ�
#define DTP_GR_GROUP_NAME			22								//��������
#define DTP_GR_UNDER_WRITE			24									//����ǩ��

//������Ϣ
#define DTP_GR_USER_NOTE			20									//�û���ע
#define DTP_GR_CUSTOM_FACE			21									//�Զ�ͷ��

//////////////////////////////////////////////////////////////////////////////////

//�������
#define REQUEST_FAILURE_NORMAL		0									//����ԭ��
#define REQUEST_FAILURE_NOGOLD		1									//��Ҳ���
#define REQUEST_FAILURE_NOSCORE		2									//���ֲ���
#define REQUEST_FAILURE_PASSWORD	3									//�������

//����ID
#define SUB_C_NOTE_CARD	12						//���������











#define PROCESS_VERSION(cbMainVer,cbSubVer,cbBuildVer)		\
	(unsigned long)(\
	(((unsigned char)(PRODUCT_VER)) << 24) + \
	(((unsigned char)(cbMainVer)) << 16) + \
	((unsigned char)(cbSubVer) << 8) + \
	(unsigned char)(cbBuildVer))

#define _MAKELONG(a, b)      (((a & 0xffff) | (b & 0xffff)) << 16)
#define VER_PLAZA_LOW					1								//�㳡�汾
#define VER_PLAZA_HIGH					1								//�㳡�汾
#define VERSION_PLAZA				_MAKELONG(VER_PLAZA_LOW,VER_PLAZA_HIGH)//PROCESS_VERSION(9,0,3)								//�����汾
#define CountArray(Array)			(sizeof(Array)/sizeof(Array[0]))															//����ά��


//�����ں�
struct TCP_Info
{
	unsigned char							cbDataKind;																			//��������
	unsigned char							cbCheckCode;																		//Ч���ֶ�
	unsigned short							wPacketSize;																		//���ݴ�С
};

//��������
struct TCP_Command
{
	unsigned short							wMainCmdID;																			//��������
	unsigned short							wSubCmdID;																			//��������
};

//�����ͷ
struct TCP_Head
{
	TCP_Info								TCPInfo;																			//�����ṹ
	TCP_Command								CommandInfo;																		//������Ϣ
};

//�ʺŵ�¼
struct CMD_GP_LogonAccounts
{
	//ϵͳ��Ϣ
	DWORD					dwPlazaVersion;								//�㳡�汾
// 	wchar_t							szMachineID[33];							//��������
// 
// 	//��¼��Ϣ
// 	wchar_t							szPassword[33];							     //��¼����
// 	wchar_t							szAccounts[32];								 //��¼�ʺ�

	WORD							szMachineID[33];							//��������

	//��¼��Ϣ
	WORD							szPassword[33];							     //��¼����
	WORD							szAccounts[32];								 //��¼�ʺ�
	char                            szUid[32];                                   //uid
	unsigned char					cbValidateFlags;																		//У���ʶ
};
//ע���ʺŷ�����Ϣ
struct CMD_GP_RegisterAccounts
{
	unsigned int dwPlazaVersion;
	char szMachineID[66];
	char szLogonPass[66];
	char szInsurePass[66];
	unsigned short wFaceID;
	unsigned char cbGender;
	char szAccounts[64];
	char szNickName[64];
	char szSpreader[64];

	char szPassPortID[38];
	char szCompellation[32];
	char szUid[32];
	unsigned char cbValidateFlags;
};
//��Ϸ��������¼������Ϣ
struct CMD_GP_GameAccounts
{
	unsigned int dwPlazaVersion;
	unsigned int dwFrameVersion;
	unsigned int dwProcessVersion;
	unsigned int dwUserID;
	char szPassword[66];
	char szMachineID[66];
	unsigned short wKindID;
	WORD  wTable;
	WORD  wChair;

};
//��������
struct CMD_GR_UserStandUp
{
	unsigned short wTableID;							//����λ��
	unsigned short wChairID;							//����λ��
	unsigned char cbForceLeave;							//ǿ���뿪�����ʱ��false,û���Ʒ�true��
};

//����ӳ��
const unsigned char g_SendByteMap[256] =
{
	0x70, 0x2F, 0x40, 0x5F, 0x44, 0x8E, 0x6E, 0x45, 0x7E, 0xAB, 0x2C, 0x1F, 0xB4, 0xAC, 0x9D, 0x91,
	0x0D, 0x36, 0x9B, 0x0B, 0xD4, 0xC4, 0x39, 0x74, 0xBF, 0x23, 0x16, 0x14, 0x06, 0xEB, 0x04, 0x3E,
	0x12, 0x5C, 0x8B, 0xBC, 0x61, 0x63, 0xF6, 0xA5, 0xE1, 0x65, 0xD8, 0xF5, 0x5A, 0x07, 0xF0, 0x13,
	0xF2, 0x20, 0x6B, 0x4A, 0x24, 0x59, 0x89, 0x64, 0xD7, 0x42, 0x6A, 0x5E, 0x3D, 0x0A, 0x77, 0xE0,
	0x80, 0x27, 0xB8, 0xC5, 0x8C, 0x0E, 0xFA, 0x8A, 0xD5, 0x29, 0x56, 0x57, 0x6C, 0x53, 0x67, 0x41,
	0xE8, 0x00, 0x1A, 0xCE, 0x86, 0x83, 0xB0, 0x22, 0x28, 0x4D, 0x3F, 0x26, 0x46, 0x4F, 0x6F, 0x2B,
	0x72, 0x3A, 0xF1, 0x8D, 0x97, 0x95, 0x49, 0x84, 0xE5, 0xE3, 0x79, 0x8F, 0x51, 0x10, 0xA8, 0x82,
	0xC6, 0xDD, 0xFF, 0xFC, 0xE4, 0xCF, 0xB3, 0x09, 0x5D, 0xEA, 0x9C, 0x34, 0xF9, 0x17, 0x9F, 0xDA,
	0x87, 0xF8, 0x15, 0x05, 0x3C, 0xD3, 0xA4, 0x85, 0x2E, 0xFB, 0xEE, 0x47, 0x3B, 0xEF, 0x37, 0x7F,
	0x93, 0xAF, 0x69, 0x0C, 0x71, 0x31, 0xDE, 0x21, 0x75, 0xA0, 0xAA, 0xBA, 0x7C, 0x38, 0x02, 0xB7,
	0x81, 0x01, 0xFD, 0xE7, 0x1D, 0xCC, 0xCD, 0xBD, 0x1B, 0x7A, 0x2A, 0xAD, 0x66, 0xBE, 0x55, 0x33,
	0x03, 0xDB, 0x88, 0xB2, 0x1E, 0x4E, 0xB9, 0xE6, 0xC2, 0xF7, 0xCB, 0x7D, 0xC9, 0x62, 0xC3, 0xA6,
	0xDC, 0xA7, 0x50, 0xB5, 0x4B, 0x94, 0xC0, 0x92, 0x4C, 0x11, 0x5B, 0x78, 0xD9, 0xB1, 0xED, 0x19,
	0xE9, 0xA1, 0x1C, 0xB6, 0x32, 0x99, 0xA3, 0x76, 0x9E, 0x7B, 0x6D, 0x9A, 0x30, 0xD6, 0xA9, 0x25,
	0xC7, 0xAE, 0x96, 0x35, 0xD0, 0xBB, 0xD2, 0xC8, 0xA2, 0x08, 0xF3, 0xD1, 0x73, 0xF4, 0x48, 0x2D,
	0x90, 0xCA, 0xE2, 0x58, 0xC1, 0x18, 0x52, 0xFE, 0xDF, 0x68, 0x98, 0x54, 0xEC, 0x60, 0x43, 0x0F
};

//����ӳ��
const unsigned char g_RecvByteMap[256] =
{
	0x51, 0xA1, 0x9E, 0xB0, 0x1E, 0x83, 0x1C, 0x2D, 0xE9, 0x77, 0x3D, 0x13, 0x93, 0x10, 0x45, 0xFF,
	0x6D, 0xC9, 0x20, 0x2F, 0x1B, 0x82, 0x1A, 0x7D, 0xF5, 0xCF, 0x52, 0xA8, 0xD2, 0xA4, 0xB4, 0x0B,
	0x31, 0x97, 0x57, 0x19, 0x34, 0xDF, 0x5B, 0x41, 0x58, 0x49, 0xAA, 0x5F, 0x0A, 0xEF, 0x88, 0x01,
	0xDC, 0x95, 0xD4, 0xAF, 0x7B, 0xE3, 0x11, 0x8E, 0x9D, 0x16, 0x61, 0x8C, 0x84, 0x3C, 0x1F, 0x5A,
	0x02, 0x4F, 0x39, 0xFE, 0x04, 0x07, 0x5C, 0x8B, 0xEE, 0x66, 0x33, 0xC4, 0xC8, 0x59, 0xB5, 0x5D,
	0xC2, 0x6C, 0xF6, 0x4D, 0xFB, 0xAE, 0x4A, 0x4B, 0xF3, 0x35, 0x2C, 0xCA, 0x21, 0x78, 0x3B, 0x03,
	0xFD, 0x24, 0xBD, 0x25, 0x37, 0x29, 0xAC, 0x4E, 0xF9, 0x92, 0x3A, 0x32, 0x4C, 0xDA, 0x06, 0x5E,
	0x00, 0x94, 0x60, 0xEC, 0x17, 0x98, 0xD7, 0x3E, 0xCB, 0x6A, 0xA9, 0xD9, 0x9C, 0xBB, 0x08, 0x8F,
	0x40, 0xA0, 0x6F, 0x55, 0x67, 0x87, 0x54, 0x80, 0xB2, 0x36, 0x47, 0x22, 0x44, 0x63, 0x05, 0x6B,
	0xF0, 0x0F, 0xC7, 0x90, 0xC5, 0x65, 0xE2, 0x64, 0xFA, 0xD5, 0xDB, 0x12, 0x7A, 0x0E, 0xD8, 0x7E,
	0x99, 0xD1, 0xE8, 0xD6, 0x86, 0x27, 0xBF, 0xC1, 0x6E, 0xDE, 0x9A, 0x09, 0x0D, 0xAB, 0xE1, 0x91,
	0x56, 0xCD, 0xB3, 0x76, 0x0C, 0xC3, 0xD3, 0x9F, 0x42, 0xB6, 0x9B, 0xE5, 0x23, 0xA7, 0xAD, 0x18,
	0xC6, 0xF4, 0xB8, 0xBE, 0x15, 0x43, 0x70, 0xE0, 0xE7, 0xBC, 0xF1, 0xBA, 0xA5, 0xA6, 0x53, 0x75,
	0xE4, 0xEB, 0xE6, 0x85, 0x14, 0x48, 0xDD, 0x38, 0x2A, 0xCC, 0x7F, 0xB1, 0xC0, 0x71, 0x96, 0xF8,
	0x3F, 0x28, 0xF2, 0x69, 0x74, 0x68, 0xB7, 0xA3, 0x50, 0xD0, 0x79, 0x1D, 0xFC, 0xCE, 0x8A, 0x8D,
	0x2E, 0x62, 0x30, 0xEA, 0xED, 0x2B, 0x26, 0xB9, 0x81, 0x7C, 0x46, 0x89, 0x73, 0xA2, 0xF7, 0x72
};
class NetData
{
public :
	TCP_Command command;
	char pDataBuffer[SOCKET_TCP_BUFFER];
	unsigned short wDataSize;
	char type;
	char readInt8();
	short readInt16();
	int readInt32();

	//again
	BYTE readByte();
	WORD readWORD();
	DWORD readDWORD();


	long long readUInt64();
	double readDouble();
	string readString(int len);
	void positionMove(int len);
};

#pragma pack()

#endif