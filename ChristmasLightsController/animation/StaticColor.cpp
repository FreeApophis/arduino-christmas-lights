#include "StaticColor.h"

StaticColor::StaticColor(AbstractLedStrip* strip, byte duration, int32_t color) :
    Animation(strip, duration, 5, 5),
    _color(color)
{
}

void StaticColor::Init()
{
    for (auto index = 0; index < _strip->numPixels(); ++index) {
        _strip->setPixelColor(index, _color);
    }
}

void StaticColor::Show()
{
}
