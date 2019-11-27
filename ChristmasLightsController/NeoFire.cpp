#include "NeoFire.h"

#include "Helper.h"

NeoFire::NeoFire(AbstractLedStrip* strip, byte duration):
    BlendManipulations(strip),
    Animation(strip, duration, 1, 5),
    color(0),
    pause(0)
{
}

void NeoFire::Init()
{
    color = 0;
    byte m = random(3);
    color |= c1 << (m * 8);
    m += random(1, 3);
    if (m >= 3)
        m = 0;
    color |= c2 << (m * 8);
}

void NeoFire::Show()
{
    if (pause > 0) {
        --pause;
        return;
    }
    pause = random(8);
    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        uint32_t blended_color = BlendManipulations::add(_strip->getPixelColor(i), color);
        const byte r = random(80);
        const uint32_t diff_color = ToColor(r, r / 2, r / 2);
        blended_color = BlendManipulations::sub(blended_color, diff_color);
        _strip->setPixelColor(i, blended_color);
    }
}