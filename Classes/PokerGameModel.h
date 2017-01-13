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
	WORD					wBankerUser;						//ׯ���û�
	WORD				 	wCurrentUser;						//��ǰ���
	DWORD					cbCardData[27];						//�˿��б�
	DWORD					bOurSeries;                         //�ҷ�����
	DWORD                    bOtherSeries;                       //�Է�����
	DWORD                    bCurrentSeries;                     //���ּ���
	int								m_iGameResult[4];                   //ʤ�����
	DWORD					RoomType;							//��������
	WORD                  wServerType;						//����������
	bool							bLiangPai;							//�Ƿ�����
	DWORD					bLiangCard;							//����
};
//�������ݰ�
struct CMD_C_OutCard
{
	BYTE					bCardCount;							//������Ŀ
	BYTE					bCardData[27];						//�˿��б�
};
//�û�����
struct CMD_S_OutCard
{
	BYTE					bCardCount;							//�˿���Ŀ
	WORD					wCurrentUser;						//��ǰ���(���������Ƶ����)
	WORD					wOutCardUser;						//������ң��ĸ���ҳ����ƣ�
	BYTE					bCardData[27];						//�˿��б�
};
//��������
struct CMD_S_PassCard
{
	BYTE					bNewTurn;							//һ�ֿ�ʼ
	WORD				 	wPassUser;							//�������
	WORD				 	wCurrentUser;						//��ǰ���
//	WORD					wJieFeng;                           //1�ӷ磬  0���ǽӷ�
};
//�û�����
struct CMD_C_PayTribute
{
	DWORD                     bPayType;							//��������  1���� 2�ع� 
	WORD                   wUser;                              //�����û�
	WORD                   wToUser;							//�ܽ����ߣ�������0���ع���Ҫ���ܻع�������ID��
	BYTE                    bCard;                              //�����˿�
};
//�û�����
struct CMD_S_PayTribute
{
	//ֻ��ǰ��������~
	BYTE                    bPayType[4];						//�������ͣ�2���� 1�ܹ� 0�ޣ�
	DWORD					 bPayStatus;						//�����׶� 0�� 1���� 2�ع� 3��ȡ�ع� 4����
	WORD                   wFromUser;                          //�����û�
	WORD                   wToUser;                            //�������û�����
	WORD                   wCurrentUser;                       //��ǰ��ң�˭��һ�����ƣ�
	BYTE                    bCard;                              //�����˿�
};
//��Ϸ����
struct CMD_S_GameEnd
{
	int							lGameTax;							//��Ϸ˰��
	int							lGameScore[4];						//��Ϸ����
	BYTE					bCardCount[4];						//�˿���Ŀ
	BYTE					bCardData[108];						//�˿��б�
	BYTE                   bOurSeries;                         //�ҷ�����
	BYTE                   bOtherSeries;                       //�Է�����
	BYTE                   bCurrentSeries;                     //���ּ���
    BYTE              bIsBlood;    //0������������   1��Ѫս������
    
    int                             m_iGameResult[4];                   //ʤ�����
	int								Rank[4];	//ֵΪ��������λ�ţ� �±�Ϊ����						//�������


};

//�û�����
struct CMD_GR_C_UserExpression
{
	WORD					wItemIndex;							//��������
	DWORD							dwTargetUserID;						//Ŀ���û�
};

//�û�����
struct CMD_GR_S_UserExpression
{
	WORD					wItemIndex;							//��������
	DWORD							dwSendUserID;						//�����û�
	DWORD							dwTargetUserID;						//Ŀ���û�
};

//���߶���
struct DAO_JU_ACTION
{
	WORD								index ;							//��������
	WORD                                fromDesk;       //˭�ӵ�
	WORD								toDesk;						//Ŀ���������ID
	WORD								id;         //actionId
	
};



//�̳���Ʒ
struct SHOP_GOOD
{
	//������Ϣ
	WORD					wIndex;								//���߱�ʶ
	//string							szPropertyName = "1";				//��������
	WORD					wDiscount;							//��Ա�ۿ�
	WORD					wIssueArea;							//������Χ

	//���ۼ۸�
	SCORE						lPropertyGold;						//���߽��
	double							dPropertyCash;						//���߼۸�

	//��������
	SCORE						lSendLoveLiness;					//��������
	SCORE						lRecvLoveLiness;					//��������
};

//�û�����
struct DBR_GR_WriteUserMissionRes
{
	WORD							wKindId;							//����ID
	DWORD							dwUserID;							//�û���ʶ
	WORD							wMissionId;							//����ID
	DWORD							dwValue;							//��ɴ���
	//SYSTEMTIME							Time;								//���ʱ��
	WORD							Complete;							//�������
};

