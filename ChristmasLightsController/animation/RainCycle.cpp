#include "RainCycle.h"

#include "manipulation/ColorManipulation.h"

RainCycle::RainCycle(AbstractLedStrip* strip) :
    Animation(0x010f, strip, 2, 8),
    _brightnessManipulation(strip),
    index(0),
    rdy(false)
{
}

void RainCycle::Init()
{
    index = 0;
    rdy = false;
}

void RainCycle::Show()
{
    if (!rdy) {
        rdy = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            _brightnessManipulation.setColor(ColorFromColorWheel((i * 256 / _strip->numPixels()) & 255));
            if (!_brightnessManipulation.change(i, 1))
                rdy = false;
        }
        return;
    }

    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _strip->setPixelColor(i, ColorFromColorWheel(((i * 256 / _strip->numPixels()) + index) & 255));
    }
    ++index; // index is from 0 to 255
}
