#ifndef __MENU_LAYER_H__
#define __MENU_LAYER_H__

#include "cocos2d.h"
#include "GameSceneDefines.h"

class MenuLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    CREATE_FUNC(MenuLayer);
};

#endif // __MENU_LAYER_H__

