#include <GL/glut.h>
#include <stdio.h>
#include "renderer.h"
#include "land.h"
#include "color_conv.h"

//land Coordinates
float land_x[12];
float land_y[12];
float land_z[12];

//land colors
float cr[2];
float cg[2];
float cb[2];

void landInit(){
 land_x[0]= -2;
 land_x[1]= gx(1920/4);
 land_x[2]= gx(1920/4);
 land_x[3]= -2;
 land_x[4]= gx(1440);
 land_x[5]= 2;
 land_x[6]= 2;
 land_x[7]= gx(1440);

 land_y[0]= gy(300);
 land_y[1]= gy(300);
 land_y[2]= gy(300);
 land_y[3]= gy(300);
 land_y[4]= gy(300);
 land_y[5]= gy(300);
 land_y[6]= gy(300);
 land_y[7]= gy(300);


 land_z[0]= 0;
 land_z[1]= 0;
 land_z[2]= -2;
 land_z[3]= -2;
 land_z[4]= 0;
 land_z[5]= 0;
 land_z[6]= -2;
 land_z[7]= -2;

 cr[0]=11/255.0;
 cg[0]=40/255.0;
 cb[0]=13/255.0;

 land_x[8]=  -2;
 land_x[9]=   2;
 land_x[10]=  2;
 land_x[11]= -2;

 land_y[8]= gy(300);
 land_y[9]= gy(300);
 land_y[10]=gy(0);
 land_y[11]=gy(0);

 land_z[8]=-1.99;
 land_z[9]=-1.99;
 land_z[10]=-1.99;
 land_z[11]=-1.99;

 cr[1]=62/255.0;
 cg[1]=39/255.0;
 cb[1]=35/255.0;
}

//Render for land
struct landStates{
 float *x;
 float *y;
 float *z;
 float *r;
 float *g;
 float *b;
 int i;
}landState;
void renderland(){
 int i;
 glColor3f(landState.r[0],landState.g[0],landState.b[0]);
 //printf("&%f %f %f %f %f %f %f %f&\n",landState.x[0],landState.x[1],landState.x[2],landState.x[3],landState.y[0],landState.y[1],landState.y[2],landState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));
 glBegin(GL_POLYGON);
  for(i=0;i<4;i++)glVertex3f(landState.x[i],landState.y[i],land_z[i]);
 glEnd();
  
 glBegin(GL_POLYGON);
  for(i=4;i<8;i++)glVertex3f(landState.x[i],landState.y[i],land_z[i]);
 glEnd();

 glColor3f(landState.r[1],landState.g[1],landState.b[1]);	
 glBegin(GL_POLYGON);
  for(i=8;i<12;i++)glVertex3f(landState.x[i],landState.y[i],land_z[i]);
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
 landState.r[0]=r;
 landState.g[0]=g;
 landState.b[0]=b;
}
int drawAnimatedLand(){
 static int i=0;
 if(drawAnimatedLandRegistered==0){
  landInit();
  landState.x=land_x;
  landState.y=land_y;
  landState.z=land_z;
  landState.r=cr;
  landState.g=cg;
  landState.b=cb;
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
