#pragma once

#include "cocos2d.h"

class LeaderboardLayer
    : public cocos2d::Layer
{
public:
    bool init();
    void update(float dt);

    CREATE_FUNC(LeaderboardLayer);

private:
    cocos2d::Label* scoreboard;
};

