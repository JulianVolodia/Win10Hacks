#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameSceneDefines.h"
#include "MenuLayer.h"
#include "InitLayer.h"
#include "GameLayer.h"
#include "SettingsLayer.h"
#include <map>

class GameScene : public cocos2d::Scene
{
public:
    typedef GameSceneDefines::GameState GState;

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
    std::map<GameSceneDefines::GameState, cocos2d::Layer*> mapLayers;
};

#endif // __GAME_SCENE_H__
