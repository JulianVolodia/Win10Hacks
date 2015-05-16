#pragma once
#include "cocos2d.h"
#include "Player.h"

class GameObject : public cocos2d::Sprite
{
public:
	bool init();
	void update(float);
	Player * player;

	CREATE_FUNC(GameObject);
};

