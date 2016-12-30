#include "SendDataService.h"
#include "TCPSocketService.h"

#include "CallCppHelper.h"
#include "DataManager.h"


const string SendDataService::NAME("SendDataService");

/*
发送钻石换金豆
*/
void SendDataService::sendUserYbToGold(DWORD	dwUserID, int num ,int wKindID)
{
	//变量定义
	BYTE cbBuffer[SOCKET_TCP_PACKET];

	//CMD_GP_UserYbToGold * userYbToGold = (CMD_GP_UserYbToGold *)cbBuffer;
	//userYbToGold->dwUserID = dwUserID;
	//userYbToGold->yb = num;
	Buy_Mall_Item *buyMallItem = (Buy_Mall_Item *)cbBuffer;
	buyMallItem->dwUserID = dwUserID;
	buyMallItem->wPropCount = num;
	buyMallItem->wKindID = wKindID;
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(3, 503, cbBuffer, sizeof(Buy_Mall_Item));
}
/*
发送登录消息
*/
void SendDataService::sendLogin(const char* Accounts, const char* Password, const char* MachineID)
{
	//变量定义
	BYTE cbBuffer[SOCKET_TCP_PACKET];

	CMD_GP_LogonAccounts * pLogonAccounts = (CMD_GP_LogonAccounts *)cbBuffer;
	pLogonAccounts->dwPlazaVersion = VERSION_PLAZA;
	memcpy(pLogonAccounts->szMachineID, MachineID, CountArray(pLogonAccounts->szMachineID) * 2);

	memcpy(pLogonAccounts->szAccounts, CallCppHelper::getInstance()->mUid, 32);
	memcpy(pLogonAccounts->szPassword, CallCppHelper::getInstance()->mUid, 32);
	strncpy(pLogonAccounts->szUid, CallCppHelper::getInstance()->mUid, 32);


	pLogonAccounts->cbValidateFlags = MB_VALIDATE_FLAGS | LOW_VER_VALIDATE_FLAGS;
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(MDM_GP_LOGON, SUB_GP_LOGON_ACCOUNTS, cbBuffer, sizeof(CMD_GP_LogonAccounts));
}
/**
szLogonPass 密码 md5加密
wFaceID 头像id
cbGender 性别
szAccounts 帐号
szNickName 昵称
*/
void SendDataService::sendRegister(const char* szLogonPass, int wFaceID, int cbGender, const char* szAccounts, const char*  szNickName)
{

	//变量定义
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GP_RegisterAccounts * pRegisterAccounts = (CMD_GP_RegisterAccounts *)cbBuffer;
	pRegisterAccounts->dwPlazaVersion = VERSION_PLAZA;
	memcpy(pRegisterAccounts->szMachineID, "aaaaaa", 66);
	memcpy(pRegisterAccounts->szInsurePass, szLogonPass, 66);
	pRegisterAccounts->wFaceID = wFaceID;
	pRegisterAccounts->cbGender = cbGender;
	memcpy(pRegisterAccounts->szNickName, szNickName, 64);
	memcpy(pRegisterAccounts->szSpreader, "", 64);
	memcpy(pRegisterAccounts->szPassPortID, "", 38);
	memcpy(pRegisterAccounts->szCompellation, "", 32);

	memcpy(pRegisterAccounts->szAccounts, CallCppHelper::getInstance()->mUid, 32);
	memcpy(pRegisterAccounts->szLogonPass, CallCppHelper::getInstance()->mUid, 32);
	strncpy(pRegisterAccounts->szUid, CallCppHelper::getInstance()->mUid, 32);

	pRegisterAccounts->cbValidateFlags = MB_VALIDATE_FLAGS | LOW_VER_VALIDATE_FLAGS;

	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(MDM_GP_LOGON, 3, cbBuffer, sizeof(CMD_GP_RegisterAccounts));
}

//test for create acount
void SendDataService::sendLoginTest(int sumer)
{
	//变量定义
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	char randomUid[100];
	sprintf(randomUid, "%09d", sumer);
	CMD_GP_LogonAccounts * pLogonAccounts = (CMD_GP_LogonAccounts *)cbBuffer;
	pLogonAccounts->dwPlazaVersion = VERSION_PLAZA;
	memcpy(pLogonAccounts->szMachineID, randomUid, CountArray(pLogonAccounts->szMachineID) * 2);

	memcpy(pLogonAccounts->szAccounts, randomUid, 32);
	memcpy(pLogonAccounts->szPassword, randomUid, 32);
	strncpy(pLogonAccounts->szUid, randomUid, 32);
	pLogonAccounts->cbValidateFlags = MB_VALIDATE_FLAGS | LOW_VER_VALIDATE_FLAGS;
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(MDM_GP_LOGON, SUB_GP_LOGON_ACCOUNTS, cbBuffer, sizeof(CMD_GP_LogonAccounts));

}

