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










