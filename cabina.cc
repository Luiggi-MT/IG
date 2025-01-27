#include "cabina.h"

_cabina::_cabina() {}
void _cabina::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0.5, 0 ,0);
    glScaled(1, 2, 1);
    Cube.draw_point();
    glPopMatrix();
}
void _cabina::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0.5, 0 ,0);
    glScaled(1, 2, 1);
    Cube.draw_line();
    glPopMatrix();
}
void _cabina::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0.5, 0 ,0);
    glScaled(1, 2, 1);
    Cube.draw_fill();
    glPopMatrix();
}
void _cabina::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0.5, 0 ,0);
    glScaled(1, 2, 1);
    Cube.draw_chess();
    glPopMatrix();
}
