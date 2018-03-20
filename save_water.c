#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cross_sleep.h"
#include "color_conv.h"
#include "renderer.h"
#include "sky.h"
#include "land.h"
#include "building.h"




/*                                                                                 Constants                                       */

//sky.c


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

//renderer.c code here



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

//sky.c


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
  //glutPostRedisplay();
  
 } else {
  
  t.i=i;
  //glutPostRedisplay();
 }

 return (i++==(strlen(string)-1))?1:0;
  
}

//sky.c

int toggle=1;
void toggleAnimation(){
 toggle=toggle?0:1;
}

/*Animation Manager:
Format stepx_y where x=scene_no, y=sequence_no
Drawings in a scene in same sequence_no are rendered sequentially.
Drawings in a scene in different sequence_no are rendered paralelly.
*/ 
int step1_1=-1;
int step2_1=0;
int step2_2=0;
int step2_3=0;

int scene=2;

void animate(){

 if(toggle){
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
  } 
  else if(scene==2){
   switch(step2_1){
    case 0:
    
     step2_1+=drawAnimatedSky(0,0,1);
    
     break;
   }
   switch(step2_2){
    case 0:
     step2_2+=drawAnimatedLand();
     break;
   }
   switch(step2_3){
    case 0:
     step2_3+=drawAnimatedBuilding();
     break;
   }
   sleep_ms(30);
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

  case 'p':
  case 'P':
  toggleAnimation();
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
 glutInitWindowSize(W=((argc==3)?atoi(argv[1]):W),H=((argc==2)?atoi(argv[2]):H));
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
