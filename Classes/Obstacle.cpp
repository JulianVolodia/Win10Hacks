#include "pch.h"
#include "Obstacle.h"


bool Obstacle::init()
{
	if (!initWithFile("CloseSelected.png"))
	{
		return false;
	}

	scheduleUpdate();

	return true;
}

void Obstacle::update(float dt)
{
	GameObject::update(dt);
}