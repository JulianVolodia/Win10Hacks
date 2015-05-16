//#include "pch.h"
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

    Label * title = Label::createWithTTF("LEADERBOARDS", "fonts/arial.ttf", titleSize);
    title->setPosition(visibleSize.width / 2, visibleSize.height * titleHeight);
    title->setColor(logoColor);
    this->addChild(title);

    cocos2d::MenuItemLabel * miBack = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("<<< Back", "fonts/arial.ttf", fontSize));
    miBack->setColor(cocos2d::Color3B::BLACK);

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

void LeaderboardLayer::update(float dt)
{
    std::string board = " \n";
    int count = 5;
    for (auto score : Leaderboard::scores)
    {
        board += String::createWithFormat("%s   %d\n", score.name.c_str(), score.score)->getCString();
        if (--count <= 0) break;
    }
    scoreboard->setString(board);
    scoreboard->setColor(cocos2d::Color3B::BLACK);
}

void LeaderboardLayer::onActive()
{
    Leaderboard::pull(5);
}