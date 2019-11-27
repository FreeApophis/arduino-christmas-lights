#include "ColorWalk.h"

#include "Helper.h"
#include "framework.h"

ColorWalk::ColorWalk(AbstractLedStrip* strip, byte duration) :
    Animation(strip, duration, 4, 12),
    index(0),
    period(0),
    fwd(false),
    w(0)
{
}

void ColorWalk::Init()
{
    index = 0;
    w = random(256);
    fwd = random(2);
    period = random(10, 30);
}

void ColorWalk::Show()
{
    int n = _strip->numPixels();
    if (fwd) {
        if (index > n) {
            index -= period;
            _strip->setPixelColor(n - 1, 0);
        }
        uint32_t color = ColorFromColorWheel(w--);
        for (int i = index; i > 0; i -= period) {
            if (i > 0)
                _strip->setPixelColor(i - 1, 0);
            _strip->setPixelColor(i, color);
        }
        ++index;
    } else {
        if (index < 0) {
            index += period;
            _strip->setPixelColor(0, 0);
        }
        uint32_t color = ColorFromColorWheel(w++);
        for (int i = index; i < n; i += period) {
            if (i < int(_strip->numPixels() - 1))
                _strip->setPixelColor(i + 1, 0);
            _strip->setPixelColor(i, color);
        }
        --index;
    }
}