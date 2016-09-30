#include "ShowDaoJuActionCommand.h"
void ShowDaoJuActionCommand::execute(void* data)
{
	chatID++;

	DAO_JU_ACTION daoJuData = *(DAO_JU_ACTION*)data;
	daoJuData.id = chatID;

	creatView(new DaoJuActionView(), new DaoJuActionMediator(daoJuData));
}