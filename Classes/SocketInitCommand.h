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
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);
	void heartPacket2(float dt);
	void recvDate();

	//
	void socketEventDispatch(float dt);
	void callNotConnect(Ref*  psender);
	void checkNetWorks2(float dt);     //�ͻ��˼���Ƿ����

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