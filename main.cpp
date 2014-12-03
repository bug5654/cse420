#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>

static int shapeScore = 0, correctScore = 0,
		   shapeScore2 = 0, correctScore2 = 0,
		   shapeScore3 = 0, correctScore3 = 0,
		   shapeScore4 = 0, correctScore4 = 0,
		   shapeScore5 = 0, correctScore5 = 0,
		   shapeScore6 = 0, correctScore6 = 0,
		   shapeScore7 = 0, correctScore7 = 0,
		   shapeScore8 = 0, correctScore8 = 0,
		   shapeScore9 = 0, correctScore9 = 0,
		   shapeScore10 = 0, correctScore10 = 0;
static int guesses = 0;

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

void init(void)
{
	tally = glGenLists(1);
	glNewList(tally, GL_COMPILE);
		glColor3f(0.0, 0.0, 0.0);
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
	GLfloat black[3] = { 0.0, 0.0, 0.0 };
	glClearColor(0.5, 0.5, 0.5, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3fv(black);

	glRasterPos2i(20, 480);
	printString("WELCOME TO MASTERMIND");
	glRasterPos2i(20, 460);
	printString("A AND D TO SELECT A SHAPE");
	glRasterPos2i(20, 440);
	printString("'G' TO CONFRIM YOUR SHAPE");
	glRasterPos2i(20, 420);
	printString("YOU HAVE TEN GUESSES TO GET");
	glRasterPos2i(20, 400);
	printString("THE SHAPES IN THE RIGHT LOCATION");
	glRasterPos2i(20, 380);
	printString("GOOD LUCK");
	glFlush();
}


void score(GLint a, GLint b)
{
	
	glPushMatrix();
	for (int i = 0; i < a; i++)
	{
		glCallList(tally);
	}
	glTranslatef(130 - (10 * a), 0, 0);
	for (int i = 0; i < b; i++)
	{
		glCallList(tally);
	}

	glPopMatrix();
	glFlush();
}

void scoreboard(void)
{
	GLfloat black[3] = { 0.0, 0.0, 0.0 };
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
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(0.0, 0.0);
		glVertex2f(0, 500);
		glVertex2f(650, 500);
		glVertex2f(650, 0);
		glEnd();
	/*glBegin(GL_LINE);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 500.0);
	glEnd();*/
}

void display(void)
{
	glPushMatrix();
	instructions();
	glPushMatrix();
	glTranslatef(300, 0, 0);
	playarea();
	//glPushMatrix();
	glTranslatef(660, 0, 0);
	scoreboard();
	glPushMatrix();
	glTranslatef(20, 450, 0);
		if (guesses >= 0)
			score((GLint)shapeScore, (GLint)correctScore);
		if (guesses >= 1)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore2, (GLint)correctScore2);
		}
		if (guesses >= 2)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore3, (GLint)correctScore3);
		}
		if (guesses >= 3)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore4, (GLint)correctScore4);
		}
		if (guesses >= 4)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore5, (GLint)correctScore5);
		}
		if (guesses >= 5)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore6, (GLint)correctScore6);
		}
		if (guesses >= 6)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore7, (GLint)correctScore7);
		}
		if (guesses >= 7)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore8, (GLint)correctScore8);
		}
		if (guesses >= 8)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore9, (GLint)correctScore9);
		}
		if (guesses >= 9)
		{
			glTranslatef(0, -20, 0);
			score((GLint)shapeScore10, (GLint)correctScore10);
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
	//gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glOrtho(0.0, w, 0.0, h, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's':
		if (guesses == 0)
			shapeScore = (shapeScore + 1);
		if (guesses == 1)
			shapeScore2 += 1;
		if (guesses == 2)
			shapeScore3 += 1;
		if (guesses == 3)
			shapeScore4 += 1;
		if (guesses == 4)
			shapeScore5 += 1;
		if (guesses == 5)
			shapeScore6 += 1;
		if (guesses == 6)
			shapeScore7 += 1;
		if (guesses == 7)
			shapeScore8 += 1;
		if (guesses == 8)
			shapeScore9 += 1;
		if (guesses == 9)
			shapeScore10 += 1;
		glutPostRedisplay();
		break;
	case 'w':
		if (guesses == 0)
			correctScore += 1;
		if (guesses == 1)
			correctScore2 += 1;
		if (guesses == 2)
			correctScore3 += 1;
		if (guesses == 3)
			correctScore4 += 1;
		if (guesses == 4)
			correctScore5 += 1;
		if (guesses == 5)
			correctScore6 += 1;
		if (guesses == 6)
			correctScore7 += 1;
		if (guesses == 7)
			correctScore8 += 1;
		if (guesses == 8)
			correctScore9 += 1;
		if (guesses == 9)
			correctScore10 += 1;
		glutPostRedisplay();
		break;
	case 'A':
	case 'a':
		break;
	case 'D':
	case 'd':
		break;
	case 'G':
	case 'g':
		guesses += 1;
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