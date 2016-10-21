#include "GameOverCommand.h"
#include "SGTools.h"
#include "DataManager.h"
/**
�¼�ִ֪ͨ�к���
*/
void GameOverCommand::execute(void* data)
{
	
	//��Ϸ������Ϣ
	CMD_S_GameEnd Data = *(CMD_S_GameEnd*)(data);
	DATA->GameEndData = Data;


	//����Լ����е����ơ�������ʾ
	GameDataModel *gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	for (DWORD i = 0; i < gameDataModel->player[0].pokerArr.size(); i++)
	{
		pokeridData *data = new pokeridData();
		data->pokerID = gameDataModel->player[0].pokerArr.at(i)->pokerID;
		data->pokerID2 = gameDataModel->player[0].pokerArr.at(i)->pokerID2;
		blueSkyDispatchEvent(EventType::REMOVE_POKER, data);
	}
	for (DWORD j = 0; j < gameDataModel->player[0].outPokerArr.size(); j++)
	{
		pokeridData *data1 = new pokeridData();
		data1->deskID = 0;
		data1->pokerID = gameDataModel->player[0].outPokerArr.at(j)->pokerID;
		blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data1);
	}
	
	//���������ҵĳ�����ʾ
	for (DWORD j = 0; j < gameDataModel->player[1].outPokerArr.size(); j++)
	{
		pokeridData *data1 = new pokeridData();
		data1->deskID = 1;
		data1->pokerID = gameDataModel->player[1].outPokerArr.at(j)->pokerID;
		blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data1);
	}
	for (DWORD j = 0; j < gameDataModel->player[2].outPokerArr.size(); j++)
	{
		pokeridData *data1 = new pokeridData();
		data1->deskID = 2;
		data1->pokerID = gameDataModel->player[2].outPokerArr.at(j)->pokerID;
		blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data1);
	}
	for (DWORD j = 0; j < gameDataModel->player[3].outPokerArr.size(); j++)
	{
		pokeridData *data1 = new pokeridData();
		data1->deskID = 3;
		data1->pokerID = gameDataModel->player[3].outPokerArr.at(j)->pokerID;
		blueSkyDispatchEvent(EventType::REMOVE_OUT_POKER, data1);
	}

	//�������
	gameDataModel->player[0].pokerArr = {};
	gameDataModel->player[0].outPokerArr = {};
	gameDataModel->player[1].outPokerArr = {};
	gameDataModel->player[2].outPokerArr = {};
	gameDataModel->player[3].outPokerArr = {};
	for (int i = 0; i < 4; i++)
	{
		gameDataModel->player[i].allOutPokerArrID = {};
	}
	gameDataModel->player[0].selectedPokerArr = {};

	//������

	if (DATA->bGameCate == DataManager::E_GameCateNormal ||
		DATA->bGameCate == DataManager::E_GameRandZhupai
		)
	{
		DATA->bLastMatch = 2;
		creatView(new AccountView(), new AccountMediator(Data));
	}

	if (DATA->bGameCate == DataManager::E_GameCateMatch 
		&& DATA->wMatchNowLuanci == DATA->wMatchAllLunci)  //�����ܽ���
	{
		DATA->bLastMatch = 1;
		creatView(new AccountView(), new AccountMediator(Data));
	}

	if (DATA->bGameCate == DataManager::E_GameCateMatch)
	{
	    if (DATA->wMatchNowChangci < DATA->wMatchAllChangci)  //�ȴ�, ��ʾloading
		{
			blueSkyDispatchEvent(10506);

		}
		else if (DATA->wMatchNowChangci == DATA->wMatchAllChangci 
			&&  DATA->wMatchNowLuanci != DATA->wMatchAllLunci) //����
		{
			blueSkyDispatchEvent(10509);
		}
	}
}