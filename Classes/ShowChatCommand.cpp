#include "ShowChatCommand.h"
void ShowChatCommand::execute(void* data)
{
	chatID++;
	CMD_GR_S_UserExpression chatData = *(CMD_GR_S_UserExpression*)data;

	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));

	//
	int desk = -1;
	for (int i = 0; i < 4; i++)
	{
		if (playerInDeskModel->DeskPlayerInfo[i].dwUserID == chatData.dwSendUserID)
			desk = playerInDeskModel->chair[i];
	}

	int index = chatData.wItemIndex;
	creatView(new ShowChatView(), new ShowChatMediator(desk, index, chatID));
}