#include <core/point.h>
#include <core/vector.h>
#include <cmath>
#include <core/scalar.h>
namespace rt {
    
    Vector Point::operator-( const Point& b ) const
    {
        Vector c;
        c.x = x - b.x;
        c.y = y - b.y;
        c.z = z - b.z;
        return c;
    }
    Vector Point::operator+( const Point& b ) const
    {
        Vector c;
        c.x = x + b.x;
        c.y = y + b.y;
        c.z = z + b.z;
        return c;
    }
    bool Point::operator==(const Point& b) const
    {
        if (x != b.x ) { return 0; }
        if (y != b.y ) { return 0; }
        if (z != b.z ) { return 0; }
        return 1;
    }
    bool Point::operator!=(const Point& b) const
    {
        if (x == b.x ) { return 0; }
        if (y == b.y ) { return 0; }
        if (z == b.z ) { return 0; }
        return 1;
    }
    
    Point operator*(float scalar, const Point& b) {
        return Point(scalar * b.x, scalar * b.y, scalar * b.z);
    }
    
    Point operator*(const Point& a, float scalar) {
        return Point(scalar * a.x, scalar * a.y, scalar * a.z);
    }
    
    Point min(const Point& a, const Point& b) {
        return Point(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
    }
    
    Point max(const Point& a, const Point& b){
        return Point(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
    }
    
    
}
