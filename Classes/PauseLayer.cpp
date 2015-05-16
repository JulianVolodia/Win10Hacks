#include "PauseLayer.h"

using namespace cocos2d;

bool PauseLayer::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    this->scheduleUpdate();

    return true;
}