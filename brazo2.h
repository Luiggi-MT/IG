#ifndef BRAZO2_H
#define BRAZO2_H
#include "object3d.h"
#include "brazo1.h"

class _brazo2: public _object3D
{
private:
    _cube Cube;
    _brazo1 Brazo;
    GLdouble beta;
    bool sentido;
public:
    _brazo2();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void actualizar_movimiento();
    void calculaHorizontal(GLdouble gamma);
};

#endif // BRAZO2_H
