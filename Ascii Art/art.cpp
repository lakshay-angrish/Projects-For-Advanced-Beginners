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

    std::cout << image.baseColumns() << '\t' << image.baseRows() << '\n';

    return 0;
}