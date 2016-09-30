#include "BlueSky.h"


BlueSkyService::BlueSkyService()
{
}


BlueSkyService::~BlueSkyService()
{
}
/**
����������
*/
Scene* BlueSkyService::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
��ȡ����ģ��
*/
void* BlueSkyService::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
��ȡ����
*/
void* BlueSkyService::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}
/**
�����¼�
*/
void BlueSkyService::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}
/**
������ʾ����
*/
void BlueSkyService::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view,mediator,noteData);
}
