#include "NeoFire.h"

#include "manipulation/ColorManipulation.h"

NeoFire::NeoFire(AbstractLedStrip* strip) :
    Animation(0x010d, strip, 1, 5),
    _color(0),
    _pause(0)
{
}

auto NeoFire::Init() -> void
{
    _color = 0;
    byte m = random(3);
    _color |= _color1 << (m * 8);
    m += random(1, 3);
    if (m >= 3) {
        m = 0;
    }
    _color |= _color2 << (m * 8);
}

auto NeoFire::Show() -> void
{
    if (_pause > 0) {
        --_pause;
        return;
    }
    _pause = static_cast<char>(random(8));
    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        auto blendedColor = AddColors(_strip->getPixelColor(i), _color);
        const byte redPart = random(80);
        const auto differentColor = ToColor(redPart, redPart / 2, redPart / 2);
        blendedColor = SubtractColors(blendedColor, differentColor);
        _strip->setPixelColor(i, blendedColor);
    }
}
