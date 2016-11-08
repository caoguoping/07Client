#ifndef  _PokerGameModel_
#define  _PokerGameModel_

#include "cocos2d.h"
#include "BlueSky.h"
#include "SGTools.h"
#pragma pack(1)


//��Ʒ��ȡ��ʾ
struct MessageVO
{
	int type = -1;														//1�������ʯ��2����ý�ң�3����õ���
	string name;														//��ʯ��ҵ����������ߵ�����
};

struct CMD_S_GameStart
{
	unsigned short					wBankerUser;						//ׯ���û�
	unsigned short				 	wCurrentUser;						//��ǰ���
	unsigned int					cbCardData[27];						//�˿��б�
	unsigned int					bOurSeries;                         //�ҷ�����
	unsigned int                    bOtherSeries;                       //�Է�����
	unsigned int                    bCurrentSeries;                     //���ּ���
	int								m_iGameResult[4];                   //ʤ�����
	unsigned int					RoomType;							//��������
	unsigned short                  wServerType;						//����������
	bool							bLiangPai;							//�Ƿ�����
	unsigned int					bLiangCard;							//����
};
//�������ݰ�
struct CMD_C_OutCard
{
	unsigned char					bCardCount;							//������Ŀ
	unsigned char					bCardData[27];						//�˿��б�
};
//�û�����
struct CMD_S_OutCard
{
	unsigned char					bCardCount;							//�˿���Ŀ
	unsigned short					wCurrentUser;						//��ǰ���(���������Ƶ����)
	unsigned short					wOutCardUser;						//������ң��ĸ���ҳ����ƣ�
	unsigned char					bCardData[27];						//�˿��б�
};
//��������
struct CMD_S_PassCard
{
	unsigned char					bNewTurn;							//һ�ֿ�ʼ
	unsigned short				 	wPassUser;							//�������
	unsigned short				 	wCurrentUser;						//��ǰ���
};
//�û�����
struct CMD_C_PayTribute
{
	unsigned int                     bPayType;							//��������  1���� 2�ع� 
	unsigned short                   wUser;                              //�����û�
	unsigned short                   wToUser;							//�ܽ����ߣ�������0���ع���Ҫ���ܻع�������ID��
	unsigned char                    bCard;                              //�����˿�
};
//�û�����
struct CMD_S_PayTribute
{
	//ֻ��ǰ��������~
	unsigned char                    bPayType[4];						//�������ͣ�2���� 1�ܹ� 0�ޣ�
	unsigned int					 bPayStatus;						//�����׶� 0�� 1���� 2�ع� 3��ȡ�ع� 4����
	unsigned short                   wFromUser;                          //�����û�
	unsigned short                   wToUser;                            //�������û�����
	unsigned short                   wCurrentUser;                       //��ǰ��ң�˭��һ�����ƣ�
	unsigned char                    bCard;                              //�����˿�
};
//��Ϸ����
struct CMD_S_GameEnd
{
	DWORD							lGameTax;							//��Ϸ˰��
	DWORD							lGameScore[4];						//��Ϸ����
	BYTE					bCardCount[4];						//�˿���Ŀ
	BYTE					bCardData[108];						//�˿��б�
	BYTE                   bOurSeries;                         //�ҷ�����
	BYTE                   bOtherSeries;                       //�Է�����
	BYTE                   bCurrentSeries;                     //���ּ���
	int                             m_iGameResult[4];                   //ʤ�����
	int								Rank[4];	//ֵΪ��������λ�ţ� �±�Ϊ����						//�������
	BYTE              bIsBlood;    //0������������   1��Ѫս������

};

//�û�����
struct CMD_GR_C_UserExpression
{
	unsigned short					wItemIndex;							//��������
	long							dwTargetUserID;						//Ŀ���û�
};

//�û�����
struct CMD_GR_S_UserExpression
{
	unsigned short					wItemIndex;							//��������
	long							dwSendUserID;						//�����û�
	long							dwTargetUserID;						//Ŀ���û�
};

