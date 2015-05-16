#pragma once

#include "cocos2d.h"
#include "MainLayer.h"

class AchievementsLayer : public MainLayer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    virtual void onActive()
    {}

    CREATE_FUNC(AchievementsLayer);
};

