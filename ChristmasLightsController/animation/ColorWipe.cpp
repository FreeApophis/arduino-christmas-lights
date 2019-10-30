#include "ColorWipe.h"

#include "../Helper.h"
#include "../framework.h"

ColorWipe::ColorWipe(AbstractLedStrip* strip, byte duration) :
    Animation(strip, duration, 2, 8),
    index(0),
    fwd(false)
{
    w = random(256);
}

void ColorWipe::Init()
{
    const int p = random(2, 4);
    w += p * 16 + 1;
    fwd = random(2);
    index = 0;
    if (!fwd)
        index = _strip->numPixels() - 1;
}

void ColorWipe::Show()
{
    const uint32_t color = ColorFromColorWheel(w);

    if (fwd) {
        if (index > int(_strip->numPixels())) { // Start new sequence with the new color
            Init();
            _complete = true;
            return;
        }
        _strip->setPixelColor(index++, color);
    } else {
        if (index < 0) { // Start new sequence with the new color
            Init();
            _complete = true;
            return;
        }
        _strip->setPixelColor(index--, color);
    }
    _complete = false;
}