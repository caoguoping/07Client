#include "RegistCharacterCommand.h"
/**
�¼�ִ֪ͨ�к���
*/
void RegistCharacterCommand::execute(void* data)
{
	registLogin rLogin = *(registLogin*)data;

	creatView(new CreateRoleView(), new CreateRoleMediator(rLogin));
}