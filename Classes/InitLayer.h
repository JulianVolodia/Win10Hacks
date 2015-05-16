#ifndef __INIT_LAYER_H__
#define __INIT_LAYER_H__

#include "cocos2d.h"
#include "GameSceneDefines.h"

class InitLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    virtual void update(float dt)
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

#endif // __INIT_LAYER_H__

