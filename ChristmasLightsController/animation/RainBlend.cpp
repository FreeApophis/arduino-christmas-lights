#include "RainBlend.h"

#include "manipulation/ColorManipulation.h"

RainBlend::RainBlend(AbstractLedStrip* strip) :
    Animation(0x010e, strip, 1, 6),
    _index(0)
{
}

void RainBlend::Show()
{
    if (_index < int(_strip->numPixels())) {
        _strip->setPixelColor(_index, ColorFromColorWheel(((_index * 256 / _strip->numPixels())) & 255));
        ++_index;
        return;
    }
    for (uint16_t i = 0; i < _strip->numPixels(); ++i)
        _strip->setPixelColor(i, Shimmer(_strip->getPixelColor(i)));
}
