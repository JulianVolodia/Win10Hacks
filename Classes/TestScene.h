#pragma once

#include "cocos2d.h"

class TestScene : public cocos2d::Scene
{
public:
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(TestScene);
};
