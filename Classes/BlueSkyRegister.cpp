#include "BlueSky.h"
#include "SGTools.h"
#include "ViewManager.h"
BlueSkyRegister* BlueSkyRegister::_instance;
BlueSkyRegister::BlueSkyRegister()
{
	gameOnEventList = new list<BlueSkyEvent*>();
	eventVOList = new list<EventVO*>();
}


BlueSkyRegister::~BlueSkyRegister()
{
}
void BlueSkyRegister::creatView(BlueSkyView *view,BlueSkyMediator *mediator, void* noteData)
{
	mediator->setNoteData(noteData);
	mediator->setView(view);
	mediator->OnRegister();
   Layer* layer = mediator->getLayer();
	if (layer != NULL)
	{
		layer->addChild(view);
	}
	else
	{
		//log("getLayer is NULL");
	}
	BlueSkyRegister::getInstance()->registerOnEvent(mediator);
}
void BlueSkyRegister::removeView(BlueSkyMediator *mediator)
{
	mediator->onRemove();
	if (mediator->getLayer() != NULL)
	{
		mediator->getLayer()->removeChild(mediator->getView());
	}
	deleteOnEvent(mediator);
 	mediator = NULL;
}
/**
·¢ËÍÊÂ¼þ
*/
void BlueSkyRegister::blueSkyDispatchEvent(int type, void* data)
{
	
	EventVO *eventVO = new EventVO();
	eventVO->type = type;
	eventVO->data = data;

	eventVOList->push_back(eventVO);
	if (!isInEvent)
	{
		blueSkyDispatchEventHandler();
	}
}
void BlueSkyRegister::blueSkyDispatchEventHandler()
{

	if (eventVOList->size() > 0)
	{
		isInEvent = true;
		EventVO *eventVO = eventVOList->front();
		int type = eventVO->type;
		void* data = eventVO->data;
		if (gameCommand[type] != NULL)
		{
			gameCommand[type]->execute(data);
			//return;
		}
		list<BlueSkyEvent*>::iterator j;
		for (j = gameOnEventList->begin(); j != gameOnEventList->end();)
		{
			BlueSkyEvent *blueSkyEvent = *j;
			++j;
			blueSkyEvent->onEvent(type, data);
		}
		eventVOList->pop_front();
		eventVO->data = NULL;
		delete eventVO;
		eventVO = NULL;
		blueSkyDispatchEventHandler();
	}
	else
	{
		isInEvent = false;
	}
}

void BlueSkyRegister::registerOnEvent(BlueSkyEvent *blueSkyEvent)
{
	blueSkyEvent->blueSkyOnEventID = blueSkyIndex++;
	gameOnEventList->push_back(blueSkyEvent);

}
void BlueSkyRegister::deleteOnEvent(BlueSkyEvent *blueSkyEvent)
{
	list<BlueSkyEvent*>::iterator j;
	for (j = gameOnEventList->begin(); j != gameOnEventList->end(); )
	{
		if ((*j)->blueSkyOnEventID == blueSkyEvent->blueSkyOnEventID)
		{
			gameOnEventList->erase(j++);
		}
		else
		{
			++j;
		}
	}
}
