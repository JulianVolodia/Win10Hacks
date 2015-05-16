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

	auto physicalBody = PhysicsBody::create();

	if (r > 1)
	{
		//PRZESZKODA
		type = GameObjectType::DESTRUCTIBLE;
		if (r == 2) setTexture("gfx/akacja.png");
		if (r == 3) setTexture("gfx/duzy_kamien.png");
		if (r == 4) setTexture("gfx/kloda.png");
		setScale(2);
		physicalBody->setTag(1);
	}
	else
	{
		//SPEEDUP
		type = GameObjectType::SPEEDUP;
		setTexture("CloseSelected.png");
		setRotation(-90.0f);
		physicalBody->setTag(2);
	}

	physicalBody->addShape(PhysicsShapeBox::create(getContentSize()));
	physicalBody->setDynamic(true);
	physicalBody->setContactTestBitmask(0xFFFFFFFF);
	setPhysicsBody(physicalBody);

	scheduleUpdate();

	return true;
}

void GameObject::update(float dt)
{
	this->setPositionY(getPositionY() - player->verticalSpeed * dt);

	if (this->getPositionY() < 0)
	{
		this->removeFromParent();
	}
}