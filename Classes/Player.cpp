//#include "pch.h"
#include "Player.h"
#include "GameObject.h"

using namespace cocos2d;

bool Player::init()
{
	if (!Sprite::initWithFile("CloseNormal.png"))
	{
		return false;
	}

	setAnchorPoint(Vec2(0.5, 0.5));

	speedUp[0] = 100;
	speedUp[1] = 120;
	speedUp[2] = 150;
	speedUp[3] = 200;
	speedUp[4] = 250;

	accelerationBase[0] = 2;
	accelerationBase[1] = 4;
	accelerationBase[2] = 6;
	accelerationBase[3] = 10;
	accelerationBase[4] = 15;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto physicsBody = PhysicsBody::createBox(this->getContentSize());
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(0xFFFFFFFF);
	physicsBody->setTag(0);
	this->setPhysicsBody(physicsBody);

	CCLOG("log0");

	setPosition(Vec2(visibleSize.width / 2, - visibleSize.height / 4));

	scheduleUpdate();

	touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Player::onTouchMoved, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}


void Player::update(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	if (this->getBoundingBox().getMinX() + horizontalSpeed < 0)
	{
		setPositionX(this->getBoundingBox().size.width / 2);
	}
	else if (this->getBoundingBox().getMaxX() + horizontalSpeed > visibleSize.width)
	{
		setPositionX(visibleSize.width - this->getBoundingBox().size.width / 2);
	}
	else
	{
		this->setPositionX(getPositionX() + horizontalSpeed);
	}
	if (gameRunning)
	{
		if (verticalSpeed + acceleration * dt <= speedUp[currentLevel] + 3)
		{
			verticalSpeed += acceleration * dt;
		}

		if (acceleration - dt * accelerationBase[currentLevel] < accelerationBase[currentLevel])
		{
			acceleration = accelerationBase[currentLevel];
		}
		else
		{
			acceleration -= dt * accelerationBase[currentLevel];
		}
	}
}

bool Player::onTouchBegan(Touch* touch, Event* event)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 position = touch->getLocationInView();
	position.y = visibleSize.height - position.y;

	if (position.y > visibleSize.height / 5)
	{
		if (position.x > getPositionX())
		{
			horizontalSpeed = 5.0f;
		}
		else
		{
			horizontalSpeed = -5.0f;
		}
	}
	else
	{
		boostUp();
	}

	return true;
}

void Player::onTouchEnded(Touch* touch, Event* event)
{
	horizontalSpeed = 0.0f;
}

void Player::onTouchMoved(Touch* touch, Event* event)
{

}

void Player::boostUp()
{
	if (verticalSpeed >= speedUp[currentLevel] && currentLevel <=3)
	{
		CCLOG("BOOOOOOST!!!!");
		currentLevel++;
	}
}

void Player::startGame()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	touchListener->setEnabled(true);
	gameRunning = true;

	auto moveTo = MoveTo::create(0.5f, Vec2(visibleSize.width / 2, visibleSize.height / 4));
	runAction(moveTo);
}

void Player::endGame()
{
	CCLOG("CHUJ");
	touchListener->setEnabled(false);
	acceleration = 0;
	verticalSpeed = 0;
	gameRunning = false;
    EndGameLayer::saveScore(horizontalSpeed, 10);
	horizontalSpeed = 0;
    GameSceneDefines::queuedState = GameSceneDefines::ENDGAME;
}

void Player::resetGame()
{
	horizontalSpeed = 0;
	acceleration = 5;
}
