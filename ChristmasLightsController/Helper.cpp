#include "Helper.h"

#include "framework.h"

uint32_t ToColor(uint8_t r, uint8_t g, uint8_t b)
{
    return static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | b;
}

// Input a value 0 to 255 to get a color value. The colours are a transition r - g - b - back to r.
uint32_t ColorFromColorWheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return ToColor(255 - WheelPos * 3, 0, WheelPos * 3);
    }

    if (WheelPos < 170) {
        WheelPos -= 85;
        return ToColor(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return ToColor(WheelPos * 3, 255 - WheelPos * 3, 0);
}

uint32_t ColorSuperPosition(uint32_t color1, uint32_t color2)
{
    uint32_t c = 0;
    for (byte i = 0; i < 3; ++i) {
        uint32_t p = color1 >> (i * 8);
        p += color2 >> (i * 8);
        p &= 0xff;
        p <<= i * 8;
        c |= p;
    }
    return c;
}
