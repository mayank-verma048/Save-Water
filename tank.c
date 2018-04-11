#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "renderer.h"
#include "tank.h"
#include "color_conv.h"

//tank Coordinates
float tank_x[2000];//= {gx(0),gx(1920),gx(1920),gx(0)};
float tank_y[2000];//= {gy(300),gy(300),gy(1080),gy(1080)};
float tank_z[2000];//= {0,0,0,0};
void tankInit(){
  //top1
 tank_x[0]= gx(340);
 tank_x[1]= gx(380);
 tank_x[2]= gx(380);
 tank_x[3]= gx(340);

 //front1
 tank_x[4]= gx(340);
 tank_x[5]= gx(320);
 tank_x[6]= gx(400);
 tank_x[7]= gx(380);

 //back1
 tank_x[8]= gx(340);
 tank_x[9]= gx(320);
 tank_x[10]= gx(400);
 tank_x[11]= gx(380);

 //left1
 tank_x[12]= gx(340);
 tank_x[13]= gx(340);
 tank_x[14]= gx(320);
 tank_x[15]= gx(320);

 //right1
 tank_x[16]= gx(380);
 tank_x[17]= gx(380);
 tank_x[18]= gx(400);
 tank_x[19]= gx(400);

 //top1
 tank_y[0]= gy(400);
 tank_y[1]= gy(400);
 tank_y[2]= gy(400);
 tank_y[3]= gy(400);

 //front1
 tank_y[4]= gy(400);
 tank_y[5]= gy(350);
 tank_y[6]= gy(350);
 tank_y[7]= gy(400);

 //back1
 tank_y[8]= gy(400);
 tank_y[9]= gy(350);
 tank_y[10]= gy(350);
 tank_y[11]= gy(400);

 //left1
 tank_y[12]= gy(400);
 tank_y[13]= gy(400);
 tank_y[14]= gy(350);
 tank_y[15]= gy(350);

 //right1
 tank_y[16]= gy(400);
 tank_y[17]= gy(400);
 tank_y[18]= gy(350);
 tank_y[19]= gy(350);

 //top1
 tank_z[0]= -0.450;
 tank_z[1]= -0.450;
 tank_z[2]= -0.525;
 tank_z[3]= -0.525;

 //front1
 tank_z[4]= -0.450;
 tank_z[5]= -0.375;
 tank_z[6]= -0.375;
 tank_z[7]= -0.450;

 //back1
 tank_z[8]= -0.525;
 tank_z[9]= -0.6;
 tank_z[10]= -0.6;
 tank_z[11]= -0.525;

 //left1
 tank_z[12]= -0.450;
 tank_z[13]= -0.525;
 tank_z[14]= -0.6;
 tank_z[15]= -0.375;

 //right1
 tank_z[16]= -0.525;
 tank_z[17]= -0.450;
 tank_z[18]= -0.375;
 tank_z[19]= -0.6;

//
//top2
 tank_x[20]= gx(300);
 tank_x[21]= gx(420);
 tank_x[22]= gx(420);
 tank_x[23]= gx(300);

 //front2
 tank_x[24]= gx(420);
 tank_x[25]= gx(300);
 tank_x[26]= gx(280);
 tank_x[27]= gx(440);

 //back2
 tank_x[28]= gx(420);
 tank_x[29]= gx(300);
 tank_x[30]= gx(280);
 tank_x[31]= gx(440);

 //left2
 tank_x[32]= gx(300);
 tank_x[33]= gx(280);
 tank_x[34]= gx(280);
 tank_x[35]= gx(300);

 //right2
 tank_x[36]= gx(420);
 tank_x[37]= gx(440);
 tank_x[38]= gx(440);
 tank_x[39]= gx(420);

 //top2
 tank_y[20]= gy(350);
 tank_y[21]= gy(350);
 tank_y[22]= gy(350);
 tank_y[23]= gy(350);

 //front2
 tank_y[24]= gy(350);
 tank_y[25]= gy(350);
 tank_y[26]= gy(300);
 tank_y[27]= gy(300);

 //back2
 tank_y[28]= gy(350);
 tank_y[29]= gy(350);
 tank_y[30]= gy(300);
 tank_y[31]= gy(300);

 //left2
 tank_y[32]= gy(350);
 tank_y[33]= gy(300);
 tank_y[34]= gy(300);
 tank_y[35]= gy(350);

 //right2
 tank_y[36]= gy(350);
 tank_y[37]= gy(300);
 tank_y[38]= gy(300);
 tank_y[39]= gy(350);

 //top2
 tank_z[20]= -0.225;
 tank_z[21]= -0.225;
 tank_z[22]= -0.675;
 tank_z[23]= -0.675;

 //front2
 tank_z[24]= -0.225;
 tank_z[25]= -0.225;
 tank_z[26]= -0.150;
 tank_z[27]= -0.150;

 //back2
 tank_z[28]= -0.675;
 tank_z[29]= -0.675;
 tank_z[30]= -0.750;
 tank_z[31]= -0.750;

 //left2
 tank_z[32]= -0.675;
 tank_z[33]= -0.750;
 tank_z[34]= -0.150;
 tank_z[35]= -0.225;

 //right2
 tank_z[36]= -0.675;
 tank_z[37]= -0.750;
 tank_z[38]= -0.150;
 tank_z[39]= -0.225;
}




