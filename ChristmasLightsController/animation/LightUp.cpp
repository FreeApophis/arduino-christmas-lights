#include "LightUp.h"

LightUp::LightUp(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 12, 6, 24)
{
}

void LightUp::Show()
{
    bool finish = BrightnessManipulation::changeAll(inc);
    if (finish) {
        if (inc > 0)
            inc = -8;
        else {
            ++sp;
            inc = sp;
            if (sp > 8) {
                sp = 1;
                newColor();
            }
        }
    }
}

void LightUp::newColor()
{
    uint32_t c = 0;
    for (byte i = 0; i < 3; ++i) {
        c <<= 8;
        byte d = random(16) << 4;
        c |= d;
    }
    BrightnessManipulation::setColor(c);
}