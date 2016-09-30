#include "BlueSky.h"


BlueSkyView::BlueSkyView()
{
}


BlueSkyView::~BlueSkyView()
{
}
/**
界面主容器
*/
Scene* BlueSkyView::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
获取数据模型
*/
void* BlueSkyView::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
获取服务
*/
void* BlueSkyView::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}


/**
发送事件
*/
void BlueSkyView::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}

/**
创建显示对象
*/
void BlueSkyView::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view, mediator, noteData);
}
