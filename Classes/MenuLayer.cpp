#include "MenuLayer.h"

bool MenuLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!MainLayer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    // Vector for menut items.
    cocos2d::Vector<cocos2d::MenuItem*> vecMenuItems;

    // Menu items on the main menu
    cocos2d::MenuItemFont * miNewGame = cocos2d::MenuItemFont::create("New Game");

    vecMenuItems.pushBack(miNewGame);
    miNewGame->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::GAME;
    });

    cocos2d::MenuItemFont * miSettings = cocos2d::MenuItemFont::create("Settings");
    vecMenuItems.pushBack(miSettings);
    miSettings->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::SETTINGS;
    });

    cocos2d::MenuItemFont * miLeaderboards = cocos2d::MenuItemFont::create("Leaderboards");
    vecMenuItems.pushBack(miLeaderboards);
    miLeaderboards->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::LEADERBOARDS;
    });

    cocos2d::MenuItemFont * miCredits = cocos2d::MenuItemFont::create("Credits");
    vecMenuItems.pushBack(miCredits);
    miCredits->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::CREDITS;
    });

    cocos2d::MenuItemFont * miAchievements = cocos2d::MenuItemFont::create("Achievements");
    vecMenuItems.pushBack(miAchievements);
    miAchievements->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::ACHIEVEMENTS;
    });


    cocos2d::Menu * menu = cocos2d::Menu::createWithArray(vecMenuItems);
    menu->setPosition(origin.x + visibleSize.width / 2.f, origin.y + visibleSize.height / 2.f);
    menu->alignItemsVerticallyWithPadding(5.f);

    this->addChild(menu);

    this->scheduleUpdate();

    return true;
}