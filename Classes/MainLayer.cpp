#include "MainLayer.h"

bool MainLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    logoColor = cocos2d::Color3B(255, 188, 46);
    disableColor = cocos2d::Color3B(50, 50, 50);
    this->scheduleUpdate();

    return true;
}