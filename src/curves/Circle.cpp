#include "Circle.h"

Circle::Circle(size_t id, const std::string& name, const Point3D& center, double radius): Curve(id, name, center), radius_(radius) {

        if (radius <= 0) {
            throw std::invalid_argument("Radius can't be negative");
        }

};

Point3D Circle::point(double t) const {

    return Point3D(
        radius_ * std::cos(t) + center_.x,
        radius_ * std::sin(t) + center_.y,
        center_.z
    );
};

Point3D Circle::derivative(double t) const {

    return Point3D(
        radius_ * (-1 * std::sin(t)),
        radius_ * std::cos(t),
        0 
    );
};

double Circle::getRadius() const {
    return radius_;
}