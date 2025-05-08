#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "utils.h"

//Reads the contents of the file at programDirectory/name and returns it as a string
std::string readFile(std::string name) {
    std::ifstream fileStream(name);

    if (!fileStream.is_open()) {
        std::cout << "File not found." << std::endl;
        return nullptr;
    }

    std::stringstream out;

    std::string line;
    while (getline(fileStream, line)) {
        out << line << "\n";
    }

    fileStream.close();

    return out.str();
}