//list.cpp
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

static void init (void)
{
   //cout << "is any of my code doing anything?";  //use make clean....
   listName = glGenLists (1);
   glNewList (listName, GL_COMPILE);
      glColor3f (0.0, 0.0, 1.0);  /*  current color red...still red!  */
      glBegin (GL_POLYGON);
      glVertex2f (0.3, 0.0);
      glVertex2f (0.0, 0.7);
      glVertex2f (0.5, 1.0);
      glVertex2f (1.0, 0.7);
      glVertex2f (0.7, 0.0);
      glEnd ();
      glTranslatef (2.0, 0.0, 0.0); /*  move position  */
   glEndList ();
   glShadeModel (GL_FLAT);
}



void display(void)
{
   GLuint i;

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (0.0, 1.0, 0.0);  /*  current color green  */
   for (i = 0; i < 10; i++)    /*  draw 10 triangles    */
      glCallList (listName);

   glFlush ();
}

void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h) 
      gluOrtho2D (0.0, 2.0, -0.5 * (GLfloat) h/(GLfloat) w, 
         1.5 * (GLfloat) h/(GLfloat) w);
   else 
      gluOrtho2D (0.0, 2.0*(GLfloat) w/(GLfloat) h, -0.5, 1.5); 
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'w':
      case 'W':
      
         break;
      case 'a':
      case 'A':
      
         break;
      case 's':
      case 'S':
      
         break;
      case 'd':
      case 'D':
      
         break;
      case 'g':
      case 'G':
      
         break;
      
      
   
      case 27:
         exit(0);
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800, 600);
   glutCreateWindow(argv[0]);
   init ();
   glutReshapeFunc (reshape);
   glutKeyboardFunc (keyboard);
   glutDisplayFunc (display);
   glutMainLoop();
   return 0;
}