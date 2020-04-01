#include<iostream>
#include<Magick++.h>
#include<cmath>
#include<string>
using namespace Magick;

const std::string ascii_map = ".`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

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

    image.resize("500x170");
    std::cout << "Image Size = " << image.columns() << " X " << image.rows() << '\n';

    Magick::PixelPacket *pixels = image.getPixels(0, 0, image.columns(), image.rows());
    const int columns = image.columns();
    const int rows = image.rows();

    int brightness;
    int char_idx = 0;
    for (int i = 0; i != rows; i++) {
        for (int j = 0; j != columns; j++) {
            brightness = how_bright(pixels->red, pixels->green, pixels->blue);
            pixels++;
            char_idx = (brightness * ascii_map.size()) / 256;
            std::cout << ascii_map[char_idx] << ascii_map[char_idx] ;
        }
        std::cout << '\n';
    }

    return 0;
}
