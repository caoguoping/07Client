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
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
};

#endif