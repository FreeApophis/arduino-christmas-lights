#include "Fire.h"

#include "../manipulation/ColorManipulation.h"

#include "framework.h"

Fire::Fire(AbstractLedStrip* strip) :
    Animation(0xb002, strip, 2, 6)
{
}

auto Fire::Init() -> void
{
}

auto Fire::Show() -> void
{
    Burn(55, 120);
}

auto Fire::SetPixelHeatColor(int index, byte temperature) const -> void
{
    // Scale 'heat' down from 0-255 to 0-191
    const byte t192 = static_cast<byte>((temperature / 255.0) * 191);

    // calculate ramp up from
    byte heatRamp = t192 & 0x3F; // 0..63
    heatRamp <<= 2;              // scale up to 0..252

    // figure out which third of the spectrum we're in:
    if (t192 > 0x80) { // hottest
        _strip->setPixelColor(index, ToColor(255, 255, heatRamp));
    } else if (t192 > 0x40) { // middle
        _strip->setPixelColor(index, ToColor(255, heatRamp, 0));
    } else { // coolest
        _strip->setPixelColor(index, ToColor(heatRamp, 0, 0));
    }
}

auto Fire::Burn(const int cooling, const int sparks) const -> void
{
    static byte heat[100];

    // Step 1.  Cool down every cell a little
    for (auto index = 0; index < _strip->numPixels(); index++) {
        const auto cooldown = random(0, cooling * 10 / _strip->numPixels() + 2);

        if (cooldown > heat[index]) {
            heat[index] = 0;
        } else {
            heat[index] = heat[index] - cooldown;
        }
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for (auto index = _strip->numPixels() - 1; index >= 2; index--) {
        heat[index] = (heat[index - 1] + heat[index - 2] + heat[index - 2]) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if (random(255) < sparks) {
        const auto sparkPosition = random(7);
        heat[sparkPosition] = heat[sparkPosition] + random(160, 255);
        //heat[y] = random(160,255);
    }

    // Step 4.  Convert heat to LED colors
    for (auto index = 0; index < _strip->numPixels(); index++) {
        SetPixelHeatColor(index, heat[index]);
    }
}
