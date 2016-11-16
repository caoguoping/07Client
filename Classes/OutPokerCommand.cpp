#include "OutPokerCommand.h"
#include "SGTools.h"
/**
事件通知执行函数
*/
void OutPokerCommand::execute(void* data)
{
	//取出本轮上一家玩家的出牌数据
	
	//先判断是哪个玩家出的牌
	int desk = DATAPlayerIndesk->chair[DATAPokerGame->playerOutCard.wOutCardUser];

	//先清空该玩家之前出的牌的显示和数据
	for (DWORD i = 0; i < DATAGameData->player[desk].outPokerArr.size(); i++)
	{
		pokeridData *data1 = new pokeridData();
		data1->deskID = desk;
		data1->pokerID = DATAGameData->player[desk].outPokerArr.at(i)->pokerID;
		blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data1);
	}
	DATAGameData->player[desk].outPokerArr.clear();
	//取出出的牌的ID
	vector<int> pokerIDArr = {};
	for (int i = 0; i < DATAPokerGame->playerOutCard.bCardCount; i++)
	{
		pokerIDArr.push_back(DATAPokerGame->playerOutCard.bCardData[i]);
	}
	
	pokerIDArr = PokerLogic::sortPokerIDArr(pokerIDArr);

	int len = pokerIDArr.size();
	for (int i = 0; i < len; i++)
	{
		creatView(new PokerView(pokerIDArr.at(i)), new PokerMediator(pokerIDArr.at(i), true, desk));
	}	
}
