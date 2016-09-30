#include "ReSortPokerCommand.h"
#include "SGTools.h"

void ReSortPokerCommand::execute(void* data)
{
	//先创建其他的牌
	vector<PokerVO> otherPokerArr = {};

	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
	{
		if (!gameDataModel->player[0].pokerArr.at(i)->isSelected)
			otherPokerArr.push_back(*(gameDataModel->player[0].pokerArr.at(i)));
	}

	//这边清之前的手牌数据
	gameDataModel->player[0].pokerArr = {};


	vector<vector<PokerVO>> otherPokerDui = {};
	int nowDuiAll = 0;
	if (otherPokerArr.size() > 0)
	{
		otherPokerDui = PokerLogic::reFenPokerArr1(otherPokerArr);
		nowDuiAll = otherPokerDui.size();
		for (int i = 0; i < nowDuiAll; i++)
		{
			for (DWORD j = 0; j < otherPokerDui.at(i).size(); j++)
			{
				int id = otherPokerDui.at(i).at(j).pokerID;
				int changePos = otherPokerDui.at(i).at(j).isChangePosition;
				bool isGongPai = otherPokerDui.at(i).at(j).isGongPai;
				creatView(new PokerView(id), new PokerMediator(id, false, -1, i, j, nowDuiAll + 1, otherPokerDui.at(i).size(), changePos, isGongPai));
			}
		}
	}

	//再创建要离成一排的牌
	int zhangAllNum = gameDataModel->player[0].selectedPokerArr.size();
	//添加用户选的牌的显示和数据
	for (int i = 0; i < zhangAllNum; i++)
	{
		int id = gameDataModel->player[0].selectedPokerArr.at(i)->pokerID;
		int changePos = gameDataModel->player[0].selectedPokerArr.at(i)->isChangePosition;
		bool isGongPai = gameDataModel->player[0].selectedPokerArr.at(i)->isGongPai;
		creatView(new PokerView(id), new PokerMediator(id, false, -1, nowDuiAll, i, nowDuiAll + 1, zhangAllNum, changePos, isGongPai));
	}
	gameDataModel->player[0].selectedPokerArr = {};

	//
	//重新分析玩家的手牌类型
	gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);
}