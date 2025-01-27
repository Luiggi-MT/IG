#ifndef GRUA_H
#define GRUA_H
#include "object3d.h"
#include "brazo2.h"
#include "cuerpo.h"

class _grua: public _object3D
{
private:
    _cuerpo Cuerpo;
    _brazo2 Brazo;
    GLdouble gamma;
    GLdouble delta;
    bool sentido;
public:
    _grua();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void actualizar_movimiento();
};

#endif // GRUA_H
