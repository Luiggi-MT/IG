#include "grua.h"

_grua::_grua() {
    gamma = 120;
    delta = 1;
    sentido = true;
}
void _grua::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cuerpo.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 2, 0);
    glRotated(gamma, 0, 0, 1);
    glScaled(delta, 1, 1);
    Brazo.draw_point();
    glPopMatrix();

}
void _grua::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cuerpo.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 2, 0);
    glRotated(gamma, 0, 0, 1);
    glScaled(delta, 1, 1);
    Brazo.draw_line();
    glPopMatrix();
}
void _grua::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cuerpo.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 2, 0);
    glRotated(gamma, 0, 0, 1);
    glScaled(delta, 1, 1);
    Brazo.draw_fill();
    glPopMatrix();
}
void _grua::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cuerpo.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 2, 0);
    glRotated(gamma, 0, 0, 1);
    glScaled(delta, 1, 1);
    Brazo.draw_chess();
    glPopMatrix();
}
void _grua::actualizar_movimiento(){
    if (sentido) {
        gamma += 1.0;
        delta += 0.5/4;
        Brazo.calculaHorizontal(1);
        if (gamma >= 170.0) sentido = false;
    } else {
        gamma -= 1.0;
        delta -= 0.5/4;
        Brazo.calculaHorizontal(-1);
        if (gamma <= 120.0) sentido = true;
    }
}
