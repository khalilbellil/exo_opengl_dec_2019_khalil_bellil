//
// Created by ASUS_BELLIL on 2019-04-23.
//

#ifndef EXO1JOUR8_UTILS_H
#define EXO1JOUR8_UTILS_H

#include <gl/gl.h>
#include <gl/glu.h>

class Utils {
public:
    static void dessinerRepere(float taille){
        glLineWidth(5.f);
        glBegin(GL_LINES);

        glColor3ub(255,0,0);
        glVertex3f(0,0,0);
        glVertex3f(taille,0,0);
        glColor3ub(0,255,0);
        glVertex3f(0,0,0);
        glVertex3f(0,taille,0);
        glColor3ub(0,0,255);
        glVertex3f(0,0,0);
        glVertex3f(0,0,taille);
        glEnd();
    }

    static void dessinerCube(){
        glBegin(GL_QUADS);

        glColor3ub(255, 0, 0); //face rouge
        glVertex3d(1, 1, 1);
        glVertex3d(1, 1, -1);
        glVertex3d(-1, 1, -1);
        glVertex3d(-1, 1, 1);

        glColor3ub(0, 255, 0); //face verte
        glVertex3d(1, -1, 1);
        glVertex3d(1, -1, -1);
        glVertex3d(1, 1, -1);
        glVertex3d(1, 1, 1);

        glColor3ub(0, 0, 255); //face bleue
        glVertex3d(-1, -1, 1);
        glVertex3d(-1, -1, -1);
        glVertex3d(1, -1, -1);
        glVertex3d(1, -1, 1);

        glColor3ub(255, 255, 0); //face jaune
        glVertex3d(-1, 1, 1);
        glVertex3d(-1, 1, -1);
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, -1, 1);

        glColor3ub(0, 255, 255); //face cyan
        glVertex3d(1, 1, -1);
        glVertex3d(1, -1, -1);
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, 1, -1);

        glColor3ub(255, 0, 255); //face magenta
        glVertex3d(1, -1, 1);
        glVertex3d(1, 1, 1);
        glVertex3d(-1, 1, 1);
        glVertex3d(-1, -1, 1);

        glEnd();
    }

};



#endif //EXO1JOUR8_UTILS_H
