#include "ColorWipe.h"

#include "manipulation/ColorManipulation.h"

#include "framework.h"

ColorWipe::ColorWipe(AbstractLedStrip* strip) :
    Animation(0x0105, strip, 2, 8),
    _index(0),
    fwd(false)
{
    w = random(256);
}

void ColorWipe::Init()
{
    const int p = random(2, 4);
    w += p * 16 + 1;
    fwd = random(2);
    _index = 0;
    if (!fwd)
        _index = _strip->numPixels() - 1;
}

void ColorWipe::Show()
{
    const uint32_t color = ColorFromColorWheel(w);

    if (fwd) {
        if (_index > int(_strip->numPixels())) { // Start new sequence with the new color
            Init();
            _complete = true;
            return;
        }
        _strip->setPixelColor(_index++, color);
    } else {
        if (_index < 0) { // Start new sequence with the new color
            Init();
            _complete = true;
            return;
        }
        _strip->setPixelColor(_index--, color);
    }
    _complete = false;
}