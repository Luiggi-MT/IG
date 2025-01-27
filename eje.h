#ifndef EJE_H
#define EJE_H
#include "object3d.h"
#include "rueda.h"
#include "cylinder.h"

class _eje: public _object3D
{
private:
    _cylinder Cylinder;
    _rueda Rueda;
public:
    _eje();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // EJE_H
