#include <iostream>
#include <fstream>
#include <sstream>
#include "Point3D.h"
#include "curves/Curve.h"
#include "curves/Circle.h"

int main(int argc, char* argv[]) {

    if (argc < 1) {
    
        std::cout << "Too few arguments" << std::endl;
        return 0;
    }

    std::string path = "../examples/curves_to_check.txt";
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << path << std::endl;
        return 1;
    }


    int line_number = 0;

    if (!(file >> line_number)) {
        std::cerr << "Unable to read number of lines" << std::endl;
    }

    std::cout << line_number << std::endl;

    std::string line = "";

    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::cout << line << "\n";

        std::string curve_type = "";
        std::string curve_name = "";
        size_t id = 0;
        double x, y, z;
        Point3D center;

        ss >> curve_type;
        std::cout << curve_type << "\n";

        ss >> id;
        std::cout << id << "\n";

        ss >> curve_name;
        std::cout << curve_name << "\n";

        ss >> x;
        std::cout << x << "\n";

        ss >> y;
        std::cout << y << "\n";

        ss >> z;
        std::cout << z << "\n";
    }


    return 0;
}