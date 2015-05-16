#include "pch.h"
#include "GameObject.h"

using namespace cocos2d;

bool GameObject::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	auto physicalBody = PhysicsBody::create();
	setPhysicsBody(physicalBody);

	return true;
}

void GameObject::update(float dt)
{
	this->setPositionY(getPositionY() - player->verticalSpeed*dt);

	if (this->getPositionY() < 0)
	{
		this->removeFromParent();
	}
}