#include "BlueSky.h"


BlueSkyMediator::BlueSkyMediator()
{
}


BlueSkyMediator::~BlueSkyMediator()
{
	//log("delete test BlueSkyMediator");
}
/**
开始执行函数
*/
void BlueSkyMediator::OnRegister()
{

}
/**
结束回收执行函数
*/
void BlueSkyMediator::onRemove()
{

}
void BlueSkyMediator::setView(BlueSkyView* view)
{
	_view = view;
}
/**
* 创建时的透传参数
*/
void* BlueSkyMediator::getNoteData()
{
	return _noteData;
}
void BlueSkyMediator::setNoteData(void* data)
{
	_noteData = data;
}

/**
界面主容器
*/
Scene* BlueSkyMediator::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
获取数据模型
*/
void* BlueSkyMediator::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
获取服务
*/
void* BlueSkyMediator::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}
/**
发送事件
*/
void BlueSkyMediator::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}
/**
创建显示对象
*/
void BlueSkyMediator::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view,mediator,noteData);
}

/**
获取自身对应的View
*/
BlueSkyView* BlueSkyMediator::getView()
{
	return _view;
}
/**
删除显示对象
*/
void BlueSkyMediator::removeView(BlueSkyMediator *mediator, bool isHide)
{
	BlueSkyRegister::getInstance()->removeView(mediator, isHide);
}