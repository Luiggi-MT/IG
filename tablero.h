#ifndef TABLERO_H
#define TABLERO_H

#include "object3d.h"
class _tablero: public _object3D
{
public:
    _tablero(float Size=1.0);
    void draw_line();
    void draw_fill_flat();
    void draw_fill_smooth();
};

#endif // TABLERO_H
