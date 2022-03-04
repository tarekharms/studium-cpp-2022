
extern "C" {
#include "libattopng.h"
}

#define W 250
#define H 200

#define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))
#define RGB(r, g, b) RGBA(r, g, b, 0xff)


int main(int argc, char *argv[]) {
  int x, y;
  libattopng_t *png = libattopng_new(W, H, PNG_RGB);
  
  for (y = 0; y < H; y++) {
    for (x = 0; x < W; x++) {
      libattopng_set_pixel(png, x, y, RGB(x & 128, y & 255, 128));
    }
  }
  libattopng_save(png, "test_cpp_rgb.png");
  libattopng_destroy(png);
  

  return 0;
}



