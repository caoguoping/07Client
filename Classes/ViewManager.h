#ifndef  _View_MANAGER_
#define  _View_MANAGER_

#include "cocos2d.h"
#include "SGTools.h"
#include "ViewPopup.h"

USING_NS_CC;


#define GOrderPlayerHead 10

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
		eViewGame,
		eViewMax

	};

	Scene*  mainScene;   //主场景
    Layer *mainLayer;
    Layer* outPokerLayer;
    Layer* myPokerLayer;

    Layer *uiLayer;
        Layer *menuLayer;
    Layer *maskLayer;
    Layer *TopLayer;
    int nowViewTag = eViewMain;  //当前的界面标识
	//Node*  mViews[eViewMax];
    


public:
	static ViewManager * getInstance();

	void init();
    void createLayer();
};

#define VIEW ViewManager::getInstance()

#endif

