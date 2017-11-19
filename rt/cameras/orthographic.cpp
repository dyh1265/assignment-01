#include <rt/cameras/camera.h>
#include <core/vector.h>
#include <core/point.h>
#include <rt/cameras/orthographic.h>
#include <rt/ray.h>

namespace rt {
    OrthographicCamera::OrthographicCamera( const Point& center, const Vector& forward, const Vector& up, float scaleX, float scaleY ):center(center),up(up),scaleX(scaleX/2.f),scaleY(scaleY/2.f) {
        
        imgY = cross(cross(up, forward),forward).normalize();
        this->forward = forward.normalize();
        imgX = cross(this->forward, imgY);
    }
    
    Ray OrthographicCamera::getPrimaryRay( float x, float y ) const {
        Point o = center + imgX * x * scaleX - imgY * y * scaleY;
        Ray r(o, forward);
        return r;
    }
}

