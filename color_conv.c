
struct struct_RGB{
 float r,g,b;
};

typedef struct struct_RGB RGB;


static float hue2rgb(float p, float q, float t){
 if(t < 0) t += 1;
 if(t > 1) t -= 1;
 if(t < 1/6) return p + (q - p) * 6 * t;
 if(t < 1/2) return q;
 if(t < 2/3) return p + (q - p) * (2/3 - t) * 6;

 return p;
}

RGB hslToRgb(float h, float s, float l){
 float r, g, b, p, q;
 RGB rgb;
 if(s == 0){
  r = g = b = l; // achromatic
 }else{ 
  q = l < 0.5 ? l * (1 + s) : l + s - l * s;
  p = 2 * l - q;
  r = hue2rgb(p, q, h + 1/3);
  g = hue2rgb(p, q, h);
  b = hue2rgb(p, q, h - 1/3);
 }
 rgb.r=r;
 rgb.g=g;
 rgb.b=b;
 return rgb;
}
