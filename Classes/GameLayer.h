#pragma once
#include "cocos2d.h"
#include "Player.h"

class GameLayer : public cocos2d::Layer
{
public:
	bool init();
	CREATE_FUNC(GameLayer);
	Player * getPlayer();

    void update(float dt);

    void setupPostProcess();
private:
	Player * player;
    cocos2d::GLProgram* prog;

    float time{ 0 };
};

