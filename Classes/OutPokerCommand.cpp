#include "OutPokerCommand.h"
#include "SGTools.h"
/**
�¼�ִ֪ͨ�к���
*/
void OutPokerCommand::execute(void* data)
{
	//ȡ��������һ����ҵĳ�������
	PokerGameModel *pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
	//���ж����ĸ���ҳ�����
	int desk = playerInDeskModel->chair[pokerGameModel->playerOutCard.wOutCardUser];

	//����ո����֮ǰ�����Ƶ���ʾ������
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
	//ȡ�������Ƶ�ID
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
