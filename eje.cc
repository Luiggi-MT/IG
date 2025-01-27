#include "eje.h"

_eje::_eje() {}

void _eje::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cylinder.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-3, 0, 0);
    Rueda.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslated(3, 0, 0);
    Rueda.draw_point();
    glPopMatrix();

}
void _eje::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cylinder.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-3, 0, 0);
    Rueda.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslated(3, 0, 0);
    Rueda.draw_line();
    glPopMatrix();
}
void _eje::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cylinder.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-3, 0, 0);
    Rueda.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(3, 0, 0);
    Rueda.draw_fill();
    glPopMatrix();
}
void _eje::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(1, 6, 1);
    Cylinder.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-3, 0, 0);
    Rueda.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslated(3, 0, 0);
    Rueda.draw_chess();
    glPopMatrix();
}