//test for create acount
void SendDataService::sendRegisterTest(int sumer)
{
	//变量定义
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	char randomUid[32];
	 sprintf(randomUid, "%09d", sumer);
	CMD_GP_RegisterAccounts * pRegisterAccounts = (CMD_GP_RegisterAccounts *)cbBuffer;
	pRegisterAccounts->dwPlazaVersion = VERSION_PLAZA;
	memcpy(pRegisterAccounts->szMachineID, "aaaaaa", 66);
	memcpy(pRegisterAccounts->szInsurePass, "abcdefghijklmn", 66);
	pRegisterAccounts->wFaceID = 1;
	pRegisterAccounts->cbGender = 1;
	memcpy(pRegisterAccounts->szNickName, randomUid, 64);
	memcpy(pRegisterAccounts->szSpreader, "", 64);
	memcpy(pRegisterAccounts->szPassPortID, "", 38);
	memcpy(pRegisterAccounts->szCompellation, "", 32);

	memcpy(pRegisterAccounts->szAccounts, randomUid, 32);
	memcpy(pRegisterAccounts->szLogonPass, randomUid, 32);
	strncpy(pRegisterAccounts->szUid, randomUid, 32);

	pRegisterAccounts->cbValidateFlags = MB_VALIDATE_FLAGS | LOW_VER_VALIDATE_FLAGS;

	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(MDM_GP_LOGON, 3, cbBuffer, sizeof(CMD_GP_RegisterAccounts));
}


//最后加wTable, wChair
void SendDataService::sendGameServerLogin(DWORD dwUserID, const char* szLogonPass, WORD wKindID, WORD wTable, WORD wChair)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GP_GameAccounts * pGameAccounts = (CMD_GP_GameAccounts *)cbBuffer;
	pGameAccounts->dwPlazaVersion = VERSION_PLAZA;
	pGameAccounts->dwFrameVersion = VERSION_PLAZA;
	pGameAccounts->dwProcessVersion = VERSION_PLAZA;
	pGameAccounts->dwUserID = dwUserID;
	memcpy(pGameAccounts->szPassword, CallCppHelper::getInstance()->mUid, 32);
	memcpy(pGameAccounts->szMachineID, szLogonPass, 66);
	pGameAccounts->wKindID = wKindID;
	pGameAccounts->wTable = wTable;
	pGameAccounts->wChair = wChair;
	((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->wKindID = wKindID;
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(MDM_GP_LOGON, 1, cbBuffer, sizeof(CMD_GP_GameAccounts));
}

/*
	发送准备消息
*/
void SendDataService::sendReady()
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(100, 2, cbBuffer,0);
}
/*
发送出牌
*/
void SendDataService::sendOutPoker(BYTE bCardCount, BYTE bCardData[27])
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_C_OutCard * outCard = (CMD_C_OutCard *)cbBuffer;
	outCard->bCardCount = bCardCount;
	for (int i = 0; i < bCardCount; i++)
	{
		outCard->bCardData[i] = bCardData[i];
	}

	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(200, 2, cbBuffer, bCardCount + 1);
}
/*
不出
*/
void SendDataService::sendNotOutPoker()
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(200, 3, cbBuffer, 0);
}
/*进贡*/
void SendDataService::sendPayTribute(DWORD bPayType, WORD wUser, WORD wToUser, BYTE bCard)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_C_PayTribute * payTribute = (CMD_C_PayTribute *)cbBuffer;
	payTribute->bPayType = bPayType;
	payTribute->wUser = wUser;
	payTribute->wToUser = wToUser;
	payTribute->bCard = bCard;
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(200, 4, cbBuffer, 9);
}

/*
	发送断开游戏服务器消息
*/
void SendDataService::sendLeaveTable(WORD wTableID, WORD wChairID, BYTE cbForceLeave)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GR_UserStandUp *leaveTable = (CMD_GR_UserStandUp *)cbBuffer;
	leaveTable->wTableID = wTableID;
	leaveTable->wChairID = wChairID;
	leaveTable->cbForceLeave = cbForceLeave;
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(3, 4, cbBuffer, 5);
}

/*
	聊天
*/
void SendDataService::sendChat(WORD wItemIndex, DWORD dwTargetUserID)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GR_C_UserExpression *chat = (CMD_GR_C_UserExpression *)cbBuffer;
	chat->dwTargetUserID = dwTargetUserID;
	chat->wItemIndex = wItemIndex;
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(100, 11, cbBuffer, 6);
}

/*
	七日登录
*/
void SendDataService::sendSevenLogin(DWORD dwUserID, WORD LogonCnt)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	DBO_GP_Seven_Logon *sevenLogin = (DBO_GP_Seven_Logon*)cbBuffer;
	sevenLogin->dwUserID = dwUserID;
	sevenLogin->LogonCnt = LogonCnt;
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(3, 602, cbBuffer, 6);
}

