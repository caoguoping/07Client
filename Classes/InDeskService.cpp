#include "InDeskService.h"
#include "DataManager.h"

const string InDeskService::NAME("InDeskService");
	

void InDeskService::onEvent(int i, void* data)
{
	OnDesk onDeskResult;
	OnDeskPlayerInfo result;

	PlayerInDeskModel *playerInDeskModel;
	int wKindID;
	switch (i)
	{
	case EventType::ON_DESK:
		onDeskResult = *(OnDesk*)data;

		if (onDeskResult.dwUserID == DATA->myBaseData.dwUserID 
			&& 
			(onDeskResult.cbUserStatus == US_SIT	|| onDeskResult.cbUserStatus == US_READY)
			&& isFirstInDesk)
		{
			int wKindID = ((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->wKindID;

			isFirstInDesk = false;


			if (wKindID == 2)
			{
				creatView(new PlayPokerView(), new PlayPokerMediator(), &((PlayerInDeskModel *)getModel(PlayerInDeskModel::NAME))->ccNun);
				creatView(new PokerActionView(), new PokerActionMediator());
				creatView(new JiPaiView(), new JiPaiMediator());
			}
			
		}
		break;

	case EventType::OTHER_PLAYER_ON_DESK:
		result = *(OnDeskPlayerInfo*)data;
		result.isClear = false;
		playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
		wKindID = playerInDeskModel->wKindID;
		playerInDeskModel->DeskPlayerInfo[result.wChairID] = result;

		//result.wChairId   服务器定义的椅子ID，四张桌子都一样
		//playerInDeskModel->chair[], 客户端相对ID，自己为0， 左边为1， 
		if (DATA->myBaseData.dwUserID == result.dwUserID)
		{
			playerInDeskModel->chair[result.wChairID] = 0;
			int index = result.wChairID;

			for (int i = 1; i < 4; i++)
			{
				index++;
				if (index > 3)
				{
					index = 0;
				}
				playerInDeskModel->chair[index] = i;
			}
			if (DATA->bGameCate == DataManager::E_GameCateMatch)
			{
				blueSkyDispatchEvent(EventType::SHOW_PLAYER_ON_DESK);
			}
			
		}
		if (DATA->bGameCate == DataManager::E_GameCateNormal ||
			DATA->bGameCate == DataManager::E_GameRandZhupai)
		{
			blueSkyDispatchEvent(EventType::SHOW_PLAYER_ON_DESK);
		}
		break;
	case EventType::BACK_TO_HALL:
		isFirstInDesk = true;
		break;
	}
}