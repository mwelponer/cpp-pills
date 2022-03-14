#include <iostream>
#include <cstdlib>
#include <cmath>

typedef struct {
    double r;       // a fraction between 0 and 1
    double g;       // a fraction between 0 and 1
    double b;       // a fraction between 0 and 1
} rgb;

typedef struct {
    double h;       // angle in degrees
    double s;       // a fraction between 0 and 1
    double v;       // a fraction between 0 and 1
} hsv;

static hsv   rgb2hsv(rgb in);
static rgb   hsv2rgb(hsv in);

hsv rgb2hsv(rgb in)
{
    std::cout << "rgb (" << in.r  << ", " << in.g << ", " << in.b << ")" << std::endl;
    
    hsv out;
    double min, max, delta;

    min = in.r < in.g ? in.r : in.g;
    min = min  < in.b ? min  : in.b;

    max = in.r > in.g ? in.r : in.g;
    max = max  > in.b ? max  : in.b;
    
    std::cout << "max: " << max << std::endl;
    std::cout << "min: " << min << std::endl;

    out.v = max;                                // v
    delta = max - min;
    if (delta < 0.00001)
    {
        out.s = 0;
        out.h = 0; // undefined, maybe nan?
        return out;
    }
    if( max > 0.0 ) { // NOTE: if Max is == 0, this divide would cause a crash
        out.s = (delta / max);                  // s
    } else {
        // if max is 0, then r = g = b = 0              
        // s = 0, h is undefined
        out.s = 0.0;
        out.h = NAN;                            // its now undefined
        return out;
    }
    if( in.r >= max )                           // > is bogus, just keeps compilor happy
        out.h = ( in.g - in.b ) / delta;        // between yellow & magenta
    else
    if( in.g >= max )
        out.h = 2.0 + ( in.b - in.r ) / delta;  // between cyan & yellow
    else
        out.h = 4.0 + ( in.r - in.g ) / delta;  // between magenta & cyan

    out.h *= 60.0;                              // degrees

    if( out.h < 0.0 )
        out.h += 360.0;

    return out;
}

//int main(int argc, char **argv)
//{
//    int r = 48;
//    int g = 145;
//    int b = 68; 
//    
//    rgb myrgb {(double)r/255, (double)g/255, (double)b/255};
//    std::cout << "myrgb (" << myrgb.r  << ", " << myrgb.g << ", " << myrgb.b << ")" << std::endl;
//    
//    hsv myhsv = rgb2hsv(myrgb);
//
//    std::cout   << "[RGB] (" << r << ", " << g << ", " << b << ")" << std::endl;
//    std::cout   << "[HSV] (" << myhsv.h << ", " << myhsv.s << ", " << myhsv.v << ")" << std::endl;
//}