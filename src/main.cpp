#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include "Point3D.h"
#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Helix.h"

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

    std::string line = "";

    int line_number = 0;
    std::getline(file, line);

    try {

        line_number = std::stoi(line);
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Unable to read number of lines: " << e.what() << std::endl; 
        return 1;
    }
    
    std::vector<std::shared_ptr<Curve>> curves;
    curves.reserve(line_number);

    for (int i = 0; i < line_number && std::getline(file, line); i++) {

        std::stringstream ss(line);

        char curve_type;
        std::string curve_name = "";
        size_t id = 0;
        Point3D center;
        double radius = 0.0;

        if (!(ss >> curve_type >> id >> std::quoted(curve_name) >> center.x >> 
                                                                   center.y >> 
                                                                   center.z >>
                                                                   radius)) {

            std::cerr << "Unable to parse line: " << "\"" << line << "\"" << "\n";
            return 1;
        }

        if (radius < 0) {
            std::cout << radius << "\n";
            std::cerr << "Radius can't be negative" << "\n";
            return 1;
        }

        if (curve_type == 'C') {
            
            curves.emplace_back(std::make_shared<Circle>(Circle(id, curve_name, center, radius)));

        }
        else if (curve_type == 'E') {

            double minor_radius = 0.0;
            ss >> minor_radius;

            curves.emplace_back(std::make_shared<Ellipse>(Ellipse(id, curve_name, center, radius, minor_radius)));
        }
        else if (curve_type == 'H') {

            double step = 0.0;
            ss >> step;

            curves.emplace_back(std::make_shared<Helix>(Helix(id, curve_name, center, radius, step)));

        }
    }

    for (auto& c: curves) {
        
        std::cout << "id: " << c->getId() << "  name: " << c->getName() << "  " << c->point(M_PI / 4).toString()  << "\n";
        

    }


    
    return 0;
}