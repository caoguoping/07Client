#ifndef  _AlertCommand_
#define  _AlertCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "EventType.h"
#include "WarningMediator.h"
#include "WarningView.h"
#include "GameDataModel.h"

class  AlertCommand : public BlueSkyCommand
{
public:
	AlertCommand(){};
	~AlertCommand(){};
	/**
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
};



#endif