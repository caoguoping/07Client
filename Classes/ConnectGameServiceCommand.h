#ifndef  _ConnectGameServiceCommand_
#define  _ConnectGameServiceCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "EventType.h"
#include "RoomListModel.h"
#include "SendDataService.h"
#include "md5.h"
#include "DataManager.h"

class  ConnectGameServiceCommand : public Node, public BlueSkyCommand
{
public:
	ConnectGameServiceCommand(){};
	~ConnectGameServiceCommand(){};
	/**
	事件通知执行函数
	*/
	void execute(void* data);
	void heartPacket(float dt);
	void recvDate();

	void callNotConnect(Ref*  psender);
	void checkNetWorks(float dt);     //客户端检测是否断线

};

#endif