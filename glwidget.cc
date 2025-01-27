/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1), AnimationEnabled(false)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
  Timer = new QTimer(this); // Crear el temporizador
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER; break;
  case Qt::Key_5:Object=OBJECT_SPHERE; break;
  case Qt::Key_6:Object=OBJECT_PLY; break;
  case Qt::Key_7:Object=OBJECT_GRUA; break;
  case Qt::Key_8:Object=OBJECT_DASHBOARD; break;
  case Qt::Key_9:Object=OBJECT_BEETHOVEN;break;

  case Qt::Key_A:AnimationEnabled = !AnimationEnabled;timerEvent();break;

  case Qt::Key_C: ProyectionType=PERSPECTIVE; break;
  case Qt::Key_V: ProyectionType=PARALLEL;break;



  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_K:Draw_fill_color=!Draw_fill_color; break;

  case Qt::Key_F1:Draw_fill=!Draw_fill;break;
  case Qt::Key_F2:Draw_chess=!Draw_chess; break;
  case Qt::Key_F3:Draw_fill_shaded=!Draw_fill_shaded; break;
  case Qt::Key_F4:Draw_fill_gouraud=!Draw_fill_gouraud; break;
  case Qt::Key_F5:Draw_texture=!Draw_texture; break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (ProyectionType == PERSPECTIVE){
        // Mantener la relación de aspecto en función del tamaño de la ventana
        if (aspectRatio >= 1.0f) {
            // Relación de aspecto más ancha, ajustamos el eje X
            glFrustum(X_MIN * aspectRatio, X_MAX * aspectRatio, Y_MIN, Y_MAX, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
        } else {
            // Relación de aspecto más alta, ajustamos el eje Y
            glFrustum(X_MIN, X_MAX, Y_MIN / aspectRatio, Y_MAX / aspectRatio, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
        }
    }else if(ProyectionType == PARALLEL){
        // Proyección paralela
        if (aspectRatio >= 1.0f) {
            // Relación de aspecto más ancha, ajustamos el eje X
            glOrtho(X_MIN * aspectRatio * RELACION_PANTALLA, X_MAX * aspectRatio * RELACION_PANTALLA, Y_MIN * RELACION_PANTALLA, Y_MAX * RELACION_PANTALLA, FRONT_PLANE_PARLLEL, BACK_PLANE_PARALLEL);
        } else {
            // Relación de aspecto más alta, ajustamos el eje Y
            glOrtho(X_MIN * RELACION_PANTALLA, X_MAX * RELACION_PANTALLA, Y_MIN / aspectRatio * RELACION_PANTALLA, Y_MAX / aspectRatio * RELACION_PANTALLA, FRONT_PLANE_PARLLEL, BACK_PLANE_PARALLEL);
        }
    }
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{


    if(Draw_fill_color){
        glDisable(GL_LIGHT0);
        glEnable(GL_LIGHTING);     // Habilitar iluminación
        glEnable(GL_LIGHT2);       // Activar una luz

        glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
        glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
        glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);



        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


    }
    else {
        glDisable(GL_LIGHT2);
        glEnable(GL_LIGHTING);     // Habilitar iluminación
        glEnable(GL_LIGHT1);       // Activar una luz
        glEnable(GL_COLOR_MATERIAL);

        glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);


        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    }

  Axis.draw_line();
  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point(); break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY:Object_ply.draw_point();break;
    case OBJECT_GRUA:Grua.draw_point();break;
    case OBJECT_DASHBOARD:Dashboard.draw_point(); break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_GRUA:Grua.draw_line();break;
    case OBJECT_PLY:Object_ply.draw_line();break;
    case OBJECT_DASHBOARD:Dashboard.draw_line();break;

    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CONE:Cone.draw_fill();break;
    case OBJECT_CYLINDER:Cylinder.draw_fill();break;
    case OBJECT_SPHERE:Sphere.draw_fill();break;
    case OBJECT_PLY:Object_ply.draw_fill();break;
    case OBJECT_GRUA:Grua.draw_fill();break; // hay que cambiar por draw_fill
    case OBJECT_DASHBOARD:Dashboard.draw_fill();break;
    case OBJECT_BEETHOVEN:Beethoven.draw_fill();break;
    case OBJECT_SCENE:Scene.draw_fill();break;
    default:break;
    }
  }
  if(Draw_fill_shaded){
      glColor3fv((GLfloat *) &BLUE);
      switch (Object) {
      case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill_flat();break;
      case OBJECT_CUBE:Cube.draw_fill_flat();break;
      case OBJECT_CONE:Cone.draw_fill_flat();break;
      case OBJECT_CYLINDER:Cylinder.draw_fill_flat();break;
      case OBJECT_SPHERE:Sphere.draw_fill_flat();break;
      case OBJECT_PLY:Object_ply.draw_fill_flat();break;
      case OBJECT_GRUA:Grua.draw_fill_flat();break;
      case OBJECT_DASHBOARD:Dashboard.draw_fill_flat();break;
      default:break;
      }
  }
  if(Draw_fill_gouraud){
      glColor3fv((GLfloat *) &BLUE);
      switch (Object) {
      case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill_smooth();break;
      case OBJECT_CUBE:Cube.draw_fill_smooth();break;
      case OBJECT_CONE:Cone.draw_fill_smooth();break;
      case OBJECT_CYLINDER:Cylinder.draw_fill_smooth();break;
      case OBJECT_SPHERE:Sphere.draw_fill_smooth();break;
      case OBJECT_PLY:Object_ply.draw_fill_smooth();break;
      case OBJECT_GRUA:Grua.draw_fill_smooth();break;
      default:break;
      }
  }


  if (Draw_chess){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_PLY:Object_ply.draw_chess();break;
    case OBJECT_GRUA:Grua.draw_chess(); break;
    case OBJECT_DASHBOARD:Dashboard.draw_chess();break;
    default:break;
    }
  }
  if (Draw_texture){
      glColor3fv((GLfloat *) &BLUE);
      switch (Object){
      case OBJECT_DASHBOARD:Dashboard.create_textue();break;
      default:break;
      }
  }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
  // Calcula la relación de aspecto (aspect ratio)
  aspectRatio = (float)Width1 / (float)Height1;

}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
        //NO ESTA BIEN
      /* Problem: glewInit failed, something is seriously wrong. */
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
  }

  strm = glGetString(GL_VENDOR);  // Esto debe ir después de glewInit.
  cerr << "GLEW: " << strm << endl;

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;
  Draw_fill_color=false;
  Draw_fill_shaded=false;
  Draw_fill_gouraud=false;
  Draw_texture=false;

  AnimationEnabled=false;

  ProyectionType=PERSPECTIVE;


}

