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
	physicalBody->setDynamic(true);

	setPhysicsBody(physicalBody);

	scheduleUpdate();

	return true;
}

void GameObject::update(float dt)
{
	this->getPhysicsBody()->setVelocity(Vec2(0,-player->verticalSpeed));

	if (this->getPositionY() < 0)
	{
		this->removeFromParent();
	}
}