#include "GameDataModel.h"
#include "SGTools.h"
const string GameDataModel::NAME("GameDataModel");

/*
移除自己手中的出掉的牌
*/
void GameDataModel::removeMyPokerArr(vector<PokerVO*> arr)
{
	vector<PokerVO*>::iterator it;
	for (it = player[0].pokerArr.begin(); it != player[0].pokerArr.end();)
	{
		bool isRemoved = false;
		for (DWORD i = 0; i < arr.size(); i++)
		{
			if (arr.at(i)->pokerID == (*it)->pokerID && arr.at(i)->pokerID2 == (*it)->pokerID2)
			{
				it = player[0].pokerArr.erase(it);
				isRemoved = true;
				break;
			}
		}
		if (!isRemoved)
			it++;
	}
}

/*
移除自己选的要出的牌
*/
void GameDataModel::removeMySelectedPokerArr(PokerVO* arr)
{
	vector<PokerVO*>::iterator it;
	for (it = player[0].selectedPokerArr.begin(); it != player[0].selectedPokerArr.end();)
	{
		if (arr->pokerID == (*it)->pokerID && arr->pokerID2 == (*it)->pokerID2)
		{
			it = player[0].selectedPokerArr.erase(it);
			break;
		}
		else
			it++;
	}
}

