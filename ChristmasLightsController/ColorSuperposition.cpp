#include "ColorSuperposition.h"

uint32_t ColorSuperposition::add(uint32_t c1, uint32_t c2)
{
    uint32_t c = 0;
    for (byte i = 0; i < 3; ++i) {
        uint32_t p = c1 >> (i * 8);
        p += c2 >> (i * 8);
        p &= 0xff;
        p <<= i * 8;
        c |= p;
    }
    return c;
}