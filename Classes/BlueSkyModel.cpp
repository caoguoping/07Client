#include "BlueSky.h"


BlueSkyModel::BlueSkyModel()
{
}


BlueSkyModel::~BlueSkyModel()
{
}
/**
��ȡ����ģ��
*/
void* BlueSkyModel::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}