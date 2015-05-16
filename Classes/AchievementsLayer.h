#pragma once

#include "cocos2d.h"
#include "MainLayer.h"
#include <map>
#include <string>

class AchievementsLayer : public MainLayer
{
public:
    static enum ACHIEVEMENTS
    {
        FIRST_GAME,
        VIEW_CREDITS
    };
    virtual bool init();

    virtual void update(float dt)
    {}

    virtual void onActive();


    CREATE_FUNC(AchievementsLayer);

    static void achieve(ACHIEVEMENTS code)
    {
        mapA[code] = true;
    }

    static std::string name;

private:
    static std::map<ACHIEVEMENTS, bool> mapA;
    cocos2d::Label * a1;
    cocos2d::Label * a2;
};

