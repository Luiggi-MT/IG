#ifndef BEETHOVEN_H
#define BEETHOVEN_H
#include "file_ply_stl.h"
#include "object3d.h"

class _beethoven: public _object3D
{
private:
    vector<float> Coordinates;
    vector<unsigned int> Positions;
public:
    _beethoven(string file = "../../ply_models/");
};

#endif // BEETHOVEN_H
