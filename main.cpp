#include <iostream>
#include <string>
#include "funcs.h"
#include "imageio.h"

int main() {

  
invert("image1.pgm");
  

invert_half("image1.pgm");

box("image1.pgm");

frame("image1.pgm");

scale("inImage.pgm");

pixelate("image1.pgm");

}
