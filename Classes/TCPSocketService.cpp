#include "TCPSocketService.h"
#include "assert.h"

#include "PlatFormControl.h"
#include "SGTools.h"
#include "MTNotificationQueue.h"





const string TCPSocketService::LOGIN("LOGIN_TCPSocketService");
const string TCPSocketService::GAME("GAME_TCPSocketService");

TCPSocketService::TCPSocketService()
{
	logV("cocos2d-x tcp socketServiceLogin %p ", this);
#if (PlatWhich == PlatWin)
	unsigned short wVersionRequested;
	wVersionRequested = MAKEWORD(2, 0);
	WSADATA wsaData;
	int nRet = WSAStartup(wVersionRequested, &wsaData);
	if (nRet != 0)
	{
		return;
	}
#endif
	m_wRecvSize = 0;
	lastRcvTime = time(NULL);

	eventList.clear();
}


TCPSocketService::~TCPSocketService()
{
	
}

bool TCPSocketService::Connect(const char* dwServerIP, unsigned short wPort)
{
	//���� SOCKET
	m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in SocketAddr;
	memset(&SocketAddr, 0, sizeof(SocketAddr));

	SocketAddr.sin_family = AF_INET;
	SocketAddr.sin_port = htons(wPort);
	//SocketAddr.sin_addr.S_un.S_addr = inet_addr(dwServerIP);
	SocketAddr.sin_addr.s_addr = inet_addr(dwServerIP);
	//���ӷ�����
	int iErrorCode = 0;

	//���ӷ�����
	iErrorCode = connect(m_hSocket, (struct sockaddr*)&SocketAddr, sizeof(SocketAddr));
	
	if (iErrorCode == -1)
	{

		return false;
	}
	return true;
}
void TCPSocketService::closeMySocket()
{
#if (PlatWhich == PlatWin)
		closesocket(m_hSocket);

#else

		close(m_hSocket);

#endif
		//m_isSocketOpen = 0;
		m_hSocket = 0;
}

//���ͺ���
unsigned short TCPSocketService::SendData(unsigned short wMainCmdID, unsigned short wSubCmdID, void * pData, unsigned short wDataSize)
{
	if (wMainCmdID != 0)
	{
		logV("send main %d, sub %d, size %d", wMainCmdID, wSubCmdID, wDataSize);
		logF("send main %d, sub %d, size %d", wMainCmdID, wSubCmdID, wDataSize);
	}

	//Ч���С
	if (wDataSize > SOCKET_TCP_PACKET) return false;

	//��������
	unsigned char cbDataBuffer[SOCKET_TCP_BUFFER];
	TCP_Head* pHead = (TCP_Head *)cbDataBuffer;
	pHead->CommandInfo.wMainCmdID = wMainCmdID;
	pHead->CommandInfo.wSubCmdID = wSubCmdID;
	if (wDataSize > 0)
	{
		//ASSERT(pData != NULL);
		memcpy(pHead + 1, pData, wDataSize);
	}

	//��������
	unsigned short wSendSize = EncryptBuffer(cbDataBuffer, sizeof(TCP_Head)+wDataSize, sizeof(cbDataBuffer));

	//��������
	return SendDataBuffer(cbDataBuffer, wSendSize);
}

