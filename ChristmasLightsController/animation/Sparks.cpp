#include "Sparks.h"

#include "manipulation/ColorManipulation.h"

Sparks::Sparks(AbstractLedStrip* strip, byte duration) :
    Animation(0x011b, strip, 12, 2, 6),
    _brightnessManipulation(strip)
{
}

void Sparks::Init()
{
    for (unsigned short& position : _positions) {
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
            _brightnessManipulation.change(_positions[byte(i)], -128);
        _positions[byte(i)] = _positions[byte(i - 1)];
    }
    const int p = random(_strip->numPixels() + 1);
    _positions[0] = p;
    _strip->setPixelColor(p, c);
}
