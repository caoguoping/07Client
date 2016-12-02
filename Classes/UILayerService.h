#ifndef  _UILayerService_
#define  _UILayerService_

#include "cocos2d.h"
#include "BlueSky.h"
#include "EventType.h"

#include "ShopView.h"
#include "ShopMediator.h"

class  UILayerService : public BlueSkyService
{
public:
	UILayerService();
	~UILayerService();
// 	Layer *mainLayer;
// 	Layer* outPokerLayer;
// 	Layer* myPokerLayer;
// 	Layer *menuLayer;
// 	Layer *uiLayer;
// 	Layer *maskLayer;
// 	Layer *TopLayer;
	// ÷≈∆≤„°¢≥ˆ≈∆≤„


	static const string NAME;

	void onEvent(int i, void* data);
private:
	void init();
};

#endif
