#include "RandomFade.h"

#include "Helper.h"

RandomFade::RandomFade(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 12, 6, 24)
{
}

void RandomFade::Show()
{
    BrightnessManipulation::changeAll(-16);
    byte newDot = random(1, 5);
    for (byte i = 0; i < newDot; ++i) {
        int p = random(_strip->numPixels() + 1);
        uint32_t c = ColorFromColorWheel(random(256));
        if (_strip->getPixelColor(p) == 0)
            _strip->setPixelColor(p, c);
    }
}
