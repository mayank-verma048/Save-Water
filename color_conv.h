#ifndef COLOR_CONV_H
#define COLOR_CONV_H


struct struct_RGB{
 float r,g,b;
};

typedef struct struct_RGB RGB;

RGB hslToRgb(float h, float s, float l);

#endif
