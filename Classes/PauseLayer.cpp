#include "PauseLayer.h"

using namespace cocos2d;

bool PauseLayer::init()
{
    if (!MainLayer::init())
    {
        return false;
    }

    this->scheduleUpdate();

    return true;
}