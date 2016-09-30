#ifndef  _LobbyMediator_
#define  _LobbyMediator_

#include "cocos2d.h"
#include "BlueSky.h"



#include "LobbyView.h"
#include "DataManager.h"


#include "InDeskService.h"
#include "MatchView.h"
#include "MatchMediator.h"
#include "UILayerService.h"
#include "EventType.h"
#include "UIUtil.h"
#include "head.h"
#include "SendDataService.h"
#include "PokerGameModel.h"
#include "PlayerInDeskModel.h"
#include "GameDataModel.h"
#include "PokerLogic.h"

class LobbyMediator : public BlueSkyMediator
{
public:
	LobbyMediator();
	~LobbyMediator();

	void OnRegister();

	void onRemove();

	void onEvent(int i, void* data);
	Layer* getLayer();

	//
	bool canShowMessage = true;
	
	public:
	LobbyView* lobbyView;

};

#endif