#ifndef _RGB_COLOR_H_
#define _RGB_COLOR_H_

#include "arduino-emulation.h"

typedef uint8_t color_t;
typedef uint32_t rgb_color_t;

// 0 <= X,Y <= 255
// 0 <=   f <= 1.0
#define converge(X, Y, f)   (Y*f + (1 - f)*X)
#define MOD_minus(X, Y)     (X >= Y ? X - Y : 0)
#define MOD_plus(X, Y)      ((((int)X + (int)Y)) > 255 ? 255 : ((int)X + (int)Y))

class RGBColor {
public:

    color_t r;
    color_t g;
    color_t b;

    color_t *colors[3] = {&r, &g, &b};

    RGBColor() :
            r(0),
            g(0),
            b(0) {
    }

    RGBColor(color_t r,
             color_t g,
             color_t b) :
            r(r),
            g(g),
            b(b) {
    }

    RGBColor(rgb_color_t p) {
        r = (p >> 16) & 0xff;
        g = (p >> 8) & 0xff;
        b = p & 0xff;
    }

    uint8_t getComponentAt(const uint8_t index) const {
        if (index < 3)
            return *colors[index];
        return 0;
    }

    void setComponentAt(const uint8_t index,
                   uint8_t value) {
        if (index < 3)
            *colors[index] = value;
    }

    void getHex(char *buf) {
        sprintf(buf, "%#08x", getValue());
    }

    rgb_color_t getValue() {
        return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
    }

    RGBColor operator-(const RGBColor c) {
        return RGBColor(
                MOD_minus(r, c.r),
                MOD_minus(g, c.g),
                MOD_minus(b, c.b)
        );
    }

    RGBColor operator+(const RGBColor c) {
        return RGBColor(
                MOD_plus(r, c.r),
                MOD_plus(g, c.g),
                MOD_plus(b, c.b)
        );
    }

    void operator-=(const RGBColor c) {
        for (uint8_t i = 0; i < 3; i++) {
            setComponentAt(i, MOD_minus(getComponentAt(i), c.getComponentAt(i)));
        }
    }

    void operator+=(const RGBColor c) {
        for (uint8_t i = 0; i < 3; i++) {
            setComponentAt(i, MOD_plus(getComponentAt(i), c.getComponentAt(i)));
        }
    }

    RGBColor operator*(const float f) {
        color_t tR = r * f;
        color_t tG = g * f;
        color_t tB = b * f;
        return RGBColor(tR, tG, tB);
    }

    /* expecting 0 <= f <= 1 */
    RGBColor scaleTo(const RGBColor other,
                     const float ratio) {
        return RGBColor(
                converge(r, other.r, ratio),
                converge(r, other.g, ratio),
                converge(r, other.b, ratio)
        );
    }

    RGBColor operator/(const int f) {
        return RGBColor(r / f, g / f, b / f);
    }
};

#endif
