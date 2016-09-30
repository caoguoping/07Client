#include "UIUtil.h"
bool UIUtil::isInRect(Vec2 vec2, Node *node)
{
	if (vec2.x > node->getPositionX() - node->getBoundingBox().size.width / 2 && vec2.x < node->getPositionX() + node->getBoundingBox().size.width / 2)
	{

	}
	else
	{
		return false;
	}
	if (vec2.y > node->getPositionY() - node->getBoundingBox().size.height / 2 && vec2.y < node->getPositionY() + node->getBoundingBox().size.height / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}