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
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
};

#endif