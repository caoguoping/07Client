#ifndef __TCP_SOCKET_H__
#define __TCP_SOCKET_H__
#include "PlatFormControl.h"


#if (PlatWhich == PlatWin)
#include <WinSock2.h>
#pragma comment(lib, "WS2_32.lib")
#define HSocket SOCKET
#else

#include <arpa/inet.h>		// for inet_**
#include <netdb.h>			// for gethost**
#include <netinet/in.h>		// for sockaddr_in
#include <sys/types.h>		// for socket
#include <sys/socket.h>		// for socket
#include <unistd.h>
#include <stdio.h>		    // for printf
#include <stdlib.h>			// for exit
#include <string.h>			// for bzero
#include <unistd.h>
#define HSocket int
#endif




#include "iostream"
#include "head.h"
#include "BlueSky.h"
#include "EventType.h"
#include <time.h>

using namespace std;
class TCPSocketService: public BlueSkyService//, public Node
{
public:
	TCPSocketService();
	~TCPSocketService();
public:
	int								m_hSocket;//
	//int                             m_isSocketOpen;   //是否打开   0, 关闭，  1：打开
	unsigned char					m_cbRecvBuf[SOCKET_TCP_BUFFER ];		//接收缓冲
	unsigned short					m_wRecvSize;								//接收长度
	char type = 0;//1为login 2为game 0未初始化
	bool isInUse;      //true 正在处理

	time_t lastRcvTime;    //最后一次收到报文的时间

	//
	list<NetData*> eventList;
	EventDispatcher *_eventDispatcher;
public:
	bool Connect(const char* dwServerIP, unsigned short wPort);																//网络连接
	void closeMySocket();
	unsigned short SendData(unsigned short wMainCmdID, unsigned short wSubCmdID, void * pData, unsigned short wDataSize);	//发送函数
	unsigned short EncryptBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize, unsigned short wBufferSize);		//加密数据
	unsigned short CrevasseBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize);									//解密数据
	unsigned char MapSendByte(unsigned char const cbData);																	//发送映射
	unsigned char MapRecvByte(unsigned char const cbData);
	unsigned long SendDataBuffer(void * pBuffer, unsigned short wSendSize);													//发送数据
	bool OnRecvPacket();	//接收数据
	void checkNetWorks(float dt);     //检测是否断线
	void callNotConnect(Ref* psender);

	void pushEvent(NetData*  netdata);
	static const string LOGIN;
	static const string GAME;
};

#endif
