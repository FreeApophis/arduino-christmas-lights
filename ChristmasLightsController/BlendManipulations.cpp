#include "BlendManipulations.h"

#include "Helper.h"

BlendManipulations::BlendManipulations(AbstractLedStrip* strip)
{
}

uint32_t BlendManipulations::add(uint32_t color1, uint32_t color2)
{
    uint8_t r1, g1, b1;
    uint8_t r2, g2, b2;

    r1 = (uint8_t)(color1 >> 16),
    g1 = (uint8_t)(color1 >> 8),
    b1 = (uint8_t)(color1 >> 0);

    r2 = (uint8_t)(color2 >> 16),
    g2 = (uint8_t)(color2 >> 8),
    b2 = (uint8_t)(color2 >> 0);

    return ToColor(constrain(r1 + r2, 0, 255), constrain(g1 + g2, 0, 255), constrain(b1 + b2, 0, 255));
}

uint32_t BlendManipulations::sub(uint32_t color1, uint32_t color2)
{
    uint8_t r1, g1, b1;
    uint8_t r2, g2, b2;
    int16_t r, g, b;

    r1 = (uint8_t)(color1 >> 16),
    g1 = (uint8_t)(color1 >> 8),
    b1 = (uint8_t)(color1 >> 0);

    r2 = (uint8_t)(color2 >> 16),
    g2 = (uint8_t)(color2 >> 8),
    b2 = (uint8_t)(color2 >> 0);

    r = (int16_t)r1 - (int16_t)r2;
    g = (int16_t)g1 - (int16_t)g2;
    b = (int16_t)b1 - (int16_t)b2;
    if (r < 0)
        r = 0;
    if (g < 0)
        g = 0;
    if (b < 0)
        b = 0;

    return ToColor((uint8_t)r, (uint8_t)g, (uint8_t)b);
}

void BlendManipulations::blendPixel(uint16_t p)
{
    byte r1 = random(20);
    byte g1 = random(20);
    byte b1 = random(20);
    uint32_t diff_color = ToColor(r1, g1, b1);
    uint32_t blended_color = BlendManipulations::add(diff_color, _blendStrip->getPixelColor(p));
    r1 = random(20);
    g1 = random(20);
    b1 = random(20);
    diff_color = ToColor(r1, g1, b1);
    blended_color = BlendManipulations::sub(blended_color, diff_color);
    _blendStrip->setPixelColor(p, blended_color);
}