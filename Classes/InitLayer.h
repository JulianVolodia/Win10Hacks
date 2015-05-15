#ifndef __INIT_LAYER_H__
#define __INIT_LAYER_H__

#include "cocos2d.h"

class InitLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(InitLayer);
};

#endif // __INIT_LAYER_H__

