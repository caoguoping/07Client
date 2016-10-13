#ifndef  _PlayGoldMediator_
#define  _PlayGoldMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "PlayGoldView.h"

class PlayGoldMediator : public BlueSkyMediator
{
public:
	PlayGoldView*   playGoldView;
public:
	PlayGoldMediator();
	~PlayGoldMediator();
	void OnRegister();
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();

};

#endif