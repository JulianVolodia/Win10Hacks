#pragma once

#include "cocos2d.h"
#include "MainLayer.h"

class MenuLayer : public MainLayer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    void onActive()
    {}

    CREATE_FUNC(MenuLayer);
};

