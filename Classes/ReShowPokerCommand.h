#ifndef  _ReShowPokerCommand_
#define  _ReShowPokerCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PokerView.h"
#include "PokerMediator.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"
#include "OutPokerLogicRule.h"

class  ReShowPokerCommand : public BlueSkyCommand
{
public:
	ReShowPokerCommand(){};
	~ReShowPokerCommand(){};
	/**
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
};

#endif