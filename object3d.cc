/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */

#include "object3d.h"

#define GREEN 0, 1, 0
#define RED 1, 0, 0
#define TRIANGLE 3

using namespace _colors_ne;

/*****************************************************************************
 *
 * Dibujar en modo línea
 *
 *****************************************************************************/
void _object3D::draw_line() {
    glBegin(GL_LINES);
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        unsigned int v0 = Triangles[i][0];
        unsigned int v1 = Triangles[i][1];
        unsigned int v2 = Triangles[i][2];

        glVertex3fv((GLfloat*)&Vertices[v0]);
        glVertex3fv((GLfloat*)&Vertices[v1]);

        glVertex3fv((GLfloat*)&Vertices[v1]);
        glVertex3fv((GLfloat*)&Vertices[v2]);

        glVertex3fv((GLfloat*)&Vertices[v2]);
        glVertex3fv((GLfloat*)&Vertices[v0]);
    }
    glEnd();
}

/*****************************************************************************//**
 *
 * Dibujar en modo relleno
 *
 *****************************************************************************/
void _object3D::draw_fill() {
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        glVertex3fv((GLfloat*)&Vertices[Triangles[i][0]]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i][1]]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i][2]]);
    }
    glEnd();
}

/*****************************************************************************
 *
 * Dibujar con sombreado plano (flat shading)
 *
 *****************************************************************************/
void _object3D::draw_fill_flat() {
    glShadeModel(GL_FLAT);

    NormalesTriangles.resize(Triangles.size());

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        _vertex3f v0 = Vertices[Triangles[i][0]];
        _vertex3f v1 = Vertices[Triangles[i][1]];
        _vertex3f v2 = Vertices[Triangles[i][2]];
        _vertex3f normal = calcularNormal(v0, v1, v2);

        NormalesTriangles[i] = normal;
        glNormal3f(normal.x, normal.y, normal.z);

        glVertex3fv((GLfloat*)&Vertices[Triangles[i][0]]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i][1]]);
        glVertex3fv((GLfloat*)&Vertices[Triangles[i][2]]);
    }
    glEnd();

    glDisable(GL_LIGHTING);
}

/*****************************************************************************
 *
 * Dibujar con sombreado suave (smooth shading)
 *
 *****************************************************************************/
void _object3D::draw_fill_smooth() {
    glShadeModel(GL_SMOOTH);

    // Inicializar el vector de normales por vértice
    NormalesVertices.resize(Vertices.size(), _vertex3f(0.0f, 0.0f, 0.0f));

    // Acumular las normales de los triángulos en los vértices
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        unsigned int v0 = Triangles[i][0];
        unsigned int v1 = Triangles[i][1];
        unsigned int v2 = Triangles[i][2];

        _vertex3f normal = calcularNormal(Vertices[v0], Vertices[v1], Vertices[v2]);

        NormalesVertices[v0].x += normal.x;
        NormalesVertices[v0].y += normal.y;
        NormalesVertices[v0].z += normal.z;

        NormalesVertices[v1].x += normal.x;
        NormalesVertices[v1].y += normal.y;
        NormalesVertices[v1].z += normal.z;

        NormalesVertices[v2].x += normal.x;
        NormalesVertices[v2].y += normal.y;
        NormalesVertices[v2].z += normal.z;
    }

    // Normalizar las normales por vértice
    for (unsigned int i = 0; i < NormalesVertices.size(); i++) {
        NormalesVertices[i] = normalizar(NormalesVertices[i]);
    }

    // Dibujar los triángulos con normales suavizadas
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        for (unsigned int j = 0; j < 3; j++) {
            unsigned int vertexIndex = Triangles[i][j];
            _vertex3f normal = NormalesVertices[vertexIndex];
            _vertex3f vertex = Vertices[vertexIndex];
            glNormal3f(normal.x, normal.y, normal.z);
            glVertex3f(vertex.x, vertex.y, vertex.z);
        }
    }
    glEnd();

    glDisable(GL_LIGHTING);
}

/*****************************************************************************
 *
 * Dibujar en modo ajedrez
 *
 *****************************************************************************/
void _object3D::draw_chess() {
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        (i % 2 == 0) ? glColor3f(GREEN) : glColor3f(RED);
        for (unsigned int j = 0; j < TRIANGLE; j++) {
            glVertex3fv((GLfloat*)&Vertices[Triangles[i][j]]);
        }
    }
    glEnd();
}

/*****************************************************************************
 *
 * Calcular normal de un triángulo
 *
 *****************************************************************************/
_vertex3f _object3D::calcularNormal(_vertex3f vertice0, _vertex3f vertice1, _vertex3f vertice2) {
    _vertex3f A(vertice1.x - vertice0.x, vertice1.y - vertice0.y, vertice1.z - vertice0.z);
    _vertex3f B(vertice2.x - vertice0.x, vertice2.y - vertice0.y, vertice2.z - vertice0.z);

    _vertex3f normal;
    normal.x = (A.y * B.z) - (A.z * B.y);
    normal.y = (A.z * B.x) - (A.x * B.z);
    normal.z = (A.x * B.y) - (A.y * B.x);

    return normalizar(normal);
}

/*****************************************************************************
 *
 * Normalizar un vector
 *
 *****************************************************************************/
_vertex3f _object3D::normalizar(_vertex3f vector) {
    float norma = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);

    if (norma > 0.0f) {
        vector.x /= norma;
        vector.y /= norma;
        vector.z /= norma;
    }
    return vector;
}


GLuint _object3D::cargarImagenComoTextura(const QString& file_name){
    // Code for reading an image
    QImage Image;
    QImageReader Reader(file_name);
    Reader.setAutoTransform(true);
    Image = Reader.read();

    if (Image.isNull()) {
        // Mostrar mensaje de error si la imagen no se puede cargar
        QMessageBox::information(nullptr, "Error", "No se pudo cargar la imagen.");
        exit(-1);
    }
    GLuint texture;
    Image = Image.mirrored();
    Image = Image.convertToFormat(QImage::Format_RGB888);

    glGenTextures(1, &texture);  // Genera un identificador para la textura

    glBindTexture(GL_TEXTURE_2D, texture);  // Asocia la textura generada

    // Control de la aplicación de la textura
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    // Pasar la imagen a OpenGL para crear una textura 2D
    glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.width(), Image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, Image.bits());

    return texture;
}

