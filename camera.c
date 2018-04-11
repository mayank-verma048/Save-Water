#include <GL/glut.h>
#include <stdio.h>
#include "camera.h"

float cam_eye_x=0.0;
float cam_eye_y=0.2;
float cam_eye_z=5.0;
float ref_x=0.0;
float ref_y=0.0;
float ref_z=0.0;
float up_x=0.0;
float up_y=1.0;
float up_z=0.0;
float zoom=0.0;

void cameraUpdate(){
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 glFrustum (-1.0+zoom, 1.0-zoom, -1.0+zoom, 1.0-zoom, 5.0, 10.0);

 glMatrixMode (GL_MODELVIEW);
 glLoadIdentity ();                  
 gluLookAt (cam_eye_x,cam_eye_y,cam_eye_z,ref_x,ref_y,ref_z,up_x,up_y,up_z);
 //printf("%f %f %f %f %f %f %f %f %f\n",cam_eye_x,cam_eye_y,cam_eye_z,ref_x,ref_y,ref_z,up_x,up_y,up_z);
}
