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
    mapLayers[GState::GAME] = InitLayer::create();
    mapLayers[GState::SETTINGS] = SettingsLayer::create();

    for (unsigned int i = GState::INIT; i < GState::__END; ++i)
    {
        this->addChild(mapLayers[static_cast<GState>(i)]);
        mapLayers[static_cast<GState>(i)]->setVisible(false);
    }

    mapLayers[GameSceneDefines::activeState]->setVisible(true);

    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
