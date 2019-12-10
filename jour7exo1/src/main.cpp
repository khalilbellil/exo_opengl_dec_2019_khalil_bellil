#include "entities/Includes.h"
using namespace std;
int width = 800, height = 600;

int main(int argc, char **args) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32  frameStart;
    int frameTime;

    Game* game = new Game();

    game->Init("Jour7 Exo1",width,height);

    while (game->running()){
        game->Clear();

        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

        game->Clean();
    }

    SDL_DestroyWindow(game->win);
    SDL_Quit();
    return 0;

}