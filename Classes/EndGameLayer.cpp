#include "EndGameLayer.h"

using namespace cocos2d;

bool EndGameLayer::init()
{
    /*if (!cocos2d::Layer::init())
    {
        return false;
    }*/

    this->scheduleUpdate();

    return true;
}
