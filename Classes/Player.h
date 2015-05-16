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

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
private:
	float horizontalSpeed{ 0 };
	float verticalSpeed{ 0 };
	float acceleration{ 5 };

};

