//
//  vector.cpp
//  CG1-raytracer
//
//  Created by Андрей Сиразитдинов on 09/11/2017.
//
#include <core/point.h>
#include <core/vector.h>
#include <core/scalar.h>
#include <cmath>

namespace rt {
    
    Vector Vector::operator+(const Vector& b) const
    { return Vector(x + b.x, y + b.y, z + b.z);}
    
    Vector Vector::operator-(const Vector& b) const
    { return Vector(x - b.x, y - b.y, z - b.z);}
    
    Vector Vector::normalize() const
    {return *this / this->length();}
    
    Vector Vector::operator-() const
    {return Vector(0.f - x, 0.f - y, 0.f - z);}
    
    float Vector::lensqr() const
    { return sqr(x) + sqr(y) + sqr(z);}
    
    float Vector::length() const
    { return sqrt(sqr(x) + sqr(y) + sqr(z));}
    
    
    bool Vector::operator!=(const Vector& b) const
    {
        if ( x == b.x ) { return 0; }
        if ( y == b.y ) { return 0; }
        if ( z == b.z ) { return 0; }
        return 1;
    }
    
    bool Vector::operator==(const Vector& b) const
    {
        if ( x != b.x ) { return 0; }
        if ( y != b.y ) { return 0; }
        if ( z != b.z ) { return 0; }
        return 1;
    }
    
    Vector operator*(float scalar, const Vector& b)
    {return Vector(scalar * b.x, scalar * b.y, scalar * b.z);}
    
    Vector operator*(const Vector& a, float scalar)
    {return Vector(scalar * a.x, scalar * a.y, scalar * a.z);}
    
    Vector operator/(const Vector& a, float scalar)
    {return Vector(a.x / scalar, a.y / scalar, a.z / scalar);}
    
    Vector cross(const Vector& a, const Vector& b)
    {return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);}
    
    float dot(const Vector& a, const Vector& b)
    {return (a.x * b.x + a.y * b.y + a.z * b.z);}
    
    Vector min(const Vector& a, const Vector& b)
    {return Vector(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));}
    
    Vector max(const Vector& a, const Vector& b)
    {return Vector(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));}
    
    Point operator+(const Point& a, const Vector& b)
    { return Point(a.x + b.x, a.y + b.y, a.z + b.z);}
    
    Point operator+(const Vector& a, const Point& b)
    { return Point(a.x + b.x, a.y + b.y, a.z + b.z);}
    
    Point operator-(const Point& a, const Vector& b)
    { return Point(a.x - b.x, a.y - b.y, a.z - b.z);}
    
    // Gram-Schmidt
    //https://www.math.hmc.edu/calculus/tutorials/gramschmidt/
    Vector orthogonalize( const Vector&a, const Vector& b ) {
        Vector c=a;
        if (dot(a, b) != 0)
        c = a - (dot(a, b) / dot(b,b)) * b;
        return c;
    }
    
}

