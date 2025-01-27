#include "sphere.h"
// Función para obtener el punto rotado
_vertex3f _sphere::obtener_punto(_vertex3f punto, float radian) {
    float radio = punto.x;
    return _vertex3f(radio * cos(radian), punto.y, -radio * sin(radian));
}

// Generar los vértices del cono por barrido
void _sphere::generar_por_barrido(vector<_vertex3f> curva_generatriz) {
    Vertices.resize(curva_generatriz.size() * PARTICION);
    float radian = (2 * PI) / PARTICION;

    // Iteramos sobre las particiones y la curva generatriz
    for (unsigned i = 0; i < PARTICION; i++) {
        for (unsigned j = 0; j < curva_generatriz.size(); j++) {
            // Asignación correcta de los vértices
            Vertices[i * curva_generatriz.size() + j] = obtener_punto(curva_generatriz[j], radian * i);
        }
    }
}

// Generar los triángulos del cono
void _sphere::generar_triangulos(unsigned int puntos)
{
    Triangles.resize(2 * Vertices.size());
    unsigned int mod = Vertices.size();

    unsigned int p0 = 1;
    unsigned int p1 = 0;
    unsigned int p2 = puntos;

    unsigned int op0 = puntos;
    unsigned int op1 = puntos + 1;
    unsigned int op2 = 1;

    int num_colum = PARTICION;
    int num_row = puntos;
    int i = 0;

    for (int row = 0; row < num_row; row++) {
        for (int colum = 0; colum < num_colum; colum++) {
            Triangles[i] = _vertex3ui(p0, p1, p2);
            i++;
            Triangles[i] = _vertex3ui(op0, op1, op2);
            i++;

            p0 = (p0 + puntos) % mod;
            p1 = (p1 + puntos) % mod;
            p2 = (p2 + puntos) % mod;

            op0 = (op0 + puntos) % mod;
            op1 = (op1 + puntos) % mod;
            op2 = (op2 + puntos) % mod;
        }

        p0 = (p0 + 1) % mod;
        p1 = (p1 + 1) % mod;
        p2 = (p2 + 1) % mod;

        op0 = (op0 + 1) % mod;
        op1 = (op1 + 1) % mod;
        op2 = (op2 + 1) % mod;
    }
}
_sphere::_sphere(float Size)
{
    vector<_vertex3f> curva_generatriz;
    const int particiones = PARTICION;
    curva_generatriz.resize(particiones+1);
    float distance = PI/particiones ;
    int i=0;
    for(float radian = PI/2; radian < (3*PI)/2; radian += distance)
        curva_generatriz[i++] = _vertex3f((Size/2) * cos(radian), (Size/2) * sin(radian), 0);
    curva_generatriz[i++] = _vertex3f((Size/2) * cos((3*PI)/2), (Size/2) * sin((3*PI)/2), 0);
    generar_por_barrido(curva_generatriz);
    generar_triangulos(curva_generatriz.size());
}
