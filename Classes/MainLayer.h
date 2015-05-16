#pragma once

#include "cocos2d.h"
#include "GameSceneDefines.h"

class MainLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    virtual void onActive()
    {}

    CREATE_FUNC(MainLayer);

protected:
    float backX = 4.f;
    float backY = 6.f;
    float titleHeight = 5.f / 6.f;
    cocos2d::Color3B logoColor;
    cocos2d::Color3B disableColor;
    int titleSize = 40;
    int fontSize = 30;
};

