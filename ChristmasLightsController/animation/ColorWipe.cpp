#include "ColorWipe.h"

#include "manipulation/ColorManipulation.h"

#include "framework.h"

ColorWipe::ColorWipe(AbstractLedStrip* strip) :
    Animation(0x0105, strip, 2, 8),
    _index(0),
    _isForward(false)
{
    _wheelIndex = random(256);
}

auto ColorWipe::Init() -> void
{
    const int p = random(2, 4);
    _wheelIndex += p * 16 + 1;
    _isForward = random(2) != 0;
    _index = 0;
    if (!_isForward) {
        _index = _strip->numPixels() - 1;
    }
}

auto ColorWipe::Show() -> void
{
    const auto color = ColorFromColorWheel(_wheelIndex);

    if (_isForward) {
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
