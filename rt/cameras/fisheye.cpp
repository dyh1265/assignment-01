#include <rt/cameras/fisheye.h>
#include <core/vector.h>
#include <core/point.h>
#include <rt/ray.h>
#include <core/assert.h>
#include <core/scalar.h>
namespace rt {
    FishEyeCamera::FishEyeCamera(const Point& center,
                  const Vector& forward,
                  const Vector& up,
                                 float psiMax):center(center), forward(forward), up(up), psiMax(psiMax){
        /* Orthogonalize vectors */
        imgY = cross(cross(up, forward),forward).normalize();;
        this->forward = forward.normalize();
        imgX = cross(this->forward, imgY);
    }

    Ray FishEyeCamera::getPrimaryRay(float x, float y) const  {
        // Kevin Suffern Ray Tracing from the ground up page 188
        float rsqr = x * x  + y * y;
        if (rsqr <= 1.0) {
            float rad = sqrt(rsqr);
            float psi = rad * psiMax * PI_ON_180;
            float sinPsi = sin(psi);
            float cosPsi = cos(psi);
            float sinAlpha = y / rad;
            float cosAlpha = x / rad;
            Vector d = sinPsi * cosAlpha * imgX + sinPsi * sinAlpha * imgY  - cosPsi * forward;
            d = d.normalize();
            Ray r(center, d);
            return r;
        } else {
            return Ray(center, Vector::rep(-9.f));
        }
    }
}
