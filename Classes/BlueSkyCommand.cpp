#include "BlueSky.h"

BlueSkyCommand::BlueSkyCommand()
{
}


BlueSkyCommand::~BlueSkyCommand()
{
}
/**
�¼�ִ֪ͨ�к���
*/
void BlueSkyCommand::execute(void* data)
{

}
/**
����������
*/
Scene* BlueSkyCommand::getcontainer()
{
	return BlueSkyRegister::getInstance()->container;
}

/**
��ȡ����ģ��
*/
void* BlueSkyCommand::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}
/**
��ȡ����
*/
void* BlueSkyCommand::getService(string name)
{
	return BlueSkyRegister::getInstance()->gameService[name];
}
/**
�����¼�
*/
void BlueSkyCommand::blueSkyDispatchEvent(int type, void* data)
{
	BlueSkyRegister::getInstance()->blueSkyDispatchEvent(type, data);
}

/**
������ʾ����
*/
void BlueSkyCommand::creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData)
{
	BlueSkyRegister::getInstance()->creatView(view,mediator,noteData);
}