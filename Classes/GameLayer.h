#pragma once
#include "cocos2d.h"
#include "Player.h"

class GameLayer : public cocos2d::Layer
{
public:
	bool init();
	CREATE_FUNC(GameLayer);
	Player * getPlayer();
private:
	Player * player;
};