//���߶���
struct DAO_JU_ACTION
{
	int								index = -1;							//��������
	int								toDesk = -1;						//Ŀ���������ID
	int								id = -1;
};

//ǩ����ѯ
struct DBO_GP_Seven_Logon
{
	unsigned long					dwUserID;							//�û���ʶ
	unsigned short					LogonCnt;							//ǩ������
};

//�̳���Ʒ
struct SHOP_GOOD
{
	//������Ϣ
	unsigned short					wIndex;								//���߱�ʶ
	//string							szPropertyName = "1";				//��������
	unsigned short					wDiscount;							//��Ա�ۿ�
	unsigned short					wIssueArea;							//������Χ

	//���ۼ۸�
	long long						lPropertyGold;						//���߽��
	double							dPropertyCash;						//���߼۸�

	//��������
	long long						lSendLoveLiness;					//��������
	long long						lRecvLoveLiness;					//��������
};

//�û�����
struct DBR_GR_WriteUserMissionRes
{
	unsigned short							wKindId;							//����ID
	unsigned long							dwUserID;							//�û���ʶ
	unsigned short							wMissionId;							//����ID
	unsigned long							dwValue;							//��ɴ���
	//SYSTEMTIME							Time;								//���ʱ��
	unsigned short							Complete;							//�������
};

//�û�����
struct DBR_GR_UserLogonMissionRes
{
	unsigned short							wKindId;							//����ID
	unsigned long							dwUserID;							//�û���ʶ
	unsigned short							wMissionId;							//����ID
	unsigned long							dwValue;							//��ɴ���
	//SYSTEMTIME						    Time;								//���ʱ��
	unsigned short							Complete;							//�������	0- �Ѿ����  1-  δ���
	unsigned short							Receive;							//��ɱ�־  1 - �Ѿ���ȡ 0 -δ��ȡ
};


//��������ȡ
struct CMD_GR_UerMissionRec
{
	unsigned long							dwUserID;							//�û� I D
	unsigned short							wMissionId;							//����ID
	unsigned short							wKindID;							//����ID
};
//������
struct CMD_GR_GetMissionRewardRec
{
	unsigned short							flag;								//1-- �ɹ� 2 -- ʧ��
	unsigned short							wMissionId;							//����ID
	unsigned short							Score;								//�������
	unsigned short							KindID;								//����ID(����ID)
	unsigned short							PropCnt;							//���߸���
};
//��Ҳ���
struct CMD_GP_UserAddandSubScore
{
	unsigned long							dwUserID;							//�û� I D
	unsigned long							lSaveScore;							//������
	unsigned short							time;								//�齱����
};
// �齱����
// struct CMD_GP_User_Gambling
// {
// 	unsigned long							dwUserID;							//�û� I D
// 	unsigned long							Gambling;							//����	I D
// 	unsigned long							Currency;							//�û���ʯ
// 	unsigned long							GamblingCnt;						//�齱����
// };

//�齱����
struct CMD_GP_User_Gambling
{
	unsigned int							dwUserID;							//�û� I D
	unsigned short							Gambling;							//����	I D
	unsigned short							GamblingCnt;						//�齱����
	unsigned short                          diamondNum;                         //��ʯ
};
//��������
struct Package_Item
{
	unsigned long							dwPropID;							//����ϵͳID,��ʾ��Ʒ
	unsigned short							wPropCount;							//���߸���
	unsigned short							wKindID;							//����ID
};
//�����̳ǵ���
struct Buy_Mall_Item
{
	unsigned long							dwUserID;							//�û�ID
	unsigned short							wPropCount;							//�������
	unsigned short							wKindID;							//����ID
};
//����ʹ��
struct DBR_GR_UseProperty
{
	unsigned long							dwUserID;							//�û� I D
	unsigned short							wPropertyIndex;						//��������
	unsigned short							wItemCount;							//ʹ����Ŀ
	unsigned long							dwTargetUserID;						//ʹ�ö���
	unsigned char							cbRequestArea;			            //ʹ�÷�Χ 
};
//���߳ɹ�
struct CMD_GR_S_PropertySuccess
{
	unsigned char                           cbRequestArea;						//ʹ�û���
	unsigned short							wItemCount;							//������Ŀ
	unsigned short							wPropertyIndex;						//��������
	unsigned long							dwSourceUserID;						//Ŀ�����
	unsigned long							dwTargetUserID;						//ʹ�ö���
};

