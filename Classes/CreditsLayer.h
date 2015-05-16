#pragma once

#include "cocos2d.h"
#include "MainLayer.h"
#include "AchievementsLayer.h"

class CreditsLayer : public MainLayer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    virtual void onActive()
    {
        AchievementsLayer::achieve(AchievementsLayer::VIEW_CREDITS);
    }

    CREATE_FUNC(CreditsLayer);
};

