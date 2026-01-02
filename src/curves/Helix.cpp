#include "Helix.h"

Helix::Helix(size_t id, const std::string& name, const Point3D& center, double radius, double step): Curve(id, name, center), 
                                                                                    radius_(radius),
                                                                                    step_(step) {
        if (radius <= 0) {
        
            throw std::invalid_argument("Radius can't be negative");
        }
};

Point3D Helix::point(double t) const {

    return Point3D(
        radius_ * std::cos(t) + center_.x,
        radius_ * std::sin(t) + center_.y,
        step_ * t
    );
};

Point3D Helix::derivative(double t) const {

    return Point3D(
        radius_ * (-1 * std::sin(t)),
        radius_ * std::cos(t),
        step_ 
    );
}   