#ifndef POINT3D_H
#define POINT3D_H

#include "sstream"

struct Point3D {

    double x = 0;
    double y = 0;
    double z = 0;

    Point3D(double x, double y, double z): x(x), y(y), z(z) {};
    Point3D() = default;

    std::string toString() const {

        std::stringstream ss;

        ss << "(" << x << ", " << y << ", " << z << ")";

        return ss.str();
    };

};

#endif