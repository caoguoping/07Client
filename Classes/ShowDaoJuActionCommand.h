#ifndef  _ShowDaoJuActionCommand_
#define  _ShowDaoJuActionCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "EventType.h"
#include "DaoJuActionView.h"
#include "DaoJuActionMediator.h"
#include "GameDataModel.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"

class  ShowDaoJuActionCommand : public BlueSkyCommand
{
public:
	ShowDaoJuActionCommand(){};
	~ShowDaoJuActionCommand(){};
	/**
	�¼�ִ֪ͨ�к���
	*/
	void execute(void* data);

	int chatID = -1;
};
#endif