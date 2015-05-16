#include "InitLayer.h"

using namespace cocos2d;

bool InitLayer::init()
{
    /*if (!cocos2d::Layer::init())
    {
        return false;
    }*/

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    cocos2d::Sprite * logo = cocos2d::Sprite::create("Misc/logo.png");

    logo->setScale(0.3f);
    logo->setPosition(visibleSize / 2);

    this->addChild(logo);

    auto touchListenerInit = EventListenerTouchOneByOne::create();
    touchListenerInit->onTouchBegan = CC_CALLBACK_2(InitLayer::onTouchBegan, this);
    touchListenerInit->onTouchEnded = CC_CALLBACK_2(InitLayer::onTouchEnded, this);
    touchListenerInit->onTouchMoved = CC_CALLBACK_2(InitLayer::onTouchMoved, this);
    touchListenerInit->onTouchCancelled = CC_CALLBACK_2(InitLayer::onTouchCancelled, this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListenerInit, this);

    this->scheduleUpdate();

    return true;
}

void InitLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    GameSceneDefines::queuedState = GameSceneDefines::MENU;

}