//#include "pch.h"
#include "Spawner.h"
#include "GameLayer.h"
#include "MiscObject.h"

#define MAPA1 "gfx/mapa.png"
#define MAPA2 "gfx/mapa2.png"
#define MAPA3 "gfx/mapa3.png"

using namespace cocos2d;

bool Spawner::init()
{
	if (!Node::init())
	{
		return false;
	}

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	mapa1 = Sprite::create(MAPA1);
	mapa2 = Sprite::create(MAPA2);
	mapa3 = Sprite::create(MAPA3);

	mapa1->getTexture()->setAliasTexParameters();
	mapa2->getTexture()->setAliasTexParameters();
	mapa3->getTexture()->setAliasTexParameters();

	mapa1->setAnchorPoint(Vec2(0, 0));
	mapa2->setAnchorPoint(Vec2(0, 0));
	mapa3->setAnchorPoint(Vec2(0, 0));

	mapa1->setPosition(Vec2(0, 0));
	mapa2->setPosition(Vec2(0, visibleSize.height));
	mapa3->setPosition(Vec2(0, 2 * visibleSize.height));

	mapa1->setScale(2.23);
	mapa2->setScale(2.23);
	mapa3->setScale(2.23);

	addChild(mapa1);
	addChild(mapa2);
	addChild(mapa3);

	scheduleUpdate();

	return true;
}

void Spawner::update(float dt)
{
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();


	mapa1->setPositionY(mapa1->getPositionY() - player->verticalSpeed*dt);
	mapa2->setPositionY(mapa2->getPositionY() - player->verticalSpeed*dt);
	mapa3->setPositionY(mapa3->getPositionY() - player->verticalSpeed*dt);

	if (mapa1->getPositionY() < -visibleSize.height)
	{
		mapa1->setPositionY(mapa1->getPositionY() + 2*visibleSize.height);
	}

	if (mapa2->getPositionY() < -visibleSize.height)
	{
		mapa2->setPositionY(mapa2->getPositionY() + 2 * visibleSize.height);
	}

	if (mapa3->getPositionY() < -visibleSize.height)
	{
		mapa3->setPositionY(mapa3->getPositionY() + 2 * visibleSize.height);
	}

		//mapa2->setPositionY(mapa2->getPositionY() + mapa2->getContentSize().height);
		//mapa3->setPositionY(mapa3->getPositionY() + mapa3->getContentSize().height);

		//mapa1->setTexture(mapa2->getTexture());
		//mapa2->setTexture(mapa3->getTexture());

		//int r = rand() % 3;

		//if (r == 0)
		//{
		//	mapa3->setTexture(MAPA1);
		//}
		//if (r == 1)
		//{
		//	mapa3->setTexture(MAPA2);
		//}
		//if (r == 2)
		//{
		//	mapa3->setTexture(MAPA3);
		//}
	//}

	gameObjectlastDrop += player->verticalSpeed * dt;

	if (gameObjectlastDrop > gameObjectDistance)
	{
		if (player->gameRunning)
		{
			spawnGameObject();
		}
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

	rock->setPositionX(visibleSize.width * 0.1 + x / 10.0f);

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
