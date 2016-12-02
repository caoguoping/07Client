#ifndef  _DaoJuActionView_
#define  _DaoJuActionView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  DaoJuActionView : public BlueSkyView
{
public:
	DaoJuActionView();
	~DaoJuActionView();

	//都是clientDesk,不是服务器椅子ID
	void initView(int index = -1, int fromID = -1, int toDesk = -1, int actionID = -1);
	void showAction(int index = -1, int fromID = -1, int toDesk = -1);
	void showNextAction();
	void removeAction();

private:

	//
	Sprite* boom;
	Sprite* egg;
	Sprite* flower;
	Sprite* heart;

	//
	cocostudio::timeline::ActionTimeline* daoJuAction;

	//
	int id = -1;
};

#endif