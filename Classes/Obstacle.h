#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	bool init();
	CREATE_FUNC(Obstacle);
};

