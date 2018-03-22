#ifndef RENDERER_H
#define RENDERER_H

extern unsigned int W;
extern unsigned int H;

float gx(float x);
float gy(float y);
void init(void);
void render(void);
void reshape(GLsizei width, GLsizei height);
void register_func(void (*func)());
void clear_render();


#endif


