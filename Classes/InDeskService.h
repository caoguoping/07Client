#ifndef  _InDeskService_
#define  _InDeskService_

#include "cocos2d.h"
#include "BlueSky.h"
#include "EventType.h"
#include "PlayerInDeskModel.h"
#include "DataManager.h"
#include "PlayPokerView.h"
#include "PlayPokerMediator.h"
#include "PokerActionView.h"
#include "PokerActionMediator.h"
#include "JiPaiView.h"
#include "JiPaiMediator.h"

class  InDeskService : public BlueSkyService
{
public:
	InDeskService(){};
	~InDeskService(){};
	static const string NAME;
	void onEvent(int i, void* data);
	bool isFirstInDesk = true;//返回大厅时置为true

};

#endif