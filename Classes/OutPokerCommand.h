#ifndef  _OutPokerCommand_
#define  _OutPokerCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PokerView.h"
#include "PokerMediator.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"
#include "OutPokerLogicRule.h"

class  OutPokerCommand : public BlueSkyCommand
{
public:
	OutPokerCommand(){};
	~OutPokerCommand(){};
	/**
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
};

#endif