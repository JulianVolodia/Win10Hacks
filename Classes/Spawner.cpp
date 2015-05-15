#include "pch.h"
#include "Spawner.h"

bool Spawner::init()
{
	if (!Node::init())
	{
		return false;
	}

	scheduleUpdate();

	return true;
}

void Spawner::update(float)
{

}