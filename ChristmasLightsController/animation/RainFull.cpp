#include "RainFull.h"

#include "manipulation/ColorManipulation.h"

RainFull::RainFull(AbstractLedStrip* strip) :
    Animation(0x0110, strip, 6, 24),
    _brightnessManipulation(strip),
    _index(0),
    _isReady(false)
{
}

auto RainFull::Init() -> void
{
    _index = random(256);
    _isReady = false;
}

auto RainFull::Show() -> void
{
    if (!_isReady) {
        _isReady = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            _brightnessManipulation.SetColor(ColorFromColorWheel(_index));
            if (!_brightnessManipulation.Change(i, 1)) {
                _isReady = false;
            }
        }
        return;
    }

    for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
        _strip->setPixelColor(index, ColorFromColorWheel(_index));
    }
    ++_index; // index is from 0 to 255
}
