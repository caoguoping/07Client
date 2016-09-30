#ifndef  _LoginCompleteCommand_
#define  _LoginCompleteCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PlayPokerView.h"
#include "PlayPokerMediator.h"
#include "LoginView.h"
#include "LoginMediator.h"

#include "SevenDayGiftView.h"
#include "SevenDayGiftMediator.h"
#include "DataManager.h"
#include "LobbyView.h"
#include "LobbyMediator.h"

class  LoginCompleteCommand : public BlueSkyCommand
{
public:
	LoginCompleteCommand(){};
	~LoginCompleteCommand(){};
	/**
	事件通知执行函数
	*/
	void execute(void* data);
};

#endif