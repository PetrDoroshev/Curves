#include "Ellipse.h"


Ellipse::Ellipse(size_t id, const std::string& name, const Point3D& center, double major_radius, double minor_radius): Curve(id, name, center), 
                                                                                                    major_radius_(major_radius),
                                                                                                    minor_radius_(minor_radius) {

    if (major_radius <= 0 || minor_radius <= 0) {
        
        throw std::invalid_argument("Radius can't be negative");
    }
};


Point3D Ellipse::point(double t) const {

    return Point3D(
        major_radius_ * std::cos(t) + center_.x,
        minor_radius_ * std::sin(t) + center_.y,
        center_.z
    );
};

Point3D Ellipse::derivative(double t) const {

    return Point3D(
        major_radius_ * (-1 * std::sin(t)),
        minor_radius_ * std::cos(t),
        0 
    );
}                                                                                                  