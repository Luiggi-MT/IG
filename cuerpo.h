#ifndef CUERPO_H
#define CUERPO_H
#include "object3d.h"
#include "eje.h"
#include "cube.h"

class _cuerpo: public _object3D
{
private:
    _cube Cube;
    _eje Eje;
public:
    _cuerpo();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // CUERPO_H
