#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "renderer.h"
#include "bomb.h"
#include "color_conv.h"


#define SCALE 10

//bomb Coordinates
float bomb_x[200];
float bomb_y[200];
float bomb_z[200];

int DIV;


void bombInit(int div){
 int i;
 int j;
 DIV=div;
 /*bomb_x[0]= gx(480);
 bomb_x[1]= gx(1440);
 bomb_x[2]= gx(1440);
 bomb_x[3]= gx(480);*/
 
 /*printf("%f\n",M_PI);
 for(i=0,j=0;i<div;i++,j+=2){
  bomb_x[j]=R*(9.0/16.0)*cos((float)(2*M_PI/(div-1))*i); //To nullify aspect ratio
  bomb_y[j]=R*sin((float)(2*M_PI/(div-1))*i);
  bomb_z[j]= 0;

  bomb_x[j+1]=R*(9.0/16.0)*cos((float)(2*M_PI/(div-1))*i); //To nullify aspect ratio
  bomb_y[j+1]=R*sin((float)(2*M_PI/(div-1))*i);
  bomb_z[j+1]= -0.2;
  //printf("%f \n",R*cos((float)(2*M_PI/div)*i));
  //printf("%f %f %f\n",bomb_x[i],bomb_y[i],bomb_z[i]);
  //printf("%f %f %f \t %f %f %f\n",bomb_x[j],bomb_y[j],bomb_z[j],bomb_x[j+1],bomb_y[j+1],bomb_z[j+1]);
 }*/

 
 

 /*for(i=0;i<=div;i++){
  bomb_x[i]=gx(480)+((float)((gx(1440)-gx(480))/div)*i);
  bomb_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)i/5));
  bomb_z[i]= 0;
  //printf("%f %f %f\n",bomb_x[i],bomb_y[i],bomb_z[i]);
 }*/


 /*int j=0;
 for(i=div+1;i<=2*div+1;i++){
  bomb_x[i]=gx(1440)-((float)((gx(1440)-gx(480))/div)*(i-div-1));
  bomb_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)(div-j)/5));
  bomb_z[i]= -2;
  //printf("%f %f %f\n",bomb_x[i],bomb_y[i],bomb_z[i]);
  j++;
 }*/




 /*bomb_y[0]= gy(200);
 bomb_y[1]= gy(200);
 bomb_y[2]= gy(200);
 bomb_y[3]= gy(200);



 bomb_z[0]= 0;
 bomb_z[1]= 0;
 bomb_z[2]= -2;
 bomb_z[3]= -2;*/

}

//Render for bomb
struct bombStates{
 float *x;
 float *y;
 float *z;
 float r;
 float g;
 float b;
 int i;
}bombState;
void renderBomb(){
 int i;
 glColor4f(bombState.r,bombState.g,bombState.b,1.0);
 //printf("&%f %f %f %f %f %f %f %f&\n",bombState.x[0],bombState.x[1],bombState.x[2],bombState.x[3],bombState.y[0],bombState.y[1],bombState.y[2],bombState.y[3]);
 //printf("^%f %f %f %f %f %f %f %f^\n",gx(0),gx(1920),gx(1920),gx(0),gy(300),gy(300),gy(1080),gy(1080));

 //printf("^^%d^^\n",DIV);


 /*for(i=0;i<=DIV;i++){
  bomb_y[i]=gy(280)+((gy(300)-gy(280))*sin((float)i/5+bombState.i/10.0));
  //printf("%f %f %f\n",bomb_x[i],bomb_y[i],bomb_z[i]);
 }*/

 glPushMatrix();
 if(bombState.i>1000)glTranslatef(-0.51+((bombState.i-1000)/100.0),-0.3,-0.51);
 else glTranslatef(-0.51,-0.3,-0.51);
 printf("%d\n",bombState.i);
 glScalef(pow(9.0/16.0,1),1,1);
 glutSolidSphere(0.011,50,50);
 glPopMatrix();

}

//Animation
int drawAnimatedBombRegistered=0;
void setBombColor(float r,float g,float b){
 bombState.r=r;
 bombState.g=g;
 bombState.b=b;
}
int drawAnimatedBomb(int div){
 static int i=0;
 if(drawAnimatedBombRegistered==0){
  bombInit(100);
  bombState.x=bomb_x;
  bombState.y=bomb_y;
  bombState.z=bomb_z;
  bombState.r=1.0;
  bombState.g=0.0;
  bombState.b=0.0;
  bombState.i=i;
  register_func(renderBomb);
  drawAnimatedBombRegistered=1;
  
 } else {
 RGB color;
 color = hslToRgb(10/360.0, 0.554, 0.1+(((i/100.0)<0.4)?i/100.0:0.4));
 //printf("%f %f %f\n",color.r,color.g,color.b);
 setBombColor(color.r,color.g,color.b);

  bombState.i=i;
 }
 glutPostRedisplay();
 
 i++;
 return 0;//((i++) == 80 ? 1:0);
}
