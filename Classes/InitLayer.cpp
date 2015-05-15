#include "InitLayer.h"

bool InitLayer::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    cocos2d::Sprite * logo = cocos2d::Sprite::create("Misc/logo.png");
		
		logo->setScale(0.3f);

    logo->setPosition(visibleSize / 2);

    this->addChild(logo);

    return true;
}