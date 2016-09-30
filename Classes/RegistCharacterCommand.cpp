#include "RegistCharacterCommand.h"
/**
事件通知执行函数
*/
void RegistCharacterCommand::execute(void* data)
{
	registLogin rLogin = *(registLogin*)data;

	creatView(new CreateRoleView(), new CreateRoleMediator(rLogin));
}