//#include "pch.h"
#include "GameObject.h"
#include "Coin.h"

using namespace cocos2d;

bool GameObject::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	int r = rand() % 6;

	auto physicalBody = PhysicsBody::create();

	if (r > 2)
	{
		//PRZESZKODA
		type = GameObjectType::DESTRUCTIBLE;
		if (r == 3) setTexture("gfx/akacja.png");
		if (r == 4) setTexture("gfx/duzy_kamien.png");
		if (r == 5) setTexture("gfx/kloda.png");
		physicalBody->setTag(1);
		setScale(2);
		physicalBody->addShape(PhysicsShapeBox::create(getContentSize()*1.9));

	}
	else if (r == 1)
	{
		//SPEEDUP
		type = GameObjectType::SPEEDUP;
		setTexture("gfx/potionek.png");
		physicalBody->setTag(2);
		physicalBody->addShape(PhysicsShapeBox::create(getContentSize()*1));
	}
	else
	{
		type = GameObjectType::COIN;
		//setTexture("gfx/potionek.png");
		physicalBody->setTag(2);
		physicalBody->addShape(PhysicsShapeBox::create(getContentSize() * 1));
        auto coin = Coin::create();
        coin->setScale(0.5);
        addChild(coin);
	}

	getTexture()->setAliasTexParameters();

	physicalBody->setDynamic(true);
	physicalBody->setRotationEnable(false);
	physicalBody->setContactTestBitmask(0xFFFFFFFF);
	setPhysicsBody(physicalBody);

	scheduleUpdate();

	return true;
}

void GameObject::update(float dt)
{
	this->setPositionY(getPositionY() - player->verticalSpeed * dt);

	if (getBoundingBox().getMaxY() <= 0)
	{
		this->removeFromParent();
	}
}