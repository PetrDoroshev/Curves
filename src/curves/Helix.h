#ifndef HELIX_H
#define HELIX_H

#include "Curve.h"

class Helix: public Curve {

public:

    ~Helix() = default;

    Helix(size_t id, std::string name, Point3D center, double radius, double step): Curve(id, name, center), 
                                                                                    radius(radius),
                                                                                    step(step) {
        if (radius < 0) {
        
            throw std::invalid_argument("Radius can't be negative");
        }
    };

private:

    double radius;
    double step;

};

#endif