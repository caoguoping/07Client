#ifndef  _GameStartCommand_
#define  _GameStartCommand_

#include "cocos2d.h"
#include "BlueSky.h"
#include "PlayPokerView.h"
#include "PlayPokerMediator.h"
#include "LoginView.h"
#include "LoginMediator.h"
#include "ShopView.h"
#include "ShopMediator.h"
#include "UTF8.h"
#include "GameDataModel.h"
#include "MessageShowView.h"
#include "MessageShowMediator.h"


class  GameStartCommand : public BlueSkyCommand
{
public:
	GameStartCommand(){};
	~GameStartCommand(){};
	/**
	事件通知执行函数
	*/
	void execute(void* data);
};

#endif