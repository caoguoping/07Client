#include "LoginCompleteCommand.h"
/**
�¼�ִ֪ͨ�к���
*/
void LoginCompleteCommand::execute(void* data)
{
	DATA->lobbyview = new LobbyView();
	creatView(DATA->lobbyview, new LobbyMediator());

// 	if (DATA->myBaseData.isFirstLogin == 1)
// 	{
// 		log("cocos2d-x step into sevenDay gift");
// 		creatView(new SevenDayGiftView(), new SevenDayGiftMediator(true));
// 	}

}