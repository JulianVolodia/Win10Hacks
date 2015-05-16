#include "EndGameLayer.h"

using namespace cocos2d;

int EndGameLayer::speed = 0;
int EndGameLayer::coins = 0;

bool EndGameLayer::init()
{
    if (!MainLayer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    Label * title = Label::createWithTTF("GAME OVER!", "fonts/arial.ttf", titleSize);
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

    Label * scoreLabel = Label::createWithTTF("Score: ", "fonts/arial.ttf", fontSize);
    title->setPosition(visibleSize.width / 2 - 50, visibleSize.height);
    title->setColor(logoColor);
    this->addChild(scoreLabel);

    Label * coinsLabel = Label::createWithTTF("Coins: ", "fonts/arial.ttf", fontSize);
    title->setPosition(visibleSize.width / 2 - 50, visibleSize.height * 3.f / 7.f);
    title->setColor(logoColor);
    this->addChild(coinsLabel);

    Label * scoreValue = Label::createWithTTF(std::to_string(speed), "fonts/arial.ttf", fontSize);
    title->setPosition(visibleSize.width / 2, visibleSize.height);
    this->addChild(scoreValue);

    Label * coinsValue = Label::createWithTTF(std::to_string(coins), "fonts/arial.ttf", fontSize);
    title->setPosition(visibleSize.width / 2, visibleSize.height * 3.f / 7.f);
    this->addChild(coinsValue);

    scheduleUpdate();

    return true;
}
