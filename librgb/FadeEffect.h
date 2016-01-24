#ifndef _RGB_PIXEL_EFFECT_H_
#define _RGB_PIXEL_EFFECT_H_

#include "RGBColor.h"
#include "Effect.h"

/**
* Linear fade from one color to another.
*/


class FadeEffect : public Effect {

private:
    RGB      _startColor,
             _endColor;
    uint32_t _periodMs;
    uint32_t _fadeStartedAt = 0;

public:
    FadeEffect(RGB from,
               RGB to,
               long periodMs) {

        stop();
        _startColor    = from;
        _endColor      = to;
        _fadeStartedAt = millis();
        _periodMs      = periodMs;
        _setColor(_startColor);

    };

    void tick() {
        long _now = millis();
        if (_now - _fadeStartedAt > _periodMs) {
            _mode = Normal;
            _setColor(_endColor);
        } else {
            if (_now - _lastUpdateAt > 20) {
                float _ratio        = 1.0 * (1.0 * _now - 1.0 * _fadeStartedAt) / 1.0 * _periodMs;
                RGB   _intermediate = _startColor.scaleTo(_endColor, _ratio);
                _lastUpdateAt = _now;
                _setColor(_intermediate);
                _log();
            }
        }
    }


    void stop() {
        _mode         = Normal;
        _startColor   = _endColor = 0;
        _periodMs     = 0;
        _lastUpdateAt = 0;
    }

private:


    void _log() {
        printf("My color is now %#08x\n", _color.getValue());
    }

};

#endif
