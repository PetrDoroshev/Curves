#ifndef ELLIIPSE_H
#define ELLIPSE_H

#include "Curve.h"

class Ellipse: public Curve {

public:

    ~Ellipse() = default;

    Ellipse(size_t id, std::string name, Point3D center, double major_radius, double minor_radius): Curve(id, name, center), 
                                                                                                    major_radius(major_radius),
                                                                                                    minor_radius(minor_radius) {};

private:

    double major_radius;
    double minor_radius;

};

#endif