/*
    MIT License

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

    (c) 2015-2016 Konstantin Gredeskoul
    Created on 1/1/2016

    A simple but perhaps not very efficient RGB color manipulation implemention
    allowing basic arithmetic with 3-valued colors, for example:

    RGB(0xFF0022) + RGB(0x101010) = RGB(0xFF2031) # so each
 */


#ifndef _RGB_COLOR_H_
#define _RGB_COLOR_H_

#include <inttypes.h>
#include <stdio.h>

typedef uint8_t color_t;
typedef uint32_t rgb_color_t;

#define RGB RGBColor

// 0 <= X,Y <= 255
// 0 <=   f <= 1.0
#define converge(   X, Y, f)   (color_t)(Y*f + (1 - f)*X)
#define MOD_minus(  X, Y)      (color_t)(X >= Y ? X - Y : 0)
#define MOD_plus(   X, Y)      (color_t)((((int)X + (int)Y)) > 255 ? 255 : ((int)X + (int)Y))

class RGBColor {
public:
    color_t r;
    color_t g;
    color_t b;

    color_t *components[3] = {&r, &g, &b};

    RGB() :
            r(0),
            g(0),
            b(0) {
    }

    RGB(color_t r,
        color_t g,
        color_t b) :
            r(r),
            g(g),
            b(b) {
    }

    RGB(rgb_color_t p) {
        r = (color_t) ((p >> 16) & 0xff);
        g = (color_t) ((p >> 8) & 0xff);
        b = (color_t) (p & 0xff);
    }

    uint8_t colorComponent(const uint8_t index) const {
        if (index < 3)
            return *components[index];
        return 0;
    }

    void setColorComponent(const uint8_t index,
                           uint8_t value) {
        if (index < 3)
            *components[index] = value;
    }

    void hex(char *buf) const {
        sprintf(buf, "%#08x", getValue());
    }

    rgb_color_t getValue() const {
        return (rgb_color_t) (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
    }

    RGB operator-(const RGB c) {
        return RGB(
                MOD_minus(r, c.r),
                MOD_minus(g, c.g),
                MOD_minus(b, c.b)
        );
    }

    RGB operator+(const RGB c) {
        return RGB(
                MOD_plus(r, c.r),
                MOD_plus(g, c.g),
                MOD_plus(b, c.b)
        );
    }

    void operator-=(const RGB c) {
        for (uint8_t i = 0; i < 3; i++) {
            setColorComponent(i, MOD_minus(colorComponent(i), c.colorComponent(i)));
        }
    }

    void operator+=(const RGB c) {
        for (uint8_t i = 0; i < 3; i++) {
            setColorComponent(i, MOD_plus(colorComponent(i), c.colorComponent(i)));
        }
    }

    RGB operator*(const float f) {
        color_t tR = (color_t) (r * f);
        color_t tG = (color_t) (g * f);
        color_t tB = (color_t) (b * f);
        return RGB(tR, tG, tB);
    }

    /* expecting 0 <= f <= 1 */
    RGB scaleTo(const RGB other,
                const float ratio)const {
        return RGB(
                converge(r, other.r, ratio),
                converge(r, other.g, ratio),
                converge(r, other.b, ratio)
        );
    }

    RGB operator/(const int f) {
        return RGB((color_t) (r / f),
                   (color_t) (g / f),
                   (color_t) (b / f));
    }
};

#endif
