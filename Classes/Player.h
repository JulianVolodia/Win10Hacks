#pragma once
#include "cocos2d.h"
#include "GameSceneDefines.h"
#include "EndGameLayer.h"
#include "AchievementsLayer.h"
#include "Leaderboard.h"
#include "AchievementsLayer.h"
#include "SoundEngine.h"

class Player : public cocos2d::Sprite
{
public:
    static Player* create(std::string fileName, std::string animationToRun = "", std::function<void()> callback = nullptr);
	void update(float);
	void tick(float);
	bool init();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);

	bool onContactBegin(cocos2d::PhysicsContact& contact);
	float verticalSpeed{ 150 };
	cocos2d::EventListenerTouchOneByOne * touchListener;
	cocos2d::EventListenerKeyboard * keyboardListener;
	void startGame();
	void endGame();
	void resetGame();
    void runAnimation(std::string animationToRun = "", std::function<void()> callback = nullptr);

    std::string animationFile;
	bool gameRunning{ false };
	float horizontalSpeed{ 0 };
	float acceleration{ 2 };
	void boostUp();
	int speedUp[5];
	int accelerationBase[5];
	int currentLevel = 0;
	int horSpeed = 5;

	cocos2d::Sprite * button;
	cocos2d::Sprite * getButton();
};

