#include "CreditsLayer.h"

using namespace cocos2d;

bool CreditsLayer::init()
{
    if (!MainLayer::init())
    {
        return false;
    }

    this->scheduleUpdate();

    return true;
}