/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <QWindow>
#include <QTimer>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "ply_object.h"
#include "grua.h"
#include "tablero.h"
#include "scene.h"

#define PERSPECTIVE 1
#define PARALLEL 2

namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float RELACION_PANTALLA = 10;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float FRONT_PLANE_PARLLEL=.001;
  const float BACK_PLANE_PARALLEL=1000;
  const float DEFAULT_DISTANCE=2;
  const float DISTANCE_PARALLEL=200;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_CONE, OBJECT_CYLINDER, OBJECT_SPHERE, OBJECT_PLY, OBJECT_DASHBOARD, OBJECT_SCENE, OBJECT_BEETHOVEN, OBJECT_GRUA} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
  void tick();
  void timerEvent();          // Para animación

  void mousePressEvent(QMouseEvent *event);     // Cuando haga click;
  void mouseReleaseEvent(QMouseEvent *event);   // Cuando deja de hacer click;
  void mouseMoveEvent(QMouseEvent *event);      // Cuando se mueva el ratón;
  void wheelEvent(QWheelEvent *event);          // Cuando usamos la rueda del raton.

  void pick();

  // Función que convierte un identificador único (ID) en un color RGB
  void idToColor(unsigned int obj_id, GLfloat& r, GLfloat& g, GLfloat& b);
  // Función que convierte un color RGB en un identificador único (ID)
  unsigned int colorToId(GLfloat r, GLfloat g, GLfloat b);
  // Función para renderizar los objetos con el color asignado
  void renderObjectForPicking(unsigned int obj_id);

  //dibujar escena
  void display();

private:
  // Para el manejo del raton;
  bool mousePressed = false;
  int lastMouseX, lastMouseY;
  const GLfloat ANGLE_STEP = 5.0f;
  const GLfloat DISTANCE_STEP = 0.1f;

  float aspectRatio;


  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cone Cone;
  _cylinder Cylinder;
  _sphere Sphere;
  _ply_object Object_ply;
  _tablero Dashboard;
  _scene Scene;
  _beethoven Beethoven;

  _grua Grua;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_fill_shaded;
  bool Draw_fill_gouraud;
  bool Draw_fill_color;
  bool Draw_chess;
  bool Draw_texture;
  bool AnimationEnabled; // Activar/desactivar animación
  QTimer *Timer;
  GLint ProyectionType;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  int Window_width = 800;  // Ancho predeterminado
  int Window_height = 600; // Alto predeterminado

  int Selection_position_x;
  int Selection_position_y;


  GLfloat light1_position[4] = {1.0f, 1.0f, 1.0f, 0.0f};

  GLfloat light1_specular[4] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat light1_diffuse[4] = {1.0f, 1.0f, 1.0f, 1.0f};    // Color blanco difuso
  GLfloat light1_ambient[4] = {0.2f, 0.2f, 0.2f, 1.0f};    // Luz ambiental tenue

  GLfloat light2_position[4] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat light2_specular[4] = {1.0f, 0.0f, 0.7f, 1.0f}; // Posición inicial de la luz
  GLfloat light2_diffuse[4] = {1.0f, 0.0f, 1.0f, 1.0f};    // Color blanco difuso
  GLfloat light2_ambient[4] = {0.2f, 0.0f, 0.2f, 1.0f};    // Luz ambiental tenue
  GLfloat light2_velocity[3] = {0.6f, 0.6f, 0.6f};      // Velocidad de movimiento

  GLfloat mat_specular[4] = {0.3f, 0.3f, 0.3f, 0.3f}; // Especular blanca
  GLfloat mat_diffuse[4] = {0.6f, 0.6f, 0.6f, 0.6f};  // Difusa gris claro
  GLfloat mat_ambient[4] = {0.1f, 0.1f, 0.1f, 0.1f};  // Ambiental tenue
  GLfloat mat_shininess[1] = {50.0f};                 // Brillo especular
};

#endif
