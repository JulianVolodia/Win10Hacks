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
	cocos2d::Sprite * mapa1;
	cocos2d::Sprite * mapa2;
	cocos2d::Sprite * mapa3;
	void spawnGameObject();
	void spawnMiscObject();
	float gameObjectDistance{ 120.f };
	float gameObjectlastDrop{ 0.0f };
	float miscObjectDistance{ 20.f };
	float miscObjectlastDrop{ 0.0f };

};