#ifndef  _PlayerInDeskModel_
#define  _PlayerInDeskModel_

#include "cocos2d.h"
#include "BlueSky.h"
#pragma pack(1)


struct OnDesk
{
	unsigned int dwUserID;
	unsigned short wTableID;
	unsigned short wChairID;
	unsigned char cbUserStatus;
};

struct OnDeskPlayerInfo
{
	unsigned int dwGameID;//游戏 I D
	unsigned long dwUserID;//用户 I D

	unsigned int dwGroupID;//社团 I D

	unsigned int wFaceID;//头像索引
	unsigned int dwCustomID;//自定标识
	unsigned int cbGender;//用户性别
	unsigned int cbMemberOrder;//会员等级

	unsigned int cbMasterOrder;//管理等级

	unsigned int wTableID;//桌子索引
	unsigned int wChairID;//椅子索引
	unsigned int cbUserStatus;//用户状态

	long long lScore;//用户分数
	long long lGrade;//用户成绩
	long long lInsure;//用户银行

	unsigned int dwWinCount;//盘数
	unsigned int dwLostCount;//失败盘数
	unsigned int dwDrawCount;//和局盘数
	unsigned int dwFleeCount;//逃跑盘数

	unsigned int dwUserMedal;//用户奖牌

	unsigned int dwExperience;//用户经验
	unsigned int lLoveLiness;//用户魅力

	string szNickName;//10--
	string szGroupName;//11--
	string szUnderWrite;//12--

	unsigned int nick1;
	unsigned int nick2;

	bool isClear = true;   //false 需要显示 true 不显示
};

class PlayerInDeskModel : public BlueSkyModel
{
public:
	PlayerInDeskModel(){};
	~PlayerInDeskModel(){};
	static const string NAME;

	//上座的玩家信息
	OnDeskPlayerInfo DeskPlayerInfo[4];



	OnDeskPlayerInfo FruitPlayer;
	int chair[4];   //服务器椅子ID
	//清理玩家信息
	void clean();
	
	//根据玩家的客户端椅子ID获取玩家的服务器椅子ID
	int getServiceChairID(int clientID);


	//比赛场次 SessionSelectMediator中测试使用 之后需根据服务器发来的值赋值
	int ccNun;
	int wKindID;
};

#endif