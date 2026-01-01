#ifndef CURVE_H
#define CURVE_H

#include <sstream>
#include <string>
#include <cmath>
#include "../Point3D.h"

class Curve {

public:
    Curve(size_t id, const std::string& name, const Point3D& center): id_(id), name_(name), center_(center) {};

    virtual ~Curve() = default;

    virtual Point3D point(double t) const = 0;
    virtual Point3D derivative(double t) const = 0;

    size_t getId() const { return id_; };
    std::string getName() const { return name_; };
 
protected:

    size_t id_;
    std::string name_;

    Point3D center_;

};


#endif