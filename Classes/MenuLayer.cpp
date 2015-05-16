#include "MenuLayer.h"

using namespace cocos2d;

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
    cocos2d::MenuItemLabel * miNewGame = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("New Game", "fonts/arial.ttf",fontSize));

    vecMenuItems.pushBack(miNewGame);
    miNewGame->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::GAME;
    });

    cocos2d::MenuItemLabel * miSettings = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Settings", "fonts/arial.ttf", fontSize));
    vecMenuItems.pushBack(miSettings);
    miSettings->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::SETTINGS;
    });

    cocos2d::MenuItemLabel * miLeaderboards = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Leaderboards", "fonts/arial.ttf", fontSize));
    vecMenuItems.pushBack(miLeaderboards);
    miLeaderboards->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::LEADERBOARDS;
    });

    cocos2d::MenuItemLabel * miCredits = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Credits", "fonts/arial.ttf", fontSize));
    vecMenuItems.pushBack(miCredits);
    miCredits->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::CREDITS;
    });

    cocos2d::MenuItemLabel * miAchievements = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Achievements", "fonts/arial.ttf", fontSize));
    vecMenuItems.pushBack(miAchievements);
    miAchievements->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::ACHIEVEMENTS;
    });

    cocos2d::MenuItemLabel * miName = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Confirm", "fonts/arial.ttf", fontSize));
    vecMenuItems.pushBack(miName);

    miName->setCallback([&] (Ref* sender)
    {
        textField->detachWithIME();
        textField->setVisible(false);
        AchievementsLayer::name = textField->getString();
    });


    cocos2d::Menu * menu = cocos2d::Menu::createWithArray(vecMenuItems);
    menu->setPosition(visibleSize / 2.f);
    menu->alignItemsVerticallyWithPadding(5.f);

    miName->setPosition(miName->getPosition() + Vec2(0, -30));

    this->addChild(menu);

    textField = TextFieldTTF::textFieldWithPlaceHolder("Enter Your name here:", "fonts/arial.ttf", 30.f);

    //textField->ignoreContentAdaptWithSize(false);
    textField->setContentSize(Size(240, 160));
    textField->setAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
    textField->setPosition(visibleSize.width / 2.f, 50);

    //textField->getString();
    //textField->addEventListener(CC_CALLBACK_2(UITextFieldTest_LineWrap::textFieldEvent, this));
    this->addChild(textField);

    this->scheduleUpdate();

    return true;
}