//
// Created by ASUS_BELLIL on 2019-12-04.
//

#ifndef JOUR7EXO1_UTILS_H

#include "Includes.h"

class Utils{
private:

public:
    static void drawAxe() {
        glBegin(GL_LINES);
        //axe X
        glColor3f(0, 0, 1);
        glVertex2f(0, 0);
        glVertex2f(100, 0);

        //axe Y
        glColor3f(0, 1, 0);
        glVertex2f(0, 0);
        glVertex2f(0, 100);

        glEnd();
    }

    static void drawRect(float widthDivider, float heightDivider, float r, float g, float b){
        float x = 1;
        float y = 1;
        x /= widthDivider;
        y /= heightDivider;

        glBegin(GL_QUADS);
        glColor3f(r, g, b);

        glVertex2d(-x, y);
        glVertex2d(x, y);

        glVertex2d(x, -y);
        glVertex2d(-x, -y);

        glEnd();

    }
};

#define JOUR7EXO1_UTILS_H

#endif //JOUR7EXO1_UTILS_H
