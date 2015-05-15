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
    this->addChild(mapLayers[GState::MENU]);

    /*for (unsigned int i = GameScene::INIT; i < GameScene::__END; ++i)
    {
        this->addChild(mapLayers[static_cast<GameState>(i)]);
    }*/

    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
