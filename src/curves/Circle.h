#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"

class Circle: public Curve {

public:

    ~Circle() = default;

    Circle(size_t id, std::string name, Point3D center, double radius): Curve(id, name, center), radius(radius) {};

private:

    double radius;

};

#endif