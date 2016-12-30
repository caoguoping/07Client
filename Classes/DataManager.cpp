#include "DataManager.h"

static DataManager *_instance = NULL;


DataManager *  DataManager::getInstance()
{
	if (_instance == NULL)  
	{
		_instance = new DataManager();
		_instance->initData();
	}
	return _instance;
};

void DataManager::initData()
{
	bLastMatch = 2;
	wCdRank = 12;
	wMatchScore = 10;
	wMatchNextPlayerCount = 8;
	wMatchPlayer = 12;
	wBestRank = 12;
	bMatchOver = 0;
	bGameCateSub = 0;
	myBaseData.wBeiZaNum[0] = 0;
	myBaseData.wBeiZaNum[1] = 0;
	myBaseData.wBeiZaNum[2] = 0;
	myBaseData.wBeiZaNum[3] = 0;
	dwRoleCreate = 123456789;
	dwGameState = 0;
	
}

void DataManager::saveRankData(CMD_GP_CupInfo* cupInfo)
{
	memcpy(&myRankInfo, cupInfo, sizeof(CMD_GP_CupInfo));
}








