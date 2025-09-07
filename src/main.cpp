#include <iostream>

int main() {

    // Image

    int image_width = 400;
    int image_height = 400;
    int square_size = 50;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            int ix = i / square_size;
            int jy = j / square_size;

            bool is_white = ((ix + jy) % 2 == 0);

            int r, g, b;
            if (is_white) {
                r = g = b = 255;  // branco
            } else {
                r = g = b = 0;    // preto
            }

            std::cout << r << " " << g << " " << b << "\n";
        }
    }
}