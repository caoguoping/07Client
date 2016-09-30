#ifndef  _GameOverCommand_
#define  _GameOverCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "AccountView.h"
#include "AccountMediator.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"

class  GameOverCommand : public BlueSkyCommand
{
public:
	GameOverCommand(){};
	~GameOverCommand(){};
	/**
	事件通知执行函数
	*/
	void execute(void* data);
};

#endif