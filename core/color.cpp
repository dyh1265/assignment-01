#include <core/color.h>
#include <cmath>
#include <core/scalar.h>
namespace rt {
    
    RGBColor RGBColor::operator+(const RGBColor& c) const {
        return RGBColor(r + c.r, g + c.g, b + c.b);
        
    }
    
    RGBColor RGBColor::operator-(const RGBColor& c) const {
        return RGBColor(r - c.r, g - c.g, b - c.b);
    }
    
    RGBColor RGBColor::operator*(const RGBColor& c) const {
        return RGBColor(r * c.r, g * c.g, b * c.b);
    }
    
    bool RGBColor::operator==(const RGBColor& b) const {
        if ( r != b.r ) { return 0; }
        if ( g != b.g ) { return 0; }
        if ( this->b != b.b ) { return 0; }
        return 1;
    }
    
    bool RGBColor::operator!=(const RGBColor& b) const {
        if ( r == b.r ) { return 0; }
        if ( g == b.g ) { return 0; }
        if ( this->b == b.b ) { return 0; }
        return 1;
    }
    
    RGBColor RGBColor::clamp() const {
        RGBColor o;
        o.r = r > 1.0f ? 1.0f : (r < 0.0f ? 0.0f : r);
        o.g = g > 1.0f ? 1.0f : (g < 0.0f ? 0.0f : g);
        o.b = b > 1.0f ? 1.0f : (b < 0.0f ? 0.0f : b);
        return o;
    }
    
    RGBColor operator*(float scalar, const RGBColor& b) {
        return RGBColor(scalar * b.r, scalar * b.g, scalar * b.b);
    }
    
    RGBColor operator*(const RGBColor& a, float scalar) {
        return RGBColor(scalar * a.r, scalar * a.g, scalar * a.b);
    }
    
    RGBColor operator/(const RGBColor& a, float scalar) {
        return RGBColor(a.r/scalar, a.g / scalar , a.b / scalar);
    }
    
    
}
