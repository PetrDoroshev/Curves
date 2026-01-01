#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"

class Circle: public Curve {

public:

    ~Circle() = default;

    Circle(size_t id, std::string name, Point3D center, double radius): Curve(id, name, center), radius(radius) {

        if (radius < 0) {
            throw std::invalid_argument("Radius can't be negative");
        }

    };

private:

    double radius;

};

#endif