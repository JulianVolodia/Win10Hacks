#include "pch.h"
#include "GameLayer.h"
#include "Player.h"
#include "Spawner.h"

using namespace cocos2d;

bool GameLayer::init()
{
    if (!MainLayer::init())
	{
		return false;
	}

	player = Player::create();
	auto spawner = Spawner::create();
	spawner->player = player;

	this->addChild(player);
	this->addChild(spawner);

    this->scheduleUpdate();
	return true;
}

Player * GameLayer::getPlayer()
{
	return player;
}

void GameLayer::update(float dt)
{
    //time += dt;
    //prog->use();
    //auto timeLoc = prog->getUniformLocationForName("u_time");
    //prog->setUniformLocationWith1f(timeLoc, time);
}

void GameLayer::setupPostProcess()
{
    prog = new GLProgram();
    prog->initWithFilenames("shaders/postprocess.vs", "shaders/postprocess.fs");
    prog->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    prog->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    prog->link();
    prog->updateUniforms();

    auto timeLoc = prog->getUniformLocationForName("u_time");
    prog->setUniformLocationWith1f(timeLoc, time);

    // Mozemy dodac ze dwie tekstury
    auto tex1Loc = prog->getUniformLocationForName("CC_Texture1");
    prog->setUniformLocationWith1i(tex1Loc, 1);

    prog->use();

    Texture2D::TexParams p;
    p.minFilter = GL_LINEAR;
    p.magFilter = GL_LINEAR;
    p.wrapS = GL_REPEAT;
    p.wrapT = GL_REPEAT;

    auto textureCache = Director::getInstance()->getTextureCache();
    auto tex1 = textureCache->addImage("shaders/noise_512.png");
    tex1->setTexParameters(p);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, tex1->getName());

    glActiveTexture(GL_TEXTURE0);

    ShaderCache::getInstance()->addProgram(prog, "clouds");
    setShaderProgram(prog);
    prog->release();
}

void GameLayer::onActive()
{
    player->startGame();
}