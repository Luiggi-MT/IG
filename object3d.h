/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#define PI 3.14159265
#define PARTICION  50

#include <math.h>
#include <QString>
#include <QImageReader>
#include <QMessageBox>
#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
    vector<_vertex3ui> Triangles;
    vector<_vertex3f> NormalesTriangles;
    vector<_vertex3f> NormalesVertices;
    vector<_vertex3f> Texturas;

    void draw_line();
    void draw_fill();
    void draw_fill_flat();
    void draw_fill_smooth();
    void draw_chess();
    GLuint cargarImagenComoTextura(const QString& file_name);
    void create_textue(const std::string& file_name = "../../texture/");

    _vertex3f calcularNormal(_vertex3f vertice0, _vertex3f vertice1, _vertex3f vertice2);
    _vertex3f normalizar(_vertex3f vector);

};

#endif // OBJECT3D_H
