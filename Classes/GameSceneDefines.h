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
        __END
    };

    static GameState activeState;

    //static std::map<GameState, GameState>
};

#endif // __GAME_SCENE_DEFINES_H__