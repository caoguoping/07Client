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
	事件通知执行函数
	*/
	void execute(void* data);
};



#endif