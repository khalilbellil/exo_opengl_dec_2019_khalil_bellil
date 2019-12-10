//
// Created by ASUS_BELLIL on 2019-12-04.
//

#include "Game.h"
using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::Init(const char *title, int width, int height){
    this->WIDTH = width;
    this->HEIGHT = height;

    //Init SDL:
    SDL_Init(SDL_INIT_EVERYTHING);

    //Init OpenGl:
    win = SDL_CreateWindow(title,
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           width, height,
                           SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    context = SDL_GL_CreateContext(win);
    gluOrtho2D(-width/2, width/2, -height/2, height/2);
}

void Game::Clear(){
    //Nettoyer la fenetre
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
}

void Game::HandleEvents() {
    SDL_PollEvent(&event);
    keyBordStates = SDL_GetKeyboardState(NULL);

    if (event.type == SDL_QUIT) {
        this->isRunning = false;
    }

    if (keyBordStates[SDL_SCANCODE_LEFT]) {

    }

    if (keyBordStates[SDL_SCANCODE_RIGHT]) {

    }

    if (keyBordStates[SDL_SCANCODE_UP]) {

    }

    if (keyBordStates[SDL_SCANCODE_DOWN]) {

    }
}

void Game::Update() {
}

void Game::Render() {
    //Dessiner les differents objets dans la fenetre:
    Utils::drawRect(2, 4, 1, 1, 1);
    glTranslatef(-1,-1,0);
    Utils::drawAxe();
}

void Game::Clean() {
    //pause dans l image
    SDL_Delay(1);

    //mise a jour de l ecran
    glFlush();
    SDL_GL_SwapWindow(win);
}