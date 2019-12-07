#include "RainBlend.h"

#include "manipulation/ColorManipulation.h"

RainBlend::RainBlend(AbstractLedStrip* strip) :
    Animation(0x010e, strip, 1, 6),
    _index(0)
{
}

auto RainBlend::Init() -> void
{
    _index = 0;
}

auto RainBlend::Show() -> void
{
    if (_index < int(_strip->numPixels())) {
        _strip->setPixelColor(_index, ColorFromColorWheel(((_index * 256 / _strip->numPixels())) & 255));
        ++_index;
        return;
    }
    for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
        _strip->setPixelColor(index, Shimmer(_strip->getPixelColor(index)));
    }
}
