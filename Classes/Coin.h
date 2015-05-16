#pragma once
#include "cocos2d.h"
#include "GameSceneDefines.h"
#include "EndGameLayer.h"
#include "AchievementsLayer.h"
#include "Leaderboard.h"
#include "AchievementsLayer.h"
#include "SoundEngine.h"

class Coin : public cocos2d::Sprite
{
public:
    static Coin* create();

	bool init();
	bool onContactBegin(cocos2d::PhysicsContact& contact);

    void runAnimation(std::string animationToRun = "", std::function<void()> callback = nullptr);

    std::string animationFile;

};

