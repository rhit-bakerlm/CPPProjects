#include <iostream>
#include <fstream>
#include <string.h>

int main() {
    std::ofstream file("out.ppm");

    int width, height;
    width = 100;
    height = 100;

    int maxColorVal = 255;

    file << "P3\n" << width << " " << height << "\n" << maxColorVal << "\n";

    for (int i = 0; i < height; i++) {
        std::string row;

        for (int j = 0; j < width; j++) {
            row += std::to_string(0) + " " + std::to_string(255) + " " + std::to_string(255) + " ";
        }

        file << row << "\n";
    }

    file.close();
}