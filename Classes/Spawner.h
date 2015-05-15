#pragma once
#include "cocos2d.h"

class Spawner : public cocos2d::Node
{
public:
	CREATE_FUNC(Spawner);
	bool init();
	void update(float);

private:
	float delay{ 2.5f };
};