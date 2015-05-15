#include "SettingsLayer.h"

bool SettingsLayer::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();


    return true;
}