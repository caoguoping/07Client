#ifndef  _GetJingGongCommand_
#define  _GetJingGongCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PokerView.h"
#include "PokerMediator.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"
#include "OutPokerLogicRule.h"

class  GetJingGongCommand : public BlueSkyCommand
{
public:
	GetJingGongCommand(){};
	~GetJingGongCommand(){};
	/**
	事件通知执行函数
	*/
	void execute(void* data);
};

#endif