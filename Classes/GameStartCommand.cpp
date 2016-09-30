#include "GameStartCommand.h"
/**
事件通知执行函数
*/
void GameStartCommand::execute(void* data)
{
	creatView(new LoginView(), new LoginMediator());
	creatView(new MessageShowView(),new MessageShowMediator());

}