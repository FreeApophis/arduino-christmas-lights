#include "NeoFire.h"

#include "manipulation/ColorManipulation.h"

NeoFire::NeoFire(AbstractLedStrip* strip) :
    Animation(0x010d, strip, 1, 5),
    _color(0),
    pause(0)
{
}

void NeoFire::Init()
{
    _color = 0;
    byte m = random(3);
    _color |= c1 << (m * 8);
    m += random(1, 3);
    if (m >= 3)
        m = 0;
    _color |= c2 << (m * 8);
}

void NeoFire::Show()
{
    if (pause > 0) {
        --pause;
        return;
    }
    pause = random(8);
    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        uint32_t blended_color = AddColors(_strip->getPixelColor(i), _color);
        const byte r = random(80);
        const uint32_t diff_color = ToColor(r, r / 2, r / 2);
        blended_color = SubtractColors(blended_color, diff_color);
        _strip->setPixelColor(i, blended_color);
    }
}