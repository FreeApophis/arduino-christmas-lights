#include "RainBlend.h"
#include "../Helper.h"

RainBlend::RainBlend(AbstractLedStrip* strip, byte duration):
    BlendManipulations(strip),
    Animation(strip, duration, 1, 6)
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
        BlendManipulations::blendPixel(i);
}
