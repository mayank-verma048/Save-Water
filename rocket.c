#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "renderer.h"
#include "rocket.h"
#include "color_conv.h"


#define SCALE 10

//rocket Coordinates
float rocket_x[200];
float rocket_y[200];
float rocket_z[200];

int DIV;
const float R=0.02;

void rocketInit(int div){
 int i;
 int j;
 DIV=div;
 /*rocket_x[0]= gx(480);
 rocket_x[1]= gx(1440);
 rocket_x[2]= gx(1440);
 rocket_x[3]= gx(480);*/
 printf("%f\n",M_PI);
 for(i=0,j=0;i<div;i++,j+=2){
  rocket_x[j]=R*(9.0/16.0)*cos((float)(2*M_PI/(div-1))*i); //To nullify aspect ratio
  rocket_y[j]=R*sin((float)(2*M_PI/(div-1))*i);
  rocket_z[j]= 0;

  rocket_x[j+1]=R*(9.0/16.0)*cos((float)(2*M_PI/(div-1))*i); //To nullify aspect ratio
  rocket_y[j+1]=R*sin((float)(2*M_PI/(div-1))*i);
  rocket_z[j+1]= -0.2;
  //printf("%f \n",R*cos((float)(2*M_PI/div)*i));
  //printf("%f %f %f\n",rocket_x[i],rocket_y[i],rocket_z[i]);
  //printf("%f %f %f \t %f %f %f\n",rocket_x[j],rocket_y[j],rocket_z[j],rocket_x[j+1],rocket_y[j+1],rocket_z[j+1]);
 }
 

 /*for(i=0;i<=div;i++){
  rocket_x[i]=gx(480)+((float)((gx(1440)-gx(480))/div)*i);
  rocket_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)i/5));
  rocket_z[i]= 0;
  //printf("%f %f %f\n",rocket_x[i],rocket_y[i],rocket_z[i]);
 }*/


 /*int j=0;
 for(i=div+1;i<=2*div+1;i++){
  rocket_x[i]=gx(1440)-((float)((gx(1440)-gx(480))/div)*(i-div-1));
  rocket_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)(div-j)/5));
  rocket_z[i]= -2;
  //printf("%f %f %f\n",rocket_x[i],rocket_y[i],rocket_z[i]);
  j++;
 }*/




 /*rocket_y[0]= gy(200);
 rocket_y[1]= gy(200);
 rocket_y[2]= gy(200);
 rocket_y[3]= gy(200);



 rocket_z[0]= 0;
 rocket_z[1]= 0;
 rocket_z[2]= -2;
 rocket_z[3]= -2;*/

}

//Render for rocket
struct rocketStates{
 float *x;
 float *y;
 float *z;
 float r;
 float g;
 float b;
 int i;
}rocketState;
void renderRocket(){
 int i;
 glColor4f(rocketState.r,rocketState.g,rocketState.b,1.0);
 //printf("&%f %f %f %f %f %f %f %f&\n",rocketState.x[0],rocketState.x[1],rocketState.x[2],rocketState.x[3],rocketState.y[0],rocketState.y[1],rocketState.y[2],rocketState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));

 //printf("^^%d^^\n",DIV);


 /*for(i=0;i<=DIV;i++){
  rocket_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)i/5+rocketState.i/10.0));
  //printf("%f %f %f\n",rocket_x[i],rocket_y[i],rocket_z[i]);
 }*/

 glPushMatrix();
 glRotatef(90,0,1,0);
 glTranslatef(0.51,-0.3,-0.49);
 glScalef(1,1,0.7); 

 glBegin(GL_QUAD_STRIP);
  for(i=0;i<2*(DIV);i++)glVertex3f(rocketState.x[i],rocketState.y[i],rocket_z[i]);
 glEnd();



 glPopMatrix();

}

//Animation
int drawAnimatedRocketRegistered=0;
void setrocketColor(float r,float g,float b){
 rocketState.r=r;
 rocketState.g=g;
 rocketState.b=b;
}
int drawAnimatedRocket(int div){
 static int i=0;
 if(drawAnimatedRocketRegistered==0){
  rocketInit(100);
  rocketState.x=rocket_x;
  rocketState.y=rocket_y;
  rocketState.z=rocket_z;
  rocketState.r=1.0;
  rocketState.g=0.0;
  rocketState.b=0.0;
  rocketState.i=i;
  register_func(renderRocket);
  drawAnimatedRocketRegistered=1;
  
 } else {
 RGB color;
 color = hslToRgb(200/360.0, 0.554, 0.1+(((i/100.0)<0.4)?i/100.0:0.4));
 //printf("%f %f %f\n",color.r,color.g,color.b);
 setrocketColor(color.r,color.g,color.b);

  rocketState.i=i;
 }
 glutPostRedisplay();
 
 i++;
 return 0;//((i++) == 80 ? 1:0);
}