//��������
unsigned short TCPSocketService::EncryptBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize, unsigned short wBufferSize)
{
	//Ч�����
// 	assert(wDataSize >= sizeof(TCP_Head));
// 	assert(wBufferSize >= (wDataSize + 2 * sizeof(unsigned long)));
// 	assert(wDataSize <= (sizeof(TCP_Head)+SOCKET_TCP_PACKET));

	if (wDataSize < sizeof(TCP_Head) || wBufferSize < (wDataSize + 2 * sizeof(unsigned int)) || wDataSize > (sizeof(TCP_Head)+SOCKET_TCP_PACKET))
	{
		log("encryptBufferError!");
		return 0;
	}

	//��������
	unsigned short wEncryptSize = wDataSize - sizeof(TCP_Command), wSnapCount = 0;
	if ((wEncryptSize % sizeof(unsigned int)) != 0)
	{
		wSnapCount = sizeof(unsigned int)-wEncryptSize%sizeof(unsigned int);
		memset(pcbDataBuffer + sizeof(TCP_Info) + wEncryptSize, 0, wSnapCount);
	}

	//Ч�������ֽ�ӳ�䣬������TCP_Info, ����ͷ4�ֽ�
	unsigned char cbCheckCode = 0;
	unsigned short i = 0;
	for (i = sizeof(TCP_Info); i<wDataSize; i++)
	{
		cbCheckCode += pcbDataBuffer[i];
		pcbDataBuffer[i] = MapSendByte(pcbDataBuffer[i]);
	}

	//��д��Ϣͷ
	TCP_Head* pHead = (TCP_Head *)pcbDataBuffer;
	pHead->TCPInfo.cbCheckCode = ~cbCheckCode + 1;
	pHead->TCPInfo.wPacketSize = wDataSize;
	//pHead->TCPInfo.cbVersion=SOCKET_TCP_VER;

	return wDataSize;
}

//��������
unsigned short TCPSocketService::CrevasseBuffer(unsigned char pcbDataBuffer[], unsigned short wDataSize)
{
	//Ч�����
	
// 	assert(wDataSize >= sizeof(TCP_Head));
// 	assert(((TCP_Head *)pcbDataBuffer)->TCPInfo.wPacketSize == wDataSize);


// 	if (wDataSize < sizeof(TCP_Head) || ((TCP_Head *)pcbDataBuffer)->TCPInfo.wPacketSize != wDataSize)
// 	{
// 		return 0;
// 	}
	if (wDataSize < sizeof(TCP_Command))
	{
		logP
		return 0;
	}


	//��������
	unsigned short wSnapCount = 0;
	if ((wDataSize % sizeof(unsigned int)) != 0)
	{
		wSnapCount = sizeof(unsigned int) - wDataSize % sizeof(unsigned int);
		memset(pcbDataBuffer + wDataSize, 0, wSnapCount);
	}

	//Ч�������ֽ�ӳ��
	//TCP_Head * pHead = (TCP_Head *)pcbDataBuffer;
	//unsigned char cbCheckCode = pHead->TCPInfo.cbCheckCode;
	for (int i = 0; i < wDataSize; i++)
	{
		pcbDataBuffer[i] = MapRecvByte(pcbDataBuffer[i]);
		//cbCheckCode += pcbDataBuffer[i];
	}
	//if (cbCheckCode != 0) return 0;

	return wDataSize;
}

//ӳ�䷢������
unsigned char TCPSocketService::MapSendByte(unsigned char const cbData)
{
	/*unsigned char cbMap = g_SendByteMap[(unsigned char)(cbData + m_cbSendRound)];
	m_cbSendRound += 3;*/
	unsigned char cbMap = g_SendByteMap[(unsigned char)(cbData)];
	return cbMap;
}

//ӳ���������
unsigned char TCPSocketService::MapRecvByte(unsigned char const cbData)
{
	//BYTE cbMap=g_RecvByteMap[cbData]-m_cbRecvRound;
	//m_cbRecvRound+=3;
	unsigned char cbMap = g_RecvByteMap[cbData];
	return cbMap;
}

//��������
bool TCPSocketService::SendDataBuffer(void * pBuffer, unsigned short wSendSize)
{
	//Ч�����
	if (wSendSize == 0)
	{
		return false;
	}

	//��������
	unsigned short wSended = 0;
	while (wSended < wSendSize)
	{
		int iErrorCode = send(m_hSocket, (char *)pBuffer + wSended, wSendSize - wSended, 0);
		if (iErrorCode == -1)
		{
			return false;
		}
		wSended += iErrorCode;
	}
	return true;
}



