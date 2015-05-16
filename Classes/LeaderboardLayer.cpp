#include "pch.h"
#include "LeaderboardLayer.h"
#include "Leaderboard.h"

USING_NS_CC;

bool LeaderboardLayer::init()
{
    if (!Layer::init()) return false;

    Leaderboard::push("Dalton", 100);
    Leaderboard::pull(5);

    scoreboard = Label::create();
    scoreboard->setSystemFontSize(48);
    scoreboard->setPosition(Director::getInstance()->getVisibleSize() / 2.f);
    addChild(scoreboard);

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