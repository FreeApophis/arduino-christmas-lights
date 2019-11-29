#include "ColorWalk.h"

#include "manipulation/ColorManipulation.h"

#include "framework.h"

ColorWalk::ColorWalk(AbstractLedStrip* strip) :
    Animation(0x0103, strip, 4, 12),
    _index(0),
    _period(0),
    fwd(false),
    w(0)
{
}

void ColorWalk::Init()
{
    _index = 0;
    w = random(256);
    fwd = random(2);
    _period = random(10, 30);
}

void ColorWalk::Show()
{
    int n = _strip->numPixels();
    if (fwd) {
        if (_index > n) {
            _index -= _period;
            _strip->setPixelColor(n - 1, 0);
        }
        uint32_t color = ColorFromColorWheel(w--);
        for (int i = _index; i > 0; i -= _period) {
            if (i > 0)
                _strip->setPixelColor(i - 1, 0);
            _strip->setPixelColor(i, color);
        }
        ++_index;
    } else {
        if (_index < 0) {
            _index += _period;
            _strip->setPixelColor(0, 0);
        }
        uint32_t color = ColorFromColorWheel(w++);
        for (int i = _index; i < n; i += _period) {
            if (i < int(_strip->numPixels() - 1))
                _strip->setPixelColor(i + 1, 0);
            _strip->setPixelColor(i, color);
        }
        --_index;
    }
}