#if 0
bool TCPSocketService::OnRecvPacket()
{
	int iRetCode = 0;
	unsigned short wPacketSize;
	unsigned short wPacketSizeSave;
	TCP_Info   pInfoHead;
	bool  isContinune;

	//while (((iRetCode = recv(m_hSocket, (char*)&pInfoHead, sizeof(TCP_Info), 0)) >= 0)
	while (((iRetCode = recv(m_hSocket, (char*)&pInfoHead, sizeof(TCP_Info), 0))) >= 0
		&& (m_isSocketOpen == 1))
	{
		(&shareNotificationQueueLock)->lock();
		logV("head iRetCode %d", iRetCode);
		isContinune = false;
		wPacketSizeSave = wPacketSize = pInfoHead.wPacketSize - sizeof(TCP_Info);  //ȥ��TCP_info��ĳ���

		if (wPacketSize > SOCKET_TCP_BUFFER)
		{

			continue;
		}

		int recv_len = 0;
		while (1)
		{
			iRetCode = recv(m_hSocket, (char *)m_cbRecvBuf + recv_len, wPacketSize - recv_len, 0);
			lastRcvTime = time(NULL);   //���½���ʱ��

			logV("body iRetCode %d", iRetCode);
			recv_len += iRetCode;
			if (recv_len >= wPacketSize)
			{
				isContinune = true;
				break;
			}
		}
		if (isContinune)
		{
			wPacketSize = wPacketSizeSave;
			unsigned char cbDataBuffer[SOCKET_TCP_BUFFER + sizeof(TCP_Head)];
			memcpy(cbDataBuffer, m_cbRecvBuf, wPacketSize);   //m_cbRecvBuf ������TCP_info

			//��������//
			unsigned short wRealySize = CrevasseBuffer(cbDataBuffer, wPacketSize);
			if (wRealySize < sizeof(TCP_Command))
			{
				continue;
			}
			//��������
			unsigned short wDataSize = wRealySize - sizeof(TCP_Command); //�����ݳ���
			void * pDataBuffer = cbDataBuffer + sizeof(TCP_Command);    //������
			TCP_Command* Command = (TCP_Command *)cbDataBuffer;
			if (Command->wMainCmdID == MDM_KN_COMMAND)
			{
				switch (Command->wSubCmdID)
				{
				case SUB_KN_DETECT_SOCKET:	//������
				{
												SendData(MDM_KN_COMMAND, SUB_KN_DETECT_SOCKET, pDataBuffer, wDataSize);
												break;
				}
				}
				continue;
			}
			NetData *netData = new NetData();
			netData->type = type;
			netData->command = *Command;
			memcpy(netData->pDataBuffer, pDataBuffer, wDataSize);
			netData->wDataSize = wDataSize;
			//pushEvent(netData);
			
			eventList.push_back(netData);
			
		}
		(&shareNotificationQueueLock)->unlock();
	}


	return true;
}
#endif

