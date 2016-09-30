#include "ReShowPokerCommand.h"
#include "SGTools.h"

/**
�¼�ִ֪ͨ�к���
*/
void ReShowPokerCommand::execute(void* data)
{
	vector<int> myPokerIDArr = *(vector<int>*)(data);

	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));

	gameDataModel->player[0].pokerArr = {};
	gameDataModel->player[0].selectedPokerArr = {};

	//�ѻ�õĽ��������û�
	int size = myPokerIDArr.size();
	gameDataModel->player[0].getPokerID = myPokerIDArr.at(size - 1);

	vector<vector<int>> pokerIDDui = PokerLogic::fenPokerIDArr(myPokerIDArr);

	//
	for (DWORD i = 0; i < pokerIDDui.size(); i++)
	{
		for (DWORD j = 0; j < pokerIDDui.at(i).size(); j++)
		{
			creatView(new PokerView(pokerIDDui.at(i).at(j)), new PokerMediator(pokerIDDui.at(i).at(j), false, -1, i, j, pokerIDDui.size(), pokerIDDui.at(i).size()));
		}
	}

	//�ѻ�õĽ������Ƽ��ϱ��
	for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size();i++)
	{
		if (gameDataModel->player[0].pokerArr.at(i)->pokerID == gameDataModel->player[0].getPokerID)
		{
			pokeridData *data = new pokeridData();
			data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
			data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
			blueSkyDispatchEvent(EventType::POKER_GONG_PAI_STATE, data);
			break;
		}
	}

	//������ҵ�����
	//vector<PokerVO*> pokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr;
	gameDataModel->player[0].pokerTypeArr = OutPokerLogicRule::fenXiShouPai(gameDataModel->player[0].pokerArr);
}