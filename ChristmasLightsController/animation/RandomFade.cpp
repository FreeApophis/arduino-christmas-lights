#include "RandomFade.h"

#include "manipulation/ColorManipulation.h"

RandomFade::RandomFade(AbstractLedStrip* strip) :
    Animation(0x0114, strip, 6, 24),
    _brightnessManipulation(strip)
{
}

void RandomFade::Init()
{
}

void RandomFade::Show()
{
    _brightnessManipulation.changeAll(-16);
    const byte newDot = random(1, 5);
    for (byte i = 0; i < newDot; ++i) {
        int p = random(_strip->numPixels() + 1);
        uint32_t c = ColorFromColorWheel(random(256));
        if (_strip->getPixelColor(p) == 0)
            _strip->setPixelColor(p, c);
    }
}
