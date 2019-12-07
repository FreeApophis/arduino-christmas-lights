#include "Rainbow.h"

#include "manipulation/ColorManipulation.h"

Rainbow::Rainbow(AbstractLedStrip* strip) :
    Animation(0x0111, strip, 2, 8),
    _brightnessManipulation(strip),
    _index(0),
    _isReady(false)
{
}

auto Rainbow::Init() -> void
{
    _index = 0;
    _isReady = false;
}

auto Rainbow::Show() -> void
{
    if (!_isReady) {
        _isReady = true;
        for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
            _brightnessManipulation.SetColor(ColorFromColorWheel(index & 255));
            if (!_brightnessManipulation.Change(index, 2)) {
                _isReady = false;
            }
        }
        return;
    }

    for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
        _strip->setPixelColor(index, ColorFromColorWheel((index + _index) & 255));
    }
    ++_index; // index is from 0 to 255
}
