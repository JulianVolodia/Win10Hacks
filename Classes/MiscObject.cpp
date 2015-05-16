//#include "pch.h"
#include "MiscObject.h"


bool MiscObject::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	int r = rand() % 1;

	if (r == 1) setTexture("gfx/trawa_kamien.png");
	if (r == 2) setTexture("gfx/kamienie.png");

	setScale(2);

	scheduleUpdate();

	return true;
}

void MiscObject::update(float dt)
{
	this->setPositionY(getPositionY() - player->verticalSpeed * dt);

	if (getBoundingBox().getMaxY() <= 0)
	{
		removeFromParent();
	}
}
