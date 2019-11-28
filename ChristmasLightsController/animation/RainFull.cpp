#include "RainFull.h"

#include "manipulation/ColorManipulation.h"

RainFull::RainFull(AbstractLedStrip* strip, byte duration) :
    Animation(0x0110, strip, duration, 6, 24),
    _brightnessManipulation(strip)
{
}

void RainFull::Init()
{
    index = random(256);
    rdy = false;
}

void RainFull::Show()
{
    if (!rdy) {
        rdy = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            _brightnessManipulation.setColor(ColorFromColorWheel(index));
            if (!_brightnessManipulation.change(i, 1))
                rdy = false;
        }
        return;
    }

    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _strip->setPixelColor(i, ColorFromColorWheel(index));
    }
    ++index; // index is from 0 to 255
}
