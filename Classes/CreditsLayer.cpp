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

    cocos2d::MenuItemLabel * miBack = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("<<< Back", "fonts/arial.ttf", fontSize));
    miBack->setColor(cocos2d::Color3B::BLACK);

    miBack->setCallback([&] (Ref* sender)
    {
        GameSceneDefines::queuedState = GameSceneDefines::MENU;
    });

    cocos2d::Menu * menu = cocos2d::Menu::createWithItem(miBack);
    menu->setPosition(origin.x + visibleSize.width / backX, origin.y + visibleSize.height / backY / 2.f);
    menu->alignItemsVerticallyWithPadding(5.f);

    Label * graphics = Label::createWithTTF("Graphics:", "fonts/arial.ttf", fontSize);
    graphics->setPosition(visibleSize.width / 2, visibleSize.height * 9.f / 12.f);
    graphics->setColor(logoColor);
    this->addChild(graphics);

    Label * graphics1 = Label::createWithTTF("Ola Wiak, Beata Lach", "fonts/arial.ttf", fontSize);
    graphics1->setPosition(visibleSize.width / 2, visibleSize.height * 8.f / 12.f);
    graphics1->setColor(cocos2d::Color3B::BLACK);
    this->addChild(graphics1);

    Label * audio = Label::createWithTTF("Audio:", "fonts/arial.ttf", fontSize);
    audio->setPosition(visibleSize.width / 2, visibleSize.height * 6.f / 12.f);
    audio->setColor(logoColor);
    this->addChild(audio);

    Label * audio1 = Label::createWithTTF("Adrian Szymczykiewicz", "fonts/arial.ttf", fontSize);
    audio1->setPosition(visibleSize.width / 2, visibleSize.height * 5.f / 12.f);
    audio1->setColor(cocos2d::Color3B::BLACK);
    this->addChild(audio1);

    Label * programmers = Label::createWithTTF("Code:", "fonts/arial.ttf", fontSize);
    programmers->setPosition(visibleSize.width / 2, visibleSize.height * 3.f / 12.f);
    programmers->setColor(logoColor);
    this->addChild(programmers);


    Label * programmers1 = Label::createWithTTF("Kacper Domanski, Krzysiek Pachulski,\nPawel Kaczynski", "fonts/arial.ttf", fontSize);
    programmers1->setPosition(visibleSize.width / 2, visibleSize.height * 2.f / 12.f);
    programmers1->setColor(cocos2d::Color3B::BLACK);
    this->addChild(programmers1);

    this->addChild(menu);

    scheduleUpdate();

    return true;
}