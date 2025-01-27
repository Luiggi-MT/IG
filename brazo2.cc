#include "brazo2.h"

_brazo2::_brazo2() {
    beta = -60;
    sentido = true;
}
void _brazo2::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(3, -0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cube.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslated(6, -1, 0);
    glRotated(beta, 0, 0, 1);
    Brazo.draw_point();
    glPopMatrix();
}
void _brazo2::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(3, -0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cube.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslated(6, -1, 0);
    glRotated(beta, 0, 0, 1);
    Brazo.draw_line();
    glPopMatrix();
}
void _brazo2::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(3, -0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cube.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(6, -1, 0);
    glRotated(beta, 0, 0, 1);
    Brazo.draw_fill();
    glPopMatrix();
}
void _brazo2::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(3, -0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cube.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslated(6, -1, 0);
    glRotated(beta, 0, 0, 1);
    Brazo.draw_chess();
    glPopMatrix();
}

void _brazo2::calculaHorizontal(GLdouble gamma){
    beta -= gamma;
    Brazo.calculoHorizontal(gamma);
}
