#include <rt/cameras/environment.h>
#include <core/vector.h>
#include <core/point.h>
#include <rt/ray.h>
#include <core/assert.h>
#include <core/scalar.h>
namespace rt{
    
   EnvironmentCamera::EnvironmentCamera(const Point& center,
                                 const Vector& forward,
                                 const Vector& up,
                                 float psiMax, float lambdaMax):center(center), forward(forward), up(up), psiMax(psiMax), lambdaMax(lambdaMax){
        /* Orthogonalize vectors */
        imgY = orthogonalize(up, forward).normalize();
        this->forward = forward.normalize();
        imgX = cross(this->forward, imgY);
   }
    
    Ray EnvironmentCamera::getPrimaryRay(float x, float y) const{
        // compute angles lambda and phi in radians
        float lambda = x * lambdaMax * PI_ON_180;
        float psi = y * psiMax * PI_ON_180;
        // compute the spherical azimuth and polar angles
        float phi = pi - lambda;
        float theta = 0.5 * pi - psi;
        float sinPhi = sin(phi);
        float cosPhi = cos(phi);
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);
        Vector dir = sinTheta * sinPhi * imgX + cosTheta * imgY + sinTheta * cosPhi * forward;
        return Ray(center, dir);
    }
}


