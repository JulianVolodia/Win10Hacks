#pragma once

#include "cocos2d.h"
#include "MainLayer.h"

class InitLayer : public MainLayer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    virtual void onActive()
    {}

    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*)
    {
        return true;
    }
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*)
    {}
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*)
    {}

    CREATE_FUNC(InitLayer);
};

