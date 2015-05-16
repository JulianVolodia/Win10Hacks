#pragma once

#include "cocos2d.h"
#include "GameSceneDefines.h"

class AchievementsLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    CREATE_FUNC(AchievementsLayer);
};

