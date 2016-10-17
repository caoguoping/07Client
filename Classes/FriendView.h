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
		esInvite = 0,   //����
		esAgree,        //
		esRefuse,
		esDelete,
	};

	/*
		-- 0  ����  -- �Ѿ�����
		-- 1  ����  -- ����ɹ�
		-- 2  ����  -- ����ʧ��

		-- 3  ͬ��	 -- ��Ӻ��ѳɹ�
		-- 4  ͬ��	 -- �Ѿ��Ǻ��ѹ�ϵ
		-- 5  ͬ��	 -- ��Ӻ���ʧ��

		-- 6  �ܾ�	 -- �����������ϵ
		-- 7  �ܾ�   -- �ܾ��ɹ�
		-- 8  �ܾ�   -- �ܾ�ʧ��

		-- 9  ɾ��	 -- �����ں��ѹ�ϵ
		-- 10 ɾ��   -- ɾ���ɹ�
		-- 11 ɾ��   -- ɾ��ʧ��
		*/
	enum ec_FriendOption  //����
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
	DWORD   dwSearchUserId;  //���ҵõ���UserId
	Layout*  laySearch;
	Layout*  layPush;

	//rank
	CheckBox*   chkRanks[E_RankMax];    
	ListView*   lstRank;  

	int currentTitle;
	Text* txtDiamond;  //��ʯ
	Text* txtGold;     //���


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


	//���Һ���
	void clickSearch(Ref* pSender);
	void showSearchResult(WORD wFaceId, std::string szNickName);
	void clickOneKeyAdd(Ref* pSender);
	void clickRefind(Ref* pSender);
	void clickSearchAdd(Ref* pSender);


	//��������

	void clickOneAgree(Ref* pSender);
	void clickOneRefuse(Ref* pSender);


	//handle
	void handleFriendOptMe(void* data);
	void handleFriendOptHim(void* data);

	BTN_TOUCH_HANDLE(Button, closeBtn, 12301);

};

#endif