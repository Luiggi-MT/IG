#include "tablero.h"

/*****************************************************************************//**
 * Implementación del tablero de ajedrez con tamaño `Size`
 *****************************************************************************/

_tablero::_tablero(float Size) {
    // 64 casillas -> 128 triángulos -> 384 vértices
    Vertices.resize(384);
    Texturas.resize(384);

    float salto = Size / 8; // Tamaño de cada casilla
    int idx = 0;           // Índice global para los vértices

    // Generar los vértices y las coordenadas de textura
    for (int i = 0; i < 8; i++) {       // Filas
        for (int j = 0; j < 8; j++) {   // Columnas
            // Esquinas de la casilla (cuadrado)
            float x0 = -Size / 2 + j * salto;
            float y0 = -Size / 2 + i * salto;
            float x1 = x0 + salto;
            float y1 = y0 + salto;

            // Definir los 6 vértices para dos triángulos (para una casilla)
            _vertex3f v0 = _vertex3f(x0, y0, 0); // Esquina inferior izquierda
            _vertex3f v1 = _vertex3f(x1, y0, 0); // Esquina inferior derecha
            _vertex3f v2 = _vertex3f(x1, y1, 0); // Esquina superior derecha
            _vertex3f v3 = _vertex3f(x1, y1, 0); // Esquina superior derecha (repetido)
            _vertex3f v4 = _vertex3f(x0, y1, 0); // Esquina superior izquierda
            _vertex3f v5 = _vertex3f(x0, y0, 0); // Esquina inferior izquierda (repetido)

            // Asignar los vértices a la lista
            Vertices[idx++] = v0;
            Vertices[idx++] = v1;
            Vertices[idx++] = v2;
            Vertices[idx++] = v3;
            Vertices[idx++] = v4;
            Vertices[idx++] = v5;

            // Asignar las coordenadas de textura (asumiendo textura 2x2, se puede adaptar según la imagen)
            float u0 = j / 8.0f;
            float v0_tex = i / 8.0f;
            float u1 = (j + 1) / 8.0f;
            float v1_tex = (i + 1) / 8.0f;

            // Coordenadas de textura para los vértices
            Texturas[idx - 6] = _vertex2f(u0, v0_tex);  // Textura en v0
            Texturas[idx - 5] = _vertex2f(u1, v0_tex);  // Textura en v1
            Texturas[idx - 4] = _vertex2f(u1, v1_tex);  // Textura en v2
            Texturas[idx - 3] = _vertex2f(u1, v1_tex);  // Textura en v3
            Texturas[idx - 2] = _vertex2f(u0, v1_tex);  // Textura en v4
            Texturas[idx - 1] = _vertex2f(u0, v0_tex);  // Textura en v5
        }
    }
}
void _tablero::draw_line(){
    glBegin(GL_LINES);
    for (unsigned int i = 0; i < Vertices.size(); i += 3) {
        glVertex3fv((GLfloat*)&Vertices[i]);
        glVertex3fv((GLfloat*)&Vertices[i + 1]);

        glVertex3fv((GLfloat*)&Vertices[i + 1]);
        glVertex3fv((GLfloat*)&Vertices[i + 2]);

        glVertex3fv((GLfloat*)&Vertices[i + 2]);
        glVertex3fv((GLfloat*)&Vertices[i]);
    }
    glEnd();
}
// Función para cargar la textura y aplicarla
void _object3D::create_textue(const std::string& file_name){
    // Convertir std::string a QString
    QString path = QString::fromStdString(file_name) + "tablero.jpg";
    GLuint texture = cargarImagenComoTextura(path);
    if (texture == 0) {
        std::cerr << "Error al cargar la textura: " << path.toStdString() << std::endl;
        return;
    }

    glEnable(GL_TEXTURE_2D);  // Habilitar el uso de texturas
    glBindTexture(GL_TEXTURE_2D, texture);  // Vincula la textura cargada

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Vertices.size(); i += 6) {
        // Dibuja un triángulo con la textura aplicada
        glTexCoord2fv((GLfloat *)&Texturas[i]);
        glVertex3fv((GLfloat *)&Vertices[i]);

        glTexCoord2fv((GLfloat *)&Texturas[i + 1]);
        glVertex3fv((GLfloat *)&Vertices[i + 1]);

        glTexCoord2fv((GLfloat *)&Texturas[i + 2]);
        glVertex3fv((GLfloat *)&Vertices[i + 2]);

        glTexCoord2fv((GLfloat *)&Texturas[i + 3]);
        glVertex3fv((GLfloat *)&Vertices[i + 3]);

        glTexCoord2fv((GLfloat *)&Texturas[i + 4]);
        glVertex3fv((GLfloat *)&Vertices[i + 4]);

        glTexCoord2fv((GLfloat *)&Texturas[i + 5]);
        glVertex3fv((GLfloat *)&Vertices[i + 5]);
    }
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);  // Desvincula la textura
}
void _tablero::draw_fill_flat(){
    glEnable(GL_LIGHTING);
    glBegin(GL_TRIANGLES);

    for (unsigned int i = 0; i < Vertices.size(); i += 3) {
        // Calcular la normal del triángulo
        _vertex3f v0 = Vertices[i];
        _vertex3f v1 = Vertices[i + 1];
        _vertex3f v2 = Vertices[i + 2];

        _vertex3f normal = _object3D::normalizar(_object3D::calcularNormal(v0, v1, v2));

        // Usar la misma normal para todo el triángulo
        glNormal3fv((GLfloat*)&normal);
        glVertex3fv((GLfloat*)&v0);
        glVertex3fv((GLfloat*)&v1);
        glVertex3fv((GLfloat*)&v2);
    }

    glEnd();
    glDisable(GL_LIGHTING);
}
void _tablero::draw_fill_smooth(){
    // Calcular normales para cada vértice
    NormalesVertices.resize(Vertices.size());

    for (unsigned int i = 0; i < Vertices.size(); i += 3) {
        // Calcular la normal del triángulo
        _vertex3f v0 = Vertices[i];
        _vertex3f v1 = Vertices[i + 1];
        _vertex3f v2 = Vertices[i + 2];

        _vertex3f normal = _object3D::normalizar(_object3D::calcularNormal(v0, v1, v2));

        // Sumar la normal a los vértices del triángulo
        NormalesVertices[i] = normal;
        NormalesVertices[i + 1] = normal;
        NormalesVertices[i + 2] = normal;
    }


    // Dibujar el modelo con las normales calculadas
    glEnable(GL_LIGHTING);
    glBegin(GL_TRIANGLES);

    for (unsigned int i = 0; i < Vertices.size(); i++) {
        glNormal3fv((GLfloat*)&NormalesVertices[i]);
        glVertex3fv((GLfloat*)&Vertices[i]);
    }

    glEnd();
    glDisable(GL_LIGHTING);
}

