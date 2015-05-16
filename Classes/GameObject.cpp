#include "pch.h"
#include "GameObject.h"

using namespace cocos2d;

bool GameObject::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	int r = rand() % 5;

	if (r > 1)
	{
		//PRZESZKODA
		type = GameObjectType::DESTRUCTIBLE;
		setTexture("CloseSelected.png");
		setRotation(90.0f);
	}
	else
	{
		//SPEEDUP
		type = GameObjectType::SPEEDUP;
		setTexture("CloseSelected.png");
		setRotation(-90.0f);
	}

	auto physicalBody = PhysicsBody::createBox(getContentSize());
	setPhysicsBody(physicalBody);

	scheduleUpdate();

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