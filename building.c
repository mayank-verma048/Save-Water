#include <GL/glut.h>
#include <stdio.h>
#include "renderer.h"
#include "building.h"
#include "color_conv.h"

//building Coordinates
float building_x[2000];//= {gx(0),gx(1920),gx(1920),gx(0)};
float building_y[2000];//= {gy(300),gy(300),gy(1080),gy(1080)};
float building_z[2000];//= {0,0,0,0};
void buildingInit(){
 //top
 building_x[0]= gx(20);
 building_x[1]= gx(90);
 building_x[2]= gx(90);
 building_x[3]= gx(20);

 //front
 building_x[4]= gx(20);
 building_x[5]= gx(90);
 building_x[6]= gx(90);
 building_x[7]= gx(20);

 //back
 building_x[8]= gx(20);
 building_x[9]= gx(90);
 building_x[10]= gx(90);
 building_x[11]= gx(20);

 //left
 building_x[12]= gx(20);
 building_x[13]= gx(20);
 building_x[14]= gx(20);
 building_x[15]= gx(20);

 //right
 building_x[16]= gx(90);
 building_x[17]= gx(90);
 building_x[18]= gx(90);
 building_x[19]= gx(90);

 //top
 building_y[0]= gy(500);
 building_y[1]= gy(500);
 building_y[2]= gy(500);
 building_y[3]= gy(500);

 //front
 building_y[4]= gy(500);
 building_y[5]= gy(500);
 building_y[6]= gy(300);
 building_y[7]= gy(300);

 //back
 building_y[8]= gy(500);
 building_y[9]= gy(500);
 building_y[10]= gy(300);
 building_y[11]= gy(300);

 //left
 building_y[12]= gy(500);
 building_y[13]= gy(500);
 building_y[14]= gy(300);
 building_y[15]= gy(300);

 //right
 building_y[16]= gy(500);
 building_y[17]= gy(500);
 building_y[18]= gy(300);
 building_y[19]= gy(300);

 //top
 building_z[0]= 0;
 building_z[1]= 0;
 building_z[2]= -0.4;
 building_z[3]= -0.4;

 //front
 building_z[4]= 0;
 building_z[5]= 0;
 building_z[6]= 0;
 building_z[7]= 0;

 //back
 building_z[8]= -0.4;
 building_z[9]= -0.4;
 building_z[10]= -0.4;
 building_z[11]= -0.4;

 //left
 building_z[12]= -0.4;
 building_z[13]= 0;
 building_z[14]= 0;
 building_z[15]= -0.4;

 //right
 building_z[16]= 0;
 building_z[17]= -0.4;
 building_z[18]= -0.4;
 building_z[19]= 0;
}

int no=1;
//x,y,z is the vertex at front,left,top of the building.
void initSpecs(float x,float y,float z,float length, float depth){
 

 if(no<100){
  //top
  building_x[0+no*20]= gx(x);
  building_x[1+no*20]= gx(x)+length;
  building_x[2+no*20]= gx(x)+length;
  building_x[3+no*20]= gx(x);

  //front
  building_x[4+no*20]= gx(x);
  building_x[5+no*20]= gx(x)+length;
  building_x[6+no*20]= gx(x)+length;
  building_x[7+no*20]= gx(x);

  //back
  building_x[8+no*20]= gx(x);
  building_x[9+no*20]= gx(x)+length;
  building_x[10+no*20]= gx(x)+length;
  building_x[11+no*20]= gx(x);

  //left
  building_x[12+no*20]= gx(x);
  building_x[13+no*20]= gx(x);
  building_x[14+no*20]= gx(x);
  building_x[15+no*20]= gx(x);

  //right
  building_x[16+no*20]= gx(x)+length;
  building_x[17+no*20]= gx(x)+length;
  building_x[18+no*20]= gx(x)+length;
  building_x[19+no*20]= gx(x)+length;

  //top
  building_y[0+no*20]= gy(y);
  building_y[1+no*20]= gy(y);
  building_y[2+no*20]= gy(y);
  building_y[3+no*20]= gy(y);

  //front
  building_y[4+no*20]= gy(y);
  building_y[5+no*20]= gy(y);
  building_y[6+no*20]= gy(300);
  building_y[7+no*20]= gy(300);

  //back
  building_y[8+no*20]= gy(y);
  building_y[9+no*20]= gy(y);
  building_y[10+no*20]= gy(300);
  building_y[11+no*20]= gy(300);

  //left
  building_y[12+no*20]= gy(y);
  building_y[13+no*20]= gy(y);
  building_y[14+no*20]= gy(300);
  building_y[15+no*20]= gy(300);

  //right
  building_y[16+no*20]= gy(y);
  building_y[17+no*20]= gy(y);
  building_y[18+no*20]= gy(300);
  building_y[19+no*20]= gy(300);

  //top
  building_z[0+no*20]= z;
  building_z[1+no*20]= z;
  building_z[2+no*20]= z-depth;
  building_z[3+no*20]= z-depth; 

  //front
  building_z[4+no*20]= z;
  building_z[5+no*20]= z;
  building_z[6+no*20]= z;
  building_z[7+no*20]= z;

  //back
  building_z[8+no*20]= z-depth;
  building_z[9+no*20]= z-depth;
  building_z[10+no*20]= z-depth;
  building_z[11+no*20]= z-depth;

  //left
  building_z[12+no*20]= z-depth;
  building_z[13+no*20]= z;
  building_z[14+no*20]= z;
  building_z[15+no*20]= z-depth;

  //right
  building_z[16+no*20]= z;
  building_z[17+no*20]= z-depth;
  building_z[18+no*20]= z-depth;
  building_z[19+no*20]= z;
  
 } 
 else printf("Error! Not enough memory.");

 no++;
}

