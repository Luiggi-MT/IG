#include "cuerpo.h"

_cuerpo::_cuerpo() {}

void _cuerpo::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScaled(12, 4, 5);
    Cube.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-4, -2, 0);
    glRotated(90, 0 , 1, 0);
    Eje.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, -2, 0);
    glRotated(90, 0 , 1, 0 );
    Eje.draw_point();
    glPopMatrix();
}
void _cuerpo::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScaled(12, 4, 5);
    Cube.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-4, -2, 0);
    glRotated(90, 0 , 1, 0 );
    Eje.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, -2, 0);
    glRotated(90, 0 , 1, 0 );
    Eje.draw_line();
    glPopMatrix();
}
void _cuerpo::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScaled(12, 4, 5);
    Cube.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-4, -2, 0);
    glRotated(90, 0 , 1, 0 );
    Eje.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, -2, 0);
    glRotated(90, 0 , 1, 0 );
    Eje.draw_fill();
    glPopMatrix();
}
void _cuerpo::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScaled(12, 4, 5);
    Cube.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-4, -2, 0);
    glRotated(90, 0 , 1, 0 );
    Eje.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, -2, 0);
    glRotated(90, 0 , 1, 0 );
    Eje.draw_chess();
    glPopMatrix();
}
