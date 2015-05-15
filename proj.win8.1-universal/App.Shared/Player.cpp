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


	this->setPosition(visibleSize / 2);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Player::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Player::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	return true;
}


void Player::update(float dt)
{


}

void Player::keyPressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->end();
	}
}

void Player::keyReleased(EventKeyboard::KeyCode keyCode, Event * event)
{

}
