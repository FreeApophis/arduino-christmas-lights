#include "ColorManipulation.h"

#include "framework.h"

uint32_t ToColor(const uint8_t r, const uint8_t g, const uint8_t b)
{
    return static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | b;
}

uint8_t ExtractRed(const uint32_t color)
{
    return static_cast<uint8_t>(color >> 16);
}

uint8_t ExtractGreen(const uint32_t color)
{
    return static_cast<uint8_t>(color >> 8);
}

uint8_t ExtractBlue(const uint32_t color)
{
    return static_cast<uint8_t>(color >> 0);
}

uint32_t AddColors(const uint32_t color1, const uint32_t color2)
{
    return ToColor(
        constrain(ExtractRed(color1) + ExtractRed(color2), 0, 255),
        constrain(ExtractGreen(color1) + ExtractGreen(color2), 0, 255),
        constrain(ExtractBlue(color1) + ExtractBlue(color2), 0, 255));
}

// Input a value 0 to 255 to get a color value. The colours are a transition r - g - b - back to r.
uint32_t ColorFromColorWheel(const byte position)
{
    if (position < 85) {
        return ToColor(255 - 3 * position, 3 * position, 0);
    }

    if (position >= 170) {
        return ToColor(0, 510 - 3 * position, 3 * position - 255);
    }

    return ToColor(3 * position - 510, 0, 765 - 3 * position);
}

uint32_t ColorSuperPosition(const uint32_t color1, const uint32_t color2)
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

uint32_t SubtractColors(const uint32_t minuend, const uint32_t subtrahend)
{
    int16_t r = static_cast<int16_t>(ExtractRed(minuend)) - static_cast<int16_t>(ExtractRed(subtrahend));
    int16_t g = static_cast<int16_t>(ExtractGreen(minuend)) - static_cast<int16_t>(ExtractGreen(subtrahend));
    int16_t b = static_cast<int16_t>(ExtractBlue(minuend)) - static_cast<int16_t>(ExtractBlue(subtrahend));

    if (r < 0) {
        r = 0;
    }
    if (g < 0) {
        g = 0;
    }
    if (b < 0) {
        b = 0;
    }

    return ToColor(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b));
}

uint32_t CreateVariation()
{
    return ToColor(
        random(20),
        random(20),
        random(20));
}

uint32_t Shimmer(const uint32_t color)
{
    return SubtractColors(AddColors(CreateVariation(), color), CreateVariation());
}