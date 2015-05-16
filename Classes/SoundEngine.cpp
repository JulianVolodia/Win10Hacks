#include "SoundEngine.h"

using namespace cocos2d;

void SoundEngine::preloadBackgrounds(std::vector<std::string> backgrounds)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    for (auto & x : backgrounds)
        audio->preloadBackgroundMusic(x.c_str());
}

void SoundEngine::preloadEffects(std::vector<std::string> effects)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    for (auto & x : effects)
        audio->preloadEffect(x.c_str());

}

void SoundEngine::playBackground(std::string file, float volume, bool repeat)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->setBackgroundMusicVolume(volume);
    audio->playBackgroundMusic(file.c_str(), repeat);
}

int SoundEngine::playEffect(std::string file, bool repeat,
                            float volume, float pitch, float pan)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->setEffectsVolume(volume);
    return audio->playEffect(file.c_str(), repeat, pitch, pan, volume);

}

void SoundEngine::setBackgroundVolume(float volume)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->setBackgroundMusicVolume(volume);
}
void SoundEngine::setEffectsVolume(float volume)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->setEffectsVolume(volume);
}

void SoundEngine::pauseAll(bool alsoBackground)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->pauseAllEffects();
    if (alsoBackground)
        audio->pauseBackgroundMusic();
}
void SoundEngine::pauseBackground()
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->pauseBackgroundMusic();
}
void SoundEngine::pauseEffect(unsigned int effectId)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->pauseEffect(effectId);
}

void SoundEngine::stopAll(bool alsoBackground)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->stopAllEffects();
    if (alsoBackground)
        audio->stopBackgroundMusic();
}
void SoundEngine::stopBackground()
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->stopBackgroundMusic();
}
void SoundEngine::stopEffect(unsigned int effectId)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->stopEffect(effectId);
}

void SoundEngine::resumeAll(bool alsoBackground)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->resumeAllEffects();
    if (alsoBackground)
        audio->resumeBackgroundMusic();
}
void SoundEngine::resumeBackground()
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->resumeBackgroundMusic();
}
void SoundEngine::resumeEffect(unsigned int effectId)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->resumeEffect(effectId);
}