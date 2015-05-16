#include "CreditsLayer.h"

using namespace cocos2d;

bool CreditsLayer::init()
{
    if (!MainLayer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    Label * title = Label::createWithTTF("CREDITS", "fonts/arial.ttf", titleSize);
    title->setPosition(visibleSize.width / 2, visibleSize.height * titleHeight);
    title->setColor(logoColor);
    this->addChild(title);

    cocos2d::MenuItemFont * miBack = cocos2d::MenuItemFont::create("<<< Back");
    miBack->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::MENU;
    });

    cocos2d::Menu * menu = cocos2d::Menu::createWithItem(miBack);
    menu->setPosition(origin.x + visibleSize.width / backX, origin.y + visibleSize.height / backY);
    menu->alignItemsVerticallyWithPadding(5.f);

    this->addChild(menu);

    scheduleUpdate();

    return true;
}