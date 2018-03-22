#include <GL/glut.h>
#include <stdio.h>
#include "renderer.h"
#include "sky.h"
#include "color_conv.h"

//Sky Coordinates
float sky_x[4];//= {gx(0),gx(1920),gx(1920),gx(0)};
float sky_y[4];//= {gy(300),gy(300),gy(1080),gy(1080)};
float sky_z[4];//= {0,0,0,0};
void skyInit(){
 sky_x[0]= -2;
 sky_x[1]= gx(2*1920);
 sky_x[2]= gx(2*1920);
 sky_x[3]= -2;
 sky_y[0]= gy(0);
 sky_y[1]= gy(0);
 sky_y[2]= gy(2*1080);
 sky_y[3]= gy(2*1080);
 sky_z[0]= -2;
 sky_z[1]= -2;
 sky_z[2]= -2;
 sky_z[3]= -2;
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
 //printf("&%f %f %f %f %f %f %f %f&\n",sState.x[0],sState.x[1],sState.x[2],sState.x[3],sState.y[0],sState.y[1],sState.y[2],sState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));
 glBegin(GL_POLYGON);
  glVertex3f(sState.x[0],sState.y[0],sky_z[0]);
  glVertex3f(sState.x[1],sState.y[1],sky_z[1]);
  glVertex3f(sState.x[2],sState.y[2],sky_z[2]);
  glVertex3f(sState.x[3],sState.y[3],sky_z[3]);
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
int drawAnimatedSkyRegistered=0;
void setSkyColor(float r1,float g1,float b1){
 sState.r1=r1;
 sState.g1=g1;
 sState.b1=b1;
}
int drawAnimatedSky(float r, float g, float b){
 static int i=0;
 if(drawAnimatedSkyRegistered==0){
  skyInit();
  sState.x=sky_x;
  sState.y=sky_y;
  sState.z=sky_z;
  sState.r1=r;
  sState.g1=g;
  sState.b1=b;
  sState.i=i;
  register_func(renderSky);
  drawAnimatedSkyRegistered=1;
  
 } else {
  RGB color;
  color = hslToRgb(208/360.0, 1, 0.2+((i/100.0)<0.6)?i/100.0:0.6);
  //printf("&!%f,%f,%f!&\n",color.r,color.g,color.b);
  setSkyColor(color.r,color.g,color.b);
  sState.i=i;
 }
 glutPostRedisplay();
 
 
 return ((i++) == 80 ? 1:0);
}
