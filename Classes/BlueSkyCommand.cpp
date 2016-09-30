#include "BlueSky.h"

BlueSkyCommand::BlueSkyCommand()
{
}


BlueSkyCommand::~BlueSkyCommand()
{
}
/**
事件通知执行函数
*/
void BlueSkyCommand::execute(void* data)
{

}
/**
界面主容器
*/
Scene* BlueSkyCommand::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
获取数据模型
*/
void* BlueSkyCommand::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
获取服务
*/
void* BlueSkyCommand::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}
/**
发送事件
*/
void BlueSkyCommand::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}

/**
创建显示对象
*/
void BlueSkyCommand::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view,mediator,noteData);
}