//
//  environment.h
//  CG1-raytracer
//
//  Created by Андрей Сиразитдинов on 10/11/2017.
//

#ifndef environment_h
#define environment_h

#include <rt/cameras/camera.h>
#include <core/vector.h>
#include <core/point.h>


namespace rt {
    class EnvironmentCamera : public Camera {
    public:
        Point center;
        Vector forward;
        Vector up;
        float psiMax;
        float lambdaMax;
        EnvironmentCamera(const Point& center,
                      const Vector& forward,
                      const Vector& up,
                      float psiMax,
                      float lambdaMax
                      );
        virtual Ray getPrimaryRay(float x, float y) const;
    private:
        Vector imgX;
        Vector imgY;
    };
}
#endif /* environment_h */
