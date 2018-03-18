#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cross_sleep.h"
#include "color_conv.h"



//Screen Resolution
int W = 1920;
int H = 1080;

int pSize=0;
void (*render_proc[100])();

float gx(unsigned int x){
 return -1.0 + (2.0/W)*x;
}

float gy(unsigned int y){
 return -1.0 + (2.0/H)*y;
}

/*                                                                                 Constants                                       */

//Sky Coordinates
float sky_x[4];//= {gx(0),gx(1920),gx(1920),gx(0)};
float sky_y[4];//= {gy(300),gy(300),gy(1080),gy(1080)};
float sky_z[4];//= {0,0,0,0};
void skyInit(){
 sky_x[0]= gx(0);
 sky_x[1]= gx(1920);
 sky_x[2]= gx(1920);
 sky_x[3]= gx(0);
 sky_y[0]= gy(300);
 sky_y[1]= gy(300);
 sky_y[2]= gy(1080);
 sky_y[3]= gy(1080);
 sky_z[0]= 0;
 sky_z[1]= 0;
 sky_z[2]= 0;
 sky_z[3]= 0;
}



void drawText(float x, float y, float r, float g, float b, const char *string){
 int i;
 glColor3f(r, g, b);
 glRasterPos2f(x, y);
 for(i=0;i<strlen(string);i++)glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
}

void drawText1(float x, float y, float r, float g, float b, const char *string){
 int i;

 glColor3f(r, g, b);
 glRasterPos2f(x, y);
 for(i=0;i<strlen(string);i++)glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}

void init(void){
 glClearColor(0,0,0,0);
 glClearDepth(1.0f);

}

void render(void){
 int i;
 // clear the drawing buffer.
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

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

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glutPostRedisplay();
}



void register_func(void (*func)()){
 render_proc[pSize++]=func;
}

void clear_render(){
 pSize=0;
}



/*                                                                All Render Functions here                                                      */

void renderStaticText(){
 drawText(gx(850), gy(1020), 0.5, 1, 0.8, "PROJECT TITLE:");
 //drawText(gx(850), gy(1000), 0.4, 0.21, 1, "Save Water, Maintain Peace!");
 drawText(gx(850), gy(980), 1, 1, 1, "Developed By:");

 drawText(gx(850), gy(960), 1, 0, 0, "MAYANK VERMA");
 drawText(gx(850), gy(940), 1, 1, 0.2, "(1DS15CS056)");
 drawText(gx(850), gy(920), 1, 0, 0, "MOHAMMED FAIZAN");
 drawText(gx(850), gy(900), 1, 1, 0.2, "(1DS15CS059)");
 drawText(gx(850), gy(880), 1, 0, 0, "MOHAMMED NAHID");
 drawText(gx(850), gy(860), 1, 1, 0.2, "(1DS15CS060)");


 drawText(gx(850), gy(840), 1, 1, 1, "Under the guidance of :");
 drawText(gx(850), gy(820), 1, 0, 0, "Prof RAVICHANDRAN H");
 drawText1(gx(850), gy(800), 1, 1, 0.2, "Asst Professor, Dept of CSE");

 drawText(gx(850), gy(780), 1, 0, 0, "VASUDHENDRA SHROFF");
 drawText1(gx(850), gy(760), 1, 1, 0.2, "Guest Faculty of DSCE");


 drawText(gx(850), gy(740), 0, 1, 0, "PRESS 'x' FOR MANUAL PAGE");
}

//Render for animated text
struct textStates{
 float x;
 float y;
 float r;
 float g;
 float b;
 const char *string;
 int i;
}t;
void renderAnimatedText(){
 int i;
 //printf("Hello %f %f %d\n",t.x,t.y,t.i);
 glColor3f(t.r, t.g, t.b);
 glRasterPos2f(t.x, t.y);
 for(i=0;i<=t.i;i++)glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t.string[i]);
 
}

//Render for sky
struct skyStates{
 float *x;
 float *y;
 float *z;
 float r1;
 float g1;
 float b1;
 int i;
}sState;
void renderSky(){
 glColor3f(sState.r1,sState.g1,sState.b1);
 printf("&%f %f %f %f %f %f %f %f&\n",sState.x[0],sState.x[1],sState.x[2],sState.x[3],sState.y[0],sState.y[1],sState.y[2],sState.y[3]);
 printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));
 glBegin(GL_POLYGON);
  glVertex3f(sState.x[0],sState.y[0],0);
  glVertex3f(sState.x[1],sState.y[1],0);
  glVertex3f(sState.x[2],sState.y[2],0);
  glVertex3f(sState.x[3],sState.y[3],0);
 glEnd();

}


