#include "AchievementsLayer.h"

using namespace cocos2d;

bool AchievementsLayer::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    this->scheduleUpdate();

    return true;
}