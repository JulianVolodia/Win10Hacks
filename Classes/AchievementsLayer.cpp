#include "AchievementsLayer.h"

using namespace cocos2d;

bool AchievementsLayer::init()
{
    if (!MainLayer::init())
    {
        return false;
    }

    this->scheduleUpdate();

    return true;
}