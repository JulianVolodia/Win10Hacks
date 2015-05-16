#pragma once
#include "cocos2d.h"
#include "Player.h"

enum class GameObjectType{ DESTRUCTIBLE, SPEEDUP };

class GameObject : public cocos2d::Sprite
{
public:
	bool init();
	void update(float);
	Player * player;
	GameObjectType type{ GameObjectType::DESTRUCTIBLE };
	CREATE_FUNC(GameObject);
};

