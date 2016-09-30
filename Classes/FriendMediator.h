#ifndef  _FriendMediator_H_
#define  _FriendMediator_H_

#include "cocos2d.h"
#include "BlueSky.h"
#include "FriendView.h"




class FriendMediator : public BlueSkyMediator
{
public:
	FriendMediator();
	~FriendMediator();

	void OnRegister();

	void onRemove();


	void onEvent(int i, void* data);
	Layer* getLayer();

	FriendView*  pFriendView;
};


#endif