#ifndef __SendDataService__
#define __SendDataService__
#include "iostream"
#include "head.h"
#include "BlueSky.h"
#include "EventType.h"

#include "PokerGameModel.h"
#include "DataManager.h"
#include "PlayerInDeskModel.h"
#include "SGTools.h"

using namespace std;
class SendDataService :public BlueSkyService
{
public:
	SendDataService(){};
	~SendDataService(){};
	static const string NAME;
	void sendUserYbToGold(DWORD	dwUserID, int num, int wKindID);
	void sendLogin(const char* Accounts, const char* Password, const char* MachineID);
	void sendRegister(const char* szLogonPass, int wFaceID, int cbGender, const char* szAccounts, const char*  szNickName);
	void sendGameServerLogin(DWORD dwUserID, const char* szLogonPass, WORD wKindID);
	void sendReady();
	void sendOutPoker(BYTE bCardCount, BYTE bCardData[27]);
	void sendNotOutPoker();
	void sendPayTribute(DWORD bPayType,WORD wUser,WORD wToUser,BYTE bCard);
	void sendLeaveTable(WORD wTableID, WORD wChairID, BYTE cbForceLeave);
	void sendChat(WORD wItemIndex, DWORD dwTargetUserID);
	void sendSevenLogin(DWORD dwUserID, WORD LogonCnt);
	void sendGetMisAward(DWORD	dwUserID, WORD wMissionId, WORD wKindID);
	void sendGambling(DWORD	dwUserID, DWORD lSaveScore,WORD time);
	void sendBuyItems(DWORD dwUserID, WORD wPropCount, WORD wKindID);
	void sendUseItem(DWORD dwUserID, WORD wPropertyIndex, WORD wItemCount, DWORD dwTargetUserID, BYTE cbRequestArea);
	void sendUseJiPaiQi(WORD wPropertyIndex, WORD wKindID, DWORD dwUserID, long long lScore, WORD resultID);						//结果ID);
	void sendGetRank(DWORD	dwUserID);
	void sendGetGrowth(DWORD dwUserID, WORD wIndex);
	void sendSignUp(DWORD	dwUserID);
	void sendExitSignUp(DWORD	dwUserID);
	void sendFriendReq(DWORD	dwUserID);  //请求好友列表
	void sendFriendOption(DWORD	dwUserID, DWORD dwTargetUserId, WORD wStatus);  //好友操作// 0 - 邀请 1- 同意  2 拒绝  3 ---删除

};

#define  SEND ((SendDataService*)getService(SendDataService::NAME)) 
#define SEND_LOGIN ((TCPSocketService *)getService(TCPSocketService::LOGIN))
#define SEND_GAME ((TCPSocketService *)getService(TCPSocketService::GAME))
#endif