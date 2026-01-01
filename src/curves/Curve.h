#ifndef CURVE_H
#define CURVE_H

#include <sstream>
#include <string>
#include "../Point3D.h"

class Curve {

public:
    Curve(size_t id, const std::string& name, Point3D center): id(id), name(name), center(center) {};

    virtual ~Curve() = default;
private:

    size_t id;
    std::string name;
    
    Point3D center;

};


#endif