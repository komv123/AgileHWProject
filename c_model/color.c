#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

const uint8_t Red[5]    = {0, 2, 14, 15, 0};
const uint8_t Green[5]  = {0, 6, 15, 10, 0};
const uint8_t Blue[5]   = {6, 12, 15, 0, 0};

void colored_pixels(int k, uint16_t maxiter){
  int Position[5] = {0, 0.16 * maxiter, 0.42 * maxiter, 0.64 * maxiter, maxiter};
  
  if (k >= maxiter) {
    const unsigned char black[] = {0, 0, 0};
    printf("k: %d, RGB: %x\n", k, 0x000);
  }
  else {
    unsigned char color[3];
    int segment = 0;
    for (int i = 0; i < 4; i++) {
      if (k >= Position[i] && k < Position[i+1]) {
        segment = i;
        break;
      }
    }
    
    // Integer-only interpolation using fixed-point arithmetic
    int range = Position[segment+1] - Position[segment];
    int offset = k - Position[segment];
    
    // Multiply by 256 for precision, then divide back
    color[0] = Red[segment] + ((offset * (Red[segment+1] - Red[segment]) * 256) / range) / 256;
    color[1] = Green[segment] + ((offset * (Green[segment+1] - Green[segment]) * 256) / range) / 256;
    color[2] = Blue[segment] + ((offset * (Blue[segment+1] - Blue[segment]) * 256) / range) / 256;

    uint16_t rgb = ((color[0] << 8) & 0xF00) | ((color[1] << 4) & 0x0F0) | (color[2] & 0x00F);
    
    printf("k: %d, RGB: %03x <- %x %x %x\n", k, rgb, color[0], color[1], color[2]);
  }
}

int main(int argc, char const *argv[])
{
    for (int16_t i = 1; i <= 1000; i++){
        colored_pixels(i, 1000);
    }
    return 0;
}
