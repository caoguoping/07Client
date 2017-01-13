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

	pokerSize = 0;

	readScreenLibConfig();
	
}

void DataManager::saveRankData(CMD_GP_CupInfo* cupInfo)
{
	memcpy(&myRankInfo, cupInfo, sizeof(CMD_GP_CupInfo));
}

void DataManager::split(vector<string> &vecResult, const string &str, const string &pattern)
{
	if (str.compare("") != 0)
	{
		size_t last = 0;
		size_t index = str.find_first_of(pattern, last);
		while (index != std::string::npos)
		{
			vecResult.push_back(str.substr(last, index - last));
			last = index + 1;
			index = str.find_first_of(pattern, last);
		}
		if (index - last > 0)
		{
			vecResult.push_back(str.substr(last, index - last));
		}
	}
}

bool DataManager::readScreenLibConfig()
{
	string _strScreenLib = FileUtils::getInstance()->getStringFromFile("data/screenLib.txt");

	if (_strScreenLib == "")
	{
		return false;
	}

	split(m_vecScreenCharLib, _strScreenLib, "^");

	m_vecScreenCharLib.push_back("\\");

	return true;
}

bool DataManager::onCheckScreenChar(const string& _strCheck)
{
	for (string& _strScreen : m_vecScreenCharLib)
	{
		if (_strCheck.find(_strScreen) != string::npos)
		{
			return true;
		}
	}

	return false;
}







