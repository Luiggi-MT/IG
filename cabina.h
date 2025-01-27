#ifndef CABINA_H
#define CABINA_H
#include "object3d.h"
#include "cube.h"
class _cabina: public _object3D
{
private:
    _cube Cube;
public:
    _cabina();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // CABINA_H
