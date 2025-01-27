#include "brazo1.h"

_brazo1::_brazo1() {
    alfa=-60;
}
void _brazo1::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(2, 0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 4, 1);
    Cube.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, 0, 0);
    glRotated(alfa, 0, 0, 1);
    Cabina.draw_point();
    glPopMatrix();
}
void _brazo1::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(2, 0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 4, 1);
    Cube.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, 0, 0);
    glRotated(alfa, 0, 0, 1);
    Cabina.draw_line();
    glPopMatrix();

}
void _brazo1::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(2, 0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 4, 1);
    Cube.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, 0, 0);
    glRotated(alfa, 0, 0, 1);
    Cabina.draw_fill();
    glPopMatrix();
}
void _brazo1::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(2, 0.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(1, 4, 1);
    Cube.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslated(4, 0, 0);
    glRotated(alfa, 0, 0, 1);
    Cabina.draw_chess();
    glPopMatrix();
}
void _brazo1::calculoHorizontal(GLdouble beta){
    alfa -= beta;
}

