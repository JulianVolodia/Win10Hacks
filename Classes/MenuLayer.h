#pragma once

#include "cocos2d.h"
#include "MainLayer.h"
#include "AchievementsLayer.h"

class MenuLayer : public MainLayer
{
public:
    virtual bool init();

    virtual void update(float dt)
    {}

    void onActive()
    {
        textField->attachWithIME();
    }

    CREATE_FUNC(MenuLayer);

    cocos2d::TextFieldTTF * textField;


};

