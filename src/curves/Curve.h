#ifndef CURVE_H
#define CURVE_H

#include <string>
#include "../Point3D.h"

class Curve {

public:

    virtual ~Curve() = 0;
    Curve(size_t id, std::string name, Point3D center): id(id), name(name), center(center) {};

private:

    std::string name;
    size_t id;

    Point3D center;

};


#endif