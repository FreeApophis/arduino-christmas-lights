#include "RainCycle.h"

#include "manipulation/ColorManipulation.h"

RainCycle::RainCycle(AbstractLedStrip* strip) :
    Animation(0x010f, strip, 2, 8),
    _brightnessManipulation(strip),
    _index(0),
    _brightenPhase(true)
{
}

auto RainCycle::Init() -> void
{
    _index = 0;
    _brightenPhase = true;
}

auto RainCycle::ColorWheelFromIndex(const uint16_t index) const -> uint32_t
{
    return ColorFromColorWheel(index * 256 / _strip->numPixels() + _index);
}

auto RainCycle::Brighten() -> void
{
    _brightenPhase = false;
    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        _brightnessManipulation.SetColor(ColorWheelFromIndex(i));
        if (!_brightnessManipulation.Change(i, 1)) {
            _brightenPhase = true;
        }
    }
}

auto RainCycle::Show() -> void
{
    if (_brightenPhase) {
        Brighten();
    } else {
        for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
            _strip->setPixelColor(index, ColorWheelFromIndex(index));
        }

        // unsigned, behaviour is defined %256
        ++_index;
    }
}
