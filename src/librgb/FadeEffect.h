#ifndef _RGB_PIXEL_EFFECT_H_
#define _RGB_PIXEL_EFFECT_H_

#include "RGBColor.h"
#include "Effect.h"

/**
* Linear fade from one color to another.
*/


class FadeEffect : public Effect {

public:
    FadeEffect(RGB from,
               RGB to,
               long periodMs) {

        restart(from, to, periodMs);
    };

    void restart(RGB from,
                 RGB to,
                 uint32_t periodMs) {
        stop();
        _startColor = from;
        _endColor = to;
        _startTime = millis();
        _duration = periodMs;
        set_color(_startColor);
        set_running(true);
    }


    void tick(long timestamp) {
        long _now = timestamp == 0 ? millis() : timestamp;

        if (_now - _startTime > _duration) {
            set_color(_endColor);
        } else {
            RGBColor _intermediate = _colorAt(_now);
            _lastUpdateAt = _now;
            set_color(_intermediate);
        }
    }

    RGBColor _colorAt(long timestamp) const {
        return _startColor.scaleTo(_endColor, progressAt(timestamp));
    }


    void stop() {
        _startColor = _endColor = RGB(0);
        _duration = 0;
        _lastUpdateAt = 0;
        set_running(false);
    }


};

#endif
