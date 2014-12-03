//shapes.cpp

static int shapes[5];

void loadshapes() {
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
   
   shapes[2] = glGenLists (1);
   glNewList (shapes[2], GL_COMPILE); //L-tetris
      glBegin (GL_QUADS);   //frontq1
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.5, 0.0);
      glVertex3f (0.0, 0.5, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //frontq2
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.5, 1.0, 0.0);
      glVertex3f (1.0, 1.0, 0.0);
      glVertex3f (1.0, 0.5, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //rearq1
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 0.5, 1.0);
      glVertex3f (0.0, 0.5, 1.0);
      glEnd ();
      glBegin (GL_QUADS);   //rearq2
      glVertex3f (0.5, 0.5, 1.0);
      glVertex3f (0.5, 1.0, 1.0);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (1.0, 0.5, 1.0);
      glEnd ();
      
      glBegin (GL_POLYGON);   //right
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (1.0, 1.0, 0.0);
      glEnd ();
      glBegin (GL_POLYGON);   //topright
      glVertex3f (0.5, 1.0, 0.0);
      glVertex3f (1.0, 1.0, 0.0);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (0.5, 1.0, 1.0);
      glEnd ();
      glBegin (GL_POLYGON);   //topleft
      glVertex3f (0.0, 0.5, 0.0);
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.5, 0.5, 1.0);
      glVertex3f (0.0, 0.5, 1.0);
      glEnd ();
      glBegin (GL_POLYGON);   //righttop
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.5, 0.5, 1.0);
      glVertex3f (0.5, 1.0, 1.0);
      glVertex3f (0.5, 1.0, 0.0);
      glEnd ();
      glBegin (GL_POLYGON);   //rightbot
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.5, 0.0);
      glVertex3f (0.0, 0.5, 1.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd ();
      glBegin (GL_POLYGON);   //bottom
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd ();
      
      glColor3f(0.0,0.0,0.0); //lines
      glBegin(GL_LINES);   //front
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glEnd();
      glBegin(GL_LINES);   
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 1.0, 0.0);
      glVertex3f (0.5, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.5, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.0, 0.5, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.5, 0.0);
      glVertex3f (0.0, 0.0, 0.0);
      glEnd();
      glBegin(GL_LINES);   //rear
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);   
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 1.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (0.5, 1.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.5, 0.5, 1.0);
      glVertex3f (0.5, 1.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.5, 0.5, 1.0);
      glVertex3f (0.0, 0.5, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.5, 1.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);//right
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
      glBegin(GL_LINES);   //topleft
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (0.5, 1.0, 1.0);
      glEnd();
      glBegin(GL_LINES);   
      glVertex3f (1.0, 1.0, 1.0);
      glVertex3f (0.5, 1.0, 1.0);
      glEnd();
      glBegin(GL_LINES);   
      glVertex3f (0.5, 1.0, 1.0);
      glVertex3f (0.5, 1.0, 0.0);
      glEnd();
      /*glBegin(GL_LINES);   
      glVertex3f (0.5, 1.0, 1.0);
      glVertex3f (0.0, 1.0, 1.0);
      glEnd(); //wrong*/
      /*glBegin(GL_LINES);   //toproght
      glVertex3f (0.5, 1.0, 1.0);
      glVertex3f (0.0, 1.0, 1.0);
      glEnd();//*/
      /*glBegin(GL_LINES);   
      glVertex3f (0.0, 1.0, 1.0);
      glVertex3f (0.0, 1.0, 0.0);
      glEnd();//*/
      glBegin(GL_LINES);   //last
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd();

      glBegin(GL_LINES);   //fix
      glVertex3f (0.0, 0.5, 0.0);
      glVertex3f (0.0, 0.5, 1.0);
      glEnd();
      glBegin(GL_LINES);   //fix2
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.5, 0.5, 1.0);
      glEnd();

   glEndList ();
   
   
   shapes[3] = glGenLists (1);
   glNewList (shapes[3], GL_COMPILE); //T-Tetris
   
      glBegin (GL_QUADS);   //frontq1
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.33, 0.0);
      glVertex3f (0.0, 0.33, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //frontq2
      glVertex3f (0.33, 0.33, 0.0);
      glVertex3f (0.66, 0.33, 0.0);
      glVertex3f (0.66, 1.0, 0.0);
      glVertex3f (0.33, 1.0, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //frontq1
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 0.33, 1.0);
      glVertex3f (0.0, 0.33, 1.0);
      glEnd ();
      glBegin (GL_QUADS);   //frontq2
      glVertex3f (0.33, 0.33, 1.0);
      glVertex3f (0.66, 0.33, 1.0);
      glVertex3f (0.66, 1.0, 1.0);
      glVertex3f (0.33, 1.0, 1.0);
      glEnd ();
      glBegin (GL_QUADS);   //bottom
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd ();
      glBegin (GL_QUADS);   //rightbot
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.33, 0.0);
      glVertex3f (1.0, 0.33, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd ();
      glBegin (GL_QUADS);   //righttop
      glVertex3f (1.0, 0.33, 0.0);
      glVertex3f (1.0, 0.33, 1.0);
      glVertex3f (0.66, 0.33, 1.0);
      glVertex3f (0.66, 0.33, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //topright
      glVertex3f (1.0, 0.33, 0.0);
      glVertex3f (1.0, 0.33, 1.0);
      glVertex3f (0.66, 0.33, 1.0);
      glVertex3f (0.66, 0.33, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //topmid
      glVertex3f (0.66, 1.0, 0.0);
      glVertex3f (0.66, 1.0, 1.0);
      glVertex3f (0.33, 1.0, 1.0);
      glVertex3f (0.33, 1.0, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //topleft
      glVertex3f (0.33, 0.33, 0.0);
      glVertex3f (0.33, 0.33, 1.0);
      glVertex3f (0.0, 0.33, 1.0);
      glVertex3f (0.0, 0.33, 0.0);
      glEnd ();
      glBegin (GL_QUADS);   //righttop
      glVertex3f (0.33, 0.33, 0.0);
      glVertex3f (0.33, 1.0, 0.0);
      glVertex3f (0.33, 1.0, 1.0);
      glVertex3f (0.33, 0.33, 1.0);
      glEnd ();
      glBegin (GL_QUADS);   //rightbot
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.33, 0.0);
      glVertex3f (0.0, 0.33, 1.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd ();

      glColor3f(0.0,0.0,0.0); //lines
      glBegin(GL_LINES);   //front
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (1.0, 0.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 0.0);
      glVertex3f (1.0, 0.33, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.66, 0.33, 0.0);
      glVertex3f (1.0, 0.33, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.66, 0.33, 0.0);
      glVertex3f (0.66, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.33, 1.0, 0.0);
      glVertex3f (0.66, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.33, 1.0, 0.0);
      glVertex3f (0.33, 0.33, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.33, 0.0);
      glVertex3f (0.33, 0.33, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.33, 0.0);
      glVertex3f (0.0, 0.0, 0.0);
      glEnd();
      glBegin(GL_LINES);//leftbot
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.33, 1.0);
      glVertex3f (0.0, 0.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.0, 0.33, 1.0);
      glVertex3f (0.0, 0.33, 0.0);
      glEnd();
      glBegin(GL_LINES);//topleft
      glVertex3f (0.0, 0.33, 1.0);
      glVertex3f (0.33, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.33, 0.33, 0.0);
      glVertex3f (0.33, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.33, 1.0, 1.0);
      glVertex3f (0.33, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.33, 1.0, 1.0);
      glVertex3f (0.33, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);//topmid
      glVertex3f (0.33, 1.0, 1.0);
      glVertex3f (0.66, 1.0, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.66, 1.0, 1.0);
      glVertex3f (0.66, 1.0, 0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.66, 1.0, 1.0);
      glVertex3f (0.66, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (0.66, 0.33, 0.0);
      glVertex3f (0.66, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);//topleft
      glVertex3f (0.66, 0.33, 1.0);
      glVertex3f (1.0, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.33, 0.0);
      glVertex3f (1.0, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 0.33, 1.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f (1.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 0.0);
      glEnd();
      glBegin(GL_LINES);//back
      glVertex3f (0.0, 0.0, 1.0);
      glVertex3f (1.0, 0.0, 1.0);
      glEnd();
   glEndList ();
      
   shapes[3] = glGenLists (1);
   glNewList (shapes[3], GL_COMPILE); 
   
   glEndList ();
}