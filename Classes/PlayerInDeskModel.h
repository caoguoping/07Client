#ifndef  _PlayerInDeskModel_
#define  _PlayerInDeskModel_

#include "cocos2d.h"
#include "BlueSky.h"
#include "SGTools.h"
#pragma pack(1)


struct OnDesk
{
	DWORD dwUserID;
	WORD  wTableID;
	WORD  wChairID;
	BYTE cbUserStatus;
};

struct OnDeskPlayerInfo
{
	DWORD dwGameID;//游戏 I D
	DWORD dwUserID;//用户 I D
	DWORD dwGroupID;//社团 I D
	WORD wFaceID;//头像索引
	DWORD dwCustomID;//自定标识
	BYTE cbGender;//用户性别
	BYTE cbMemberOrder;//会员等级
	BYTE cbMasterOrder;//管理等级
	WORD wTableID;//桌子索引
	WORD wChairID;//椅子索引
	BYTE cbUserStatus;//用户状态
	SCORE lScore;//用户分数
	SCORE lGrade;//用户成绩
	SCORE lInsure;//用户银行

	DWORD dwWinCount;//盘数
	DWORD dwLostCount;//失败盘数
	DWORD dwDrawCount;//和局盘数
	DWORD dwFleeCount;//逃跑盘数
	DWORD dwUserMedal;//用户奖牌
	DWORD dwExperience;//用户经验
	DWORD lLoveLiness;//用户魅力
	WORD nick1;
	WORD nick2;

	string szNickName;//10--
	string szGroupName;//11--
	string szUnderWrite;//12--
	bool isClear = true;   //false 需要显示 true 不显示
};

class PlayerInDeskModel : public BlueSkyModel
{
public:
	PlayerInDeskModel(){};
	~PlayerInDeskModel(){};
	static const string NAME;

	//上座的玩家信息
	OnDeskPlayerInfo DeskPlayerInfo[4]; //下标为服务器ID



	OnDeskPlayerInfo FruitPlayer;
	int chair[4];   //服务器椅子ID    下标为服务器Id, 值为客户端ID
	//清理玩家信息
	void clean();
	
	//根据玩家的客户端椅子ID获取玩家的服务器椅子ID
	int getServiceChairID(int clientID);


	//比赛场次 SessionSelectMediator中测试使用 之后需根据服务器发来的值赋值
	int ccNun;
	int wKindID;
};

#endif