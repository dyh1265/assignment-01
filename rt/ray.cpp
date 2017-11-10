#include <rt/ray.h>
#include <core/vector.h>
#include <core/point.h>

namespace rt {
    Ray::Ray(const Point& o, const Vector& d):o(o),d(d){}
    
    Point Ray::getPoint(float distance) const {
        return o + (distance * d);
    }
    
}

