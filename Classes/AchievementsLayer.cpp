#include "AchievementsLayer.h"

using namespace cocos2d;

std::map<AchievementsLayer::ACHIEVEMENTS, bool> AchievementsLayer::mapA = std::map<AchievementsLayer::ACHIEVEMENTS, bool>();
std::string AchievementsLayer::name = "";

bool AchievementsLayer::init()
{
    if (!MainLayer::init())
    {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    Label * title = Label::createWithTTF("ACHIEVEMENTS", "fonts/arial.ttf", titleSize);
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

    a1 = Label::createWithTTF("First Game!", "fonts/arial.ttf", titleSize);
    a1->setPosition(visibleSize.width / 2, visibleSize.height * 4.f / 7.f);
    a1->setColor(disableColor);
    this->addChild(a1);

    a2 = Label::createWithTTF("View Credits!", "fonts/arial.ttf", titleSize);
    a2->setPosition(visibleSize.width / 2, visibleSize.height * 3.f / 7.f);
    a2->setColor(disableColor);
    this->addChild(a2);

    scheduleUpdate();

    return true;
}

void AchievementsLayer::onActive()
{
    if (mapA[FIRST_GAME])
        a1->setColor(logoColor);

    if (mapA[VIEW_CREDITS])
        a2->setColor(logoColor);
}