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

void invert_half(std::string input){
    int h = 0;
    int w = 0;
    int img[MAX_H][MAX_W];
    readImage(input,img,h, w); 

    int output[MAX_H][MAX_W];
    
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(col >= w/2){
                output[row][col] = 255 - img[row][col];
            }
            else{
                output[row][col] = img[row][col];
            }
        }
    }
    
    writeImage("taskB.pgm",output, h, w);
}
void box(std::string input){

int img[MAX_H][MAX_W];
int h = 0; 
int w = 0;

readImage(input, img, h, w); 
int output[MAX_H][MAX_W];

for(int row = 0; row < h; row++) {

for(int col = 0; col < w; col++) {

if( (row >= h/4 && row < 3*h/4) && ( col >= w/4 && col < 3*w/4) ){
output[row][col] = 255;
}
else{
output[row][col] = img[row][col];
}
}
}

writeImage("taskC.pgm",output, h, w);

}

void frame (std::string input){

int img[MAX_H][MAX_W];
int h = 0;
int w = 0;

readImage(input, img, h, w); 

int starth = h/2;
starth /= 2;
  
int startw = w/2;
startw /= 2;
  
int output [MAX_H][MAX_W];

for(int row = 0; row < h; row++) {

for(int col = 0; col < w; col++) {

  output [row][col] = img [row][col];

if( col == startw  ||  col == startw*3 ){
  for (int row = starth;row < starth*3; row++){

output[row][col] = 255;
    }
  }
}
  
 if(row == starth  ||  row == starth*3 ){

   for(int col = startw; col < startw*3; col++){
output[row][col] = 255;

}
    }
  }

writeImage("taskD.pgm",output, h, w);

} 

void scale(std::string input){

int img[MAX_H][MAX_W];
int h;
int w;
readImage(input,img, h, w);

int output[MAX_H][MAX_W];
int scalingFactor = 2;

h = h * scalingFactor;
w = w * scalingFactor;

int temp;

for (int row = 0; row < h; row = row+2)
{

for (int col = 0; col < w; col = col+2)
{

temp = img[row / 2][col / 2];


output[row][col] = temp;
output[row + 1][col] = temp;
output[row][col + 1] = temp;
output[row + 1][col + 1] = temp;
}
}

writeImage("taskE.pgm",output, h, w);
}

void pixelate(std::string input){
int h = 0;
int w = 0;
int img[MAX_H][MAX_W];
int average = 0;

readImage(input, img, h, w);

int output[MAX_H][MAX_W];

for(int row = 0; row < h; row = row+2)
{
    for(int col = 0; col < w; col=col+2)
    {
        average = (img[row][col] + img[row + 1][col]

            + img[row][col + 1] + img[row + 1][col + 1]) / 4;
        output[row][col] = average;
        output[row + 1][col] = average;
        output[row][col + 1] = average;
        output[row + 1][col + 1] = average;
    }
}

writeImage("taskF.pgm", output, h, w);
}
