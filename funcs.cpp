#include <iostream>
#include "imageio.h"
#include <string>

void invert (std::string input) {

int h = 0;
int w = 0;
int img[MAX_H][MAX_W];

 readImage(input,img,h, w); 

int output[MAX_H][MAX_W];
  
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      output[row][col] = 255 - img[row][col];
    }
}
  writeImage("taskA.pgm",output,h,w);
  }
