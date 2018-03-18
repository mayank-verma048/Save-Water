/*
 *  Coordinates
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  OpenGL with prototypes for glext */
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/*  Globals */
double dim=2; /* dimension of orthogonal box */
char *windowName = "Program";

void drawText(float x, float y, int r, int g, int b, const char *string){
 int i;
 glColor3f(r, g, b);
 glRasterPos2f(x, y);
 for(i=0;i<strlen(string);i++)glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
}
void drawText1(float x, float y, int r, int g, int b, const char *string){
 int i;

 glColor3f(r, g, b);
 glRasterPos2f(x, y);
 for(i=0;i<strlen(string);i++)glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}

/*
 *  Display the scene
 */
void display()
{
  /*  Clear the image */
  glClear(GL_COLOR_BUFFER_BIT);
  /*  Reset previous transforms */
  glLoadIdentity();

  /* draw something here */
  drawText(0, 0, 0.5, 1, 0.8, "PROJECT TITLE:");
 drawText(220, 350, 0.4, 0.21, 1, "Save Water, Maintain Peace!");
 drawText(150, 230, 1, 1, 1, "Developed By:");

 drawText(150, 200, 1, 0, 0, "MAYANK VERMA");
 drawText(150, 180, 1, 1, 0.2, "(1DS15CS056)");
 drawText(150, 160, 1, 0, 0, "MOHAMMED FAIZAN");
 drawText(150, 140, 1, 0, 0, "(1DS15CS059)");
 drawText(150, 120, 1, 1, 0.2, "MOHAMMED NAHID");
 drawText(150, 100, 1, 1, 0.2, "(1DS15CS060)");


 drawText(350, 230, 1, 1, 1, "Under the guidance of :");
 drawText(350, 190, 1, 0, 0, "Prof RAVICHANDRAN H");
 drawText1(350, 170, 1, 1, 0.2, "Asst Professor, Dept of CSE");

 drawText(350, 130, 1, 0, 0, "VASUDHENDRA SHROFF");
 drawText1(350, 110, 1, 1, 0.2, "Guest Faculty of DSCE");

  /*  Flush and swap */
  glFlush();
  glutSwapBuffers();
}

/*
 *  GLUT calls this routine when a key is pressed
 */
void key(unsigned char ch,int x,int y)
{
  /*  Exit on ESC */
  if (ch == 27)
    exit(0);

  /*  Tell GLUT it is necessary to redisplay the scene */
  glutPostRedisplay();
}

/*
 *  GLUT calls this routine when an arrow key is pressed
 */
void special(int key,int x,int y)
{
  /*  Right arrow key (exit) */
  if (key == GLUT_KEY_RIGHT)
    exit(0);

  /*  Tell GLUT it is necessary to redisplay the scene */
  glutPostRedisplay();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void reshape(int width,int height)
{
  /*  Ratio of the width to the height of the window */
  double w2h = (height>0) ? (double)width/height : 1;
  /*  Set the viewport to the entire window */
  glViewport(0,0, width,height);
  /*  Tell OpenGL we want to manipulate the projection matrix */
  glMatrixMode(GL_PROJECTION);
  /*  Undo previous transformations */
  glLoadIdentity();
  /*  Orthogonal projection box adjusted for the
      aspect ratio of the window */
  glOrtho(-dim*w2h,+dim*w2h, -dim,+dim, -dim,+dim);
  /*  Switch to manipulating the model matrix */
  glMatrixMode(GL_MODELVIEW);
  /*  Undo previous transformations */
  glLoadIdentity();
}

/*
 *  Start up GLUT and tell it what to do
 */
int main(int argc,char* argv[])
{
  /*  Initialize GLUT and process user parameters */
  glutInit(&argc,argv);
  /*  Request double buffered, true color window */
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  /*  Request 500 x 500 pixel window */
  glutInitWindowSize(500,500);
  /*  Create the window */
  glutCreateWindow(windowName);
  /*  Tell GLUT to call "display" when the scene should be drawn */
  glutDisplayFunc(display);
  /*  Tell GLUT to call "reshape" when the window is resized */
  glutReshapeFunc(reshape);
  /*  Tell GLUT to call "special" when an arrow key is pressed */
  glutSpecialFunc(special);
  /*  Tell GLUT to call "key" when a key is pressed */
  glutKeyboardFunc(key);
  /*  Pass control to GLUT so it can interact with the user */
  glutMainLoop();
  /*  Return code */
  return 0;
}
