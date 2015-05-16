#ifndef __GAME_SCENE_DEFINES_H__
#define __GAME_SCENE_DEFINES_H__

class GameSceneDefines
{
public:
    static enum GameState
    {
        INIT,
        MENU,
        SETTINGS,
        CREDITS,
        ACHIEVEMENTS,
        LEADERBOARDS,
        PAUSE,
        ENDGAME,
        GAME,
        __END
    };

    static GameState activeState;
    static GameState queuedState;


};

#endif // __GAME_SCENE_DEFINES_H__