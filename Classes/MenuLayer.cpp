#include "MenuLayer.h"

bool MenuLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!cocos2d::Layer::init())
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


    cocos2d::Menu * menu = cocos2d::Menu::createWithArray(vecMenuItems);
    menu->setPosition(origin.x + visibleSize.width / 2.f, origin.y + visibleSize.height / 2.f));

    this->addChild(menu);

    return true;
}