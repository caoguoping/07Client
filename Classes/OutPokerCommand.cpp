#include "OutPokerCommand.h"
#include "SGTools.h"
/**
事件通知执行函数
*/
void OutPokerCommand::execute(void* data)
{
	//取出本轮上一家玩家的出牌数据
	PokerGameModel *pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	//先判断是哪个玩家出的牌
	int desk = playerInDeskModel->chair[pokerGameModel->playerOutCard.wOutCardUser];

	//先清空该玩家之前出的牌的显示和数据
	//vector<PokerVO*> outPokerArr = ((GameDataModel*)getModel(GameDataModel::NAME))->player[desk].outPokerArr;
	GameDataModel *gameDataModel = (GameDataModel*)getModel(GameDataModel::NAME);
	for (DWORD i = 0; i < gameDataModel->player[desk].outPokerArr.size(); i++)
	{
		pokeridData *data1 = new pokeridData();
		data1->deskID = desk;
		data1->pokerID = gameDataModel->player[desk].outPokerArr.at(i)->pokerID;
		blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data1);
	}
	gameDataModel->player[desk].outPokerArr.clear();
	//取出出的牌的ID
	vector<int> pokerIDArr = {};
	for (int i = 0; i < pokerGameModel->playerOutCard.bCardCount; i++)
	{
		pokerIDArr.push_back(pokerGameModel->playerOutCard.bCardData[i]);
	}
	
	pokerIDArr = PokerLogic::sortPokerIDArr(pokerIDArr);
	//blueSkyDispatchEvent(88887, new int(desk));
	//for (int i = 0; i < pokerIDArr.size(); i++)
	//{
	//	blueSkyDispatchEvent(88888, new int(pokerIDArr[i]));
	//}
	//blueSkyDispatchEvent(88889);
	int len = pokerIDArr.size();
	for (int i = 0; i < len; i++)
	{
		creatView(new PokerView(pokerIDArr.at(i)), new PokerMediator(pokerIDArr.at(i), true, desk));
	}	
}
