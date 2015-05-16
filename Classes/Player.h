#pragma once
#include "cocos2d.h"
#include "GameSceneDefines.h"
#include "EndGameLayer.h"

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
	float verticalSpeed{ 75 };
	cocos2d::EventListenerTouchOneByOne * touchListener;
	void startGame();
	void endGame();
	void resetGame();
	bool gameRunning{ false };
	float horizontalSpeed{ 0 };
	float acceleration{ 2 };
	void boostUp();
	int speedUp[5];
	int accelerationBase[5];
	int currentLevel = 0;
};

