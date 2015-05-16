#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "GameObject.h"

class Spawner : public cocos2d::Node
{
public:
	CREATE_FUNC(Spawner);
	bool init();
	void update(float);
	Player * player;
	void spawnGameObject();
	void spawnMiscObject();
private:
	float gameObjectDistance{ 150.f };
	float gameObjectlastDrop{ 0.0f };
	float miscObjectDistance{ 20.f };
	float miscObjectlastDrop{ 0.0f };

};