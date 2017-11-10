#include <rt/cameras/camera.h>
#include <core/vector.h>
#include <core/point.h>
#include <rt/cameras/orthographic.h>
#include <rt/ray.h>

namespace rt {
    OrthographicCamera::OrthographicCamera( const Point& center, const Vector& forward, const Vector& up, float scaleX, float scaleY ):center(center),up(up),scaleX(scaleX),scaleY(scaleY) {
        
        v = orthogonalize(up, forward).normalize();
        this->forward = forward.normalize();
        u = cross(this->forward, v);
    }
    
    Ray OrthographicCamera::getPrimaryRay( float x, float y ) const {
        Point o = center + u * x * scaleX - v * y * scaleY;
        Ray r(o, forward);
        return r;
    }
}

