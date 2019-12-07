#include "StaticColor.h"

StaticColor::StaticColor(AbstractLedStrip* strip, int32_t color, uint16_t animationId) :
    Animation(animationId, strip, 5, 5),
    _color(color)
{
}

auto StaticColor::Init() -> void
{
    for (auto index = 0; index < _strip->numPixels(); ++index) {
        _strip->setPixelColor(index, _color);
    }
}

auto StaticColor::Show() -> void
{
}
