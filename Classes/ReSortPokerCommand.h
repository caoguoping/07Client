#ifndef  _ReSortPokerCommand_
#define  _ReSortPokerCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PokerView.h"
#include "PokerMediator.h"
#include "PokerLogic.h"
#include "OutPokerLogicRule.h"
#include "PokerGameModel.h"

class  ReSortPokerCommand : public BlueSkyCommand
{
public:
	ReSortPokerCommand(){};
	~ReSortPokerCommand(){};
	/**
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
};

#endif