#ifndef HELIX_H
#define HELIX_H

#include "Curve.h"

class Helix: public Curve {

public:

    ~Helix() = default;

    Helix(size_t id, const std::string& name, const Point3D& center, double radius, double step);

    Point3D point(double t) const override;
    Point3D derivative(double t) const override;

private:

    double radius_;
    double step_;

};

#endif