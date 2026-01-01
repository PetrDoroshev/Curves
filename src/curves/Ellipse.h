#ifndef ELLIIPSE_H
#define ELLIPSE_H

#include "Curve.h"

class Ellipse: public Curve {

public:

    ~Ellipse() = default;

    Ellipse(size_t id, std::string name, Point3D center, double major_radius, double minor_radius);

    Point3D point(double t) const override;
    Point3D derivative(double t) const override;

private:

    double major_radius;
    double minor_radius;

};

#endif