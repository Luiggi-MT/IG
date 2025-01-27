#ifndef BRAZO1_H
#define BRAZO1_H
#include "object3d.h"
#include "cabina.h"
class _brazo1: public _object3D
{
private:
    _cube Cube;
    _cabina Cabina;
    GLdouble alfa;
    bool sentido;
public:
    _brazo1();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void calculoHorizontal(GLdouble beta);
};

#endif // BRAZO1_H
