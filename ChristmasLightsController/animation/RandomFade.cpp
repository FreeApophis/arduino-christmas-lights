#include "RandomFade.h"

#include "manipulation/ColorManipulation.h"

RandomFade::RandomFade(AbstractLedStrip* strip) :
    Animation(0x0114, strip, 6, 24),
    _brightnessManipulation(strip)
{
}

auto RandomFade::Init() -> void
{
}

auto RandomFade::Show() -> void
{
    _brightnessManipulation.ChangeAll(-16);
    const byte newDot = random(1, 5);
    for (byte index = 0; index < newDot; ++index) {
        const auto position = random(_strip->numPixels() + 1);
        const auto color = ColorFromColorWheel(random(256));
        if (_strip->getPixelColor(position) == 0)
            _strip->setPixelColor(position, color);
    }
}
