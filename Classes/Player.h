#pragma once
#include "cocos2d.h"

class Player : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Player);
	void update(float);
	void tick(float);
	bool init();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	float verticalSpeed{ 50 };
	cocos2d::EventListenerTouchOneByOne * touchListener;
	void startGame();
	void endGame();
	void resetGame();
	bool gameRunning{ false };
private:
	float horizontalSpeed{ 0 };
	float acceleration{ 150 };
	void boostUp();
};

