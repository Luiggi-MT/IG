#ifndef CONE_H
#define CONE_H

#include "object3d.h"

class _cone: public _object3D
{
public:
    _cone(float Size=1.0);
private:
    void generar_por_barrido(vector<_vertex3f> curva_generatriz);
    _vertex3f obtener_punto(_vertex3f punto, float radian);
    void generar_triangulos(unsigned int puntos);

};

#endif // CONE_H
