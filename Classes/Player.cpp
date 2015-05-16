#include "pch.h"
#include "Player.h"
#include "GameObject.h"
#include "AnimationUtils.h"

using namespace cocos2d;

bool Player::init()
{
	if (!Sprite::initWithFile("CloseNormal.png"))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto physicsBody = PhysicsBody::createBox(this->getContentSize());
	physicsBody->setDynamic(false
													);
	this->setPhysicsBody(physicsBody);

	CCLOG("log0");

	setPosition(Vec2(visibleSize.width/2, visibleSize.height / 4));

	scheduleUpdate();
	
	touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Player::onTouchMoved, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Player::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

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
		verticalSpeed += acceleration * dt;
		if (acceleration - dt * 5 < 5)
		{
			acceleration = 5;
		}
		else
		{
			acceleration -= dt * 5;
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
	auto visibleSize = Director::getInstance()->getVisibleSize();
	touchListener->setEnabled(true);
	gameRunning = true;
}

void Player::endGame()
{
	touchListener->setEnabled(false);
	gameRunning = false;
}

void Player::resetGame()
{
	horizontalSpeed = 0;
	acceleration = 5;
}

bool Player::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	
	GameObject * other;

	if (dynamic_cast<Player*>(nodeA) == this)
	{
		other = dynamic_cast<GameObject*>(nodeB);
	}
	else if (dynamic_cast<Player*>(nodeB) == this)
	{
		other = dynamic_cast<GameObject*>(nodeA);
	}

	if (other->type == GameObjectType::DESTRUCTIBLE)
	{
		endGame();
		//end game screen
	}
	else
	{
		acceleration += 10;
	}
	
	return true;
}

Player* Player::create(std::string fileName, std::string animationToRun, std::function<void()> callback)
{
    Player* animatedSprite{ new Player() };
    animatedSprite->animationFile = fileName;

    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(String::createWithFormat("anims/%s.plist", fileName.c_str())->getCString());

    if (animatedSprite->initWithSpriteFrameName(String::createWithFormat("anims/%s_01.png", fileName.c_str())->getCString()))
    {
        auto cache = AnimationCache::getInstance();
        cache->addAnimationsWithFile(String::createWithFormat("anims/%s.plist", fileName.c_str())->getCString());

        if (animationToRun != "")
        {
            if (callback)
                animatedSprite->runAction(AnimationUtils::getAnimationWithCallback(String::createWithFormat("%s_%s", fileName.c_str(), animationToRun.c_str())->getCString(), callback));
            else
                animatedSprite->runAction(AnimationUtils::getAnimationRunningForever(String::createWithFormat("%s_%s", fileName.c_str(), animationToRun.c_str())->getCString()));
        }

        animatedSprite->autorelease();
        animatedSprite->getTexture()->setAliasTexParameters();
        animatedSprite->init();
        animatedSprite->scheduleUpdate();

        return animatedSprite;
    }

    CC_SAFE_DELETE(animatedSprite);
    return nullptr;
}

void Player::runAnimation(std::string animationToRun, std::function<void()> callback)
{
    if (callback)
        runAction(AnimationUtils::getAnimationWithCallback(String::createWithFormat("%s_%s", animationFile.c_str(), animationToRun.c_str())->getCString(), callback));
    else
        runAction(AnimationUtils::getAnimationRunningForever(String::createWithFormat("%s_%s", animationFile.c_str(), animationToRun.c_str())->getCString()));
}