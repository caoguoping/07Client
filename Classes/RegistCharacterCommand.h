#ifndef  _RegistCharacterCommand_
#define  _RegistCharacterCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "CreateRoleView.h"
#include "CreateRoleMediator.h"
#include "SocketInitCommand.h"

class  RegistCharacterCommand : public BlueSkyCommand
{
public:
	RegistCharacterCommand(){};
	~RegistCharacterCommand(){};
	/**
	事件通知执行函数
	*/
	void execute(void* data);
};

#endif