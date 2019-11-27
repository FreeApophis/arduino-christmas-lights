#include "Sparks.h"

#include "Helper.h"

Sparks::Sparks(AbstractLedStrip* strip, byte duration) :
    BrightnessManipulation(strip),
    Animation(strip, 12, 2, 6)
{
}

void Sparks::Init()
{
    for (uint16_t& position : _positions) {
        position = 0;
    }
}

void Sparks::Show()
{
    const uint32_t c = ColorFromColorWheel(random(265));
    for (char i = 7; i >= 1; --i) {
        if (i == 6)
            _strip->setPixelColor(_positions[byte(i)], 0);
        else
            BrightnessManipulation::change(_positions[byte(i)], -128);
        _positions[byte(i)] = _positions[byte(i - 1)];
    }
    const int p = random(_strip->numPixels() + 1);
    _positions[0] = p;
    _strip->setPixelColor(p, c);
}
