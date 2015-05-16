#include "SettingsLayer.h"

USING_NS_CC;

bool SettingsLayer::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    Label * title = Label::createWithTTF("SETTINGS", "fonts/arial.ttf", 30);
    title->setPosition(visibleSize.width / 2, visibleSize.height * 3 / 5);
    this->addChild(title);

    cocos2d::MenuItemFont * miBack = cocos2d::MenuItemFont::create("<<< Back");
    miBack->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::MENU;
    });

    cocos2d::Menu * menu = cocos2d::Menu::createWithItem(miBack);
    menu->setPosition(origin.x + visibleSize.width / 2.f, origin.y + visibleSize.height / 2.f);
    menu->alignItemsVerticallyWithPadding(5.f);

    this->addChild(menu);

    this->scheduleUpdate();

    return true;
}