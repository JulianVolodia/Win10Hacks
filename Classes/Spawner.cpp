#include "pch.h"
#include "Spawner.h"
#include "GameLayer.h"
#include "Obstacle.h"

using namespace cocos2d;

bool Spawner::init()
{
	if (!Node::init())
	{
		return false;
	}

	scheduleUpdate();

	return true;
}

void Spawner::update(float dt)
{
	lastDrop += player->verticalSpeed*dt;

	if (lastDrop > distance)
	{
		spawn();
		lastDrop = 0.0f;
	}
}

void Spawner::spawn()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rock = Obstacle::create();
	
	rock->setPositionY(visibleSize.height + rock->getBoundingBox().size.height);
	
	rock->player = player;
	float x = rand() % (int)visibleSize.width * 8;

	rock->setPositionX(visibleSize.width * 0.1 + x/10.0f);

	getParent()->addChild(rock);
}