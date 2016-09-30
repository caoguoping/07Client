#include "SendPokerCommand.h"
/**
事件通知执行函数
*/
void SendPokerCommand::execute(void* data)
{
	//int* pokerID = static_cast<int*>(data);
	CMD_S_GameStart Data = *(CMD_S_GameStart*)(data);

	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	//设置本局游戏数据
	gameDataModel->gameData.bCurrentSeries = Data.bCurrentSeries;
	gameDataModel->gameData.bLiangCard = Data.bLiangCard;
	gameDataModel->gameData.bLiangPai = Data.bLiangPai;
	gameDataModel->gameData.bOtherSeries = Data.bOtherSeries;
	gameDataModel->gameData.bOurSeries = Data.bOurSeries;
	
	//
	PokerLogic::zhuPaiNum = Data.bCurrentSeries - 2;

	vector<int> pokerIDArr = {};
	for (int i = 0; i < 27;i++)
	{
		pokerIDArr.push_back(Data.cbCardData[i]);
	}

	vector<vector<int>> pokerIDDui = PokerLogic::fenPokerIDArr(pokerIDArr);
	
	//
	for (DWORD i = 0; i < pokerIDDui.size(); i++)
	{
		for (DWORD j = 0; j < pokerIDDui.at(i).size(); j++)
		{
			creatView(new PokerView(pokerIDDui.at(i).at(j)), new PokerMediator(pokerIDDui.at(i).at(j), false, -1, i, j, pokerIDDui.size(), pokerIDDui.at(i).size()));
		}
	}

	//发完牌后分析玩家的手牌
	//vector<PokerVO*> pokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr;
	gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);
}