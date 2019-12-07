#include "ColorManipulation.h"

#include "framework.h"

#include <cmath>

auto ToColor(const uint8_t r, const uint8_t g, const uint8_t b) -> uint32_t
{
    return static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | b;
}

auto ExtractRed(const uint32_t color) -> uint8_t
{
    return static_cast<uint8_t>(color >> 16);
}

auto ExtractGreen(const uint32_t color) -> uint8_t
{
    return static_cast<uint8_t>(color >> 8);
}

auto ExtractBlue(const uint32_t color) -> uint8_t
{
    return static_cast<uint8_t>(color >> 0);
}

auto AddColors(const uint32_t color1, const uint32_t color2) -> uint32_t
{
    return ToColor(
        constrain(ExtractRed(color1) + ExtractRed(color2), 0, 255),
        constrain(ExtractGreen(color1) + ExtractGreen(color2), 0, 255),
        constrain(ExtractBlue(color1) + ExtractBlue(color2), 0, 255));
}

// The color function is a follows for x:
// first 1/6 (0 - 42): linear from 0 to 255
// next 1/3 (43 - 127): constant 255
// next 1/6 (128 - 170): linear from 255 to 0
// last 1/3 (170 - 255): constant 0
// b is moving the function in x direction...
auto ColorFunction(int x, int b) -> byte
{
    return static_cast<byte>(constrain(516 - abs(85 / 14 * (x - 85 - b)), 0, 255));
}

// Input a value 0 to 255 to get a color value. The colours are a transition r - g - b - back to r.
auto ColorFromColorWheel(const byte position) -> uint32_t
{
    return ToColor(
        ColorFunction(position, 0),
        ColorFunction(position, 85),
        ColorFunction(position, position > 63 ? 170 : -85));
}

auto ColorSuperPosition(const uint32_t color1, const uint32_t color2) -> uint32_t
{
    uint32_t c = 0;
    for (byte i = 0; i < 3; ++i) {
        auto p = color1 >> (i * 8);
        p += color2 >> (i * 8);
        p &= 0xff;
        p <<= i * 8;
        c |= p;
    }
    return c;
}

auto SubtractColors(const uint32_t minuend, const uint32_t subtrahend) -> uint32_t
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

auto CreateVariation() -> uint32_t
{
    return ToColor(
        random(20),
        random(20),
        random(20));
}

auto Shimmer(const uint32_t color) -> uint32_t
{
    return SubtractColors(AddColors(CreateVariation(), color), CreateVariation());
}
