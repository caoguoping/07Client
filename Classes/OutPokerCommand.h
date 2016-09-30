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
	事件通知执行函数
	*/
	void execute(void* data);
};

#endif