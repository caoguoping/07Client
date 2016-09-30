#ifndef  _ShowChatCommand_
#define  _ShowChatCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "EventType.h"
#include "ShowChatView.h"
#include "ShowChatMediator.h"
#include "GameDataModel.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"

class  ShowChatCommand : public BlueSkyCommand
{
public:
	ShowChatCommand(){};
	~ShowChatCommand(){};
	/**
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);

	int chatID = -1;
};
#endif