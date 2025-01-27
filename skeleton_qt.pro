DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x050F00

HEADERS += \
    beethoven.h \
  brazo1.h \
    brazo2.h \
    cabina.h \
  colors.h \
  basic_object3d.h \
  cube.h \
    cuerpo.h \
  cylinder.h \
    eje.h \
    grua.h \
  object3d.h \
  axis.h \
    rueda.h \
    scene.h \
  sphere.h \
    tablero.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  ply_object.h \
  file_ply_stl.h \
  cone.h \

SOURCES += \
    beethoven.cc \
    brazo1.cc \
    brazo2.cc \
    cabina.cc \
  cone.cc \
  basic_object3d.cc \
  cube.cc \
    cuerpo.cc \
    cylinder.cc \
    eje.cc \
    grua.cc \
  object3d.cc \
  axis.cc \
    rueda.cc \
    scene.cc \
    sphere.cc \
    tablero.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
  ply_object.cc \
  file_ply_stl.cc \


LIBS += -L/usr/X11R6/lib64 -lGL -lGLEW
#LIBS += -lopenGL32


CONFIG += c++14
QT += widgets opengl openglwidgets
