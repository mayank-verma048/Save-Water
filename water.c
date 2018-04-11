#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "renderer.h"
#include "water.h"
#include "color_conv.h"

#define SCALE 10

//water Coordinates
float water_x[200];
float water_y[200];
float water_z[200];

int DIV;

void waterInit(int div){
 int i;
 int j;
 DIV=div;
 /*water_x[0]= gx(480);
 water_x[1]= gx(1440);
 water_x[2]= gx(1440);
 water_x[3]= gx(480);*/

 for(i=0,j=0;i<div;i++,j+=2){
  water_x[j]=gx(480)+((float)((gx(1440)-gx(480))/(div-1))*i);
  water_y[j]=gy(280)+((gy(300)-gy(280))*sin((float)i/SCALE));
  water_z[j]= 0;

  water_x[j+1]=gx(480)+((float)((gx(1440)-gx(480))/(div-1))*i);
  water_y[j+1]=gy(280)+((gy(300)-gy(280))*sin((float)i/SCALE));
  water_z[j+1]= -2;
  //printf("%f %f %f\n",water_x[i],water_y[i],water_z[i]);
  //printf("%f %f %f \t %f %f %f\n",water_x[j],water_y[j],water_z[j],water_x[j+1],water_y[j+1],water_z[j+1]);
 }
 

 /*for(i=0;i<=div;i++){
  water_x[i]=gx(480)+((float)((gx(1440)-gx(480))/div)*i);
  water_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)i/5));
  water_z[i]= 0;
  //printf("%f %f %f\n",water_x[i],water_y[i],water_z[i]);
 }*/


 /*int j=0;
 for(i=div+1;i<=2*div+1;i++){
  water_x[i]=gx(1440)-((float)((gx(1440)-gx(480))/div)*(i-div-1));
  water_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)(div-j)/5));
  water_z[i]= -2;
  //printf("%f %f %f\n",water_x[i],water_y[i],water_z[i]);
  j++;
 }*/




 /*water_y[0]= gy(200);
 water_y[1]= gy(200);
 water_y[2]= gy(200);
 water_y[3]= gy(200);



 water_z[0]= 0;
 water_z[1]= 0;
 water_z[2]= -2;
 water_z[3]= -2;*/

}

//Render for water
struct waterStates{
 float *x;
 float *y;
 float *z;
 float r;
 float g;
 float b;
 int i;
}waterState;
void renderwater(){
 int i;
 int j;
 glColor4f(waterState.r,waterState.g,waterState.b,0.3);
 //printf("&%f %f %f %f %f %f %f %f&\n",waterState.x[0],waterState.x[1],waterState.x[2],waterState.x[3],waterState.y[0],waterState.y[1],waterState.y[2],waterState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));

 //printf("^^%d^^\n",DIV);

 for(i=0,j=0;i<DIV;i++,j+=2){
  water_y[j]=gy(280)+((gy(300)-gy(280))*sin((float)i/SCALE+waterState.i/10.0));
  water_y[j+1]=gy(280)+((gy(300)-gy(280))*sin((float)i/SCALE+waterState.i/10.0));
  water_y[j]   -= (waterState.i<950)? 0.0005*waterState.i:0.0005*950;
  water_y[j+1] -= (waterState.i<950)? 0.0005*waterState.i:0.0005*950;
  //printf("%f %f %f\n",water_x[i],water_y[i],water_z[i]);
 }
 //printf("\n");

 /*for(i=0;i<=DIV;i++){
  water_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)i/5+waterState.i/10.0));
  //printf("%f %f %f\n",water_x[i],water_y[i],water_z[i]);
 }


 int j=0;
 for(i=DIV+1;i<=2*DIV+1;i++){
  water_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)(DIV-j)/5+waterState.i/10.0));
  //printf("%f %f %f\n",water_x[i],water_y[i],water_z[i]);
  j++;
 }*/

 glBegin(GL_QUAD_STRIP);
  for(i=0;i<2*(DIV);i++)glVertex3f(waterState.x[i],waterState.y[i],water_z[i]);
 glEnd();

  glBegin(GL_QUAD_STRIP);
  for(i=0;i<2*(DIV);i+=2){
   glVertex3f(waterState.x[i],waterState.y[i],water_z[i]);
   glVertex3f(waterState.x[i],gy(0),waterState.z[i]);
  }
 glEnd();

 /*glColor3f(1,0,0);
 glBegin(GL_LINE_LOOP);
  for(i=0;i<2*(DIV+1);i++)glVertex3f(waterState.x[i],waterState.y[i],water_z[i]);
 glEnd();*/
  


 
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
int drawAnimatedWaterRegistered=0;
void setwaterColor(float r,float g,float b){
 waterState.r=r;
 waterState.g=g;
 waterState.b=b;
}
int drawAnimatedWater(int div){
 static int i=0;
 if(drawAnimatedWaterRegistered==0){
  waterInit(100);
  waterState.x=water_x;
  waterState.y=water_y;
  waterState.z=water_z;
  waterState.r=0.0;
  waterState.g=0.0;
  waterState.b=1;
  waterState.i=i;
  register_func(renderwater);
  drawAnimatedWaterRegistered=1;
  
 } else {
 RGB color;
 color = hslToRgb(191/360.0, 0.554, 0.1+(((i/100.0)<0.4)?i/100.0:0.4));
 //printf("%f %f %f\n",color.r,color.g,color.b);
 setwaterColor(color.r,color.g,color.b);

  waterState.i=i;
 }
 glutPostRedisplay();
 
 i++;
 return 0;//((i++) == 80 ? 1:0);
}
