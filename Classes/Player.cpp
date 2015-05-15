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

	CCLog("log0");

	this->setPosition(visibleSize / 2);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Player::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Player::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	return true;
}


void Player::update(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	if (this->getBoundingBox().getMinX() + horizontalSpeed < 0)
	{
		setPositionX(0);
	}
	else if (this->getBoundingBox().getMaxX() + horizontalSpeed > visibleSize.width)
	{
		setPositionX(visibleSize.width - this->getBoundingBox().size.width);
	}
	else
	{
		this->setPositionX(getPositionX() + horizontalSpeed);
	}



}

void Player::keyPressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	CCLog("log1");
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->end();
	}
}

void Player::keyReleased(EventKeyboard::KeyCode keyCode, Event * event)
{

}
