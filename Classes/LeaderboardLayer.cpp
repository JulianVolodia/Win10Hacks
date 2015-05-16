#include "pch.h"
#include "LeaderboardLayer.h"
#include "Leaderboard.h"

USING_NS_CC;

bool LeaderboardLayer::init()
{
    if (!MainLayer::init())
        return false;

    Leaderboard::push("Dalton", 100);
    Leaderboard::pull(5);

    scoreboard = Label::create();
    scoreboard->setSystemFontSize(48);
    scoreboard->setPosition(Director::getInstance()->getVisibleSize() / 2.f);
    addChild(scoreboard);

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    cocos2d::MenuItemFont * miBack = cocos2d::MenuItemFont::create("<<< Back");
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

void LeaderboardLayer::update(float dt)
{
    std::string board = "Leaderboards:\n";
    int count = 5;
    for (auto score : Leaderboard::scores)
    {
        board += String::createWithFormat("%s   %d\n", score.name.c_str(), score.score)->getCString();
        if (--count <= 0) break;
    }
    scoreboard->setString(board);
}

void LeaderboardLayer::onActive()
{
    Leaderboard::pull(5);
}