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
界面主容器
*/
Scene* BlueSkyContext::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}
/**
发送事件
*/
void BlueSkyContext::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}
/**
注册数据模型
*/
void BlueSkyContext::registerModel(string name, BlueSkyModel *model)
{

	BlueSkyRegister::getInstance()->gameModel[name] = model;
}
/**
注册服务
*/
void BlueSkyContext::registerService(string name, BlueSkyService* service)
{
	BlueSkyRegister::getInstance()->registerOnEvent(service);
	BlueSkyRegister::getInstance()->gameService[name] = service;
}
/**
绑定事件
*/
void BlueSkyContext::registerCommand(int type, BlueSkyCommand* command)
{
	BlueSkyRegister::getInstance()->gameCommand[type] = command;
}