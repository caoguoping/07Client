#include "BlueSky.h"


BlueSkyModel::BlueSkyModel()
{
}


BlueSkyModel::~BlueSkyModel()
{
}
/**
获取数据模型
*/
void* BlueSkyModel::getModel(string name)
{
	return BlueSkyRegister::getInstance()->gameModel[name];
}