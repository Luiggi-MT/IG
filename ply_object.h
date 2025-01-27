#ifndef PLY_OBJECT_H
#define PLY_OBJECT_H
#include "file_ply_stl.h"
#include "object3d.h"
class _ply_object: public _object3D
{
    private:
    vector<float> Coordinates;
    vector<unsigned int> Positions;
    public:
    _ply_object(string file = "../../ply_models/");
};

#endif // PLY_OBJECT_H
