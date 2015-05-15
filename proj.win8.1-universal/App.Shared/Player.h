#pragma once
#include "cocos2d.h"

class Player : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Player);
	void update(float);
	bool init();

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);
private:
	float horizontalSpeed{ 0 };


};

