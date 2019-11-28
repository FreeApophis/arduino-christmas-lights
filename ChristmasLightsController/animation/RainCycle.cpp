#include "RainCycle.h"

#include "ColorManipulation.h"

RainCycle::RainCycle(AbstractLedStrip* strip, byte duration) :
    BrightnessManipulation(strip),
    Animation(0x010f, strip, duration, 2, 8),
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
            BrightnessManipulation::setColor(ColorFromColorWheel((i * 256 / _strip->numPixels()) & 255));
            if (!BrightnessManipulation::change(i, 1))
                rdy = false;
        }
        return;
    }

    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _strip->setPixelColor(i, ColorFromColorWheel(((i * 256 / _strip->numPixels()) + index) & 255));
    }
    ++index; // index is from 0 to 255
}
