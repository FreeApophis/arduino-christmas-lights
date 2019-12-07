#include "BrightnessManipulation.h"

BrightnessManipulation::BrightnessManipulation(AbstractLedStrip* strip) :
    _brightStrip(strip)
{
}

auto BrightnessManipulation::SetColor(uint32_t color) -> void
{
    _color[0] = color & 0xff;
    color >>= 8;
    _color[1] = color & 0xff;
    color >>= 8;
    _color[2] = color & 0xff;
}

auto BrightnessManipulation::ChangeAll(const int value) -> bool
{
    bool finish = true;
    for (uint16_t index = 0; index < _brightStrip->numPixels(); ++index) {
        if (!Change(index, value)) {
            finish = false;
        }
    }
    return finish;
}

auto BrightnessManipulation::Change(const uint16_t index, const int value) -> bool
{
    uint32_t color = _brightStrip->getPixelColor(index);
    byte bound = 0;
    const int e = 256 + value;
    for (char s = 2; s >= 0; --s) {
        long cc = color >> (s * 8);
        cc &= 0xff;
        const long cs = cc;
        cc *= e;
        cc >>= 8;
        if (cs == cc)
            cc += value;
        if ((value > 0) && (cc >= _color[byte(s)])) {
            cc = _color[byte(s)];
            bound++;
        }
        if ((value < 0) && (cc <= 0)) {
            cc = 0;
            bound++;
        }
        uint32_t mask = 0xff;
        mask <<= (8 * s);
        mask = ~mask;
        cc <<= (s * 8);
        color &= mask;
        color |= cc;
    }
    _brightStrip->setPixelColor(index, color);
    return (bound >= 3);
}
