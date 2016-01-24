#ifndef _RGB_PIXEL_EFFECT_H_
#define _RGB_PIXEL_EFFECT_H_

#include <lber.h>
#include "RGBColor.h"

typedef enum RGBOverTimeMode_e {
    Normal = (1 << 0),
    Blinking = (1 << 1),
    Fading = (1 << 2),
} RGBOverTimeMode;

/**
* Class that wraps three separate LEDs and treats them as a single LED.
*/

class RGBPixel {

private:
    RGBColor _color = RGBColor();
    RGBColor _fadeFrom = 0, _fadeTo = 0;
    uint32_t _lastUpdateAt = 0, _fadeStartedAt = 0;
    uint32_t _periodMs = 0;
    RGBOverTimeMode _mode = Normal;
    bool _enabled = true;

public:
    RGBPixel() {
    };

    void tick() {
        _checkTiming();
    }

    void fade(RGBColor from,
              RGBColor to,
              long periodMs) {
        _reset();
        _mode = Fading;
        _fadeFrom = from;
        _fadeTo = to;
        _fadeStartedAt = millis();
        _periodMs = periodMs;
        _setColor(_fadeFrom);
    }

    void setColor(RGBColor color) {
        _reset();
        _setColor(color);
    }

    RGBColor getColor() {
        return _color;
    }

    void off() {
        _reset();
        _off();
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

private:
    void _reset() {
        _mode = Normal;
        _fadeFrom = _fadeTo = 0;

        _periodMs = 0;
        _lastUpdateAt = 0;
    }

    void _log() {
        printf("My color is now %#08x\n", _color.getValue());
    }

    void _setColor(RGBColor color) {
        _color = color;
    }

    void _setColor(rgb_color_t color) {
        _color = RGBColor(color);
    }

    void _off() {
        _color.r = 0;
        _color.g = 0;
        _color.b = 0;
    }

    void _checkTiming() {
        long _now = millis();
        switch (_mode) {
            case Normal:
                break;
            case Fading:
                _fading(_now);
                break;
            default:
                break;
        }
    }

    void _fading(long _now) {
        if (_now - _fadeStartedAt > _periodMs) {
            _mode = Normal;
            _setColor(_fadeTo);
        } else {
            if (_now - _lastUpdateAt > 20) {
                float _ratio = 1.0 * (1.0 * _now - 1.0 * _fadeStartedAt) / 1.0 * _periodMs;
                RGBColor _intermediate = _fadeFrom.scaleTo(_fadeTo, _ratio);
                _lastUpdateAt = _now;
                _setColor(_intermediate);
                _log();
            }
        }
    }
};

#endif