//Render for tank
struct tankStates{
 float *x;
 float *y;
 float *z;
 float r;
 float g;
 float b;
 int i;
}tankState;
void renderTank(){
 int i,j;
 
 
 //printf("&%f %f %f %f %f %f %f %f&\n",tankState.x[0],tankState.x[1],tankState.x[2],tankState.x[3],tankState.y[0],tankState.y[1],tankState.y[2],tankState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));
 glPushMatrix();
 //glTranslatef(-(gx(340)+gx(380))/2.0,-(gy(400)+gy(300))/2.0,-(-0.450-0.525)/2.0);
 //glRotatef(tankState.i,0,1,0);
 //glTranslatef((gx(340)+gx(380))/2.0,(gy(400)+gy(300))/2.0,(-0.450-0.525)/2.0);
 for(j=0;j<1;j++){
  
  for(i=0;i<10;i++){
   glColor3f(tankState.r,tankState.g,tankState.b);
   glBegin(GL_POLYGON);
    glVertex3f(tankState.x[j*40+0+i*4],tankState.y[j*40+0+i*4],tankState.z[j*40+0+i*4]);
    glVertex3f(tankState.x[j*40+1+i*4],tankState.y[j*40+1+i*4],tankState.z[j*40+1+i*4]);
    glVertex3f(tankState.x[j*40+2+i*4],tankState.y[j*40+2+i*4],tankState.z[j*40+2+i*4]);
    glVertex3f(tankState.x[j*40+3+i*4],tankState.y[j*40+3+i*4],tankState.z[j*40+3+i*4]);
   glEnd();
  }

  glColor3f(0,0,0);
  for(i=0;i<10;i++){
   glBegin(GL_LINE_LOOP);
    glVertex3f(tankState.x[j*40+0+i*4],tankState.y[j*40+0+i*4],tankState.z[j*40+0+i*4]+0.005);
    glVertex3f(tankState.x[j*40+1+i*4],tankState.y[j*40+1+i*4],tankState.z[j*40+1+i*4]+0.005);
    glVertex3f(tankState.x[j*40+2+i*4],tankState.y[j*40+2+i*4],tankState.z[j*40+2+i*4]+0.005);
    glVertex3f(tankState.x[j*40+3+i*4],tankState.y[j*40+3+i*4],tankState.z[j*40+3+i*4]+0.005);
   glEnd();
  }
 }

 
 glPopMatrix();

}

//Animation
int drawAnimatedTankRegistered=0;
void settankColor(float r,float g,float b){
 tankState.r=r;
 tankState.g=g;
 tankState.b=b;
}
int drawAnimatedTank(){
 //printf("Tank called");
 static int i=0;
 if(drawAnimatedTankRegistered==0){
  tankInit();
  tankState.x=tank_x;
  tankState.y=tank_y;
  tankState.z=tank_z;
  tankState.r=0/255.0;
  tankState.g=0/255.0;
  tankState.b=0/255.0;
  tankState.i=i;
  register_func(renderTank);

    tankState.i=i;
  drawAnimatedTankRegistered=1;
  
 } else {
 RGB color;
 color = hslToRgb(194.5/360.0, 0.654, 0.1+(((i/100.0)<0.4)?i/100.0:0.4));
 //printf("%f %f %f\n",color.r,color.g,color.b);
 settankColor(color.r,color.g,color.b);

  tankState.i=i;
 }
 glutPostRedisplay();
 
 
 return ((i++) == 180 ? 1:0);
}
