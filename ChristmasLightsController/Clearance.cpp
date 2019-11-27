#include "Clearance.h"

#include "AbstractLedStrip.h"

Clearance::Clearance(AbstractLedStrip* strip) :
    _strip(strip),
    _complete(false)
{
}

bool Clearance::FadeAll(byte val)
{
    bool finish = true;
    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        if (!Fade(i, val))
            finish = false;
    }
    return finish;
}

bool Clearance::IsComplete() const
{
    return _complete;
}

bool Clearance::Fade(uint16_t index, byte val)
{
    uint32_t c = _strip->getPixelColor(index);
    byte bound = 0;
    for (char s = 16; s >= 0; s -= 8) {
        long cc = c >> s; // The color component (red, green or blue)
        cc &= 0xff;
        cc -= int(val);
        if (cc < 0) {
            cc = 0;
            bound++;
        }
        uint32_t mask = 0xff;
        mask <<= s;
        mask = ~mask;
        cc <<= s;
        c &= mask;
        c |= cc;
    }
    _strip->setPixelColor(index, c);
    return (bound >= 3);
}
