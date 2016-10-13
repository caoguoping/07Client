#include "ViewManager.h"

static ViewManager *_instance = NULL;


ViewManager *  ViewManager::getInstance()
{
	if (_instance == NULL)  
	{
		_instance = new ViewManager();
		_instance->init();
	}
	return _instance;
};

void ViewManager::init()
{

}
// 
// void ViewManager::showViewPlayGold()
// {
// 	mViews[eViewPlayGold] = ViewPlayGold::create();
// 	mainScene->addChild(mViews[eViewPlayGold], 1001, eViewPlayGold);
// 
// }
// 
// void ViewManager::hideViewPlayGold()
// {
// 	if (mViews[eViewPlayGold] != NULL)
// 	{
// 		mViews[eViewPlayGold]->removeAllChildrenWithCleanup(true);
// 		mViews[eViewPlayGold]->removeFromParentAndCleanup(true);
// 		mViews[eViewPlayGold] = NULL;
// 	}
// 
// 
// }









