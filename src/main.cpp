#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
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

    std::string path = "../examples/additional_curves_1.txt";
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

        if (radius <= 0) {
            std::cerr << "Radius can't be negative: id: " << id << "\n";
            continue;
        }

        if (curve_type == 'C') {
            
            curves.emplace_back(std::make_shared<Circle>(id, curve_name, center, radius));

        }
        else if (curve_type == 'E') {

            double minor_radius = 0.0;
            
            if (!(ss >> minor_radius)) {

                std::cerr << "Unable to parse line: " << "\"" << line << "\"" << "\n";
                return 1;
            }

            if (minor_radius <= 0) {
                
                std::cerr << "Radius can't be negative: id: " << id << "\n";
                continue;
            }

            curves.emplace_back(std::make_shared<Ellipse>(id, curve_name, center, radius, minor_radius));
        }
        else if (curve_type == 'H') {

            double step = 0.0;

            if (!(ss >> step)) {
                
                std::cerr << "Unable to parse line: " << "\"" << line << "\"" << "\n";
                return 1;
            }

            curves.emplace_back(std::make_shared<Helix>(id, curve_name, center, radius, step));

        }
    }

    std::vector<const Circle*> circles; 

    std::cout << std::left
              << std::setw(15)  << "ID"
              << std::setw(20) << "Name"
              << std::setw(30) << "Point (t=pi/4)"
              << std::setw(30) << "Derivative (t=pi/4)"
              << '\n';

    std::cout << std::string(88, '-') << '\n';

    for (auto& c: curves) {
        
        std::cout << std::left 
                  << std::setw(15) << c->getId()
                  << std::setw(20) << c->getName()
                  << std::setw(30) << c->point(M_PI / 4).toString()
                  << std::setw(30) << c->derivative(M_PI / 4).toString()
                  << '\n';

    
        if (auto circle = dynamic_cast<const Circle*>(c.get())) {
            circles.push_back(circle);
        }
    }


    //Sort circles by their radii in ascending order
    std::sort(circles.begin(), circles.end(), [](const Circle* c1, const Circle* c2) {

        return c1->getRadius() < c2->getRadius();

    });

    //Сalculate the sum of the radii
    auto radius_sum = std::accumulate(circles.begin(), circles.end(), 0.0, [](double sum, const Circle* c) {
        return sum + c->getRadius();
    });
    

    std::cout << "\nCircles: \n";
    for (auto& c: circles) {

        std::cout << "id: " << c->getId() << ", " << "radius: " <<  c->getRadius() << "\n";
    }

    std::cout << "\nSum of radii: " << radius_sum << "\n";
    
    return 0;
}

