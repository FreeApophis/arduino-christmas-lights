#include "Sparks.h"

#include "../Helper.h"

Sparks::Sparks(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 12, 2, 6)
{
}

void Sparks::show()
{
    uint32_t c = ColorFromColorWheel(random(265));
    for (char i = 7; i >= 1; --i) {
        if (i == 6)
            _strip->setPixelColor(pos[byte(i)], 0);
        else
            BrightnessManipulation::change(pos[byte(i)], -128);
        pos[byte(i)] = pos[byte(i - 1)];
    }
    int p = random(_strip->numPixels() + 1);
    pos[0] = p;
    _strip->setPixelColor(p, c);
}
