//#include "pch.h"
#include "Player.h"
#include "GameObject.h"
#include "AnimationUtils.h"
#include "GameLayer.h"

using namespace cocos2d;

bool Player::init()
{
	if (!Sprite::initWithFile("CloseNormal.png"))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	setAnchorPoint(Vec2(0.5, 0.5));

	button = Sprite::create();

	button->setAnchorPoint(Vec2(0.5, 0.5));
	button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 8));
	button->setScale(0.5);

	speedUp[0] = 150;
	speedUp[1] = 300;
	speedUp[2] = 400;
	speedUp[3] = 500;
	speedUp[4] = 700;

	accelerationBase[0] = 5;
	accelerationBase[1] = 10;
	accelerationBase[2] = 15;
	accelerationBase[3] = 25;
	accelerationBase[4] = 40;

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

	keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Player::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Player::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	setScale(0.75);

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
		if (verticalSpeed + acceleration * dt <= speedUp[currentLevel] + 3 || currentLevel == 4)
		{
			verticalSpeed += acceleration * dt;
		}

		if (verticalSpeed + acceleration * dt < speedUp[currentLevel])
		{
			button->setTexture("gfx/wylaczony.png");
		}
		else
		{
			button->setTexture("gfx/wlaczony.png");
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
		if (++currentLevel <= 3) runAnimation(String::createWithFormat("lvl%d", currentLevel)->getCString());
	}

    SoundEngine::stopBackground();
    SoundEngine::playEffect("audio/sweep.wav", false, 1.0);
    SoundEngine::playBackground("audio/afryka_1_mock_up_" + std::to_string(currentLevel) + ".wav", 1.0, true);
}

void Player::startGame()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	touchListener->setEnabled(true);
	keyboardListener->setEnabled(true);
	gameRunning = true;
	button->setTexture("gfx/wylaczony.png");

	auto moveTo = MoveTo::create(0.5f, Vec2(visibleSize.width / 2, visibleSize.height / 4));
	runAction(moveTo);
    SoundEngine::stopBackground();
    SoundEngine::playBackground("audio/afryka_1_mock_up.wav", 1.0, true);
    SoundEngine::playEffect("audio/rundirt_long.wav", true, 0.5);
}

void Player::endGame()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	CCLOG("CHUJ");
	touchListener->setEnabled(false);
	keyboardListener->setEnabled(false);
	acceleration = 0;
	verticalSpeed = 0;
	gameRunning = false;
    EndGameLayer::saveScore(horizontalSpeed, 10);
    Leaderboard::push(AchievementsLayer::name, horizontalSpeed);
	horizontalSpeed = 0;
    AchievementsLayer::achieve(AchievementsLayer::FIRST_GAME);
    GameSceneDefines::queuedState = GameSceneDefines::ENDGAME;

	auto moveTo = MoveTo::create(0.5f, Vec2(visibleSize.width / 2, -visibleSize.height / 4));
	runAction(moveTo);
	verticalSpeed = 100;
}

void Player::resetGame()
{
	horizontalSpeed = 0;
	acceleration = 5;
}

void Player::keyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		horizontalSpeed = -horSpeed;
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		horizontalSpeed = horSpeed;
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		boostUp();
	}
}

void Player::keyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		horizontalSpeed = 0;
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		horizontalSpeed = 0;
	}
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


Sprite * Player::getButton()
{
	return button;
}
