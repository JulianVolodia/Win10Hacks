//#include "pch.h"
#include "Coin.h"
#include "GameObject.h"
#include "AnimationUtils.h"

using namespace cocos2d;

bool Coin::init()
{
	if (!Sprite::initWithFile("CloseNormal.png"))
	{
		return false;
	}

	setAnchorPoint(Vec2(0.5, 0.5));


	//auto visibleSize = Director::getInstance()->getVisibleSize();
	//auto physicsBody = PhysicsBody::createBox(this->getContentSize());
	//physicsBody->setDynamic(false);
	//physicsBody->setContactTestBitmask(0xFFFFFFFF);
	//physicsBody->setTag(0);
	//this->setPhysicsBody(physicsBody);
	return true;
}




bool Coin::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	GameObject * other;

	if (dynamic_cast<Coin*>(nodeA) == this)
	{
		other = dynamic_cast<GameObject*>(nodeB);
	}
	else if (dynamic_cast<Coin*>(nodeB) == this)
	{
		other = dynamic_cast<GameObject*>(nodeA);
	}

	if (other->type == GameObjectType::DESTRUCTIBLE)
	{
	}
	else
	{
	}

	return true;
}

Coin* Coin::create()
{
    std::string fileName = "coin";
    std::string animationToRun = "turn";
    std::function<void()> callback = nullptr;
    Coin* animatedSprite{ new Coin() };
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

void Coin::runAnimation(std::string animationToRun, std::function<void()> callback)
{
    if (callback)
        runAction(AnimationUtils::getAnimationWithCallback(String::createWithFormat("%s_%s", animationFile.c_str(), animationToRun.c_str())->getCString(), callback));
    else
        runAction(AnimationUtils::getAnimationRunningForever(String::createWithFormat("%s_%s", animationFile.c_str(), animationToRun.c_str())->getCString()));
}
