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
	//int                             m_isSocketOpen;   //�Ƿ��   0, �رգ�  1����
	unsigned char					m_cbRecvBuf[SOCKET_TCP_BUFFER ];		//���ջ���
	unsigned short					m_wRecvSize;								//���ճ���
	char type = 0;//1Ϊlogin 2Ϊgame 0δ��ʼ��
	bool isInUse;      //true ���ڴ���

	time_t lastRcvTime;    //���һ���յ����ĵ�ʱ��

	//
	list<NetData*> eventList;
	EventDispatcher *_eventDispatcher;
public:
	bool Connect(const char* dwServerIP, unsigned short wPort);																//��������
	void closeMySocket();
	unsigned short SendData(unsigned short wMainCmdID, unsigned short wSubCmdID, void * pData, unsigned short wDataSize);	//���ͺ���
	unsigned short EncryptBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize, unsigned short wBufferSize);		//��������
	unsigned short CrevasseBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize);									//��������
	unsigned char MapSendByte(unsigned char const cbData);																	//����ӳ��
	unsigned char MapRecvByte(unsigned char const cbData);
	unsigned long SendDataBuffer(void * pBuffer, unsigned short wSendSize);													//��������
	bool OnRecvPacket();	//��������
	void checkNetWorks(float dt);     //����Ƿ����
	void callNotConnect(Ref* psender);

	void pushEvent(NetData*  netdata);
	static const string LOGIN;
	static const string GAME;
};

#endif
