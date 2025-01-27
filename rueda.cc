#include "rueda.h"

_rueda::_rueda() {}

void _rueda::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(2, 1, 2);
    Cylinder.draw_point();
    glPopMatrix();
}

void _rueda::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(2, 1, 2);
    Cylinder.draw_line();
    glPopMatrix();
}

void _rueda::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(2, 1, 2);
    Cylinder.draw_fill();
    glPopMatrix();
}
void _rueda::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(2, 1, 2);
    Cylinder.draw_chess();
    glPopMatrix();
}

