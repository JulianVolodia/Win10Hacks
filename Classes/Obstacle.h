#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	bool init();
	void update(float);
	CREATE_FUNC(Obstacle);
};

