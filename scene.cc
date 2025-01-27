#include "scene.h"

_scene::_scene(){}

void _scene::draw_fill() {
    Beethoven.draw_fill();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(10, 0, 0);
    Beethoven.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslated(20, 0, 0);
    Beethoven.draw_fill();
    glPopMatrix();

}
