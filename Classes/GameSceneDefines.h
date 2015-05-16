#ifndef __GAME_SCENE_DEFINES_H__
#define __GAME_SCENE_DEFINES_H__

class GameSceneDefines
{
public:
    static enum GameState
    {
        INIT,
        MENU,
        GAME,
        SETTINGS,
        CREDITS,
        ACHIEVEMENTS,
        LEADERBOARDS,
        PAUSE,
        ENDGAME,
        __END
    };

    static GameState activeState;
    static GameState queuedState;


};

#endif // __GAME_SCENE_DEFINES_H__