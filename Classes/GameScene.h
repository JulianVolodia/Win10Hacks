#pragma once

#include "cocos2d.h"
#include "GameSceneDefines.h"
#include "MenuLayer.h"
#include "InitLayer.h"
#include "GameLayer.h"
#include "SettingsLayer.h"
#include "AchievementsLayer.h"
#include "CreditsLayer.h"
#include "LeaderboardLayer.h"
#include "PauseLayer.h"
#include "EndGameLayer.h"
#include <map>

class GameScene : public cocos2d::Scene
{
public:
    typedef GameSceneDefines::GameState GState;
    typedef GameSceneDefines GDef;

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    virtual void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
    std::map<GameSceneDefines::GameState, MainLayer*> mapLayers;
};
