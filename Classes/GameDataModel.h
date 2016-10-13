#ifndef  _GameDataModel_
#define  _GameDataModel_

#include "cocos2d.h"
#include "BlueSky.h"
#pragma pack(1)

const int pkWidth = 87;					//牌的宽
const int pkHeight = 97;				//牌的高
const int pkJianJu2 = 23;				//出的牌中牌与牌之间的间距



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
int type;//0只有确定 1确定、取消
int enterEventId;//点击确定抛出事件id  <0不抛出事件
int cancleEventId;//点击取消抛出事件id  <0不抛出事件
};

//牌值
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
	ZhuPai,								//本轮的主牌
	XiaoGui,
	DaGui
};

//花色
enum PokerHuaSe
{
	HeiTao = 0,
	HongXing,
	MeiHua,
	FangKuai,
	Gui
};

//卡牌
struct PokerVO
{
	int pokerNum = -1;							//牌值
	int pokerNum2 = -1;							//牌值（不计算是否是主牌）
	int pokerHuaSe = -1;						//花色
	int pokerID = -1;							//ID
	int pokerID2 = -1;							//子ID
	bool isSelected = false;					//是否被选中
	bool canSelect = false;						//是否可以被选中
	int deskID = -1;							//哪个玩家出的牌
	int isChangePosition = -1;					//用户自定义排序的牌堆，不是则为-1
	bool isRemoveView = false;					//是否被弃用
	bool isGongPai = false;						//是否是贡牌
	//触摸选区的左下角坐标，高度及宽度
	Rect  rect;

};

//牌的类型
class PokerTypeVO
{
public:
	PokerTypeVO(){};
	~PokerTypeVO(){};
	int type;							//1.单张 2.对子 3.3张  4.3带2 5.顺子 6.连队 7.飞机  8.炸弹 9.同花顺 10.火箭
	int value;							//权值（用于比较同类型牌的大小）
	int len;							//牌的数量
	vector<PokerVO*> pokerArr;			//牌组
};

//玩家用户
class PlayerVO
{
public:
	PlayerVO(){};
	~PlayerVO(){};
	int uid = -1;								//用户uid
	int pos = -1;								//玩家的座位编号
	string name = "";							//玩家的名字
	int lv = -1;								//玩家的等级
	int gold = -1;								//玩家的金币
	int face = -1;								//玩家的形象编号
	vector<PokerVO*> pokerArr;					//玩家的手牌(从大到小排序)
	int pokerNum = -1;							//玩家的手牌数
	vector<PokerVO*> outPokerArr;				//玩家本轮出的牌
	vector<int *> allOutPokerArrID;				//玩家本局出的所有的牌的ID
	vector<PokerVO*> selectedPokerArr;			//玩家选的要出的牌
	vector<PokerTypeVO> pokerTypeArr;			//玩家的手牌类型，注意：这边的牌型中剔除了癞子！！！！
	bool isSuccess = false;						//上一轮是否胜利
	bool isNeedToDelete = false;				//本局是否与玩家相关
	int quanNum = -1;							//玩家出完牌后的其他人打牌轮数
	int getPokerID = -1;						//玩家本局获得的进贡/回贡的牌的ID
	int loginCnt = 1;							//玩家当前签到的天数
};

//游戏数据
struct GameDataVO
{
	int							    bOurSeries = -1;                         //我方级数
	int                             bOtherSeries = -1;                       //对方级数
	int                             bCurrentSeries = -1;                     //本局级数
	bool							bLiangPai = false;							//是否亮牌
	int								bLiangCard = -1;							//亮牌
	int								cPositionPokerDuiNum = 0;				//本局玩家自定义排序的牌堆数
};



class  GameDataModel : public BlueSkyModel
{
public:
	GameDataModel(){};
	~GameDataModel(){};
	static const string NAME;

	//储存玩家信息
	PlayerVO player[4];


	//储存本局游戏信息
	GameDataVO gameData;


	//移除自己手中出掉的牌
	void removeMyPokerArr(vector<PokerVO*> arr);

	//移除自己选的要出的牌
	void removeMySelectedPokerArr(PokerVO* arr);



	int myuid;
	int recordNum;
};

#endif