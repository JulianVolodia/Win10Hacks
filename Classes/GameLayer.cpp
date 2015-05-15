#include "pch.h"
#include "GameLayer.h"
#include "Player.h"

using namespace cocos2d;

bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto player = Player::create();

	this->addChild(player);

	return true;
}