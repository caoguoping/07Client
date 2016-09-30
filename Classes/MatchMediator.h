#ifndef  _MatchMediator_
#define  _MatchMediator_

#include "cocos2d.h"
#include "BlueSky.h"
#include "MatchView.h"


class MatchMediator : public BlueSkyMediator
{
public:
	MatchMediator();
	~MatchMediator();

	void OnRegister();
	void onRemove();

	void onEvent(int i, void* data);
	Layer* getLayer();
public:
	MatchView* matchView;

};
#endif