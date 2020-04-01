#include<iostream>
#include<Magick++.h>
using namespace Magick;

int main(int argc, char** argv) {
    InitializeMagick(*argv);
    Image image;

    try {
        if (argc < 2) {
            std::cout << "USAGE: ./art <path-to-image>\n";
            return 0;
        }
        image.read(argv[1]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    std::cout << "Image Size = " << image.columns() << " X " << image.rows() << '\n';

    Magick::PixelPacket *pixels = image.getPixels(0, 0, image.columns(), image.rows());
    const int columns = image.columns();
    const int rows = image.rows();

    Magick::PixelPacket* pixel_array[columns][rows];
    for (int i = 0; i != columns; i++) {
        for (int j = 0; j != rows; j++) {
            pixel_array[i][j] = pixels++;
        }
    }

    return 0;
}
