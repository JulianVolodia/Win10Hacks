#include "MainLayer.h"

bool MainLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    this->scheduleUpdate();

    return true;
}