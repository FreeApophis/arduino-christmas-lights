#include "LightUp.h"

LightUp::LightUp(AbstractLedStrip* strip) :
    Animation(0x010a, strip, 6, 24),
    _brightnessManipulation(strip),
    sp(0),
    inc(0)
{
}

void LightUp::Init()
{
    sp = 1;
    inc = sp;
    NewColor();
}

void LightUp::Show()
{
    const bool finish = _brightnessManipulation.changeAll(inc);
    if (finish) {
        if (inc > 0)
            inc = -8;
        else {
            ++sp;
            inc = sp;
            if (sp > 8) {
                sp = 1;
                NewColor();
            }
        }
    }
}

void LightUp::NewColor()
{
    uint32_t c = 0;
    for (byte i = 0; i < 3; ++i) {
        c <<= 8;
        const byte d = random(16) << 4;
        c |= d;
    }
    _brightnessManipulation.setColor(c);
}