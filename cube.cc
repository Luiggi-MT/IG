
#include "cube.h"

/*****************************************************************************//**
 *
 * Implementación del cubo centrado en el origen con lado `Size`
 *
 *****************************************************************************/

_cube::_cube(float Size)
{
    // Definir vértices para un cubo centrado en el origen y de lado `Size`
    Vertices.resize(8);

    Vertices[0] = _vertex3f(-Size / 2, -Size / 2, -Size / 2); // V0
    Vertices[1] = _vertex3f(Size / 2, -Size / 2, -Size / 2);  // V1
    Vertices[2] = _vertex3f(Size / 2, -Size / 2, Size / 2);   // V2
    Vertices[3] = _vertex3f(-Size / 2, -Size / 2, Size / 2);  // V3
    Vertices[4] = _vertex3f(-Size / 2, Size / 2, -Size / 2);  // V4
    Vertices[5] = _vertex3f(Size / 2, Size / 2, -Size / 2);   // V5
    Vertices[6] = _vertex3f(Size / 2, Size / 2, Size / 2);    // V6
    Vertices[7] = _vertex3f(-Size / 2, Size / 2, Size / 2);   // V7

    // Definir triángulos (12 triángulos, 2 por cada una de las 6 caras del cubo)
    Triangles.resize(12);

    // Cara inferior (Y negativo)
    Triangles[0] = _vertex3ui(0, 1, 2);
    Triangles[1] = _vertex3ui(0, 2, 3);

    // Cara superior (Y positivo)
    Triangles[2] = _vertex3ui(4, 6, 5);
    Triangles[3] = _vertex3ui(4, 7, 6);

    // Cara frontal (Z positivo)
    Triangles[4] = _vertex3ui(3, 2, 6);
    Triangles[5] = _vertex3ui(3, 6, 7);

    // Cara trasera (Z negativo)
    Triangles[6] = _vertex3ui(0, 5, 1);
    Triangles[7] = _vertex3ui(0, 4, 5);

    // Cara derecha (X positivo)
    Triangles[8] = _vertex3ui(1, 5, 6);
    Triangles[9] = _vertex3ui(1, 6, 2);

    // Cara izquierda (X negativo)
    Triangles[10] = _vertex3ui(0, 3, 7);
    Triangles[11] = _vertex3ui(0, 7, 4);
}
