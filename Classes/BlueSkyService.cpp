#include "BlueSky.h"


BlueSkyService::BlueSkyService()
{
}


BlueSkyService::~BlueSkyService()
{
}
/**
界面主容器
*/
Scene* BlueSkyService::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
获取数据模型
*/
void* BlueSkyService::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
获取服务
*/
void* BlueSkyService::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}
/**
发送事件
*/
void BlueSkyService::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}
/**
创建显示对象
*/
void BlueSkyService::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view,mediator,noteData);
}
