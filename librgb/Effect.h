//
// Created by Konstantin Gredeskoul on 1/24/16.
//

#ifndef COLORFADER_RGBEFFECT_H
#define COLORFADER_RGBEFFECT_H

#include <cctype>

#include "RGBColor.h"

typedef enum RGBOverTimeMode_e {
    Normal = (1 << 0),
    Blinking = (1 << 1),
    Fading = (1 << 2),
} RGBOverTimeMode;

/**
 * Abstract Class Effect
 */

class Effect {

    bool _enabled = true;

    void _setColor(rgb_color_t color) {
        _color = RGB(color);
    }

    void _off() {
        _color.r = 0;
        _color.g = 0;
        _color.b = 0;
    }

protected:
    RGB _color = RGB();
    uint32_t _lastUpdateAt = 0;
    RGBOverTimeMode _mode = Normal;

    void _setColor(RGB color) {
        _color = color;
    }

public:
    virtual void tick() {

    }

    virtual void stop() {

    }

    void setColor(RGB color) {
        _setColor(color);
    } RGB getColor() {
        return _color;
    }

    void off() {
        stop();
    }

    bool isEnabled() {
        return _enabled;
    }

    void toggleEnabled() {
        _enabled = !_enabled;
    }

    void enabled(bool enable) {
        _enabled = enable;
    }

    void enable() {
        _enabled = true;
    }

    void disable() {
        _enabled = false;
    }
};


#endif //COLORFADER_RGBEFFECT_H
