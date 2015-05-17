#pragma once

#include "cocos2d.h"
#include "MainLayer.h"

class EndGameLayer : public MainLayer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    virtual void onActive()
    {
        //coinsValue->setString(std::to_string(coins));
        scoreValue->setString(std::to_string(speed));
    }

    static void saveScore(int speed, int coins)
    {
       EndGameLayer::speed = speed;
       EndGameLayer::coins = coins;
    }

    CREATE_FUNC(EndGameLayer);
private:
    static int speed;
    static int coins;
    cocos2d::Label * scoreValue;
    cocos2d::Label * coinsValue;
};

