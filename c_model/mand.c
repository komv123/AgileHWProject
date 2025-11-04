/*
  This program is an adaptation of the Mandelbrot program
  from the Programming Rosetta Stone, see
  http://rosettacode.org/wiki/Mandelbrot_set

  Compile the program with:

  gcc -o mandelbrot -O4 mand.c

  Usage:
 
  ./mandelbrot <xmid> <ymid> <zoom> <maxiter> <out.ppm>

  Example:

  ./mandelbrot -1.34 0.0 2.0 65535 pic.ppm

  The interior of Mandelbrot set is black, the levels are gray.
  If you have very many levels, the picture is likely going to be quite
  dark. You can postprocess it to fix the palette. For instance,
  with ImageMagick you can do (assuming the picture was saved to pic.ppm):

  convert -normalize pic.ppm pic.png

  The resulting pic.png is still gray, but the levels will be nicer. You
  can also add colors, for instance:

  convert -normalize -fill blue -tint 100 pic.ppm pic.png

  See http://www.imagemagick.org/Usage/color_mods/ for what ImageMagick
  can do. It can do a lot.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

/*
Position = 0.0     Color = (  0,   7, 100)
Position = 0.16    Color = ( 32, 107, 203)
Position = 0.42    Color = (237, 255, 255)
Position = 0.6425  Color = (255, 170,   0)
Position = 0.8575  Color = (  0,   2,   0)
*/

const uint8_t Red[5]    = {0, 32, 237, 255, 0};
const uint8_t Green[5]  = {7, 107, 255, 170, 2};
const uint8_t Blue[5]   = {100, 203, 255, 0, 0};

void colored_pixels(FILE* fp, int k, uint16_t maxiter){
  int Position[5] = {0, 0.16 * maxiter, 0.42 * maxiter, 0.64 * maxiter, maxiter};

  if (k >= maxiter) {
        /* interior */
        const unsigned char black[] = {0, 0, 0};
        fwrite (black, 3, 1, fp);
      }
      else {
        /* Fit to colot palette */
        unsigned char color[3];
        int segment = 0;
        
        // Find which segment k falls into
        for (int i = 0; i < 4; i++) {
            if (k >= Position[i] && k < Position[i+1]) {
                segment = i;
                break;
            }
        }
        
        // Interpolate within the segment
        float t = (float)(k - Position[segment]) / (Position[segment+1] - Position[segment]);
        
        color[0] = Red[segment] + t * (Red[segment+1] - Red[segment]);
        color[1] = Green[segment] + t * (Green[segment+1] - Green[segment]);
        color[2] = Blue[segment] + t * (Blue[segment+1] - Blue[segment]);

        fwrite(color, 3, 1, fp);
      };
}


int main(int argc, char* argv[])
{
  /* Parse the command line arguments. */
  if (argc != 6) {
    printf("Usage:   %s <xmid> <ymid> <zoom> <maxiter> <out.ppm>\n", argv[0]);
    // printf("Example: %s 0.27085 0.27100 0.004640 0.004810 1000 1024 pic.ppm\n", argv[0]);
    printf("Example: %s 0.27085 0.27100 1.00000 1024 pic.ppm\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  /* The window in the plane. */
  const double xmid = atof(argv[1]);
  const double ymid = atof(argv[2]);
  const double zoom = atof(argv[3]);

  const double xmin = xmid - (zoom / 2);
  const double xmax = xmid + (zoom / 2);
  const double ymin = ymid - ((zoom / 2) * 0.75);
  const double ymax = ymid + ((zoom / 2) * 0.75);

  /* Maximum number of iterations, at most 65535. */
  const uint16_t maxiter = (unsigned short)atoi(argv[4]) < 256 ? 256 : (unsigned short)atoi(argv[4]);
  

  /* Image size, 640x480 */
  const int xres = 640;
  const int yres = 480;

  /* The output file name */
  const char* filename = argv[5];

  /* Open the file and write the header. */
  FILE * fp = fopen(filename,"wb");
  char *comment="# Mandelbrot set";/* comment should start with # */

  /*write ASCII header to the file*/
  fprintf(fp,
          "P6\n# Mandelbrot, xmin=%lf, xmax=%lf, ymin=%lf, ymax=%lf, maxiter=%d\n%d %d\n255\n",
          xmin, xmax, ymin, ymax, maxiter, xres, yres);

  /* Precompute pixel width and height. */
  double dx=(xmax-xmin)/xres;
  double dy=(ymax-ymin)/yres;

  double x, y; /* Coordinates of the current point in the complex plane. */
  double u, v; /* Coordinates of the iterated point. */
  int i,j; /* Pixel counters */
  int k; /* Iteration counter */
  
  // for (y = 0; y < yres; y++){
  //   for (x = 0; x < xres; x++){
  //     k = x/4;
  //     colored_pixels(fp, k, maxiter);
  //   }
  // }

  for (j = 0; j < yres; j++) {
    y = ymax - j * dy;
    for(i = 0; i < xres; i++) {
      double u = 0.0;
      double v= 0.0;
      double u2 = u * u;
      double v2 = v*v;
      x = xmin + i * dx;
      /* iterate the point */
      for (k = 1; k < maxiter && (u2 + v2 < 4.0); k++) {
            v = 2 * u * v + y;
            u = u2 - v2 + x;
            u2 = u * u;
            v2 = v * v;
      };
      /* compute  pixel color and write it to file */
      if (k >= maxiter) {
        /* interior */
        const unsigned char black[] = {0, 0, 0};
        fwrite (black, 3, 1, fp);
      }
      else {
        /* exterior */
        colored_pixels(fp, k, maxiter);
      };
    }
  }
  fclose(fp);
  return 0;
}
