#include<iostream>
#include<Magick++.h>
#include<cmath>
#include<string>
using namespace Magick;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

const std::string colors[] = {BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE};

const std::string ascii_map = ".`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

int how_bright(double r, double g, double b) {
    return (0.21 * r + 0.72 * g + 0.07 * b) / 256;
}

int calc_color(int r, int g, int b) {
    r /= 256 * 200;
    g /= 256 * 200;
    b /= 256 * 200;

    return r * 4 + g * 2 + b * 1;
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
    int color_idx = 8;
    for (int i = 0; i != rows; i++) {
        for (int j = 0; j != columns; j++) {
            brightness = how_bright(pixels->red, pixels->green, pixels->blue);
            color_idx = calc_color(pixels->red, pixels->green, pixels->blue);
            char_idx = (brightness * ascii_map.size()) / 256;
            std::cout << colors[color_idx] << ascii_map[char_idx] << ascii_map[char_idx] << RESET ;
            pixels++;
        }
        std::cout << '\n';
    }

    return 0;
}
