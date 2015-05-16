//#include "pch.h"
#include "Spawner.h"
#include "GameLayer.h"
#include "MiscObject.h"

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
	gameObjectlastDrop += player->verticalSpeed * dt;

	if (gameObjectlastDrop > gameObjectDistance)
	{
		spawnGameObject();
		gameObjectlastDrop = 0.0f;
	}

	miscObjectlastDrop += player->verticalSpeed * dt;

	if (miscObjectlastDrop > miscObjectDistance)
	{
		spawnMiscObject();
		miscObjectlastDrop = 0.0f;
	}
}

void Spawner::spawnGameObject()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rock = GameObject::create();

	rock->setPositionY(visibleSize.height + rock->getBoundingBox().size.height);

	rock->player = player;
	float x = rand() % (int)visibleSize.width * 8;

	rock->setPositionX(visibleSize.width * 0.1 + x/10.0f);

	getParent()->addChild(rock);
}

void Spawner::spawnMiscObject()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rock = MiscObject::create();

	rock->setPositionY(visibleSize.height + rock->getBoundingBox().size.height);

	rock->player = player;
	float x = rand() % (int)visibleSize.width * 8;

	rock->setPositionX(visibleSize.width * 0.1 + x / 10.0f);

	getParent()->addChild(rock);
}