#if 1
bool TCPSocketService::OnRecvPacket()
{
	int iRetCode = 0;
	unsigned short wPacketSize;
	unsigned short wPacketSizeSave;
	TCP_Info   pInfoHead;
	bool  isContinune;
	//logV("cocos2d-x begin m_hSocket %d", m_hSocket);
	while (m_hSocket != 0)
	{
		iRetCode = recv(m_hSocket, (char*)&pInfoHead, sizeof(TCP_Info), 0);
		//logV("cocos2d-x header %d", iRetCode);
		isContinune = true;
		if (0 == iRetCode)
		{
			//logV("cocos2d-x recv 0 header");
			continue;
		}
		else if (iRetCode < 0)
		{
			//logV("cocos2d-x recv iRetCode header");
			m_hSocket = 0;
			return true;
		}
		else
		{

			wPacketSizeSave = wPacketSize = pInfoHead.wPacketSize - sizeof(TCP_Info);  //ȥ��TCP_info��ĳ���
			//logV("cocos2d-x wpacketSize %d ", wPacketSize);
			if (wPacketSize > SOCKET_TCP_BUFFER)
			{
				//logV("cocos2d-x wPacketSize is too big  %d", wPacketSize);
				continue;
			}

			if (m_hSocket == 0)
			{
				//logV("cocos2d-x exit readBody m_hSocket %d", m_hSocket);
				return true;
			}
			int recv_len = 0;
			while (m_hSocket != 0)
			{
				iRetCode = recv(m_hSocket, (char *)m_cbRecvBuf + recv_len, wPacketSize - recv_len, 0);
				lastRcvTime = time(NULL);   //���½���ʱ��
				//logV("cocos2d-x body %d ", iRetCode);
				if (iRetCode == 0)
				{
					//logV("cocos2d-x recv 0 body");
					isContinune = false;
					continue;
				}
				else if (iRetCode < 0)
				{
					m_hSocket = 0;
					//logV("cocos2d-x recv iRetCode body");
					return true;
				}
				recv_len += iRetCode;
				if (recv_len >= wPacketSize)
				{
					break;
				}
			}
			if (isContinune)
			{
				wPacketSize = wPacketSizeSave;
				unsigned char cbDataBuffer[SOCKET_TCP_BUFFER + sizeof(TCP_Head)];
				memcpy(cbDataBuffer, m_cbRecvBuf, wPacketSize);   //m_cbRecvBuf ������TCP_info

				//��������//
				unsigned short wRealySize = CrevasseBuffer(cbDataBuffer, wPacketSize);
				if (wRealySize < sizeof(TCP_Command))
				{
					continue;
					//logV("cocos2d-x crevassBuffer failed");
				}
				//��������
				unsigned short wDataSize = wRealySize - sizeof(TCP_Command); //�����ݳ���
				void * pDataBuffer = cbDataBuffer + sizeof(TCP_Command);    //������
				TCP_Command* Command = (TCP_Command *)cbDataBuffer;
				if (Command->wMainCmdID == MDM_KN_COMMAND)
				{
					switch (Command->wSubCmdID)
					{
					case SUB_KN_DETECT_SOCKET:	//������
					{
													SendData(MDM_KN_COMMAND, SUB_KN_DETECT_SOCKET, pDataBuffer, wDataSize);
													break;
					}
					}
					continue;
				}
				NetData *netData = new NetData();
				netData->type = type;
				netData->command = *Command;
				//logV("cocos2d-x %d %d %d", Command->wMainCmdID, Command->wSubCmdID, type);
				memcpy(netData->pDataBuffer, pDataBuffer, wDataSize);
				netData->wDataSize = wDataSize;
				pushEvent(netData);
			}
		}
	}
	//logV("cocos2d-x exit header m_hSocket %d", m_hSocket);
	return true;
}
#endif



void TCPSocketService::pushEvent(NetData* netdata)
{
	LifeCircleMutexLock(&shareNotificationQueueLock);
	eventList.push_back(netdata);
}

char NetData::readInt8()
{
	char i[1];
	memcpy(i, pDataBuffer, 1);
	positionMove(1);
	return i[0];
}
short NetData::readInt16()
{
	short i[1];
	memcpy(i, pDataBuffer, 2);
	positionMove(2);
	return i[0];
}
int NetData::readInt32()
{
	int i[1];
	memcpy(i, pDataBuffer, 4);
	positionMove(4);
	return i[0];
}



BYTE NetData::readByte()
{
	unsigned char i[1];
	memcpy(i, pDataBuffer, 1);
	positionMove(1);
	return i[0];
}

WORD NetData::readWORD()
{
	unsigned short i[1];
	memcpy(i, pDataBuffer, 2);
	positionMove(2);
	return i[0];
}
DWORD NetData::readDWORD()
{
	unsigned int i[1];
	memcpy(i, pDataBuffer, 4);
	positionMove(4);
	return i[0];
}





double NetData::readDouble()
{
	double i[1];
	memcpy(i, pDataBuffer, 8);
	positionMove(8);
	return i[0];
}

long long NetData::readUInt64()
{
	long long i[1];
	memcpy(i, pDataBuffer, 8);
	positionMove(8);
	return i[0];
}
string NetData::readString(int len)
{
	string s;
	char i[SOCKET_TCP_BUFFER];
	memcpy(i, pDataBuffer, len);
	s = i;
	positionMove(len);
	return s;
}
void NetData::positionMove(int len)
{
	char cbDataBuffer[SOCKET_TCP_BUFFER];
	memcpy(cbDataBuffer, pDataBuffer, wDataSize);
	wDataSize -= len;
	void* p = cbDataBuffer + len;
	memcpy(pDataBuffer, p, wDataSize);
}