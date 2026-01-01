#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"

class Circle: public Curve {

public:

    ~Circle() = default;

    Circle(size_t id, std::string name, Point3D center, double radius);

    Point3D point(double t) const override;
    Point3D derivative(double t) const override;

private:

    double radius;

};

#endif