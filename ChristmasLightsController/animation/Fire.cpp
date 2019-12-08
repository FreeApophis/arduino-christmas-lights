#include "Fire.h"

#include "../manipulation/ColorManipulation.h"

#include "framework.h"

Fire::Fire(AbstractLedStrip* strip) :
    Animation(0xb002, strip, 2, 6)
{
}

void Fire::Init()
{
}

void Fire::Show()
{
    Burn(55, 120);
}

void Fire::SetPixelHeatColor(int index, byte temperature)
{
    // Scale 'heat' down from 0-255 to 0-191
    byte t192 = static_cast<byte>((temperature / 255.0) * 191);

    // calculate ramp up from
    byte heatramp = t192 & 0x3F; // 0..63
    heatramp <<= 2;              // scale up to 0..252

    // figure out which third of the spectrum we're in:
    if (t192 > 0x80) { // hottest
        _strip->setPixelColor(index, ToColor(255, 255, heatramp));
    } else if (t192 > 0x40) { // middle
        _strip->setPixelColor(index, ToColor(255, heatramp, 0));
    } else { // coolest
        _strip->setPixelColor(index, ToColor(heatramp, 0, 0));
    }
}

void Fire::Burn(int cooling, int sparks)
{
    static byte heat[100];
    int cooldown;

    // Step 1.  Cool down every cell a little
    for (int i = 0; i < _strip->numPixels(); i++) {
        cooldown = random(0, ((cooling * 10) / _strip->numPixels()) + 2);

        if (cooldown > heat[i]) {
            heat[i] = 0;
        } else {
            heat[i] = heat[i] - cooldown;
        }
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for (int k = _strip->numPixels() - 1; k >= 2; k--) {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if (random(255) < sparks) {
        int y = random(7);
        heat[y] = heat[y] + random(160, 255);
        //heat[y] = random(160,255);
    }

    // Step 4.  Convert heat to LED colors
    for (int j = 0; j < _strip->numPixels(); j++) {
        SetPixelHeatColor(j, heat[j]);
    }
}
