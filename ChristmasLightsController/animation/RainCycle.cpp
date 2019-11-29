#include "RainCycle.h"

#include "manipulation/ColorManipulation.h"

RainCycle::RainCycle(AbstractLedStrip* strip) :
    Animation(0x010f, strip, 2, 8),
    _brightnessManipulation(strip),
    _index(0),
    _brightenPhase(true)
{
}

void RainCycle::Init()
{
    _index = 0;
    _brightenPhase = true;
}

uint32_t RainCycle::ColorWheelFromIndex(uint16_t i) const
{
    return ColorFromColorWheel(i * 256 / _strip->numPixels() + _index);
}

void RainCycle::Brighten()
{
    _brightenPhase = false;
    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _brightnessManipulation.setColor(ColorWheelFromIndex(i));
        if (!_brightnessManipulation.change(i, 1)) {
            _brightenPhase = true;
        }
    }
}

void RainCycle::Show()
{
    if (_brightenPhase) {
        Brighten();
    } else {
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            _strip->setPixelColor(i, ColorWheelFromIndex(i));
        }

        // unsigned, behaviour is defined %256
        ++_index;
    }
}
