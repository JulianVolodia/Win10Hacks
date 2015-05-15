#pragma once
#include "cocos2d.h"

class GameObject : public cocos2d::Sprite
{
public:
	virtual bool init();
	void update(float);


	CREATE_FUNC(GameObject);
};

