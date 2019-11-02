#include "BrightnessManipulation.h"

BrightnessManipulation::BrightnessManipulation(AbstractLedStrip* strip) :
    _brightStrip(strip)
{
}

void BrightnessManipulation::setColor(uint32_t c)
{
    color[0] = c & 0xff;
    c >>= 8;
    color[1] = c & 0xff;
    c >>= 8;
    color[2] = c & 0xff;
}

bool BrightnessManipulation::changeAll(int val)
{
    bool finish = true;
    for (byte i = 0; i < _brightStrip->numPixels(); ++i) {
        if (!change(i, val))
            finish = false;
    }
    return finish;
}

bool BrightnessManipulation::change(uint16_t index, int val)
{
    uint32_t c = _brightStrip->getPixelColor(index);
    byte bound = 0;
    const int e = 256 + val;
    for (char s = 2; s >= 0; --s) {
        long cc = c >> (s * 8);
        cc &= 0xff;
        const long cs = cc;
        cc *= e;
        cc >>= 8;
        if (cs == cc)
            cc += val;
        if ((val > 0) && (cc >= color[byte(s)])) {
            cc = color[byte(s)];
            bound++;
        }
        if ((val < 0) && (cc <= 0)) {
            cc = 0;
            bound++;
        }
        uint32_t mask = 0xff;
        mask <<= (8 * s);
        mask = ~mask;
        cc <<= (s * 8);
        c &= mask;
        c |= cc;
    }
    _brightStrip->setPixelColor(index, c);
    return (bound >= 3);
}