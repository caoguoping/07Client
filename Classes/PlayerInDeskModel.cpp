#include "PlayerInDeskModel.h"
const string PlayerInDeskModel::NAME("PlayerInDeskModel");


void PlayerInDeskModel::clean()
{
	DeskPlayerInfo[0].isClear = true;
	DeskPlayerInfo[1].isClear = true;
	DeskPlayerInfo[2].isClear = true;
	DeskPlayerInfo[3].isClear = true;
}


//������ҵĿͻ�������ID��ȡ��ҵķ���������ID
int PlayerInDeskModel::getServiceChairID(int clientID)
{
	for (int m = 0; m < 4; m++)
	{
		if (chair[m] == clientID)
			return m;
	}
	return 0;
}
