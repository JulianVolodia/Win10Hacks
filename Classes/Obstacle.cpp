#include "pch.h"
#include "Obstacle.h"

USING_NS_CC;

bool Obstacle::init()
{
	if (!GameObject::init())
	{
		return false;
	}

	setTexture("CloseSelected.png");
	getPhysicsBody()->addShape(PhysicsShapeBox::create(getContentSize()));
	scheduleUpdate();

	return true;
}

void Obstacle::update(float dt)
{
	GameObject::update(dt);
}