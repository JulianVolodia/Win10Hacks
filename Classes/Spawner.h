#pragma once
#include "cocos2d.h"
#include "Player.h"

class Spawner : public cocos2d::Node
{
public:
	CREATE_FUNC(Spawner);
	bool init();
	void update(float);
	Player * player;
	void spawn();
private:
	float distance{ 50.f };
	float lastDrop{ 0.0f };
};