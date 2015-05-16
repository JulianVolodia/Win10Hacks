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
};

