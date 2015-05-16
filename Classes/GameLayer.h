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

    virtual void update(float dt)
    {}

    virtual void onActive()
    {}
private:
    Player * player;
};

