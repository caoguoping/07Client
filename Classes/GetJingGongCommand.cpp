#include "GetJingGongCommand.h"
#include "SGTools.h"

/**
�¼�ִ֪ͨ�к���
*/
void GetJingGongCommand::execute(void* data)
{
	int pokerID = *(int*)(data);

	//������������ƣ��ڼ��Ͻ�����
	vector<int> *myPokerIDArr = new vector<int>({});
	//vector<PokerVO*> myPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr;
	for (DWORD i = 0; i < ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.size(); i++)
	{
		myPokerIDArr->push_back(((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->pokerID);

		pokeridData *data = new pokeridData();
		data->pokerID = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->pokerID;
		data->pokerID2 = ((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::REMOVE_POKER,data);
	}

	myPokerIDArr->push_back(pokerID);

	blueSkyDispatchEvent(EventType::RE_SHOW_POKER, myPokerIDArr);
}