#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

SDL_Window *win;
SDL_GLContext context;
bool isRunning = true;
const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char **argv) {

    //region INIT
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("exo2jour7", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    context = SDL_GL_CreateContext(win);
    SDL_GL_SetSwapInterval(1);
    //endregion

    //region MatrixLoad
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluOrtho2D(0,WIDTH,0,HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //endregion

    SDL_Event event;
    const Uint8 * state;


    //region GAME LOOP
    while (isRunning) {
        glPushMatrix();

        //effacer le tampon d’affichage
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        //EventManager
        SDL_PollEvent(&event);
        state = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT){
            isRunning = false;}
        if(state[SDL_SCANCODE_LEFT]){

        }
        if(state[SDL_SCANCODE_RIGHT]){

        }
        if(state[SDL_SCANCODE_UP]){

        }
        if(state[SDL_SCANCODE_DOWN]){

        }

        //dessiner sur le buffer
        glTranslated(200, 300,0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);glVertex2d(0,0);
        glColor3ub(255,0,0);glVertex2d(200,0);
        glColor3ub(255,0,0);glVertex2d(200,100);
        glColor3ub(255,0,0);glVertex2d(0,100);
        glEnd();

        glTranslated(200,100,0);
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255,0,0);glVertex2d(0,0);
        glColor3ub(255,0,0);glVertex2d(-100,0);
        glColor3ub(255,0,0);glVertex2d(-100,100);
        glEnd();

        glRotated(45,0,0,1);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);glVertex2d(0,0);
        glColor3ub(255,0,0);glVertex2d(0,20);
        glColor3ub(255,0,0);glVertex2d(100,20);
        glColor3ub(255,0,0);glVertex2d(100,0);
        glEnd();


        glRotated(-45,0,0,1);
        glTranslated(57,65,0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);glVertex2d(0,0);
        glColor3ub(255,0,0);glVertex2d(0,20);
        glColor3ub(255,0,0);glVertex2d(50,20);
        glColor3ub(255,0,0);glVertex2d(50,0);
        glEnd();

        glTranslated(50,-30,0);
        glBegin(GL_QUADS);
        glColor3ub(255,0,0);glVertex2d(0,0);
        glColor3ub(255,0,0);glVertex2d(0,50);
        glColor3ub(255,0,0);glVertex2d(50,50);
        glColor3ub(255,0,0);glVertex2d(50,0);
        glEnd();

        glPopMatrix();

        //PAUSE
        SDL_Delay(10);

        //RENDERING
        glFlush();
        SDL_GL_SwapWindow(win);
    }
    //endregion

//region QUIT
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    SDL_Quit();
//endregion

    return 0;
}


