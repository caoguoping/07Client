#ifndef  _Frined_View_H_
#define  _Frined_View_H_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "DataManager.h"

class  FriendView : public BlueSkyView
{
public:
	typedef enum FriendsItem
	{
		E_friends = 0,   //
		E_familiar,        //
		E_ranks,          
		E_frinedsItemMax,

	}E_FriendsItem;

	typedef enum RankItem
	{
		E_RankCaifu = 0,   //
		E_RankMeiLi,        //
		E_RankShenglv,
		E_RankMax,

	}E_RankItem;


	enum es_FriendOption
	{
		esInvite = 0,   //邀请
		esAgree,        //
		esRefuse,
		esDelete,
	};

	/*
		-- 0  邀请  -- 已经邀请
		-- 1  邀请  -- 邀请成功
		-- 2  邀请  -- 邀请失败

		-- 3  同意	 -- 添加好友成功
		-- 4  同意	 -- 已经是好友关系
		-- 5  同意	 -- 添加好友失败

		-- 6  拒绝	 -- 不存在邀请关系
		-- 7  拒绝   -- 拒绝成功
		-- 8  拒绝   -- 拒绝失败

		-- 9  删除	 -- 不存在好友关系
		-- 10 删除   -- 删除成功
		-- 11 删除   -- 删除失败
		*/
	enum ec_FriendOption  //接收
	{
		ecInviteAlready = 0,
		ecInviteSuccess,
		ecInviteFail,
		ecAgreeSuccess,
		ecAgreeAlready,
		ecAgreeFail,
		ecRefuseNot,
		ecRefuseSuccess,
		ecRefuseFail,
		ecDeleteNot,
		ecDeleteSuccess,
		ecDeleteFail,
	};

	Node*    ndPublicTop;
	Node*    ndFriends[E_frinedsItemMax];
	CheckBox* chkFriends[E_frinedsItemMax];



	//friendsList
	Text*   txtFriendsNow;
	Text*   txtFriendsMax;
	ListView*  lstFriendsList;

	//find
	TextField*  txfFind;
	ListView*  lstShuRen;
	ListView*  lstPush;


	//find search
	Node*  ndSearch;
	ImageView*  imgSchHead;
	Text*   txtSchName;
	DWORD   dwSearchUserId;  //查找得到的UserId
	Layout*  laySearch;
	Layout*  layPush;

	//rank
	CheckBox*   chkRanks[E_RankMax];    
	ListView*   lstRank;  

	int currentTitle;
	Text* txtDiamond;  //钻石
	Text* txtGold;     //金币


public:
	FriendView();
	~FriendView();
	void initView();
	void refreshShuren();
	void turningPage(Ref* psender, PageView::EventType type);
	void setCurrentPage(int currentPage);

	void clickFriends(Ref*  pSender);
	void clickShuRen(Ref*  pSender);
	void clickRank(Ref*  pSender);


	void clickRankCaiFu(Ref*  pSender);
	void clickRankMeiLi(Ref*  pSender);
	void clickRankShengLv(Ref*  pSender);
	
	void showFriends();
	void showShuRen();
	void showPushFriends();
	void showRanks(DWORD dwWhich);
	void showCaiFuRank();


	void clickShuRenAdd(Ref*  pSender);   //shuren add Friends


	//查找好友
	void clickSearch(Ref* pSender);
	void showSearchResult(WORD wFaceId, std::string szNickName);
	void clickOneKeyAdd(Ref* pSender);
	void clickRefind(Ref* pSender);
	void clickSearchAdd(Ref* pSender);


	//好友推送

	void clickOneAgree(Ref* pSender);
	void clickOneRefuse(Ref* pSender);


	//handle
	void handleFriendOptMe(void* data);
	void handleFriendOptHim(void* data);

	BTN_TOUCH_HANDLE(Button, closeBtn, 12301);

};

#endif