#ifndef  _RoomListModel_
#define  _RoomListModel_

#include "cocos2d.h"
#include "BlueSky.h"
#include "SGTools.h"
#pragma pack(1)
struct RoomList
{
	unsigned short wKindID;
	unsigned short wwNodeID;
	unsigned short wwSortID;
	unsigned short wwServerID;
	unsigned short wwServerPort;
	unsigned int wdwOnLineCount;
	unsigned int wdwFullCount;
	string wszServerAddr;
	string wszServerName;
	unsigned int dizhu;
	WORD  wRoomType;
};

class  RoomListModel : public BlueSkyModel
{
public:
	RoomListModel(){};
	~RoomListModel(){};
	char num;
	vector<RoomList> roomList;
	static const string NAME;
	vector<RoomList> fruitroomList;
	int realSn[4];      //第一位代表新手场的ip是列表里的第几个， 第二位代表进阶场，。。。。
};




#endif