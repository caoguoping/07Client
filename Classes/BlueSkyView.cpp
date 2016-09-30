#include "BlueSky.h"


BlueSkyView::BlueSkyView()
{
}


BlueSkyView::~BlueSkyView()
{
}
/**
����������
*/
Scene* BlueSkyView::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
��ȡ����ģ��
*/
void* BlueSkyView::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
��ȡ����
*/
void* BlueSkyView::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}


/**
�����¼�
*/
void BlueSkyView::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}

/**
������ʾ����
*/
void BlueSkyView::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view, mediator, noteData);
}
