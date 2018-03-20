#include <GL/glut.h>
#include <stdio.h>
#include "renderer.h"
#include "land.h"
#include "color_conv.h"

//land Coordinates
float land_x[8];//= {gx(0),gx(1920),gx(1920),gx(0)};
float land_y[8];//= {gy(300),gy(300),gy(1080),gy(1080)};
float land_z[8];//= {0,0,0,0};
void landInit(){
 land_x[0]= -2;
 land_x[1]= gx(1920/4);
 land_x[2]= gx(1920/4);
 land_x[3]= -2;
 land_y[0]= gy(0);
 land_y[1]= gy(0);
 land_y[2]= gy(300);
 land_y[3]= gy(300);
 land_z[0]= 0;
 land_z[1]= 0;
 land_z[2]= -2;
 land_z[3]= -2;
}

//Render for land
struct landStates{
 float *x;
 float *y;
 float *z;
 float r;
 float g;
 float b;
 int i;
}landState;
void renderland(){
 
 glColor3f(landState.r,landState.g,landState.b);
 //printf("&%f %f %f %f %f %f %f %f&\n",landState.x[0],landState.x[1],landState.x[2],landState.x[3],landState.y[0],landState.y[1],landState.y[2],landState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));
 glBegin(GL_POLYGON);
  glVertex3f(landState.x[0],landState.y[0],land_z[0]);
  glVertex3f(landState.x[1],landState.y[1],land_z[1]);
  glVertex3f(landState.x[2],landState.y[2],land_z[2]);
  glVertex3f(landState.x[3],landState.y[3],land_z[3]);
 glEnd();


 
 /*glBegin (GL_LINES);

  glColor3f (1,0,0);
  //glPointSize(10.0);
  glVertex3f (-1,0,0);  
  glVertex3f (1,0,0);
  glColor3f (1,1,0);
  glVertex3f(0.5,0,-2);
  glVertex3f(0.5,0,0);
  
  
 glEnd();*/

 //glutWireCube(0.7);
 

}

//Animation
int drawAnimatedLandRegistered=0;
void setlandColor(float r,float g,float b){
 landState.r=r;
 landState.g=g;
 landState.b=b;
}
int drawAnimatedLand(){
 static int i=0;
 if(drawAnimatedLandRegistered==0){
  landInit();
  landState.x=land_x;
  landState.y=land_y;
  landState.z=land_z;
  landState.r=11/255.0;
  landState.g=40/255.0;
  landState.b=13/255.0;
  landState.i=i;
  register_func(renderland);
  drawAnimatedLandRegistered=1;
  
 } else {
 RGB color;
 color = hslToRgb(124.5/360.0, 0.554, 0.1+(((i/100.0)<0.4)?i/100.0:0.4));
 //printf("%f %f %f\n",color.r,color.g,color.b);
 setlandColor(color.r,color.g,color.b);

  landState.i=i;
 }
 glutPostRedisplay();
 
 
 return ((i++) == 80 ? 1:0);
}