void _gl_widget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        // Guardamos la posicion del raton, esta en una pantalla 2d
        Selection_position_x = event->x();
        Selection_position_y = event->y();
        lastMouseX = event->x();
        lastMouseY = event->y();
        mousePressed=!mousePressed;
    }
}

void _gl_widget::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        mousePressed=!mousePressed;
    }
}

void _gl_widget::mouseMoveEvent(QMouseEvent *event){
    if(mousePressed){

        // event->i() - lastMouseI -> calculamos el desplazamiento del ratón

        // Actualizamos los ángulos de la cámara en función del movimiento del ratón
        Observer_angle_y += (event->x() - lastMouseX) * ANGLE_STEP / 100.0f;  // Rotación en el eje Y (horizontal)
        Observer_angle_x += (event->y() - lastMouseY) * ANGLE_STEP / 100.0f;  // Rotación en el eje X (vertical)

        // Guardamos la nueva posición del ratón para el siguiente movimiento
        lastMouseX = event->x();
        lastMouseY = event->y();

        // Actualizamos la escena
        update();
    }
}

void _gl_widget::wheelEvent(QWheelEvent *event)
{
    // Si la rueda se desplaza hacia arriba, acercamos la cámara
    if (event->angleDelta().y() > 0) {
        Observer_distance -= DISTANCE_STEP;
    }
    // Si la rueda se desplaza hacia abajo, alejamos la cámara
    else {
        Observer_distance += DISTANCE_STEP;
    }

    // Limitar la distancia para evitar que la cámara se acerque demasiado o se aleje demasiado
    if (Observer_distance < 0.1f) Observer_distance = 0.1f;
    if (Observer_distance > 100.0f) Observer_distance = 100.0f;

    // Actualizamos la escena
    update();
}


void _gl_widget::timerEvent()
{
    if(AnimationEnabled){
        Timer->start(16);
        connect(Timer, &QTimer::timeout, this, & _gl_widget::tick); // Conectar el timeout del temporizador
    }else {
        Timer->stop();
    }

}
void _gl_widget::tick(){
    Grua.actualizar_movimiento();
    update();
}

void _gl_widget::display(){

}
// Skeleton for pick fuction using glDeleteFramebuffers
//
// Domingo Martín Perandrés
// GPL
//
// Window_width and Window_height are the widht and height of the device window
// Selection_position_x and Selection_position_y are the coordinates of the mouse

void _gl_widget::pick()
{

    makeCurrent();

    // Frame Buffer Object to do the off-screen rendering
    GLuint FBO;
    glGenFramebuffers(1,&FBO);
    glBindFramebuffer(GL_FRAMEBUFFER,FBO);

    // Texture for drawing
    GLuint Color_texture;
    glGenTextures(1,&Color_texture);
    glBindTexture(GL_TEXTURE_2D,Color_texture);
    // RGBA8
    glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window_width,Window_height);
    // this implies that there is not mip mapping
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    // Texure for computing the depth
    GLuint Depth_texture;
    glGenTextures(1,&Depth_texture);
    glBindTexture(GL_TEXTURE_2D,Depth_texture);
    // Float
    glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window_width,Window_height);

    // Attatchment of the textures to the FBO
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

    // OpenGL will draw to these buffers (only one in this case)
    static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1,Draw_buffers);

    /*************************/

    // dibujar escena para seleccion
    Object_ply.draw_fill();

    /*************************/

    // get the pixel
    int Color;
    glReadBuffer(GL_FRONT);
    glPixelStorei(GL_PACK_ALIGNMENT,1);
    glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);

    /*************************/

    // convertir de RGB a identificador

    // actualizar el identificador de la parte seleccionada en el objeto

    /*************************/

    glDeleteTextures(1,&Color_texture);
    glDeleteTextures(1,&Depth_texture);
    glDeleteFramebuffers(1,&FBO);
    // the normal framebuffer takes the control of drawing
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
}