//Render for building
struct buildingStates{
 float *x;
 float *y;
 float *z;
 float r;
 float g;
 float b;
 int i;
}buildingState;
void renderbuilding(){
 int i,j;
 
 //printf("&%f %f %f %f %f %f %f %f&\n",buildingState.x[0],buildingState.x[1],buildingState.x[2],buildingState.x[3],buildingState.y[0],buildingState.y[1],buildingState.y[2],buildingState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));

 
 for(j=0;j<no;j++){
  if(j==1 && buildingState.i<20)continue;
  if(j==2 && buildingState.i<50)continue;
  for(i=0;i<5;i++){
   glColor3f(buildingState.r,buildingState.g,buildingState.b);
   glBegin(GL_POLYGON);
    glVertex3f(buildingState.x[j*20+0+i*4],buildingState.y[j*20+0+i*4],building_z[j*20+0+i*4]);
    glVertex3f(buildingState.x[j*20+1+i*4],buildingState.y[j*20+1+i*4],building_z[j*20+1+i*4]);
    glVertex3f(buildingState.x[j*20+2+i*4],buildingState.y[j*20+2+i*4],building_z[j*20+2+i*4]);
    glVertex3f(buildingState.x[j*20+3+i*4],buildingState.y[j*20+3+i*4],building_z[j*20+3+i*4]);
   glEnd();
  }

  glColor3f(0,0,0);
  for(i=0;i<5;i++){
   glBegin(GL_LINE_LOOP);
    glVertex3f(buildingState.x[j*20+0+i*4],buildingState.y[j*20+0+i*4],building_z[j*20+0+i*4]+0.005);
    glVertex3f(buildingState.x[j*20+1+i*4],buildingState.y[j*20+1+i*4],building_z[j*20+1+i*4]+0.005);
    glVertex3f(buildingState.x[j*20+2+i*4],buildingState.y[j*20+2+i*4],building_z[j*20+2+i*4]+0.005);
    glVertex3f(buildingState.x[j*20+3+i*4],buildingState.y[j*20+3+i*4],building_z[j*20+3+i*4]+0.005);
   glEnd();
  }
 }



}

//Animation
int drawAnimatedBuildingRegistered=0;
void setbuildingColor(float r,float g,float b){
 buildingState.r=r;
 buildingState.g=g;
 buildingState.b=b;
}
int drawAnimatedBuilding(){
 static int i=0;
 if(drawAnimatedBuildingRegistered==0){
  buildingInit();
  buildingState.x=building_x;
  buildingState.y=building_y;
  buildingState.z=building_z;
  buildingState.r=11/255.0;
  buildingState.g=40/255.0;
  buildingState.b=13/255.0;
  buildingState.i=i;
  register_func(renderbuilding);

  initSpecs(70,700,-0.7,0.07,0.25);
  initSpecs(145,800,-0.5,0.085,0.30); 
  
  drawAnimatedBuildingRegistered=1;
  
 } else {
 RGB color;
 color = hslToRgb(194.5/360.0, 0.654, 0.1+(((i/100.0)<0.4)?i/100.0:0.4));
 //printf("%f %f %f\n",color.r,color.g,color.b);
 setbuildingColor(color.r,color.g,color.b);

  buildingState.i=i;
 }
 glutPostRedisplay();
 
 
 return ((i++) == 80 ? 1:0);
}
