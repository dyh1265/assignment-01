//
//  perspective.cpp
//  CG1-raytracer
#include <rt/cameras/camera.h>
#include <core/vector.h>
#include <core/point.h>
#include <rt/cameras/perspective.h>
#include <rt/ray.h>
#include <core/scalar.h>
namespace rt {
    PerspectiveCamera::PerspectiveCamera( const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizontalOpeningAngle):center(center),up(up),verticalOpeningAngle(verticalOpeningAngle),horizontalOpeningAngle(horizontalOpeningAngle) {
        
        tanTheta = tan(verticalOpeningAngle / 2.0f);
        tanPhi = tan(horizontalOpeningAngle / 2.0f);
        aspectRatio = tanTheta / tanPhi;
        
        /* Orthogonalize vectors */
        this->forward = forward.normalize();
        imgX = cross(this->forward,up);
        imgY = cross(this->forward, imgX).normalize();
    }
    
    /*  Find pixel center and compute ray through it. */
    Ray PerspectiveCamera::getPrimaryRay( float x, float y ) const {
        Vector d = forward + imgX * tanTheta * aspectRatio * x + imgY * tanTheta * y;
        d = d.normalize();
        Ray r(center, d);
        return r;
    }
}
