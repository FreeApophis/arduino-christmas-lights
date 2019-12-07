#include "ShineSeven.h"

#include "manipulation/ColorManipulation.h"

ShineSeven::ShineSeven(AbstractLedStrip* strip) :
    Animation(0x0117, strip, 4, 20),
    _brightnessManipulation(strip),
    _current(0),
    _wheelIndex(0),
    _base(0)
{
}

auto ShineSeven::Init() -> void
{
    _current = 0;
    _wheelIndex = random(256);
    _base = random(4, 8);
    StartNewColor();
}

auto ShineSeven::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    auto finish = true;
    for (auto index = int(_current) - 1; index < pixelCount; index += _base) { // Fade out previous color
        if (index >= 0) {
            if (!_brightnessManipulation.Change(index, -8)) {
                finish = false;
            }
        }
    }
    for (int i = _current; i < pixelCount; i += _base) { // Light up current color
        if (!_brightnessManipulation.Change(i, 8)) {
            finish = false;
        }
    }
    if (finish) { // The current color has been light fully
        ++_current;
        if (_current >= _base) {
            _current = 0;
        }
        StartNewColor();
    }
}

auto ShineSeven::StartNewColor() -> void
{
    auto color = ColorFromColorWheel(_wheelIndex);
    _wheelIndex += 97;
    _brightnessManipulation.SetColor(color);
    color &= 0x10101;
    for (uint16_t index = _current; index < _strip->numPixels(); index += _base) {
        _strip->setPixelColor(index, color);
    }
}
