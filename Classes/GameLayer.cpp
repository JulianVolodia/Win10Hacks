#include "pch.h"
#include "GameLayer.h"
#include "Player.h"
#include "Spawner.h"

using namespace cocos2d;

bool GameLayer::init()
{
	/*if (!Layer::init())
	{
		return false;
	}*/

	player = Player::create();
	auto spawner = Spawner::create();
	spawner->player = player;

	this->addChild(player);
	this->addChild(spawner);
	return true;
}

Player * GameLayer::getPlayer()
{
	return player;
}

void GameLayer::onActive()
{
    player->startGame();
}