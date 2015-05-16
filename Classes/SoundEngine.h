#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <string>
#include <vector>

class SoundEngine : public cocos2d::Ref
{
public:
    static void preloadBackgrounds(std::vector<std::string> backgrounds);
    static void preloadEffects(std::vector<std::string> effects);

    static void playBackground(std::string file, float volume, bool repeat);
    static int playEffect(std::string file, bool repeat,
                          float volume = 1.0f, float pitch = 1.0f, float pan = 0.0f);

    static void setBackgroundVolume(float volume);
    static void setEffectsVolume(float volume);

    static void pauseAll(bool alsoBackground);
    static void pauseBackground();
    static void pauseEffect(unsigned int effectId);

    static void stopAll(bool alsoBackground);
    static void stopBackground();
    static void stopEffect(unsigned int effectId);

    static void resumeAll(bool alsoBackground);
    static void resumeBackground();
    static void resumeEffect(unsigned int effectId);
};

