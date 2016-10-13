#ifndef  _GameDataModel_
#define  _GameDataModel_

#include "cocos2d.h"
#include "BlueSky.h"
#pragma pack(1)

const int pkWidth = 87;					//�ƵĿ�
const int pkHeight = 97;				//�Ƶĸ�
const int pkJianJu2 = 23;				//��������������֮��ļ��



class AlertVO
{
public:
AlertVO(int _type, string _msgParentName, string _msgName, int _enterEventId, int _cancleEventId)
{
type = _type;
msgParentName = _msgParentName;
msgName = _msgName;
enterEventId = _enterEventId;
cancleEventId = _cancleEventId;
};
~AlertVO(){};
string msgParentName;
string msgName;
int type;//0ֻ��ȷ�� 1ȷ����ȡ��
int enterEventId;//���ȷ���׳��¼�id  <0���׳��¼�
int cancleEventId;//���ȡ���׳��¼�id  <0���׳��¼�
};

//��ֵ
enum PokerNum
{
	Two = 0,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	J,
	Q,
	K,
	A,    //12
	B,
	ZhuPai,								//���ֵ�����
	XiaoGui,
	DaGui
};

//��ɫ
enum PokerHuaSe
{
	HeiTao = 0,
	HongXing,
	MeiHua,
	FangKuai,
	Gui
};

//����
struct PokerVO
{
	int pokerNum = -1;							//��ֵ
	int pokerNum2 = -1;							//��ֵ���������Ƿ������ƣ�
	int pokerHuaSe = -1;						//��ɫ
	int pokerID = -1;							//ID
	int pokerID2 = -1;							//��ID
	bool isSelected = false;					//�Ƿ�ѡ��
	bool canSelect = false;						//�Ƿ���Ա�ѡ��
	int deskID = -1;							//�ĸ���ҳ�����
	int isChangePosition = -1;					//�û��Զ���������ƶѣ�������Ϊ-1
	bool isRemoveView = false;					//�Ƿ�����
	bool isGongPai = false;						//�Ƿ��ǹ���
	//����ѡ�������½����꣬�߶ȼ����
	Rect  rect;

};

//�Ƶ�����
class PokerTypeVO
{
public:
	PokerTypeVO(){};
	~PokerTypeVO(){};
	int type;							//1.���� 2.���� 3.3��  4.3��2 5.˳�� 6.���� 7.�ɻ�  8.ը�� 9.ͬ��˳ 10.���
	int value;							//Ȩֵ�����ڱȽ�ͬ�����ƵĴ�С��
	int len;							//�Ƶ�����
	vector<PokerVO*> pokerArr;			//����
};

//����û�
class PlayerVO
{
public:
	PlayerVO(){};
	~PlayerVO(){};
	int uid = -1;								//�û�uid
	int pos = -1;								//��ҵ���λ���
	string name = "";							//��ҵ�����
	int lv = -1;								//��ҵĵȼ�
	int gold = -1;								//��ҵĽ��
	int face = -1;								//��ҵ�������
	vector<PokerVO*> pokerArr;					//��ҵ�����(�Ӵ�С����)
	int pokerNum = -1;							//��ҵ�������
	vector<PokerVO*> outPokerArr;				//��ұ��ֳ�����
	vector<int *> allOutPokerArrID;				//��ұ��ֳ������е��Ƶ�ID
	vector<PokerVO*> selectedPokerArr;			//���ѡ��Ҫ������
	vector<PokerTypeVO> pokerTypeArr;			//��ҵ��������ͣ�ע�⣺��ߵ��������޳�����ӣ�������
	bool isSuccess = false;						//��һ���Ƿ�ʤ��
	bool isNeedToDelete = false;				//�����Ƿ���������
	int quanNum = -1;							//��ҳ����ƺ�������˴�������
	int getPokerID = -1;						//��ұ��ֻ�õĽ���/�ع����Ƶ�ID
	int loginCnt = 1;							//��ҵ�ǰǩ��������
};

//��Ϸ����
struct GameDataVO
{
	int							    bOurSeries = -1;                         //�ҷ�����
	int                             bOtherSeries = -1;                       //�Է�����
	int                             bCurrentSeries = -1;                     //���ּ���
	bool							bLiangPai = false;							//�Ƿ�����
	int								bLiangCard = -1;							//����
	int								cPositionPokerDuiNum = 0;				//��������Զ���������ƶ���
};



class  GameDataModel : public BlueSkyModel
{
public:
	GameDataModel(){};
	~GameDataModel(){};
	static const string NAME;

	//���������Ϣ
	PlayerVO player[4];


	//���汾����Ϸ��Ϣ
	GameDataVO gameData;


	//�Ƴ��Լ����г�������
	void removeMyPokerArr(vector<PokerVO*> arr);

	//�Ƴ��Լ�ѡ��Ҫ������
	void removeMySelectedPokerArr(PokerVO* arr);



	int myuid;
	int recordNum;
};

#endif