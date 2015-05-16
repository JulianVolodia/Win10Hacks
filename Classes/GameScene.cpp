#include "GameScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    mapLayers[GState::MENU] = MenuLayer::create();
    mapLayers[GState::INIT] = InitLayer::create();
    mapLayers[GState::GAME] = GameLayer::create();
    mapLayers[GState::SETTINGS] = SettingsLayer::create();

    for (unsigned int i = GState::INIT; i < GState::__END; ++i)
    {
        this->addChild(mapLayers[static_cast<GState>(i)]);
        mapLayers[static_cast<GState>(i)]->setVisible(false);
        mapLayers[static_cast<GState>(i)]->setPosition(Vec2(1000, 0));
        mapLayers[static_cast<GState>(i)]->setCascadeOpacityEnabled(true);
    }

    mapLayers[GameSceneDefines::activeState]->setVisible(true);
    mapLayers[GameSceneDefines::activeState]->setPosition(Vec2(0, 0));

    this->scheduleUpdate();

    return true;
}

void GameScene::update(float dt)
{
    // Check for scene change.
    if (GDef::activeState != GDef::queuedState)
    {
        auto moveRight = MoveTo::create(0.5, Vec2(1000, 0));
        auto moveIn = MoveTo::create(0.5, Vec2(0, 0));
        auto moveLeft = MoveTo::create(0.5, Vec2(-1000, 0));
        auto fadeIn = FadeIn::create(0.5);
        auto fadeOut = FadeOut::create(0.5);
        mapLayers[GDef::queuedState]->setVisible(true);

        mapLayers[GDef::activeState]->runAction(Spawn::create(fadeOut,
            rand() % 2 == 0 ? moveLeft : moveRight, nullptr));
        mapLayers[GDef::queuedState]->runAction(Spawn::create(fadeIn,
            moveIn, nullptr));
        GDef::activeState = GDef::queuedState;
    }
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
