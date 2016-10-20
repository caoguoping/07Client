#ifndef  _BloodMediator_
#define  _BloodMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "BloodView.h"

class BloodMediator : public BlueSkyMediator
{
public:
	BloodView*   bloodView;
public:
	BloodMediator();
	~BloodMediator();
	void OnRegister();
	void onRemove();
	void onEvent(int i, void* data);
	Layer* getLayer();

};

#endif