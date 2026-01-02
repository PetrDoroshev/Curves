#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"

class Circle: public Curve {

public:

    ~Circle() = default;

    Circle(size_t id, const std::string& name, const Point3D& center, double radius);

    Point3D point(double t) const override;
    Point3D derivative(double t) const override;

    double getRadius() const;

private:

    double radius_;

};

#endif