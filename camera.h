#ifndef CAMERA_H
#define CAMERA_h

extern float cam_eye_x;
extern float cam_eye_y;
extern float cam_eye_z;
extern float ref_x;
extern float ref_y;
extern float ref_z;
extern float up_x;
extern float up_y;
extern float up_z;
extern float zoom;

//WARNING: Only render() in renderer.c uses this functon to keep the order in check.
void cameraUpdate();

#endif
