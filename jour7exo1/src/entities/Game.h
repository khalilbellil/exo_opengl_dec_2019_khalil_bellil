//
// Created by ASUS_BELLIL on 2019-12-04.
//

#ifndef JOUR7EXO1_GAME_H
#define JOUR7EXO1_GAME_H

#include "Includes.h"

class Game{
private:
    bool isRunning;
    SDL_Event event;
    const Uint8 *keyBordStates = nullptr;

public:
    SDL_Window *win;
    SDL_GLContext context;
    int WIDTH = 800;
    int HEIGHT = 600;

    Game();
    virtual ~Game();
    void Init(const char* title, int width, int height);
    void Clear();
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool running(){return isRunning;};
};

#endif //JOUR7EXO1_GAME_H
