//list.cpp
#ifdef __APPLE__
#include <GLUT/glut.h>

#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
#include <stdlib.h>
#include <iostream>

using namespace std;

static int shapes[4];
static int pyramid;
static int cube;
static int guesses[5][4];
static int spin;
static int spiny;
static int currshape;

static void init (void)
{
   glClearColor(1.0,1.0,1.0,0.0);
   currshape=0;
   spin=0;
   spiny=0;
   //cout << "is any of my code doing anything?";  //use make clean....
   shapes[0] = glGenLists (1);
   //pyramid = glGenLists (1);
   glNewList (shapes[0], GL_COMPILE); //pyramid
      glBegin (GL_POLYGON);   //front
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd ();
      glBegin (GL_POLYGON);   //right
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd ();
      glBegin (GL_POLYGON);   //back
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd ();
      glBegin (GL_POLYGON);   //left
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd ();
      glBegin (GL_POLYGON);   //bottom
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 0.0);
      glEnd ();
      
      //lines
      glLineWidth(0.5);
      glColor3f(0.0,0.0,0.0);
      //front face
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd();
      //left face
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd();
      //back face
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (0.5, 1.0, 0.5);
      glEnd();
      //last one
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd();
   glEndList ();
   shapes[1] = glGenLists (1);
   
   //cube = glGenLists (1);
   glNewList (shapes[1], GL_COMPILE); //cube
      glBegin (GL_POLYGON);   //bottom
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 0.0);
      glEnd ();
      glBegin (GL_POLYGON);   //left
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (0.0, 1.0, 1.0);
      glVertex3f (0.0, 1.0, 0.0);
      glEnd ();
      glBegin (GL_POLYGON);   //top
      glVertex3f (0.0, 1.0, 0.0);
      glVertex3f (0.0, 1.0, 1.0);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (1.0, 1.0, 0.0);
      glEnd ();
      glBegin (GL_POLYGON);   //back
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (0.0, 1.0, 1.0);
      glEnd ();
      glBegin (GL_POLYGON);   //right
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (1.0, 1.0, 0.0);
      glEnd ();
      glBegin (GL_POLYGON);   //back
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 1.0, 0.0);
      glVertex3f (0.0, 1.0, 0.0);
      glEnd ();
      
      //lines
      glLineWidth(0.5);
      glColor3f(0.0,0.0,0.0);
      //front face
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 1.0, 0.0);
      glVertex3f (1.0, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 1.0, 0.0);
      glEnd();
      //right
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (1.0, 1.0, 0.0);
      glEnd();
      //top
      glBegin(GL_LINES);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (0.0, 1.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 1.0, 1.0);
      glVertex3f (0.0, 1.0, 0.0);
      glEnd();
      //left
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd();
      //last
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (0.0, 1.0, 1.0);
      glEnd();
      
   glEndList ();
   glShadeModel (GL_SMOOTH);
}



void display(void)
{
   GLuint i;
   
   
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (0.0, 1.0, 0.0);  /*  current color green  */
   glPushMatrix();
   gluLookAt(0.0,0.0,-5.0,0.0,0.0,0.0,0.0,1.0,0.0);
   glPopMatrix();
   glPushMatrix();
   glRotatef(spin,0.5,0.5,0.5);
   glRotatef(spiny,0.0,1.0,0.0);
   //for (i = 0; i < 4; i++) {
      glCallList (shapes[currshape]);
   //}
   glPopMatrix();
   
   glFlush ();
}

void reshapes(int w, int h)
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
      case 'r':
         spin+=5;
         spin=spin%360;
         glutPostRedisplay();
         break;
      case 'R':
         spin-=5;
         spin=spin%360;
         glutPostRedisplay();
         break;
      case 'e':
         spiny+=5;
         spiny=spiny%360;
         glutPostRedisplay();
         break;
      case 'E':
         spiny-=5;
         spiny=spiny%360;
         glutPostRedisplay();
         break;
      case 't':
         currshape-=1;
         if(currshape<0) { currshape=1; }
         glutPostRedisplay();
         break; 
      case 'T':
         currshape+=1;
         if(currshape>1) { currshape=0; }
         glutPostRedisplay();
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
   glutReshapeFunc (reshapes);
   glutKeyboardFunc (keyboard);
   glutDisplayFunc (display);
   glutMainLoop();
   return 0;
}