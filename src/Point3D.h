#ifndef POINT3D_H
#define POINT3D_H

struct Point3D {

    double x = 0;
    double y = 0;
    double z = 0;

    Point3D(double x, double y, double z): x(x), y(y), z(z) {};
    Point3D() = default;

};

#endif