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

void ViewManager::createLayer()
{
    mainLayer     = Layer::create();
    outPokerLayer = Layer::create();
    myPokerLayer  = Layer::create();

    uiLayer       = Layer::create();
        menuLayer     = Layer::create();
    maskLayer     = Layer::create();
    TopLayer      = Layer::create();
    mainScene->addChild(mainLayer);
    mainScene->addChild(outPokerLayer);
    mainScene->addChild(myPokerLayer);

    mainScene->addChild(uiLayer);
        mainScene->addChild(menuLayer);
    mainScene->addChild(maskLayer);
    mainScene->addChild(TopLayer, 10000);
}










