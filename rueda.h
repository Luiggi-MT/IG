#ifndef RUEDA_H
#define RUEDA_H
#include "object3d.h"
#include "cylinder.h"
class _rueda: public _object3D
{
private:
    _cylinder Cylinder;
public:
    _rueda();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // RUEDA_H
