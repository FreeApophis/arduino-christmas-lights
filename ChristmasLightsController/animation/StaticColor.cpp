#include "StaticColor.h"

StaticColor::StaticColor(AbstractLedStrip* strip, byte duration) :
    Animation(strip, duration, 5, 5),
    _color(ToColor(220, 220, 255))
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
