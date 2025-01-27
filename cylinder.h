#ifndef CYLINDER_H
#define CYLINDER_H
#include "object3d.h"

class _cylinder:public _object3D
{
public:
    _cylinder(float Size=1.0);
private:
    void generar_por_barrido(vector<_vertex3f> curva_generatriz);
    _vertex3f obtener_punto(_vertex3f punto, float radian);
    void generar_triangulos(unsigned int puntos);
};

#endif // CYLINDER_H
