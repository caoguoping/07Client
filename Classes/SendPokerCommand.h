#ifndef  _SendPokerCommand_
#define  _SendPokerCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PokerView.h"
#include "PokerMediator.h"
#include "PokerLogic.h"
#include "OutPokerLogicRule.h"
#include "PokerGameModel.h"

class  SendPokerCommand : public BlueSkyCommand
{
public:
	SendPokerCommand(){};
	~SendPokerCommand(){};
	/**
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
	void delaySendPoker();
};

#endif