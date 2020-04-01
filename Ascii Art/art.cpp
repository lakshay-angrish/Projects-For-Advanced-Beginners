#include<iostream>
#include<Magick++.h>
#include<cmath>
#include<string>
using namespace Magick;

const std::string ascii = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

int how_bright(double r, double g, double b) {
    return (0.21 * r + 0.72 * g + 0.07 * b) / 256;
}

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

    int brightness[columns][rows];
    Magick::PixelPacket* pixel_array[columns][rows];
    for (int i = 0; i != columns; i++) {
        for (int j = 0; j != rows; j++) {
            brightness[i][j] = how_bright(pixels->red, pixels->green, pixels->blue);
            // std::cout << brightness[i][j] << '\n';
            pixel_array[i][j] = pixels++;
        }
    }

    return 0;
}