//�û�����
struct DBR_GR_UserLogonMissionRes
{
	WORD							wKindId;							//����ID
	DWORD							dwUserID;							//�û���ʶ
	WORD							wMissionId;							//����ID
	DWORD							dwValue;							//��ɴ���
	//SYSTEMTIME						    Time;								//���ʱ��
	WORD							Complete;							//�������	0- �Ѿ����  1-  δ���
	WORD							Receive;							//��ɱ�־  1 - �Ѿ���ȡ 0 -δ��ȡ
};


//��������ȡ
struct CMD_GR_UerMissionRec
{
	DWORD							dwUserID;							//�û� I D
	WORD							wMissionId;							//����ID
	WORD							wKindID;							//����ID
};
//������
struct CMD_GR_GetMissionRewardRec
{
	WORD							flag;								//1-- �ɹ� 2 -- ʧ��
	WORD							wMissionId;							//����ID
	WORD							Score;								//�������
	WORD							KindID;								//����ID(����ID)
	WORD							PropCnt;							//���߸���
};
//��Ҳ���
struct CMD_GP_UserAddandSubScore
{
	DWORD							dwUserID;							//�û� I D
	DWORD							lSaveScore;							//������
	WORD							time;								//�齱����
};
// �齱����
// struct CMD_GP_User_Gambling
// {
// 	DWORD							dwUserID;							//�û� I D
// 	DWORD							Gambling;							//����	I D
// 	DWORD							Currency;							//�û���ʯ
// 	DWORD							GamblingCnt;						//�齱����
// };

//�齱����
struct CMD_GP_User_Gambling
{
	DWORD							dwUserID;							//�û� I D
	WORD							Gambling;							//����	I D
	WORD							GamblingCnt;						//�齱����
	WORD                          diamondNum;                         //��ʯ
};
//��������
struct Package_Item
{
	DWORD							dwPropID;							//����ϵͳID,��ʾ��Ʒ
	WORD							wPropCount;							//���߸���
	WORD							wKindID;							//����ID
};
//�����̳ǵ���
struct Buy_Mall_Item
{
	DWORD							dwUserID;							//�û�ID
	WORD							wPropCount;							//�������
	WORD							wKindID;							//����ID
};
//����ʹ��
struct DBR_GR_UseProperty
{
	DWORD							dwUserID;							//�û� I D
	WORD							wPropertyIndex;						//��������
	WORD							wItemCount;							//ʹ����Ŀ
	DWORD							dwTargetUserID;						//ʹ�ö���
	BYTE							cbRequestArea;			            //ʹ�÷�Χ 
};
//���߳ɹ�
struct CMD_GR_S_PropertySuccess
{
	BYTE                           cbRequestArea;						//ʹ�û���
	WORD							wItemCount;							//������Ŀ
	WORD							wPropertyIndex;						//��������
	DWORD							dwSourceUserID;						//Ŀ�����
	DWORD							dwTargetUserID;						//ʹ�ö���
};

//��������
struct DBR_GR_PropertyConsume
{
	WORD							wPropertyIndex;						//��������
	WORD							wKindID;							//����ID
	DWORD							dwUserID;							//�û� I D
	SCORE								lScore;								//���ѻ���
	WORD							resultID;							//���ID
};

//3, 1006����
//3, 1007��Ӧ

//�������а�
struct tagCupRanking
{

	DWORD							dwUserID;						//�û�ID
	std::string						szNickName;			//�û��ǳ�
	WORD								cLevel;								//�û��ȼ�
	WORD								cExp;									//�û�����ֵ
	WORD                               faceId;
};

struct tagCupRankingInfos
{
	WORD						dwNum;					//����Ŀ
	tagCupRanking			dwRankingInfos[30];			//30��
};

//����
struct CMD_GP_CupInfo
{
	DWORD                           openTime;      //����ʱ��
	DWORD							dwUserID;
	WORD								cLevel;
	WORD								cExp;
	WORD								awards;
	tagCupRankingInfos						rankingInfo;

};

//��������
struct CMD_GP_CupAwards
{
	DWORD						dwUserID;
	WORD						flag;   // ����Ƿ�ɹ���ȡ 1 -- �ɹ�  2 -- ʧ��
	WORD						dwIndex;	
	WORD						dwAwards;
};

struct CMD_GROWTH_INFO
{
	DWORD dwUserID;
	WORD  wIndex;
};




//��������
struct CMD_GR_Match_Num
{
	DWORD							dwWaitting;							//�ȴ�����
	DWORD							dwTotal;							//��������
	DWORD							dwMatchTotal;						//������
};

//��������  ��������
struct CMD_GR_UserSitDown
{
	WORD							wTableID;							//����λ��
	WORD							wChairID;							//����λ��
	WORD							szPassword[33];			//��������
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
