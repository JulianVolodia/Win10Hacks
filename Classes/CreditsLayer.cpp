#include "CreditsLayer.h"

using namespace cocos2d;

bool CreditsLayer::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    this->scheduleUpdate();

    return true;
}