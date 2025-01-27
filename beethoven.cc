#include "beethoven.h"

_beethoven::_beethoven(string file) {
    _file_ply ply;
    file+="beethoven.ply";
    if(ply.open(file))
    {
        ply.read(Coordinates, Positions);
        ply.close();
        unsigned int pos = 0;
        auto size = Coordinates.size();
        Vertices.resize(size);
        for(unsigned int i=0;i <= size; i+=3)
        {
            Vertices[pos] = _vertex3f(Coordinates[i], Coordinates[i+1], Coordinates[i+2]);
            ++pos;
        }
        size = Positions.size();
        Triangles.resize(size);
        pos =0;
        for(unsigned int i=0; i <= size; i+=3)
        {
            Triangles[pos] = _vertex3ui(Positions[i], Positions[i+1], Positions[i+2]);
            ++pos;
        }
    }
    else
        exit(1);
}
