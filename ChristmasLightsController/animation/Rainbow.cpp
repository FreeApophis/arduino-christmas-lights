#include "Rainbow.h"

#include "manipulation/ColorManipulation.h"

Rainbow::Rainbow(AbstractLedStrip* strip) :
    Animation(0x0111, strip, 2, 8),
    _brightnessManipulation(strip),
    index(0),
    rdy(false)
{
}

void Rainbow::Init()
{
    index = 0;
    rdy = false;
}

void Rainbow::Show()
{
    if (!rdy) {
        rdy = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            _brightnessManipulation.setColor(ColorFromColorWheel(i & 255));
            if (!_brightnessManipulation.change(i, 2))
                rdy = false;
        }
        return;
    }

    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _strip->setPixelColor(i, ColorFromColorWheel((i + index) & 255));
    }
    ++index; // index is from 0 to 255
}
