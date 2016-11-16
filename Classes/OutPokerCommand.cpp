#include "OutPokerCommand.h"
#include "SGTools.h"
/**
�¼�ִ֪ͨ�к���
*/
void OutPokerCommand::execute(void* data)
{
	//ȡ��������һ����ҵĳ�������
	
	//���ж����ĸ���ҳ�����
	int desk = DATAPlayerIndesk->chair[DATAPokerGame->playerOutCard.wOutCardUser];

	//����ո����֮ǰ�����Ƶ���ʾ������
	for (DWORD i = 0; i < DATAGameData->player[desk].outPokerArr.size(); i++)
	{
		pokeridData *data1 = new pokeridData();
		data1->deskID = desk;
		data1->pokerID = DATAGameData->player[desk].outPokerArr.at(i)->pokerID;
		blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data1);
	}
	DATAGameData->player[desk].outPokerArr.clear();
	//ȡ�������Ƶ�ID
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
