#include <GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
void init2D() {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0f, 1.0f, 0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}
void dispay(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex2i(100, 100);
  glVertex2i(100, 300);
  glVertex2i(400, 300);
  glVertex2i(600, 150);
  glVertex2i(400, 100);
  glEnd();
  glFlush();
}
int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello world!");
  init2D();
  glutDisplayFunc(dispay);
  glutMainLoop();
  return 0;
}
