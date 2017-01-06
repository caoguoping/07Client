#include "BlueSky.h"


BlueSkyMediator::BlueSkyMediator()
{
}


BlueSkyMediator::~BlueSkyMediator()
{
	//log("delete test BlueSkyMediator");
}
/**
��ʼִ�к���
*/
void BlueSkyMediator::OnRegister()
{

}
/**
��������ִ�к���
*/
void BlueSkyMediator::onRemove()
{

}
void BlueSkyMediator::setView(BlueSkyView* view)
{
	_view = view;
}
/**
* ����ʱ��͸������
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
����������
*/
Scene* BlueSkyMediator::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
��ȡ����ģ��
*/
void* BlueSkyMediator::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
��ȡ����
*/
void* BlueSkyMediator::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}
/**
�����¼�
*/
void BlueSkyMediator::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}
/**
������ʾ����
*/
void BlueSkyMediator::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view,mediator,noteData);
}

/**
��ȡ�����Ӧ��View
*/
BlueSkyView* BlueSkyMediator::getView()
{
	return _view;
}
/**
ɾ����ʾ����
*/
void BlueSkyMediator::removeView(BlueSkyMediator *mediator, bool isHide)
{
	BlueSkyRegister::getInstance()->removeView(mediator, isHide);
}