#pragma once

#include "cocos2d.h"
#include "MainLayer.h"

class LeaderboardLayer
    : public MainLayer
{
public:
    bool init();
    void update(float dt);
    virtual void onActive();

    CREATE_FUNC(LeaderboardLayer);

private:
    cocos2d::Label* scoreboard;
};

