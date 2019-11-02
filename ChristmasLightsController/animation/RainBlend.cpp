#include "RainBlend.h"
#include "ColorManipulation.h"

RainBlend::RainBlend(AbstractLedStrip* strip, byte duration):
    Animation(strip, duration, 1, 6),
    index(0)
{
}

void RainBlend::Show()
{
    if (index < int(_strip->numPixels())) {
        _strip->setPixelColor(index, ColorFromColorWheel(((index * 256 / _strip->numPixels())) & 255));
        ++index;
        return;
    }
    for (uint16_t i = 0; i < _strip->numPixels(); ++i)
        _strip->setPixelColor(i, Shimmer(_strip->getPixelColor(i)));
}
