#include "pch.h"
#include "GameObject.h"

using namespace cocos2d;

void GameObject::update(float dt)
{
	if (this->getPositionY() > 0)
	{
		this->removeFromParent();
	}
}