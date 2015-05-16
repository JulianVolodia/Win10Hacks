#include "pch.h"
#include "MiscObject.h"


bool MiscObject::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	scheduleUpdate();

	return true;
}

void MiscObject::update(float dt)
{
	this->setPositionY(getPositionY() - player->verticalSpeed * dt);

	if (getPositionY() <= 0)
	{
		setPositionY(getPositionY() + 2 * getContentSize().height);
	}
}
