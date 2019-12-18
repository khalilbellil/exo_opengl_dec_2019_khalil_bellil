#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Utils.h"

SDL_Window* win;
SDL_GLContext context;

bool isRunning = true;
float dxCamera = 0;
float dyCamera = 0;


int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("exo1jour8", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_GLContext context = SDL_GL_CreateContext(win);
//    SDL_GL_SetSwapInterval(1);
    //charger la matrice de transformation
    dxCamera = 0;
    dyCamera = 0;


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) 800 / 600, 1, 1000);
    glEnable(GL_DEPTH_TEST);
	
    SDL_Event event;
    const Uint8* states = nullptr;
    while (isRunning) {

		        //effacer le tampon d’affichage
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(dxCamera+10, dyCamera+10, 5, 0, 0, 0, 0, 0, 1);

        //gestion evenement
        SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT)
            isRunning = false;

        if (states[SDL_SCANCODE_LEFT])
            dxCamera += .5;
        if (states[SDL_SCANCODE_RIGHT])
            dxCamera -= .5;
        if (states[SDL_SCANCODE_UP])
            dyCamera += .5;
        if (states[SDL_SCANCODE_DOWN])
            dyCamera -= .5;



		
        //dessin
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255); //face verte
        glVertex3d(10, -10, -2);
        glVertex3d(10, 10, -2);
        glVertex3d(-10, 10,-2);
        glVertex3d(-10, -10, -2);
        glEnd();

        glPushMatrix();
        glTranslatef(dxCamera, dyCamera, 0);




        Utils::dessinerRepere(.5);

        //pause
        SDL_Delay(3);
        //mise a jour de l'ecran
        glFlush();
        SDL_GL_SwapWindow(win);
    }
    //vider la memoire
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}