#ifndef SCENE_H
#define SCENE_H
#include "beethoven.h"
#include "object3d.h"

class _scene: public _object3D
{
    private:
    _beethoven Beethoven;
    public:
        _scene();
        void draw_fill();
};

#endif // SCENE_H
