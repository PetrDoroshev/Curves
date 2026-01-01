#include "Circle.h"

Circle::Circle(size_t id, std::string name, Point3D center, double radius): Curve(id, name, center), radius(radius) {

        if (radius < 0) {
            throw std::invalid_argument("Radius can't be negative");
        }

};

Point3D Circle::point(double t) const {

    return Point3D(
        radius * std::cos(t) + center_.x,
        radius * std::sin(t) + center_.y,
        center_.z
    );
};

Point3D Circle::derivative(double t) const {

    return Point3D(
        radius * (-1 * std::sin(t)),
        radius * std::cos(t),
        0 
    );
}