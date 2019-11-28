#include "RainFull.h"

#include "ColorManipulation.h"

RainFull::RainFull(AbstractLedStrip* strip, byte duration) :
    BrightnessManipulation(strip),
    Animation(0x0110, strip, duration, 6, 24)
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
            BrightnessManipulation::setColor(ColorFromColorWheel(index));
            if (!BrightnessManipulation::change(i, 1))
                rdy = false;
        }
        return;
    }

    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _strip->setPixelColor(i, ColorFromColorWheel(index));
    }
    ++index; // index is from 0 to 255
}
