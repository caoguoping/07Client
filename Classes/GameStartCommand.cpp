#include "GameStartCommand.h"
/**
�¼�ִ֪ͨ�к���
*/
void GameStartCommand::execute(void* data)
{
	creatView(new LoginView(), new LoginMediator());
	creatView(new MessageShowView(),new MessageShowMediator());

}