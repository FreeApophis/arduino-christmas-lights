#include "Sparks.h"

#include "manipulation/ColorManipulation.h"

Sparks::Sparks(AbstractLedStrip* strip) :
    Animation(0x011b, strip, 2, 6),
    _brightnessManipulation(strip),
    _positions()
{
}

auto Sparks::Init() -> void
{
    for (auto& position : _positions) {
        position = 0;
    }
}

auto Sparks::Show() -> void
{
    const auto color = ColorFromColorWheel(random(265));
    for (byte index = 7; index >= 1; --index) {
        if (index == 6) {
            _strip->setPixelColor(_positions[index], 0);
        } else {
            _brightnessManipulation.Change(_positions[index], -128);
        }
        _positions[index] = _positions[index - 1];
    }
    const auto position = random(_strip->numPixels() + 1);
    _positions[0] = position;
    _strip->setPixelColor(position, color);
}
