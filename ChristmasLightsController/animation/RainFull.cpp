#include "RainFull.h"

#include "manipulation/ColorManipulation.h"

RainFull::RainFull(AbstractLedStrip* strip) :
    Animation(0x0110, strip, 6, 24),
    _brightnessManipulation(strip),
    _index(0),
    _isReady(false)
{
}

void RainFull::Init()
{
    _index = random(256);
    _isReady = false;
}

void RainFull::Show()
{
    if (!_isReady) {
        _isReady = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            _brightnessManipulation.setColor(ColorFromColorWheel(_index));
            if (!_brightnessManipulation.change(i, 1))
                _isReady = false;
        }
        return;
    }

    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _strip->setPixelColor(i, ColorFromColorWheel(_index));
    }
    ++_index; // index is from 0 to 255
}
