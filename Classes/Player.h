#pragma once
#include "cocos2d.h"

class Player : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Player);
	void update(float);
	bool init();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	float verticalSpeed{ 0 };
	EventListenerTouchOneByOne * touchListener;
	void startGame();
	void endGame();
private:
	float horizontalSpeed{ 0 };
	float acceleration{ 5 };
	void boostUp();
};

