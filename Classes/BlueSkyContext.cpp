#include "BlueSky.h"

BlueSkyContext::BlueSkyContext()
{
}


BlueSkyContext::~BlueSkyContext()
{
}
void BlueSkyContext::constructor(Scene* container)
{
	BlueSkyRegister::getInstance()->container = container;
}
/**
����������
*/
Scene* BlueSkyContext::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}
/**
�����¼�
*/
void BlueSkyContext::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}
/**
ע������ģ��
*/
void BlueSkyContext::registerModel(string name, BlueSkyModel *model)
{

	BlueSkyRegister::getInstance()->gameModel[name] = model;
}
/**
ע�����
*/
void BlueSkyContext::registerService(string name, BlueSkyService* service)
{
	BlueSkyRegister::getInstance()->registerOnEvent(service);
	BlueSkyRegister::getInstance()->gameService[name] = service;
}
/**
���¼�
*/
void BlueSkyContext::registerCommand(int type, BlueSkyCommand* command)
{
	BlueSkyRegister::getInstance()->gameCommand[type] = command;
}