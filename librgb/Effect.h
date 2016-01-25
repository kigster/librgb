//
// Created by Konstantin Gredeskoul on 1/24/16.
//

#ifndef COLORFADER_RGBEFFECT_H
#define COLORFADER_RGBEFFECT_H

#include <cctype>

#include "RGBColor.h"
#include "arduino-emulation.h"

/**
 * Abstract Class Effect
 */

class Effect {

    bool     _enabled = true;
    bool     _running = false;


protected:
    RGB _color             = RGB();
    RGB _endColor          = RGB(),
        _startColor        = RGB();
    uint32_t _lastUpdateAt = 0;
    uint32_t _startTime    = 0;
    uint32_t _duration     = 0;
public:
    virtual void tick() {

    }

    virtual void stop() {
        off();
        _running = false;
    }

    void off() {
        _color.r = 0;
        _color.g = 0;
        _color.b = 0;
    }

    void toString(char *buffer,
                  int length) {
        char buf[9];
        sprintf(buf, "%#08x", _color.getValue());
        strncpy(buffer, (const char *) buf, length);
    }

    /**
     * Returns a float between 0 and 1 representing how far into the effect
     * we are in based on the start timing and duration, and the timestamp passed.
     */
    float progressAt(uint32_t timestamp) const {
        return timestamp > _startTime + _duration ?
               1.0f :
               (timestamp - _startTime) / (float)_duration;
    }

    float progress() const {
        return progressAt(millis());
    }

    //-----------------------------------------------------------------------------------------

    bool is_enabled() const {
        return _enabled;
    }

    void set_enabled(bool _enabled) {
        Effect::_enabled = _enabled;
    }

    bool is_running() const {
        return _running;
    }

    void set_running(bool _running) {
        Effect::_running = _running;
    }

    const RGBColor &get_color() const {
        return _color;
    }

    void set_color(const RGBColor &_color) {
        Effect::_color = _color;
    }

    uint32_t get_lastUpdateAt() const {
        return _lastUpdateAt;
    }

    void set_lastUpdateAt(uint32_t _lastUpdateAt) {
        Effect::_lastUpdateAt = _lastUpdateAt;
    }

    void toggleEnabled() {
        _enabled = !_enabled;
    }
    uint32_t get_duration() const {
        return _duration;
    }

    const RGBColor &get_endColor() const {
        return _endColor;
    }

    const RGBColor &get_startColor() const {
        return _startColor;
    }

    uint32_t get_startTime() const {
        return _startTime;
    }


};


#endif //COLORFADER_RGBEFFECT_H
