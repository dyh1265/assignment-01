#ifndef CG1RAYTRACER_CAMERAS_FISHEYE_HEADER
#define CG1RAYTRACER_CAMERAS_FISHEYE_HEADER

#include <rt/cameras/camera.h>
#include <core/vector.h>
#include <core/point.h>


namespace rt {
    class FishEyeCamera : public Camera {
    public:
        Point center;
        Vector forward;
        Vector up;
        float psiMax;
        FishEyeCamera(const Point& center,
                      const Vector& forward,
                      const Vector& up,
                      float psiMax
                      );
        virtual Ray getPrimaryRay(float x, float y) const;
    private:
        Vector u;
        Vector v;
    };
}
#endif /* fisheye_h */
