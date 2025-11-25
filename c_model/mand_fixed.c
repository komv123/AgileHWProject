/*
  Fixed-point integer version of Mandelbrot set visualizer
  
  Compile with:
  gcc -o mandelbrot_fixed -O4 mand_fixed.c

  Usage:
  ./mandelbrot_fixed <xmid> <ymid> <zoom> <maxiter> <out.ppm>

  Example:
  ./mandelbrot_fixed -1.34 0.0 2.0 65535 pic.ppm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

// Fixed-point configuration: use 32 bits for fractional part
#define FRAC_BITS 32
#define FIXED_ONE (1LL << FRAC_BITS)
#define PRINT 0

const uint8_t Red[5]    = {0, 32, 237, 255, 0};
const uint8_t Green[5]  = {7, 107, 255, 170, 2};
const uint8_t Blue[5]   = {100, 203, 255, 0, 0};

// Convert double to fixed-point
int64_t double_to_fixed(double d) {
    return (int64_t)(d * FIXED_ONE);
}

// Multiply two fixed-point numbers
int64_t fixed_mul(int64_t a, int64_t b) {
    // Use 128-bit intermediate to avoid overflow
    __int128 temp = (__int128)a * (__int128)b;
    return (int64_t)(temp >> FRAC_BITS);
}

void colored_pixels(FILE* fp, int k, uint16_t maxiter){
  int Position[5] = {0, 0.16 * maxiter, 0.42 * maxiter, 0.64 * maxiter, maxiter};
  
  if (k >= maxiter) {
    const unsigned char black[] = {0, 0, 0};
    fwrite(black, 3, 1, fp);
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
    
    fwrite(color, 3, 1, fp);
  }
}


int main(int argc, char* argv[])
{
  if (argc != 6) {
    printf("Usage:   %s <xmid> <ymid> <zoom> <maxiter> <out.ppm>\n", argv[0]);
    printf("Example: %s 0.27085 0.27100 1.00000 1024 pic.ppm\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  /* Parse command line - still using doubles for convenience */
  const int64_t xmid = double_to_fixed(atof(argv[1]));
  const int64_t ymid = double_to_fixed(atof(argv[2]));
  const uint64_t zoom = double_to_fixed(atof(argv[3]));

  printf("Double to fixed xmid, ymid, zoom: %ld %ld %ld\n", xmid, ymid, zoom);

  const int64_t xmin = xmid - (zoom / 2);
  const int64_t xmax = xmid + (zoom / 2);
  const int64_t ymin = ymid - ((zoom / 2) * 0.75);
  const int64_t ymax = ymid + ((zoom / 2) * 0.75);

  printf("xmin, xmax, ymin, ymax: %ld %ld %ld %ld\n", xmin, xmax, ymin, ymax);

  const uint16_t maxiter = (unsigned short)atoi(argv[4]) < 256 ? 256 : (unsigned short)atoi(argv[4]);
  
  const int xres = 20;
  const int yres = 15;
  const char* filename = argv[5];

  /* Precompute pixel width and height in fixed-point */
  int64_t dx = (xmax - xmin) / xres;
  int64_t dy = (ymax - ymin) / yres;

   printf("dx, dy: %ld %ld\n", dx, dy);

  /* Escape radius squared: 4.0 in fixed-point */
  int64_t escape = double_to_fixed(4.0);
  printf("escape, df2.0: %ld, %ld\n", escape, double_to_fixed(2.0));

  FILE * fp = fopen(filename,"wb");
  fprintf(fp,
          "P6\n# Mandelbrot (fixed-point), xmin=%ld, xmax=%ld, ymin=%ld, ymax=%ld, maxiter=%d\n%d %d\n255\n",
          xmin, xmax, ymin, ymax, maxiter, xres, yres);

  int i, j, k;
  
  for (j = 0; j < yres; j++) {
    int64_t y = ymax - j * dy;
    
    for(i = 0; i < xres; i++) {
      int64_t x = xmin + i * dx;
      
      /* Initialize iteration variables */
      int64_t u = 0;
      int64_t v = 0;
      int64_t u2 = 0;
      int64_t v2 = 0;
      
      /* Iterate the point */
      for (k = 1; k < maxiter && (u2 + v2 < escape); k++) {
        v = fixed_mul(fixed_mul(double_to_fixed(2.0), u), v) + y;
        u = u2 - v2 + x;
        u2 = fixed_mul(u, u);
        v2 = fixed_mul(v, v);
      }
      if(PRINT){printf("%d ", k);}
      /* Compute pixel color and write it to file */
      if (k >= maxiter) {
        const unsigned char black[] = {0, 0, 0};
        fwrite(black, 3, 1, fp);
      }
      else {
        colored_pixels(fp, k, maxiter);
      }
    }
    if(PRINT){printf("\n");}
  }
  
  fclose(fp);
  return 0;
}