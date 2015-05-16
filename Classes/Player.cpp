#include "pch.h"
#include "Player.h"

using namespace cocos2d;

bool Player::init()
{
	if (!Sprite::initWithFile("CloseNormal.png"))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	CCLOG("log0");

	this->setPosition(visibleSize / 2);

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

	verticalSpeed += acceleration * dt;
}

bool Player::onTouchBegan(Touch* touch, Event* event)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 position = touch->getLocationInView();
	position.y = visibleSize.height - position.y;

	if (position.y > visibleSize.height / 5)
	{
		if (position.x > visibleSize.width / 2)
		{
			horizontalSpeed = 10.0f;
		}
		else
		{
			horizontalSpeed = -10.0f;
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
	CCLOG("BOOOOOOST!!!!");
}

void Player::startGame()
{
	touchListener->setEnabled(true);
	scheduleUpdate();
}

void Player::endGame()
{
	touchListener->setEnabled(false);
	unscheduleUpdate();
}