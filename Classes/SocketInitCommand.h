#ifndef  _SocketInitCommand_
#define  _SocketInitCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "head.h"

#include "SendDataService.h"
#include "md5.h"
#include "DataManager.h"



USING_NS_CC;
using namespace std;
class  SocketInitCommand : public Node, public BlueSkyCommand
{
public:
	SocketInitCommand(){};
	~SocketInitCommand(){};
	/**
	事件通知执行函数
	*/
	void execute(void* data);
	void heartPacket2(float dt);
	void recvDate();

	//
	void socketEventDispatch(float dt);
	void callNotConnect(Ref*  psender);
	void checkNetWorks2(float dt);     //客户端检测是否断线

};

struct registLogin
{
	char type;
	const char* szLogonPass;
	int wFaceID;
	int cbGender;
	const char* szAccounts;
	const char*  szNickName;
	const char* ip;
};

#endif