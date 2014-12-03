#ifdef __APPLE__
#include <GLUT/glut.h>

#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#define WINDOWS_FLAGG
#ifndef WINDOWS_FLAGG
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "shapes.cpp"
#include <math.h>



using namespace std;
const int guessmax=5;

static int shapeScore[guessmax];
static int correctScore[guessmax];
static int currguess = 0;
static int debuga=0;
static int guesses[guessmax][4];
static float colors[5][3];
static int activeshape = 0;
static int answer[4];
static int rotate_amt=0;
static bool victory=FALSE;


//All the stuff for bitmaps
GLubyte space[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
GLubyte letters[][13] = 
{    
	 0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18,
	 0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe,
	 0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e,
	 0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc,
	 0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,
	 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff,
	 0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e,
	 0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
	 0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e,
	 0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
	 0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3,
	 0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
	 0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3,
	 0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3,
	 0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e,
	 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe,
	 0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c,
	 0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe,
	 0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e,
	 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff,
	 0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
	 0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
	 0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
	 0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3,
	 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3,
	 0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff 
};

GLuint fontOffset;

void makeRasterFont(void)
{
	GLuint i, j;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	fontOffset = glGenLists(128);
	for (i = 0, j = 'A'; i < 26; i++, j++)
	{
		glNewList(fontOffset + j, GL_COMPILE);
		glBitmap(8, 13, 0.0, 1.0, 9.0, 0.0, letters[i]);
		glEndList();
	}
	glNewList(fontOffset + ' ', GL_COMPILE);
	glBitmap(2, 4, 0.0, 2.0, 5.0, 0.0, space);
	glEndList();
}

GLuint tally;

void resetgame() {
   for(int i=0; i<guessmax;i++) {
	  shapeScore[i]=0;
	  correctScore[i]=0;
	  for(int j=0; j<4; j++) {
	     guesses[i][j]=4;  //blank element
	  }
	  
   }
   for(int j=0; j<4; j++) {      //init for first guess
	     guesses[0][j]=0;
   }
   for(int q=0;q<4;q++) {
      answer[q] = floor(rand()%4);
      cout << "\nanswer[" << q << "]: " << answer[q];
   }
   
}

void init(void)
{
   loadshapes();
	tally = glGenLists(1);
	resetgame();
   
   //associate colors with each shape
   colors[0][0]=1.0;
   colors[0][1]=0.0;
   colors[0][2]=0.0;
   
   colors[1][0]=0.0;
   colors[1][1]=1.0;
   colors[1][2]=0.0;
   
   colors[2][0]=0.0;
   colors[2][1]=0.0;
   colors[2][2]=1.0;
   
   colors[3][0]=1.0;
   colors[3][1]=1.0;
   colors[3][2]=0.0;
   
   colors[4][0]=1.0;
   colors[4][1]=1.0;
   colors[4][2]=1.0;
   for(int u=0;u<currguess;u++) {
      correctScore[u]=0;
   }
   
   
	glNewList(tally, GL_COMPILE);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);
		glVertex2f(3.0, 10.0);
		glVertex2f(3.0, 0.0);
		glEnd();
		glTranslatef(10.0, 0.0, 0.0);
	glEndList();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	makeRasterFont();
}

void printString(char *s)
{
	glPushAttrib(GL_LIST_BIT);
	glListBase(fontOffset);
	glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte *)s);
	glPopAttrib();
}

