#ifndef  _View_MANAGER_
#define  _View_MANAGER_

#include "cocos2d.h"
#include "SGTools.h"

USING_NS_CC;

class ViewManager
{
public:

	enum viemTags
	{
		eViewMain = 0,
		eViewFriend,
		eViewShop,
		eViewMatch,
		eViewPlayGold,
		eViewMax

	};

	Scene*  mainScene;   //主场景
	int nowViewTag = eViewMain;  //当前的界面标识
	//Node*  mViews[eViewMax];

public:
	static ViewManager * getInstance();

	void init();
// 	void showViewPlayGold();	
// 	void hideViewPlayGold();
};

#define VIEW ViewManager::getInstance()

#endif

