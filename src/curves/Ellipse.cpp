#include "Ellipse.h"


Ellipse::Ellipse(size_t id, std::string name, Point3D center, double major_radius, double minor_radius): Curve(id, name, center), 
                                                                                                    major_radius(major_radius),
                                                                                                    minor_radius(minor_radius) {};


Point3D Ellipse::point(double t) const {

    return Point3D(
        major_radius * std::cos(t) + center_.x,
        minor_radius * std::sin(t) + center_.y,
        center_.z
    );
};

Point3D Ellipse::derivative(double t) const {

    return Point3D(
        major_radius * (-1 * std::sin(t)),
        minor_radius * std::cos(t),
        0 
    );
}                                                                                                  