void instructions(void)
{
	GLfloat black[3] = { 1.0, 1.0, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3fv(black);

	glRasterPos2i(20, 480);
	printString("WELCOME TO MASTERMIND");
	glRasterPos2i(20, 460);
	printString("A AND D TO CHANGE SELECTION");
	glRasterPos2i(20, 440);
	printString("W AND S TO CHANGE SHAPE");
	glRasterPos2i(20, 420);
	printString("'G' TO CONFIRM YOUR SHAPE");
	glRasterPos2i(20, 400);
	printString("YOU HAVE FIVE GUESSES TO GET");
	glRasterPos2i(20, 380);
	printString("THE SHAPES IN THE RIGHT LOCATION");
	glRasterPos2i(20, 360);
	printString("GOOD LUCK");
	glFlush();
}


void score(GLint a, GLint b)
{
	
	glPushMatrix();
	glTranslatef(20.0,0.0,0.0);
	int maxa = a;
	int maxb = b;
	if (a>4) { maxa=4; }
	if (b>4) { maxb=4; }
	for (int i = 0; i < maxa; i++)
	{
		glCallList(tally);
	}
	glTranslatef(130 - (10 * a), 0, 0);
	for (int i = 0; i < maxb; i++)
	{
		glCallList(tally);
	}

	glPopMatrix();
	glFlush();
}

void scoreboard(void)
{
	GLfloat black[3] = { 1.0, 1.0, 1.0 };
	//glClearColor(0.5, 0.5, 0.5, 0.0);

	//glClear(GL_COLOR_BUFFER_BIT);

	glColor3fv(black);

	glRasterPos2i(20, 480);
	printString("SHAPES");
	glRasterPos2i(150, 480);
	printString("CORRECT");
	glFlush();
}

void playarea(void)
{
	/*glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(0.0, 0.0);
		glVertex2f(0, 500);
		glVertex2f(650, 500);
		glVertex2f(650, 0);
		glEnd();*/
	/*glBegin(GL_LINE);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 500.0);
	glEnd();*/
}

void drawshapes() {
   //cout << "\ndrawshapes called!\n";
   int drawshape = currguess+1;
   if(drawshape >9) { drawshape=9; }
   glPushMatrix();
   
   glTranslatef(400,400,0);
   glScalef(40.0,40.0,40.0);//setup for shapespace
   
   
   for(int i=0; i<=currguess; i++) {
      for(int j=0;j<4;j++) {
         glPushMatrix();
         glColor3f(colors[guesses[i][j]][0],colors[guesses[i][j]][1], colors[guesses[i][j]][2]);
         glTranslatef(0.5, 0.5, 0.5);
         glRotatef(45,1,1,0);
         if(i==currguess && j==activeshape) {
            glRotatef(rotate_amt,1,1,0);
         }
         glTranslatef(-0.5, -0.5, -0.5);
         glCallList(shapes[guesses[i][j]]);
         glPopMatrix();
         if(i==currguess && j==activeshape) {
            glPushMatrix();
            glTranslatef(0.0,-2.0,0.0);
            glColor3f(0.0, 0.5, 0.75);
            glBegin(GL_QUADS);
               glVertex3f(0.0,0.0,0.0);
               glVertex3f(1.0,0.0,0.0);
               glVertex3f(1.0,0.2,0.0);
               glVertex3f(0.0,0.2,0.0);
            glEnd();
            glPopMatrix();
         }
         glTranslatef(3,0,0);
      }
      glTranslatef(-12,-2,0);  //next line
   }
   /*
   glColor3f(0.0,1.0,0.0);
   glCallList (shapes[1]);
   glTranslatef(3,0,0);
   glColor3f(1.0,0.0,0.0);
   glCallList (shapes[2]);
   glColor3f(0.0,0.0,1.0);
   glTranslatef(3,0,0);
   glCallList(shapes[3]);
   glColor3f(1.0,1.0,0.0);
   glTranslatef(3,0,0);
   glCallList(shapes[0]);
   
   glTranslatef(-9,-2,0);  //next line
   glColor3f(0.0,1.0,0.0);
   glCallList (shapes[3]);
   glTranslatef(3,0,0);
   glColor3f(1.0,0.0,0.0);
   glCallList (shapes[0]);
   glColor3f(0.0,0.0,1.0);
   glTranslatef(3,0,0);
   glCallList(shapes[1]);
   glColor3f(1.0,1.0,0.0);
   glTranslatef(3,0,0);
   glCallList(shapes[4]);
   */
   
   glPopMatrix();
}

void display(void)
{
	glPushMatrix();
	instructions();
	drawshapes();
	glPushMatrix();
	glTranslatef(300, 0, 0);
	playarea();

	//glPushMatrix();
	glTranslatef(660, 0, 0);
	scoreboard();
	glPushMatrix();
	glTranslatef(20, 420, 0);
	int tallytranslate = -80;
	   for(int j=currguess; j < (2*currguess)+1; j++) {
	        score( (GLint)shapeScore[j-currguess], (GLint) correctScore[j-currguess]);
	        glTranslatef(0, tallytranslate, 0);
	   }
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0,  (GLsizei)w,  (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 0.0, 60.0);
	glOrtho(0.0, w, 0.0, h, -50.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}


void scoreupdate(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (guesses[currguess][i] == answer[i])
		{
			correctScore[currguess] += 1;
		}
	}
   int colorarray[4];
   colorarray[0]=0;
   colorarray[1]=0;
   colorarray[2]=0;
   colorarray[3]=0;
   
   int colorarrayguess[4];
   colorarrayguess[0]=0;
   colorarrayguess[1]=0;
   colorarrayguess[2]=0;
   colorarrayguess[3]=0;
   for (int k = 0; k < 4; k++)
   {
      colorarray[answer[k]] += 1;
   }
   
   for (int u = 0; u < 4; u++)
   {
      colorarrayguess[guesses[currguess][u]] += 1;
   }
   
   for (int m = 0; m < 4; m++)
   {
      if(colorarray[m] <= colorarrayguess[guesses[currguess][m]]) {
         shapeScore[currguess]+=colorarray[m];
      } else {
         shapeScore[currguess]+=colorarrayguess[m];
      }
   }
}


void keyboard(unsigned char key, int x, int y)
{
   
	switch (key) {
	case 's':
	case 'S':
	   guesses[currguess][activeshape]-=1;
	   if (guesses[currguess][activeshape]<0) {
	     guesses[currguess][activeshape]=3;
	   }
		glutPostRedisplay();
		break;
	case 'w':
	case 'W':
      guesses[currguess][activeshape]+=1;
	   if (guesses[currguess][activeshape]>3) {
	     guesses[currguess][activeshape]=0;
	   }
		glutPostRedisplay();
		break;
	case 'A':
	case 'a':
	   activeshape-=1;
	   if(activeshape<0) {
	     activeshape=3;
	   }
	   glutPostRedisplay();
		break;
	case 'D':
	case 'd':
	   activeshape+=1;
	   if(activeshape>3) {
	     activeshape=0;
	   }
	   glutPostRedisplay();
		break;
	case 'G':
	case 'g':
	   scoreupdate();
		currguess += 1;
		if (currguess>=guessmax) {
		    exit(0);
		    break;
		    currguess=0;
		    resetgame();
      }
      for(int k=0;k<4;k++) {
         guesses[currguess][k] = guesses[currguess-1][k];
      }
		glutPostRedisplay();
		break;
		
   case 'p':
      currguess=guessmax-1;
      
      for(int k=0;k<guessmax;k++) {
         shapeScore[k]=(k+debuga)%4+1;
         correctScore[k]=(k+debuga)%4+1;
      }
      debuga+=1;
      if(debuga>3) {
         debuga=0;
      }
      glutPostRedisplay();
      break;
      
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 500);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}