/*
领取任务奖励
wIndex -- missionID
wKind -- gameID
*/
void SendDataService::sendGetMisAward(DWORD	dwUserID, WORD wMissionId, WORD wKindID)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GR_UerMissionRec *getMisAward = (CMD_GR_UerMissionRec*)cbBuffer;
	getMisAward->dwUserID = dwUserID;
	getMisAward->wMissionId = wMissionId;
	getMisAward->wKindID = wKindID;
	/*((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(3, 400, cbBuffer, 8);*/
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(3, 702, cbBuffer, 8);

	int a = 0;
}

/*
	金币操作(抽奖)
*/
void SendDataService::sendGambling(DWORD dwUserID, DWORD lSaveScore, WORD time)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GP_UserAddandSubScore *getMisAward = (CMD_GP_UserAddandSubScore*)cbBuffer;
	getMisAward->dwUserID = dwUserID;
	getMisAward->lSaveScore = lSaveScore;
	getMisAward->time = time;   //道具id
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(1, 4, cbBuffer, sizeof(CMD_GP_UserAddandSubScore));
	log("cocos2d-x sendGambling success\n");
}

void SendDataService::sendGetRank(DWORD	dwUserID)  //qing qiu paihang
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	memcpy(cbBuffer, &dwUserID, 4);
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(3, 1006, cbBuffer, 4);
}

void SendDataService::sendGetGrowth(DWORD dwUserID, WORD wIndex)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GROWTH_INFO *getMisAward = (CMD_GROWTH_INFO*)cbBuffer;
	getMisAward->dwUserID = dwUserID;
	getMisAward->wIndex = wIndex;   //
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(3, 1005, cbBuffer, sizeof(CMD_GROWTH_INFO));
}



/*
	购买商城道具
*/
void SendDataService::sendBuyItems(DWORD dwUserID, WORD wPropCount, WORD wKindID)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	Buy_Mall_Item *buyMallItem = (Buy_Mall_Item*)cbBuffer;
	buyMallItem->dwUserID = dwUserID;
	buyMallItem->wPropCount = wPropCount;
	buyMallItem->wKindID = wKindID;    
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(3, 502, cbBuffer, sizeof(Buy_Mall_Item));
}

/*
使用道具
*/
void SendDataService::sendUseItem(DWORD dwUserID, WORD wPropertyIndex, WORD wItemCount, DWORD dwTargetUserID, BYTE cbRequestArea)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	DBR_GR_UseProperty *useItem = (DBR_GR_UseProperty*)cbBuffer;
	useItem->dwUserID = dwUserID;
	useItem->wPropertyIndex = wPropertyIndex;
	useItem->wItemCount = wItemCount;
	useItem->dwTargetUserID = dwTargetUserID;
	useItem->cbRequestArea = cbRequestArea;
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(3, 300, cbBuffer, sizeof(DBR_GR_UseProperty));
}

/*
 使用记牌器
*/
void SendDataService::sendUseJiPaiQi(WORD wPropertyIndex, WORD wKindID, DWORD dwUserID, long long lScore, WORD resultID)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	DBR_GR_PropertyConsume *useJiPaiQi = (DBR_GR_PropertyConsume*)cbBuffer;
	useJiPaiQi->wPropertyIndex = wPropertyIndex;
	useJiPaiQi->wKindID = wKindID;
	useJiPaiQi->dwUserID = dwUserID;
	useJiPaiQi->lScore = lScore;
	useJiPaiQi->resultID = resultID;
	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(3, 308, cbBuffer, sizeof(DBR_GR_PropertyConsume));
}



void SendDataService::sendSignUp(DWORD	dwUserID)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GR_UserSitDown *info = (CMD_GR_UserSitDown*)cbBuffer;
	info->wChairID = 0xFFFF;
	info->wTableID = 0xFFFF;

	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(3, 3, cbBuffer, sizeof(CMD_GR_UserSitDown));
}

//退赛
void SendDataService::sendExitSignUp(DWORD	dwUserID)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GR_UserSitDown *info = (CMD_GR_UserSitDown*)cbBuffer;
	info->wChairID = 0xFFFF;
	info->wTableID = 0xFFFF;

	((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(7, 402, cbBuffer, sizeof(CMD_GR_UserSitDown));
}

//6, 2
void SendDataService::sendFriendReq(DWORD	dwUserID)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	memcpy(cbBuffer, &dwUserID, 4);
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(6, 2, cbBuffer, 4);
}

//6,  4
void  SendDataService::sendFriendOption(DWORD	dwUserID, DWORD dwTargetUserId, WORD wStatus)
{
	BYTE cbBuffer[SOCKET_TCP_PACKET];
	CMD_GP_Snd_ADD_Friend *friendsOpt = (CMD_GP_Snd_ADD_Friend*)cbBuffer;
	friendsOpt->dwUserID = dwUserID;
	friendsOpt->dwTargretUserID = dwTargetUserId;
	friendsOpt->wStatue = wStatus;
	((TCPSocketService *)getService(TCPSocketService::LOGIN))->SendData(6, 4, cbBuffer, sizeof(CMD_GP_Snd_ADD_Friend));
}