//��������
struct DBR_GR_PropertyConsume
{
	unsigned short							wPropertyIndex;						//��������
	unsigned short							wKindID;							//����ID
	unsigned long							dwUserID;							//�û� I D
	long long								lScore;								//���ѻ���
	unsigned short							resultID;							//���ID
};

//3, 1006����
//3, 1007��Ӧ

//�������а�
struct tagCupRanking
{

	unsigned int							dwUserID;						//�û�ID
	std::string						szNickName;			//�û��ǳ�
	unsigned short								cLevel;								//�û��ȼ�
	unsigned short								cExp;									//�û�����ֵ
	unsigned short                               faceId;
};

struct tagCupRankingInfos
{
	unsigned short						dwNum;					//����Ŀ
	tagCupRanking			dwRankingInfos[30];			//30��
};

//����
struct CMD_GP_CupInfo
{
	unsigned int                           openTime;      //����ʱ��
	unsigned int							dwUserID;
	unsigned short								cLevel;
	unsigned short								cExp;
	unsigned short								awards;
	tagCupRankingInfos						rankingInfo;

};

//��������
struct CMD_GP_CupAwards
{
	unsigned int						dwUserID;
	unsigned short						flag;   // ����Ƿ�ɹ���ȡ 1 -- �ɹ�  2 -- ʧ��
	unsigned short						dwIndex;	
	unsigned short						dwAwards;
};

struct CMD_GROWTH_INFO
{
	unsigned int dwUserID;
	unsigned short  wIndex;
};




//��������
struct CMD_GR_Match_Num
{
	unsigned int							dwWaitting;							//�ȴ�����
	unsigned int							dwTotal;							//��������
	unsigned int							dwMatchTotal;						//������
};

//��������  ��������
struct CMD_GR_UserSitDown
{
	unsigned short							wTableID;							//����λ��
	unsigned short							wChairID;							//����λ��
	unsigned short							szPassword[33];			//��������
};


//�û�����   3 , 104	
//�û�����
struct tagUserScore
{
	//������Ϣ
	SCORE							lScore;								//�û�����
	SCORE							lGrade;								//�û��ɼ�
	SCORE							lInsure;							//�û�����

	//��Ӯ��Ϣ
	DWORD							dwWinCount; 
	DWORD							dwLostCount;						//ʧ������
	DWORD							dwDrawCount;						//�;�����
	DWORD							dwFleeCount;						//��������

	//ȫ����Ϣ
	DWORD							dwUserMedal;						//�û�����
	DWORD							dwExperience;						//�û�����
	LONG							lLoveLiness;						//�û�����
};

struct CMD_GR_UserScore
{
	DWORD							dwUserID;							//�û���ʶ
	tagUserScore					UserScore;							//������Ϣ
	WORD								wMatchScore;					//��������
};


//3   105  ʣ��������Ŀ
//WORD

//3  106  ���а�

struct Match_Ranking_Item
{
	DWORD			dwUserID;    //����ǳ� 
	string        szSendNickName;
	WORD				wMatchScore;				//��������
	WORD	            wRankingID;					//��������
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
	CMD_S_OutCard playerOutCard;//��һ����ҳ�����Ϣ
	

	//����������Ϣ
	vector<DBR_GR_UserLogonMissionRes> dailyMisInfo;

	//�����̳���Ʒ��Ϣ
	vector<SHOP_GOOD> mallGoodsInfo;

	//���汳��������Ϣ
	vector<Package_Item> packageItem;
	int jipaiqiNum;    //����������

	CMD_GR_Match_Num  num_info;		//��ǰ��������

	static const string NAME;
};


#endif