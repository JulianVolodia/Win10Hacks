#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "MainLayer.h"

class GameLayer : public MainLayer
{
public:
	bool init();
	CREATE_FUNC(GameLayer);
	Player * getPlayer();

    void update(float dt);

    void setupPostProcess();

    virtual void onActive();
private:
	Player * player;
    cocos2d::GLProgram* prog;

    float time{ 0 };
};

