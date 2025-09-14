#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {

    // Image

    int image_width = 400;
    int image_height = 400;
    int square_size = 50;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            int ix = i / square_size;
            int jy = j / square_size;

            bool is_white = ((ix + jy) % 2 == 0);

            color pixel_color = is_white ? color(1,1,1) : color(0,0,0);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                 \n";
}