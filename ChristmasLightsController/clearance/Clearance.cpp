#include "Clearance.h"

#include "AbstractLedStrip.h"

Clearance::Clearance(AbstractLedStrip* strip) :
    _strip(strip),
    _complete(false)
{
}

auto Clearance::FadeAll(const byte value) const -> bool
{
    auto finish = true;
    for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
        if (!Fade(index, value)) {
            finish = false;
        }
    }
    return finish;
}

auto Clearance::IsComplete() const -> bool
{
    return _complete;
}

auto Clearance::Fade(const uint16_t index, const byte value) const -> bool
{
    uint32_t color = _strip->getPixelColor(index);
    byte bound = 0;
    for (char s = 16; s >= 0; s -= 8) {
        long cc = color >> s; // The color component (red, green or blue)
        cc &= 0xff;
        cc -= int(value);
        if (cc < 0) {
            cc = 0;
            bound++;
        }
        uint32_t mask = 0xff;
        mask <<= s;
        mask = ~mask;
        cc <<= s;
        color &= mask;
        color |= cc;
    }
    _strip->setPixelColor(index, color);
    return (bound >= 3);
}
