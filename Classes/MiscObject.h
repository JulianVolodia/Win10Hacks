#pragma once
#include "cocos2d.h"
#include "Player.h"

class MiscObject :
	public cocos2d::Sprite
{
public:
	bool init();
	void update(float);
	CREATE_FUNC(MiscObject);
	Player * player;
};

