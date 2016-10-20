#ifndef  _EntertainmentMediator_
#define  _EntertainmentMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "EntertainmentView.h"

class EntertainmentMediator : public BlueSkyMediator
{
public:
	EntertainmentView*   entertainmentView;
public:
	EntertainmentMediator();
	~EntertainmentMediator();
	void OnRegister();
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();

};

#endif