/*                                                                 All animation functions here                                       */

int drawStaticTextRegistered=0;
int drawStaticText(){
 if(drawStaticTextRegistered==0){register_func(renderStaticText);drawStaticTextRegistered=1;}
 glutPostRedisplay();
 return 1;
}

int drawAnimatedTextRegistered=0;
int drawAnimatedText(float x, float y, float r, float g, float b, const char *string){
 static int i=0;
 if(drawAnimatedTextRegistered==0){
  t.x=x;
  t.y=y;
  t.r=r;
  t.g=g;
  t.b=b;
  t.string=string;
  t.i=i;
  register_func(renderAnimatedText);
  drawAnimatedTextRegistered=1;
  glutPostRedisplay();
  
 } else {
  
  t.i=i;
  glutPostRedisplay();
 }

 return (i++==(strlen(string)-1))?1:0;
  
}

int drawAnimatedSkyRegistered=0;
void setSkyColor(float r1,float g1,float b1){
 sState.r1=r1;
 sState.g1=g1;
 sState.b1=b1;
}
int drawAnimatedSky(float *x,float *y,float *z,float r, float g, float b){
 static int i=0;
 if(drawAnimatedSkyRegistered==0){
  skyInit();
  sState.x=x;
  sState.y=y;
  sState.z=z;
  sState.r1=r;
  sState.g1=g;
  sState.b1=b;
  sState.i=i;
  register_func(renderSky);
  drawAnimatedSkyRegistered=1;
  
 } else {
 if(i<10)setSkyColor(sState.r1=0.051,0.278,0.631);
 else if(i<20)setSkyColor(0.082, 0.396, 0.753);
 else if(i<30)setSkyColor(0.098, 0.463, 0.824);
 else if(i<40)setSkyColor(0.118, 0.533, 0.898);
 else if(i<50)setSkyColor(0.129, 0.588, 0.953);
 else if(i<60)setSkyColor(0.259, 0.647, 0.961);
 else if(i<70)setSkyColor(0.392, 0.71, 0.965);
 else if(i<80)setSkyColor(1,1,1);
  sState.i=i;
 }
 glutPostRedisplay();
 
 
 return ((i++) == 80 ? 1:0);
}

//Animation Manager
int step1_1=-1;
int step2_1=0;

int scene=1;

void animate(){

  
 if(scene==1){
  switch(step1_1){
   case -1:sleep_ms(50);step1_1++;break; //Proper Screen Refresh
   case 0:
    step1_1+=drawAnimatedText(gx(850), gy(1000), 0.4, 0.21, 1, "Save Water, Maintain Peace!");
    sleep_ms(100);
    break;
   case 1:
    step1_1+=drawStaticText();
    break;
  }
 } else if(scene==2){
  switch(step2_1){
   case 0:
    
    step2_1+=drawAnimatedSky(sky_x,sky_y,sky_z,0,0,1);
    sleep_ms(100);
    break;
  }
 }
 
}

void main_menu(unsigned char c,int x,int y){
 switch(c){
  case 'r':
  t.r=1;
  t.g=0;
  t.b=0;
  break;

  case 'g':
  t.r=0;
  t.g=1;
  t.b=0;
  break;

  case 'b':
  t.r=0;
  t.g=0;
  t.b=1;
  break;

  case 'x':
  case 'X':
  clear_render();
  break;

  case 'y':
  case 'Y':
  scene=2;
  break;
 }
 glutPostRedisplay();
 
}

int main(int argc, char** argv){

 glutInit(&argc, argv);
 //we initizlilze the glut. functions
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(W=((argc==3)?atoi(argv[0]):W),H=((argc==2)?atoi(argv[1]):H));
 glutCreateWindow(argv[0]);
 init();
 glutDisplayFunc(render);
 glutReshapeFunc(reshape);
 glutKeyboardFunc(main_menu);
 glutIdleFunc(animate);
 glutFullScreen();
 glEnable(GL_DEPTH_TEST);
 
 glutMainLoop();

 return 0;
}
