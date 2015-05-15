#include "InitLayer.h"

bool InitLayer::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    cocos2d::Sprite * logo = cocos2d::Sprite::create("Temp/logo.png");
    logo->setPosition(origin.x + visibleSize.width / 2.f, origin.y + visibleSize.height / 2.f);

    this->addChild(logo);

    return true;
}