#include <GL/glut.h>
#include "renderer.h"
//Screen Resolution
unsigned int W = 1920;
unsigned int H = 1080;

unsigned int pSize=0;
void (*render_proc[100])();

float gx(unsigned int x){
 return -1.0 + (2.0/W)*x;
}

float gy(unsigned int y){
 return -1.0 + (2.0/H)*y;
}

void init(void){
 glClearColor(0,0,0,0);
 //glClearDepth(1.0f);
 //glShadeModel(GL_SMOOTH);

}

void render(void){
 int i;
 static int j=0;
 // clear the drawing buffer.
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

 //Camera movement MOVE IT TO SPEPARATE FILE
 glMatrixMode (GL_MODELVIEW);
 glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
 gluLookAt (0.0, 0.2+((((j)/100.0)<1.8)?(j/100.0):1.8), 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 j++;
 //Iterate through all render procedures
 for(i=0;i<pSize;i++)render_proc[i]();
 glutSwapBuffers();
}




void reshape(GLsizei width, GLsizei height) {  
   // Compute aspect ratio of the new window

   /*if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0,0, width, height);
 
   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 *aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }*/

  /*glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //gluLookAt(0, 0, 0, 0, 0,-1, 0, 1, 0);*/
  glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 5.0, 10.0);
   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
   gluLookAt (0.0, 0.2, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glutPostRedisplay();
}



void register_func(void (*func)()){
 render_proc[pSize++]=func;
}

void clear_render(){
 pSize=0;
}
