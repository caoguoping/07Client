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
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
};

#endif