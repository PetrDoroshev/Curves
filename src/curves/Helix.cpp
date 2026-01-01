#include "Helix.h"

Helix::Helix(size_t id, std::string name, Point3D center, double radius, double step): Curve(id, name, center), 
                                                                                    radius(radius),
                                                                                    step(step) {
        if (radius < 0) {
        
            throw std::invalid_argument("Radius can't be negative");
        }
};

Point3D Helix::point(double t) const {

    return Point3D(
        radius * std::cos(t) + center_.x,
        radius * std::sin(t) + center_.y,
        t
    );
};

Point3D Helix::derivative(double t) const {

    return Point3D(
        radius * (-1 * std::sin(t)),
        radius * std::cos(t),
        1 
    );
}   