#include "AchievementsLayer.h"

using namespace cocos2d;

bool AchievementsLayer::init()
{
    if (!MainLayer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    cocos2d::MenuItemFont * miBack = cocos2d::MenuItemFont::create("<<< Back");
    miBack->setFontSize(20);
    miBack->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::MENU;
    });

    cocos2d::Menu * menu = cocos2d::Menu::createWithItem(miBack);
    menu->setPosition(origin.x + visibleSize.width / 4.f, origin.y + visibleSize.height / 4.f);    menu->alignItemsVerticallyWithPadding(5.f);

    this->addChild(menu);

    scheduleUpdate();

    return true;
}